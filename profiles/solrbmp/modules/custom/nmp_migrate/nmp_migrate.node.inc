<?php
/**
 * @file
 * User migration class.
 */

/**
 * Migration class.
 */
class NmpNodeMigration extends Migration {

  /**
   * Set up field mapping and nodes to migrate.
   */
  public function __construct($type_source, $type_destination) {
    parent::__construct(MigrateGroup::getInstance('NMPMigrate'));
    $this->description = t('Migrate Drupal 6 nodes');
    $this->dependencies = array('NmpUser');

    // Only import unmigrated nodes from the old db.
    $untouched_titles = db_select('node', 'n')
      ->fields('n', array('title'))
      ->condition('type', $type_destination)
      ->execute()
      ->fetchCol();

    $nodes_to_migrate = Database::getConnection('default', 'migrate')
      ->select('node', 'n')
      ->fields('n', array('nid', 'title'))
      ->condition('type', $type_source)
      ->condition('title', $untouched_titles, 'NOT IN')
      ->condition('status', 1)
      ->execute()
      ->fetchAllKeyed();

    file_put_contents('nodes_to_migrate', implode("\n", array_values($nodes_to_migrate)));

    $query = Database::getConnection('default', 'migrate')
      ->select('node', 'n')
      ->fields('n', array(
        'nid',
        'title',
        'uid',
        'created',
        'changed',
        'status'
      ));
    $query->join('node_revisions', 'nr', 'n.nid = nr.nid');
    $query->fields('nr', array('body'))
      ->condition('n.status', 1, '=')
      ->condition('n.nid', array_keys($nodes_to_migrate))
      ->orderBy('n.nid', 'ASC');

    $source_fields = array(
      'nid' => t('Node ID'),
    );
    $this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));

    $node_options = MigrateDestinationNode::options(LANGUAGE_NONE, 'full_html');
    $this->destination = new MigrateDestinationNode($type_destination, $node_options);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'n',
        )
      ),
      MigrateDestinationUser::getKeySchema(),
      'migrate'
    );

    // Create the field mappings.
    $this->addFieldMapping('is_new')
      ->defaultValue(TRUE);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('title_field', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('NmpUser')
      ->defaultValue('1');
    $this->addFieldMapping('status')
      ->defaultValue(NODE_PUBLISHED);
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'changed');
  }

  /**
   * Fetch taxonomy terms for the node.
   */
  public function prepareRow($current_row) {
    if (parent::prepareRow($current_row) === FALSE) {
      return FALSE;
    }
    $source_id = $current_row->nid;
    $query = Database::getConnection('default', 'migrate')
      ->select('term_node', 'tn');
    $query->join('term_data', 'td', 'tn.tid = td.tid');
    $query->fields('td', array('name', 'vid'))
      ->condition('tn.nid', $source_id, '=');
    $current_row->terms = $query->execute()->fetchAllKeyed();
    return TRUE;
  }

  /**
   * Migrate taxonomy terms.
   */
  public function prepare($entity, $row) {
    if (!$row->terms) {
      return;
    }
    $vocabs = array(
      '1' => array('1', 'blog_category', 'field_tag'),
      '6' => array('6', 'main_categories', 'field_main_categories'),
      '11' => array('2', 'tags', 'field_tags'),
    );
    foreach ($row->terms as $name => $vid) {
      if (!isset($vocabs[$vid]) || !property_exists($entity, $vocabs[$vid][2])) {
        continue;
      }
      if (!$term = reset(taxonomy_get_term_by_name($name, $vocabs[$vid][1]))) {
        $term = entity_create('taxonomy_term', array(
          'vid' => $vocabs[$vid][0],
          'vocabulary_machine_name' => $vocabs[$vid][1],
          'name' => $name,
        ));
        entity_save('taxonomy_term', $term);
      }
      $entity->{$vocabs[$vid][2]}[LANGUAGE_NONE][] = array('tid' => $term->tid);
    }
  }
}

class NmpNodeBlogpostMigration extends NmpNodeMigration {
  public function __construct() {
    parent::__construct('blog', 'blog_post');
  }
}

class NmpNodePageMigration extends NmpNodeMigration {
  public function __construct() {
    parent::__construct('page', 'page');
  }
}

class NmpNodeStoryMigration extends NmpNodeMigration {
  public function __construct() {
    parent::__construct('story', 'story');

    $this->addFieldMapping('field_image', 'image_path');
    $this->addFieldMapping('field_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_image:source_dir')
         ->defaultValue(variable_get('nmp_migrate_image_source_dir', '/var/www/nationalmortgageprofessional.com.old/htdocs/'));
    $this->addFieldMapping('field_image:destination_dir')->defaultValue('public://story');
    $this->addFieldMapping('field_image:preserve_files')
         ->defaultValue(TRUE);
  }

  /**
   * Fetch taxonomy terms for the node.
   */
  public function prepareRow($current_row) {
    if (parent::prepareRow($current_row) === FALSE) {
      return FALSE;
    }
    $source_id = $current_row->nid;
    $query = Database::getConnection('default', 'migrate')
      ->select('image_attach', 'node_img')
      ->condition('node_img.nid', $source_id);
    $query->join('image', 'i', 'i.nid = node_img.iid');
    $query->join('files', 'f', 'f.fid = i.fid');
    $query->fields('f', array('filepath'))
      ->condition('i.image_size', '_original', '=')
      ->condition('f.status', 1);
    $current_row->image_path = $query->execute()->fetchCol();
    return TRUE;
  }
}

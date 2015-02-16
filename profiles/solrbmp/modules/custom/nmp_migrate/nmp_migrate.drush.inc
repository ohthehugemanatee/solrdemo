<?php
/**
 * Drush commands.
 */

/**
 * Implements hook_drush_command().
 */
function nmp_migrate_drush_command() {
  $items['nmp-node-update'] = array(
    'description' => 'update node data with uids and stuff.',
    'aliases' => array('nmpu'),
  );

  return $items;
}

/**
 * Update nodes with their taxonomy term data.
 */
function drush_nmp_migrate_nmp_node_update() {
  $query = Database::getConnection('default', 'migrate')
    ->select('node', 'n')
    ->fields('n', array('nid', 'title', 'created', 'changed'))
    ->condition('n.status', 1, '=')
    ->condition('n.type', 'story')
    ->orderBy('n.nid', 'ASC');
  $query->join('migrate_map_nmpuser', 'map', 'n.uid = map.sourceid1');
  $query->join('url_alias', 'path', "path.src = concat('node/', n.nid)");
  $query->join('users', 'u', 'u.uid = n.uid');

  $query->fields('map', array('destid1'))
    ->fields('path', array('dst'))
    ->fields('u', array('mail', 'name'))
    ->range(0, 1000);
  $results = $query->execute();

  while ($result = $results->fetch()) {
    if (!$nid = db_select('node', 'n')
        ->fields('n', array('nid'))
        ->condition('title', $result->title)
        ->condition('status', NODE_PUBLISHED)
        ->execute()
        ->fetchField()) {
      continue;
    }
    $node = node_load($nid);

    if ($node->type === 'story') {
      $terms_query = Database::getConnection('default', 'migrate')
        ->select('term_node', 't');
      $terms_query->join('term_data', 'td', 'td.tid = t.tid');
      $terms = $terms_query
        ->fields('td', array('name', 'vid'))
        ->condition('t.nid', $result->nid)
        ->condition('td.vid', array(1, 11))
        ->execute()
        ->fetchAllKeyed();

      if ($terms) {
        $vocabs = array(
          '1' => array('1', 'main_categories'),
          '6' => array('6', 'blog_category'),
          '11' => array('2', 'tags'),
        );
        foreach ($terms as $name => $vid) {
          if (!$term = reset(taxonomy_get_term_by_name($name, $vocabs[$vid][1]))) {
            $term = entity_create('taxonomy_term', array(
              'vid' => $vocabs[$vid][0],
              'vocabulary_machine_name' => $vocabs[$vid][1],
              'name' => $name,
            ));
            entity_save('taxonomy_term', $term);
          }
          if ($vid === '1') {
            $field_name = 'field_main_categories';
          }
//          $field_name = "field_{$vocabs[$vid][1]}";
          $node->{$field_name}[LANGUAGE_NONE][] = array('tid' => $term->tid);
        }
        node_save($node);
      }
    }
  }
}

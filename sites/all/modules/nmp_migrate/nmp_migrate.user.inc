<?php
/**
 * @file
 * User migration class.
 */

/**
 * Migration class.
 */
class NmpUserMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('NMPMigrate'));
    $this->description = t('Migrate Drupal 6 users');

    // Some field definitions; roles will be added later in prepareRow().
    $source_fields = array(
      'uid' => t('User ID'),
      'roles' => t('The set of roles assigned to a user.'),
    );

    // Only import active users from the old db.
    $query = Database::getConnection('default', 'migrate')
      ->select('users', 'u')
      ->fields('u', array('uid', 'name', 'pass', 'mail', 'created', 'access', 'login', 'status', 'init'))
      ->condition('u.status', 1, '=')
      ->condition('u.uid', 1, '>')
      ->orderBy('u.uid', 'ASC');
    $this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));

    $this->destination = new MigrateDestinationUser(array('md5_passwords' => TRUE));

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique User ID',
          'alias' => 'u',
        )
      ),
      MigrateDestinationUser::getKeySchema(),
      'migrate'
    );

    // Create the field mappings
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('name', 'name')->dedupe('users', 'name');
    $this->addFieldMapping('pass', 'pass');
    $this->addFieldMapping('mail', 'mail')->dedupe('users', 'mail');
    $this->addFieldMapping('language')->defaultValue('');
    $this->addFieldMapping('theme')->defaultValue('');
    $this->addFieldMapping('signature', 'signature');
    $this->addFieldMapping('signature_format')->defaultValue('filtered_html');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('access', 'access');
    $this->addFieldMapping('login', 'login');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('picture', 'picture')->sourceMigration('NmpUserPicture');
    $this->addFieldMapping('init', 'init');
    $this->addFieldMapping('timezone')->defaultValue(NULL);
    $this->addFieldMapping('path')->issueGroup(t('DNM')); // DNM = Do Not Map
    $this->addFieldMapping('roles', 'roles');
  }

  // Massage the user roles before saving.
  public function prepareRow($current_row) {
    $source_id = $current_row->uid;
    $query = Database::getConnection('default', 'migrate')
      ->select('users_roles', 'r')
      ->fields('r', array('uid', 'rid'))
      ->condition('r.uid', $source_id, '=');
    $results = $query->execute();
    // Add the Authenticated role for everyone.
    $roles = array('2' => '2');
    foreach ($results as $row) {
      // Administrators (rid 7) need role id 3.
      if ($row->rid == 7) {
        $roles['3'] = '3';
      }
      // Bloggers (rid 6) need role id 4.
      if ($row->rid == 6) {
        $roles['4'] = '4';
      }
      // Editors (rid 3) need role id 6.
      if ($row->rid == 3) {
        $roles['6'] = '6';
      }
      // Editorial Contributors (rid 4) need role id 8.
      if ($row->rid == 4) {
        $roles['8'] = '8';
      }
      // Featured Columnist (rid 5) need role id 9.
      if ($row->rid == 5) {
        $roles['9'] = '9';
      }
    }
    $current_row->roles = $roles;
    return TRUE;
  }
}

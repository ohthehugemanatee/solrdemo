<?php
/**
 * @file
 * User picture migration class.
 */

/**
 * Migration class.
 */
class NmpUserPictureMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->dependencies = array('NmpUser');
    $this->base_dir = '/var/www/nationalmortgageprofessional.com/htdocs/';
    //$this->base_dir = '/Users/gergelycsonka/Munka/national/';
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uid' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationFile::getKeySchema(),
      'migrate'
    );


    // Only import active users from the old db.
    $query = Database::getConnection('default', 'migrate')->select('users', 'u')
      ->fields('u', array('uid', 'picture'))
      ->condition('u.status', 1, '=')
      ->condition('u.uid', 1, '>')
      ->condition('picture', '', '!=')
      ->orderBy('u.uid', 'ASC');
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));

    $this->destination = new MigrateDestinationFile();


    $this->addFieldMapping('uid', 'uid')->sourceMigration('NmpUser');
    $this->addFieldMapping('value', 'picture');
    $this->addFieldMapping('source_dir')->defaultValue($this->base_dir);
    $this->addFieldMapping('file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('destination_file', 'filename');
    $this->addFieldMapping('destination_dir', 'public://pictures');
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addUnmigratedDestinations(array('fid', 'filemime', 'timestamp'));
  }

  public function prepare($entity, stdClass $row) {
    $entity->destination_dir = 'public://pictures';
  }

  function complete($entity, stdClass $row) {
    db_update('users')
      ->fields(array(
        'picture' => $entity->fid,
      ))
      ->condition('uid', $entity->uid)
      ->execute();
  }
}

<?php
/**
 * @file
 * Profile migration class.
 */

/**
 * Migration class.
 */
class NmpProfileMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('NMPMigrate'));
    $this->dependencies = array('NmpUser');

    // Only import active users from the old db.
    $query = Database::getConnection('default', 'migrate')->select('node', 'n');
    $query->join('content_type_profile', 'c', 'n.nid = c.nid');
    $query->join('content_field_phone', 'p', 'n.nid = p.nid');
    $query->fields('n', array('nid', 'uid'))
      ->fields('c', array('field_fname_value',
                          'field_lname_value',
                          'field_address_street',
                          'field_address_city',
                          'field_address_province',
                          'field_address_postal_code',
                          'field_website_url',
                          'field_fax_value',
                          'field_aboutme_value',
                          'field_cname_value'))
      ->fields('p', array('field_phone_value'))
      ->condition('n.uid', 1, '>')
      ->orderBy('n.uid', 'ASC');


    // Set source and destination.
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationProfile2('imported_general_profile'); // The machine name of your profile.


    // Set up database mapping.
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
      MigrateDestinationProfile2::getKeySchema(),
      'migrate'
    );


    // Connecting the profile2 to the user:


    $this->addFieldMapping('uid', 'uid')->sourceMigration('NmpUser');
    $this->addFieldMapping('field_fname', 'field_fname_value');
    $this->addFieldMapping('field_lname', 'field_lname_value');
    $this->addFieldMapping('field_cname', 'field_cname_value');
    $this->addFieldMapping('field_website', 'field_website_url');
    $this->addFieldMapping('field_profile_phone', 'field_phone_value');
    $this->addFieldMapping('field_profile_fax', 'field_fax_value');
    $this->addFieldMapping('field_profile_address')->defaultValue('US');
    $this->addFieldMapping('field_profile_address:first_name', 'field_fname_value');
    $this->addFieldMapping('field_profile_address:last_name', 'field_lname_value');
    $this->addFieldMapping('field_profile_address:thoroughfare', 'field_address_street');
    $this->addFieldMapping('field_profile_address:locality', 'field_address_city');
    $this->addFieldMapping('field_profile_address:administrative_area', 'field_address_province');
    $this->addFieldMapping('field_profile_address:postal_code', 'field_address_postal_code');
    $this->addFieldMapping('field_about_me', 'field_aboutme_value');
    $this->addFieldMapping('field_about_me:format', 'filtered_html');
  }
}

<?php
/**
 * @file
 * solrbm_servers.features.inc
 */

/**
 * Implements hook_default_search_api_server().
 */
function solrbm_servers_default_search_api_server() {
  $items = array();

  $server = array(
    'name' => 'Default',
    'machine_name' => 'default',
    'description' => '',
    'class' => 'search_api_solr_service',
    'options' => variable_get('solrbm_search_api_server__default', array()) + array(
      'clean_ids' => TRUE,
      'site_hash' => TRUE,
      'scheme' => 'http',
      'host' => '127.0.0.1',
      'port' => '8983',
      'path' => 'solr/core0',
      'http_user' => '',
      'http_pass' => '',
      'excerpt' => FALSE,
      'retrieve_data' => FALSE,
      'highlight_data' => FALSE,
      'skip_schema_check' => FALSE,
      'solr_version' => '4',
      'http_method' => 'AUTO',
    ),
    'enabled' => '1',
  );

  $items['default'] = entity_import('search_api_server', json_encode($server));

  return $items;
}

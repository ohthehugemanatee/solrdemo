<?php

/**
 * @file
 * Documentation missing.
 */

$databases['default']['default']['username'] = 'my_username';
$databases['default']['default']['password'] = 'my_password';
$databases['default']['default']['database'] = 'solrbm';

/**
 * @see solrbm_servers_default_search_api_server()
 */
$conf['solrbm_search_api_server__default'] = array(
  'port' => '8983',
  'path' => 'solr/solrbm',
);

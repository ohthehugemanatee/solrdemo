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

$conf['cache_backends'][] = 'profiles/solrbmp/modules/contrib/memcache/memcache.inc';
$conf['lock_inc'] = 'profiles/solrbmp/modules/contrib/memcache/memcache-lock.inc';

// The 'cache_form' bin must be assigned to non-volatile storage.
$conf['cache_default_class'] = 'MemCacheDrupal';
$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';

$conf['memcache_servers'] = array(
  'localhost:11211' => 'default',
);

<?php
/**
 * @file
 * solrbm.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solrbm_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function solrbm_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function solrbm_default_search_api_index() {
  $items = array();
  $items['solrbm_candidates'] = entity_import('search_api_index', '{
    "name" : "SolrBM Candidates",
    "machine_name" : "solrbm_candidates",
    "description" : null,
    "server" : "default",
    "item_type" : "solrbm_candidate",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "aliases" : { "type" : "list\\u003Ctext\\u003E" },
        "cid" : { "type" : "integer" },
        "city" : { "type" : "text" },
        "educationRecords" : { "type" : "list\\u003Ctext\\u003E" },
        "emailRecords" : { "type" : "list\\u003Ctext\\u003E" },
        "employmentRecords:company" : { "type" : "list\\u003Ctext\\u003E" },
        "employmentRecords:role" : { "type" : "list\\u003Ctext\\u003E" },
        "facebookUrl" : { "type" : "uri" },
        "gitHubUrl" : { "type" : "uri" },
        "googlePlusUrl" : { "type" : "uri" },
        "links" : { "type" : "list\\u003Ctext\\u003E" },
        "municipality" : { "type" : "text" },
        "name" : { "type" : "text" },
        "pictures" : { "type" : "list\\u003Ctext\\u003E" },
        "qualitativeInformation" : { "type" : "list\\u003Ctext\\u003E" },
        "search_api_language" : { "type" : "string" },
        "skillRecords:skill" : { "type" : "list\\u003Ctext\\u003E" },
        "skillRecords:sourceUrl" : { "type" : "list\\u003Curi\\u003E" },
        "stackOverflowUrl" : { "type" : "uri" },
        "yearCareerStart" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "Full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "city" : true,
              "municipality" : true,
              "educationRecords" : true,
              "emailRecords" : true,
              "links" : true,
              "pictures" : true,
              "qualitativeInformation" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "city" : true,
              "municipality" : true,
              "educationRecords" : true,
              "emailRecords" : true,
              "links" : true,
              "pictures" : true,
              "qualitativeInformation" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "city" : true,
              "municipality" : true,
              "educationRecords" : true,
              "emailRecords" : true,
              "links" : true,
              "pictures" : true,
              "qualitativeInformation" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "city" : true,
              "municipality" : true,
              "educationRecords" : true,
              "emailRecords" : true,
              "links" : true,
              "pictures" : true,
              "qualitativeInformation" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

<?php
/**
 * @file
 * solrbm.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function solrbm_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'solrbm_candidates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_solrbm_candidates';
  $view->human_name = 'solrbm_candidates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Candidates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'cid' => 'cid',
    'name' => 'name',
    'city' => 'city',
    'municipality' => 'municipality',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'cid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'city' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'municipality' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Indexed SolrBM Candidate: ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cid']['separator'] = '';
  $handler->display->display_options['fields']['cid']['link_to_entity'] = 0;
  /* Field: Search: Relevance */
  $handler->display->display_options['fields']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Municipality */
  $handler->display->display_options['fields']['municipality']['id'] = 'municipality';
  $handler->display->display_options['fields']['municipality']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['municipality']['field'] = 'municipality';
  $handler->display->display_options['fields']['municipality']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Qualitative Information */
  $handler->display->display_options['fields']['qualitativeInformation']['id'] = 'qualitativeInformation';
  $handler->display->display_options['fields']['qualitativeInformation']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['qualitativeInformation']['field'] = 'qualitativeInformation';
  $handler->display->display_options['fields']['qualitativeInformation']['link_to_entity'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Indexed SolrBM Candidate: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Indexed SolrBM Candidate: City */
  $handler->display->display_options['filters']['city']['id'] = 'city';
  $handler->display->display_options['filters']['city']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['city']['field'] = 'city';
  $handler->display->display_options['filters']['city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['city']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Indexed SolrBM Candidate: Municipality */
  $handler->display->display_options['filters']['municipality']['id'] = 'municipality';
  $handler->display->display_options['filters']['municipality']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['municipality']['field'] = 'municipality';
  $handler->display->display_options['filters']['municipality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['municipality']['expose']['operator_id'] = 'municipality_op';
  $handler->display->display_options['filters']['municipality']['expose']['label'] = 'Municipality';
  $handler->display->display_options['filters']['municipality']['expose']['operator'] = 'municipality_op';
  $handler->display->display_options['filters']['municipality']['expose']['identifier'] = 'municipality';
  $handler->display->display_options['filters']['municipality']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Indexed SolrBM Candidate: Qualitative Information */
  $handler->display->display_options['filters']['qualitativeInformation']['id'] = 'qualitativeInformation';
  $handler->display->display_options['filters']['qualitativeInformation']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['qualitativeInformation']['field'] = 'qualitativeInformation';
  $handler->display->display_options['filters']['qualitativeInformation']['exposed'] = TRUE;
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['operator_id'] = 'qualitativeInformation_op';
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['label'] = 'Qualitative Information';
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['operator'] = 'qualitativeInformation_op';
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['identifier'] = 'qualitativeInformation';
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'table');
  $handler->display->display_options['path'] = 'candidate';
  $export['solrbm_candidates'] = $view;

  return $export;
}

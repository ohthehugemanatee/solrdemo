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
  $handler->display->display_options['use_more_text'] = 'XLS';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'search_api_views_cache';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '18';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '50, 100, 150, 200, 250';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'cid' => 'cid',
    'search_api_relevance' => 'search_api_relevance',
    'name' => 'name',
    'city' => 'city',
    'municipality' => 'municipality',
    'qualitativeInformation' => 'qualitativeInformation',
    'yearCareerStart' => 'yearCareerStart',
    'facebookUrl' => 'facebookUrl',
    'gitHubUrl' => 'facebookUrl',
    'googlePlusUrl' => 'facebookUrl',
    'stackOverflowUrl' => 'facebookUrl',
    'employmentRecords_company' => 'employmentRecords_company',
    'employmentRecords_role' => 'employmentRecords_role',
    'aliases' => 'aliases',
    'educationRecords' => 'educationRecords',
    'emailRecords' => 'emailRecords',
    'links' => 'links',
    'skillRecords_skill' => 'skillRecords_skill',
    'skillRecords_sourceUrl' => 'skillRecords_sourceUrl',
  );
  $handler->display->display_options['style_options']['default'] = 'search_api_relevance';
  $handler->display->display_options['style_options']['info'] = array(
    'cid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'search_api_relevance' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'qualitativeInformation' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'yearCareerStart' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'facebookUrl' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'gitHubUrl' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'googlePlusUrl' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'stackOverflowUrl' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'employmentRecords_company' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'employmentRecords_role' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'aliases' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'educationRecords' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'emailRecords' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'links' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'skillRecords_skill' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'skillRecords_sourceUrl' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty text';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, there were no results for your search criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Search: Relevance */
  $handler->display->display_options['fields']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_relevance']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cid']['separator'] = '';
  $handler->display->display_options['fields']['cid']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Aliases */
  $handler->display->display_options['fields']['aliases']['id'] = 'aliases';
  $handler->display->display_options['fields']['aliases']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['aliases']['field'] = 'aliases';
  $handler->display->display_options['fields']['aliases']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Career start year */
  $handler->display->display_options['fields']['yearCareerStart']['id'] = 'yearCareerStart';
  $handler->display->display_options['fields']['yearCareerStart']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['yearCareerStart']['field'] = 'yearCareerStart';
  $handler->display->display_options['fields']['yearCareerStart']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Qualitative Information */
  $handler->display->display_options['fields']['qualitativeInformation']['id'] = 'qualitativeInformation';
  $handler->display->display_options['fields']['qualitativeInformation']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['qualitativeInformation']['field'] = 'qualitativeInformation';
  $handler->display->display_options['fields']['qualitativeInformation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['qualitativeInformation']['link_to_entity'] = 0;
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
  /* Field: Employment Records: Company (indexed) */
  $handler->display->display_options['fields']['employmentRecords_company']['id'] = 'employmentRecords_company';
  $handler->display->display_options['fields']['employmentRecords_company']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['employmentRecords_company']['field'] = 'employmentRecords_company';
  $handler->display->display_options['fields']['employmentRecords_company']['label'] = 'Employment records: Company';
  $handler->display->display_options['fields']['employmentRecords_company']['link_to_entity'] = 0;
  /* Field: Employment Records: Role (indexed) */
  $handler->display->display_options['fields']['employmentRecords_role']['id'] = 'employmentRecords_role';
  $handler->display->display_options['fields']['employmentRecords_role']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['employmentRecords_role']['field'] = 'employmentRecords_role';
  $handler->display->display_options['fields']['employmentRecords_role']['label'] = 'Employment records: Role';
  $handler->display->display_options['fields']['employmentRecords_role']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Education Records */
  $handler->display->display_options['fields']['educationRecords']['id'] = 'educationRecords';
  $handler->display->display_options['fields']['educationRecords']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['educationRecords']['field'] = 'educationRecords';
  $handler->display->display_options['fields']['educationRecords']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Email Records */
  $handler->display->display_options['fields']['emailRecords']['id'] = 'emailRecords';
  $handler->display->display_options['fields']['emailRecords']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['emailRecords']['field'] = 'emailRecords';
  $handler->display->display_options['fields']['emailRecords']['link_to_entity'] = 0;
  /* Field: Skill records: Skill (indexed) */
  $handler->display->display_options['fields']['skillRecords_skill']['id'] = 'skillRecords_skill';
  $handler->display->display_options['fields']['skillRecords_skill']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['skillRecords_skill']['field'] = 'skillRecords_skill';
  $handler->display->display_options['fields']['skillRecords_skill']['label'] = 'Skill records: Skill';
  $handler->display->display_options['fields']['skillRecords_skill']['link_to_entity'] = 0;
  /* Field: Skill records: Source URL (indexed) */
  $handler->display->display_options['fields']['skillRecords_sourceUrl']['id'] = 'skillRecords_sourceUrl';
  $handler->display->display_options['fields']['skillRecords_sourceUrl']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['skillRecords_sourceUrl']['field'] = 'skillRecords_sourceUrl';
  $handler->display->display_options['fields']['skillRecords_sourceUrl']['label'] = 'Skill records: Source';
  $handler->display->display_options['fields']['skillRecords_sourceUrl']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Facebook URL */
  $handler->display->display_options['fields']['facebookUrl']['id'] = 'facebookUrl';
  $handler->display->display_options['fields']['facebookUrl']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['facebookUrl']['field'] = 'facebookUrl';
  $handler->display->display_options['fields']['facebookUrl']['label'] = 'Social links';
  $handler->display->display_options['fields']['facebookUrl']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: GitHub URL */
  $handler->display->display_options['fields']['gitHubUrl']['id'] = 'gitHubUrl';
  $handler->display->display_options['fields']['gitHubUrl']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['gitHubUrl']['field'] = 'gitHubUrl';
  $handler->display->display_options['fields']['gitHubUrl']['label'] = 'GitHub';
  $handler->display->display_options['fields']['gitHubUrl']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Google+ URL */
  $handler->display->display_options['fields']['googlePlusUrl']['id'] = 'googlePlusUrl';
  $handler->display->display_options['fields']['googlePlusUrl']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['googlePlusUrl']['field'] = 'googlePlusUrl';
  $handler->display->display_options['fields']['googlePlusUrl']['label'] = 'Google+';
  $handler->display->display_options['fields']['googlePlusUrl']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Stack Overflow URL */
  $handler->display->display_options['fields']['stackOverflowUrl']['id'] = 'stackOverflowUrl';
  $handler->display->display_options['fields']['stackOverflowUrl']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['stackOverflowUrl']['field'] = 'stackOverflowUrl';
  $handler->display->display_options['fields']['stackOverflowUrl']['label'] = 'Stack Overflow';
  $handler->display->display_options['fields']['stackOverflowUrl']['link_to_entity'] = 0;
  /* Field: Indexed SolrBM Candidate: Links */
  $handler->display->display_options['fields']['links']['id'] = 'links';
  $handler->display->display_options['fields']['links']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['fields']['links']['field'] = 'links';
  $handler->display->display_options['fields']['links']['link_to_entity'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Indexed SolrBM Candidate: ID */
  $handler->display->display_options['filters']['cid']['id'] = 'cid';
  $handler->display->display_options['filters']['cid']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['cid']['field'] = 'cid';
  $handler->display->display_options['filters']['cid']['group'] = 1;
  $handler->display->display_options['filters']['cid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cid']['expose']['operator_id'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['cid']['expose']['operator'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['identifier'] = 'cid';
  $handler->display->display_options['filters']['cid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['cid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['cid']['group_info']['label'] = 'ID';
  $handler->display->display_options['filters']['cid']['group_info']['identifier'] = 'cid';
  $handler->display->display_options['filters']['cid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['cid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Indexed SolrBM Candidate: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed SolrBM Candidate: Aliases */
  $handler->display->display_options['filters']['aliases']['id'] = 'aliases';
  $handler->display->display_options['filters']['aliases']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['aliases']['field'] = 'aliases';
  $handler->display->display_options['filters']['aliases']['group'] = 1;
  $handler->display->display_options['filters']['aliases']['exposed'] = TRUE;
  $handler->display->display_options['filters']['aliases']['expose']['operator_id'] = 'aliases_op';
  $handler->display->display_options['filters']['aliases']['expose']['label'] = 'Aliases';
  $handler->display->display_options['filters']['aliases']['expose']['operator'] = 'aliases_op';
  $handler->display->display_options['filters']['aliases']['expose']['identifier'] = 'aliases';
  $handler->display->display_options['filters']['aliases']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['aliases']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed SolrBM Candidate: Career start year */
  $handler->display->display_options['filters']['yearCareerStart']['id'] = 'yearCareerStart';
  $handler->display->display_options['filters']['yearCareerStart']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['yearCareerStart']['field'] = 'yearCareerStart';
  $handler->display->display_options['filters']['yearCareerStart']['group'] = 1;
  $handler->display->display_options['filters']['yearCareerStart']['exposed'] = TRUE;
  $handler->display->display_options['filters']['yearCareerStart']['expose']['operator_id'] = 'yearCareerStart_op';
  $handler->display->display_options['filters']['yearCareerStart']['expose']['label'] = 'Career start year';
  $handler->display->display_options['filters']['yearCareerStart']['expose']['operator'] = 'yearCareerStart_op';
  $handler->display->display_options['filters']['yearCareerStart']['expose']['identifier'] = 'yearCareerStart';
  $handler->display->display_options['filters']['yearCareerStart']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['yearCareerStart']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed SolrBM Candidate: Qualitative Information */
  $handler->display->display_options['filters']['qualitativeInformation']['id'] = 'qualitativeInformation';
  $handler->display->display_options['filters']['qualitativeInformation']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['qualitativeInformation']['field'] = 'qualitativeInformation';
  $handler->display->display_options['filters']['qualitativeInformation']['group'] = 1;
  $handler->display->display_options['filters']['qualitativeInformation']['exposed'] = TRUE;
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['operator_id'] = 'qualitativeInformation_op';
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['label'] = 'Qualitative Information';
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['operator'] = 'qualitativeInformation_op';
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['identifier'] = 'qualitativeInformation';
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['qualitativeInformation']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed SolrBM Candidate: City */
  $handler->display->display_options['filters']['city']['id'] = 'city';
  $handler->display->display_options['filters']['city']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['city']['field'] = 'city';
  $handler->display->display_options['filters']['city']['group'] = 1;
  $handler->display->display_options['filters']['city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['city']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed SolrBM Candidate: Municipality */
  $handler->display->display_options['filters']['municipality']['id'] = 'municipality';
  $handler->display->display_options['filters']['municipality']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['municipality']['field'] = 'municipality';
  $handler->display->display_options['filters']['municipality']['group'] = 1;
  $handler->display->display_options['filters']['municipality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['municipality']['expose']['operator_id'] = 'municipality_op';
  $handler->display->display_options['filters']['municipality']['expose']['label'] = 'Municipality';
  $handler->display->display_options['filters']['municipality']['expose']['operator'] = 'municipality_op';
  $handler->display->display_options['filters']['municipality']['expose']['identifier'] = 'municipality';
  $handler->display->display_options['filters']['municipality']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['municipality']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Employment Records: Company (indexed) */
  $handler->display->display_options['filters']['employmentRecords_company']['id'] = 'employmentRecords_company';
  $handler->display->display_options['filters']['employmentRecords_company']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['employmentRecords_company']['field'] = 'employmentRecords_company';
  $handler->display->display_options['filters']['employmentRecords_company']['group'] = 1;
  $handler->display->display_options['filters']['employmentRecords_company']['exposed'] = TRUE;
  $handler->display->display_options['filters']['employmentRecords_company']['expose']['operator_id'] = 'employmentRecords_company_op';
  $handler->display->display_options['filters']['employmentRecords_company']['expose']['label'] = 'Employment Records: Company';
  $handler->display->display_options['filters']['employmentRecords_company']['expose']['operator'] = 'employmentRecords_company_op';
  $handler->display->display_options['filters']['employmentRecords_company']['expose']['identifier'] = 'employmentRecords_company';
  $handler->display->display_options['filters']['employmentRecords_company']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['employmentRecords_company']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Employment Records: Role (indexed) */
  $handler->display->display_options['filters']['employmentRecords_role']['id'] = 'employmentRecords_role';
  $handler->display->display_options['filters']['employmentRecords_role']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['employmentRecords_role']['field'] = 'employmentRecords_role';
  $handler->display->display_options['filters']['employmentRecords_role']['group'] = 1;
  $handler->display->display_options['filters']['employmentRecords_role']['exposed'] = TRUE;
  $handler->display->display_options['filters']['employmentRecords_role']['expose']['operator_id'] = 'employmentRecords_role_op';
  $handler->display->display_options['filters']['employmentRecords_role']['expose']['label'] = 'Employment Records: Role';
  $handler->display->display_options['filters']['employmentRecords_role']['expose']['operator'] = 'employmentRecords_role_op';
  $handler->display->display_options['filters']['employmentRecords_role']['expose']['identifier'] = 'employmentRecords_role';
  $handler->display->display_options['filters']['employmentRecords_role']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['employmentRecords_role']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed SolrBM Candidate: Education Records */
  $handler->display->display_options['filters']['educationRecords']['id'] = 'educationRecords';
  $handler->display->display_options['filters']['educationRecords']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['educationRecords']['field'] = 'educationRecords';
  $handler->display->display_options['filters']['educationRecords']['group'] = 1;
  $handler->display->display_options['filters']['educationRecords']['exposed'] = TRUE;
  $handler->display->display_options['filters']['educationRecords']['expose']['operator_id'] = 'educationRecords_op';
  $handler->display->display_options['filters']['educationRecords']['expose']['label'] = 'Education Records';
  $handler->display->display_options['filters']['educationRecords']['expose']['operator'] = 'educationRecords_op';
  $handler->display->display_options['filters']['educationRecords']['expose']['identifier'] = 'educationRecords';
  $handler->display->display_options['filters']['educationRecords']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['educationRecords']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed SolrBM Candidate: Email Records */
  $handler->display->display_options['filters']['emailRecords']['id'] = 'emailRecords';
  $handler->display->display_options['filters']['emailRecords']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['emailRecords']['field'] = 'emailRecords';
  $handler->display->display_options['filters']['emailRecords']['group'] = 1;
  $handler->display->display_options['filters']['emailRecords']['exposed'] = TRUE;
  $handler->display->display_options['filters']['emailRecords']['expose']['operator_id'] = 'emailRecords_op';
  $handler->display->display_options['filters']['emailRecords']['expose']['label'] = 'Email Records';
  $handler->display->display_options['filters']['emailRecords']['expose']['operator'] = 'emailRecords_op';
  $handler->display->display_options['filters']['emailRecords']['expose']['identifier'] = 'emailRecords';
  $handler->display->display_options['filters']['emailRecords']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['emailRecords']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Skill records: Skill (indexed) */
  $handler->display->display_options['filters']['skillRecords_skill']['id'] = 'skillRecords_skill';
  $handler->display->display_options['filters']['skillRecords_skill']['table'] = 'search_api_index_solrbm_candidates';
  $handler->display->display_options['filters']['skillRecords_skill']['field'] = 'skillRecords_skill';
  $handler->display->display_options['filters']['skillRecords_skill']['group'] = 1;
  $handler->display->display_options['filters']['skillRecords_skill']['exposed'] = TRUE;
  $handler->display->display_options['filters']['skillRecords_skill']['expose']['operator_id'] = 'skillRecords_skill_op';
  $handler->display->display_options['filters']['skillRecords_skill']['expose']['label'] = 'Skill Records: Skill';
  $handler->display->display_options['filters']['skillRecords_skill']['expose']['operator'] = 'skillRecords_skill_op';
  $handler->display->display_options['filters']['skillRecords_skill']['expose']['identifier'] = 'skillRecords_skill';
  $handler->display->display_options['filters']['skillRecords_skill']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['skillRecords_skill']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['skillRecords_skill']['group_info']['label'] = 'Skill (indexed)';
  $handler->display->display_options['filters']['skillRecords_skill']['group_info']['identifier'] = 'skillRecords_skill';
  $handler->display->display_options['filters']['skillRecords_skill']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['skillRecords_skill']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'table');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['path'] = 'candidate';

  /* Display: Excel export */
  $handler = $view->new_display('views_data_export', 'Excel export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '250';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'techhiring-results.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'candidate/export';
  $handler->display->display_options['displays'] = array(
    'table' => 'table',
    'default' => 0,
  );
  $export['solrbm_candidates'] = $view;

  return $export;
}

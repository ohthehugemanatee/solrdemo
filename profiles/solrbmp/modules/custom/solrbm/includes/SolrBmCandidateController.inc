<?php
/**
 * @file
 * ${FILE_DESCRIPTION}
 */

/**
 * Class SolrBmCandidate.
 */
class SolrBmCandidateController extends DrupalDefaultEntityController {

  /**
   * {@inheritdoc}
   */
  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {
    $this->attachLoadAliases($queried_entities);
    $this->attachLoadEducationRecords($queried_entities);
    $this->attachLoadEmailRecords($queried_entities);
    $this->attachLoadEmploymentRecords($queried_entities);
    $this->attachLoadLinks($queried_entities);
    $this->attachLoadPictures($queried_entities);
    $this->attachLoadQualitativeInformation($queried_entities);
    $this->attachLoadSkillRecords($queried_entities);

    parent::attachLoad($queried_entities, $revision_id);
  }

  /**
   * @param array $queried_entities
   */
  protected function attachLoadAliases(&$queried_entities) {
    $this->attachLoadList($queried_entities, 'aliases', 'alias', 'aliases');
  }

  /**
   * @param array $queried_entities
   */
  protected function attachLoadEducationRecords(&$queried_entities) {
    $this->attachLoadList($queried_entities, 'education_records', 'record', 'educationRecords');
  }

  /**
   * @param array $queried_entities
   */
  protected function attachLoadEmailRecords(&$queried_entities) {
    $this->attachLoadList($queried_entities, 'email_records', 'email', 'emailRecords');
  }

  /**
   * @param array $queried_entities
   */
  protected function attachLoadEmploymentRecords(&$queried_entities) {
    $this->attachLoadStructure($queried_entities, 'employment_records', 'employmentRecords');
  }

  /**
   * @param array $queried_entities
   */
  protected function attachLoadLinks(&$queried_entities) {
    $this->attachLoadList($queried_entities, 'links', 'link_url', 'links');
  }

  /**
   * @param array $queried_entities
   */
  protected function attachLoadPictures(&$queried_entities) {
    $this->attachLoadList($queried_entities, 'pictures', 'picture_url', 'pictures');
  }

  /**
   * @param array $queried_entities
   */
  protected function attachLoadQualitativeInformation(&$queried_entities) {
    $this->attachLoadList($queried_entities, 'qualitative_information', 'information', 'qualitativeInformation');
  }

  /**
   * @param array $queried_entities
   */
  protected function attachLoadSkillRecords(&$queried_entities) {
    $this->attachLoadStructure($queried_entities, 'skill_records', 'skillRecords');
  }

  /**
   * @param array $queried_entities
   * @param string $table
   * @param string $column
   * @param string $field
   */
  protected function attachLoadList(&$queried_entities, $table, $column, $field) {
    $result = db_select($table, 'a')
      ->fields('a', array('cid', $column))
      ->condition('a.cid', array_keys($queried_entities), 'IN')
      ->execute();

    foreach ($queried_entities as $entity) {
      if (!isset($entity->$field)) {
        $entity->$field = array();
      }
    }

    foreach ($result as $row) {
      $queried_entities[$row->cid]->{$field}[] = $row->$column;
    }
  }

  /**
   * @param array $queried_entities
   * @param string $table
   * @param string $field
   */
  protected function attachLoadStructure(&$queried_entities, $table, $field) {
    $result = db_select($table, 'a')
      ->fields('a')
      ->condition('a.cid', array_keys($queried_entities), 'IN')
      ->execute();

    foreach ($queried_entities as $entity) {
      if (!isset($entity->$field)) {
        $entity->$field = array();
      }
    }

    foreach ($result as $row) {
      $queried_entities[$row->cid]->{$field}[] = $row;
    }
  }

}


<?php
/**
 * @file
 * t3_species_glossary.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 * 
 * View created within Views UI and exported
 * After installing this module, the menu cache needs to be cleared
 */
function t3_species_glossary_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 't3_species_glossary';
  $view->description = 'A listing of all published organisms on this site.';
  $view->tag = 'default';
  $view->base_table = 'OBI__0100026';
  $view->human_name = 't3_species_glossary';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Organism Overview';
  $handler->display->display_options['css_class'] = 'species_overview_table';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'taxrank__genus' => 'taxrank__genus',
    'taxrank__species' => 'taxrank__genus',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'taxrank__genus' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'taxrank__species' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  //$handler->display->display_options['style_options']['caption'] = 'Table that shows all organisms on this site.';
  $handler->display->display_options['style_options']['summary'] = 'Table with links to organism pages.';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total organisms.';
  /* Field: Organism: Description */
  $handler->display->display_options['fields']['schema__description']['id'] = 'schema__description';
  $handler->display->display_options['fields']['schema__description']['table'] = 'OBI__0100026';
  $handler->display->display_options['fields']['schema__description']['field'] = 'schema__description';
  /* Sort criterion: Organism: Genus */
  $handler->display->display_options['sorts']['taxrank__genus']['id'] = 'taxrank__genus';
  $handler->display->display_options['sorts']['taxrank__genus']['table'] = 'OBI__0100026';
  $handler->display->display_options['sorts']['taxrank__genus']['field'] = 'taxrank__genus';
  $handler->display->display_options['sorts']['taxrank__genus']['expose']['label'] = 'Genus';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null']['specify_validation'] = TRUE;
  /* Filter criterion: Organism: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'OBI__0100026';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Organism: Genus */
  $handler->display->display_options['fields']['taxrank__genus']['id'] = 'taxrank__genus';
  $handler->display->display_options['fields']['taxrank__genus']['table'] = 'OBI__0100026';
  $handler->display->display_options['fields']['taxrank__genus']['field'] = 'taxrank__genus';
  $handler->display->display_options['fields']['taxrank__genus']['label'] = '';
  $handler->display->display_options['fields']['taxrank__genus']['exclude'] = TRUE;
  $handler->display->display_options['fields']['taxrank__genus']['element_label_colon'] = FALSE;
  /* Field: Organism: Species */
  $handler->display->display_options['fields']['taxrank__species']['id'] = 'taxrank__species';
  $handler->display->display_options['fields']['taxrank__species']['table'] = 'OBI__0100026';
  $handler->display->display_options['fields']['taxrank__species']['field'] = 'taxrank__species';
  $handler->display->display_options['fields']['taxrank__species']['label'] = '';
  $handler->display->display_options['fields']['taxrank__species']['exclude'] = TRUE;
  $handler->display->display_options['fields']['taxrank__species']['element_label_colon'] = FALSE;
  /* Field: Organism: Link */
  $handler->display->display_options['fields']['link']['id'] = 'link';
  $handler->display->display_options['fields']['link']['table'] = 'OBI__0100026';
  $handler->display->display_options['fields']['link']['field'] = 'link';
  $handler->display->display_options['fields']['link']['label'] = 'Organisms';
  $handler->display->display_options['fields']['link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['link']['alter']['text'] = '[taxrank__genus] [taxrank__species]';
  $handler->display->display_options['fields']['link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['path'] = 't3_species_glossary';

  $export['species_glossary'] = $view;

  return $export;
}

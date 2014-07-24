<?php
/**
 * @file
 * newman_to_catman.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function newman_to_catman_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'newman_catman_import';
  $feeds_importer->config = array(
    'name' => 'Newman to Catman Import',
    'description' => 'Imports newman records to catman system',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Series_total',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Series_prefix_value',
            'target' => 'field_series_prefix',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Series_number',
            'target' => 'field_series_number',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Series_suffix',
            'target' => 'field_series_suffix',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Alt_series',
            'target' => 'field_alt_series_number',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Cover_image',
            'target' => 'field_publication_thumbnail',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Description',
            'target' => 'field_publication_description',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Length',
            'target' => 'field_length',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Corresp_author_catman_node',
            'target' => 'field_corresponding_author:nid:duplicates',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Status_date',
            'target' => 'field_status_date:start',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Project_manager_catman_value',
            'target' => 'field_project_manager',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Media_type_catman_node',
            'target' => 'field_media_type',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          13 => array(
            'source' => 'General_notes',
            'target' => 'field_general_notes',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'EESC_or_purchased_catman_value',
            'target' => 'field_eesc_produced_purchased',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Mode_of_delivery_catman_value',
            'target' => 'field_mode_of_delivery',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'Date_pub_or_rev',
            'target' => 'field_publication_date:start',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'Date_reviewed',
            'target' => 'field_date_reviewed:start',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'Review_notes',
            'target' => 'field_review_notes',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'Add_to_store_node',
            'target' => 'field_add_to_store',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'Account_catman_node',
            'target' => 'field_account_type:nid:duplicates',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'Topics_catman_nodes',
            'target' => 'field_topic',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          22 => array(
            'source' => 'Program_area_catman_node',
            'target' => 'field_program_area',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          23 => array(
            'source' => 'New_revised_catman_value',
            'target' => 'field_new_or_revised',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'Print_specs',
            'target' => 'field_print_specs',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'Estimate_expense_notes',
            'target' => 'field_estimates_expense_notes',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'Status_catman_value',
            'target' => 'field_publication_status',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'Authors_catman_nodes',
            'target' => 'field_authors_entity_ref:etid',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'Active_pdf',
            'target' => 'field_pdf_file',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'Active_xls',
            'target' => 'field_excel_file',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'Active_epub',
            'target' => 'field_epub_file',
            'unique' => FALSE,
          ),
          31 => array(
            'source' => 'Preview_file',
            'target' => 'field_preview_file',
            'unique' => FALSE,
          ),
          32 => array(
            'source' => 'Permanent_link',
            'target' => 'field_catman_link:url',
            'unique' => FALSE,
          ),
          33 => array(
            'source' => 'Link_or_file_catman_value',
            'target' => 'field_link_or_upload',
            'unique' => FALSE,
          ),
          34 => array(
            'source' => 'Publication_SKU',
            'target' => 'field_publication_product:sku',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'osu_catalog_publication',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['newman_catman_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'pub_author_import';
  $feeds_importer->config = array(
    'name' => 'Publication author importer',
    'description' => 'Imports publications authors using .csv file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'last_name',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'first_name',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'bundle' => 'publication_author',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['pub_author_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'store_items_importer';
  $feeds_importer->config = array(
    'name' => 'Newman to Catman store items importer',
    'description' => 'Imports newman ecommerce items to catman system',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'product',
        'author' => '1',
        'tax_rate' => '',
        'mappings' => array(
          0 => array(
            'source' => 'Series_total',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Sales_price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Add_to_store_node',
            'target' => 'status',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Inventory',
            'target' => 'commerce_stock',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Cost_per_copy',
            'target' => 'field_cost_per_copy:amount',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Publication_SKU',
            'target' => 'sku',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'product',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['store_items_importer'] = $feeds_importer;

  return $export;
}

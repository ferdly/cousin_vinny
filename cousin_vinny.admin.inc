<?php

function cousin_vinny_overview() {
    return 'Hello Overview!';
}
function cousin_vinny_test() {
  $form = array();

  $form['cousin_vinny_test'] = array(
    '#type' => 'textfield',
    '#title' => t('Test VIN'),
    // '#default_value' => variable_get('cousin_vinny_test_vin', 3),
    '#default_value' => 'KL1TD5DE2BB119431',
    '#size' => 25,
    '#maxlength' => 17,
    '#description' => t("The Test VIN for Cousin Vinny testing."),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

function cousin_vinny_settings() {
  $form = array();

  $form['cousin_vinny_content_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Content Type'),
    // '#default_value' => variable_get('cousin_vinny_test_vin', 3),
    '#default_value' => 'Vehicle',
    '#size' => 200,
    '#maxlength' => 128,
    '#description' => t("The Content Type for Cousin Vinny."),
    '#required' => TRUE,
  );
  $form['cousin_vinny_content_edmunds_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Edmunds API Key'),
    '#default_value' => variable_get('cousin_vinny_content_edmunds_key', 'hwxwzk7x36pxvtvtc8reqtrp'),
    // '#default_value' => 'hwxwzk7x36pxvtvtc8reqtrp',
    '#size' => 200,
    '#maxlength' => 128,
    '#description' => t("The API Key for Edmunds."),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * END: Tradition Drupal Module Functionality
 */

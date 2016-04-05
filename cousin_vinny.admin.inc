<?php

function cousin_vinny_overview() {
    return 'Hello Overview!';
}
function cousin_vinny_test($form, $form_state) {
  $form = array();

  $form["test_vin_select"] = array(
    "#type" => "select",
    "#title" => t("Select a Vehicle to Test."),
    "#default_value" => variable_get('NNULL'),
    "#options" => array(
      'NNULL' => 'Select',
      'kL1TD5DE2BB119431' => "2011 Chevrolet Aveo",
      '5gAEV23778J206256' => "2008 Buick Enclave",
      'JTDBL40E99J044394' => "2009 Toyota Corolla LE",
      '5TDBT44A73S145029' => "2003 Toyota Sequoia",
      '1G1RA6E48FU138415' => "2015 Chevrolet Volt",
      'JTDKN3DU5F1971796' => "2015 Toyota Prius Three",
      ),
    "#description" => t("Select plugin."),
    );
  $form['test_vin_direct'] = array(
    '#type' => 'textfield',
    '#title' => t('Test VIN'),
    // '#default_value' => variable_get('cousin_vinny_test_vin', 3),
    // '#default_value' => 'KL1TD5DE2BB119431',
    '#size' => 25,
    '#maxlength' => 17,
    '#description' => t("Or Directly Input a Test VIN for Cousin Vinny testing."),
    // '#required' => TRUE,
  );
  $form['dev'] = array(
    '#type' => 'radios',
    '#title' => t("Also show full 'Edmunds' result"),
    // '#default_value' => 0,
    '#options' => array(1=>t('Show'))
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  $vin = @$form_state['input']['test_vin_select'] != 'NNULL' ? @$form_state['input']['test_vin_select'] : '';
  $vin .= @$form_state['input']['test_vin_direct'];
  if (strlen($vin) > 0) {
    $options_array['dev'] = @$form_state['input']['dev'] + 0 > 0 ? TRUE : FALSE;
    _test_execute_vin_collect($vin, 'common', $options_array);
 }
  // $form['cousin_vinny_test']['#submit'][] = 'cousin_vinny_settings';
  $form_id = 'cousin_vinny_ztest';
  if (1 == 2 && $form_id == 'cousin_vinny_test') {
    glueDeveloper_form_FORM_ID_alter($form, $form_state, $form_id);
  }
  return $form;
}
function cousin_vinny_cousin_vinny_test_submit($form, &$form_state) {
  drupal_set_message(t('The form has been submitted.'));
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

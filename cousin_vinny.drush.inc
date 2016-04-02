<?php

/**
 * Implements hook_drush_command().
 */
function cousin_vinny_drush_command() {
/**
 * Essential to the function of the Drush Command
 */
  $items['vin-collect'] = array(
    'aliases' => array(
      'vinny',
      'vinc',
      ),
    'arguments' => array(
      'vin' => 'is argument',
    ),
    'options' => array(
      'dev' => 'is option',
    ),
  );

/**
  * $items Append & Overload below
  * description ONLY here
  * examples ONLY here
  * aliases isn't associative so NEVER here
  * others fleshed out for HELP command
  */
$items['vin_collect']['description'] = "Description php_coder: \r\nComposes SQL Code to apply Auto-Entry Label Titles to current titles. Useful when there is lots of data already entered before AEL implemented, or when the configuration of EAL is tweaked.";

$items['vin_collect']['arguments']['vin'] = "A valid VIN Number";

$items['vin_collect']['options']['dev'] = "Return any and all pertinent variable data";

$items['vin_collect']['examples']['drush vin_collect'] = 'Simply returns a listing of the VIN.';
$items['vin_collect']['examples']['drush vinny'] = 'Using the alias, returns a listing of the VIN';
$items['vin_collect']['examples']['drush vinc'] = 'Using the alias, returns a listing of the VIN.';


return $items;
}

/**
 * Callback for the drush-demo-command command
 */
function drush_cousin_vinny_vin_collect($vin = FALSE) {
//drush_mymodule_custom_save_node
  // Check for existence of argument
    $arguments = _vin_arguments(); //use custom function to encapsulate
    if (!$vin) {
        $vin = drush_choice($arguments, dt('Which VIN would you like to interact with using \'Cousin Vinny\'?'));
    }

  // Check for correct argument
  $correct_args = array_keys($arguments);
  if (!in_array($vin, $correct_args)) {
    if ($vin == '0') {
      drush_user_abort('Buh-Bye! VIN Collect!');
      return;
    }
    $string = _vin_arguments('string');
    return drush_set_error(dt('"@type" is not a valid example. ',
      array('@type' => $example)) . $string);
  }

  // drush_print($vin);
  // return;
  _drush_execute_vin_collect($vin);
} //END function drush_node_tablelist($vin = FALSE)

function _vin_arguments($vin = 'array'){
  $vin_arguments = array();
  $vin_arguments['kL1TD5DE2BB119431'] = "2011 Chevrolet Aveo";
  $vin_arguments['5gAEV23778J206256'] = "2008 Buick Enclave";
  $vin_arguments['1FdWE35P55HA46480'] = "EXCEPTION: 2005 Ford E-350 Super Duty Van";
  $vin_arguments['5LAxD94p70LA2372'] = "INVALID: 16 Characters";
  $vin_arguments['5IAoO94Q70qq2372'] = "INVALID: 16 Characters 6 of I-O-Q";
  $vin_arguments['5IAoO94Q70qq23:2'] = "INVALID: 16 Characters 6 of I-O-Q and colon";
  $vin_arguments['5LAXd94p70LO23721'] = "VALID: But Made Up";

  switch ($vin) {
    case 'array':
      return $vin_arguments;
      break;
    case 'string':
      $correct_args = array_keys($vin_arguments);
      $correct_args_count = count($correct_args);
      $first_args = $correct_args;
      $last_arg = '"' .  array_pop($first_args) . '"';
      $first_args_list = implode(",", $first_args);
      $first_args_list = '"' . str_replace(",", '", "', $first_args_list) . '"';
      $zero = 'Please ask for assistance, there are currently no php_coder examples in use';
      $non_zero = 'Please select';
      $grammar = $correct_args_count > 2?' among ':': ';
      $grammar = $correct_args_count == 2?' between ':$grammar;
      $list = '';
      $list = $correct_args_count == 1?$last_arg:$list;
      $list = $correct_args_count > 1?$first_args_list. ' and ' . $last_arg:$list;
      if ($correct_args_count == 0) {
        $string = $zero;
      }else{
        $string = $non_zero . $grammar . $list . '. (Or supply no example and select from prompted values.)';
      }
      return $string;
      break;

    default:
      return $vin_arguments;
      #\_ OOAAOC notwithstanding default $which, this is its raison detre
      break;
  }
  return; //OOAAOC
}

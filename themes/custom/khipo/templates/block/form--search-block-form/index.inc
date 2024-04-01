<?php 

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_alter().
 */
function khipo_form_search_block_form_alter(&$form, FormStateInterface $form_state, $form_id) {
    $form['keys']['#attributes']['placeholder'] = "Pesquisar";
    unset($form['actions']);

    if(\Drupal::request()->get('keys')) {
        $form['keys']['#default_value'] = \Drupal::request()->get('keys');
    }
}


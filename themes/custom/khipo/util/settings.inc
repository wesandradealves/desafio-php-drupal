<?php 

use Drupal\Core\Form\FormStateInterface;
function khipo_form_system_theme_settings_alter(&$form, FormStateInterface $form_state) {
    $form['head'] = array(
      '#type' => 'fieldset',
      '#title' => 'Head',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );   

    $form['head']['descricao'] = array(
        '#type' => 'textarea',
        '#title' => 'Description',
        '#default_value' => theme_get_setting('descricao')
    );    

    $form['head']['scripts'] = array(
        '#type' => 'textarea',
        '#title' => 'Scripts',
        '#default_value' => theme_get_setting('scripts')
    ); 

    $form['head']['thumbnail'] = array(
        '#type' => 'managed_file',
        '#upload_location' => 'public://',
        '#title' => 'Thumbnail',
        '#default_value' => theme_get_setting('thumbnail'),
    );   
 
    $form['#validate'][] = 'khipo_form_system_theme_settings_validate';
    $form['#submit'][] = 'khipo_form_system_theme_settings_submit';
}

function khipo_form_system_theme_settings_validate(&$form, FormStateInterface $form_state) {
    $values = $form_state->getValues();

    $thumbnail = file_save_upload('thumbnail');

    if (isset($thumbnail)) {
      if ($thumbnail) {
        $values['thumbnail_upload'] = $thumbnail;
      }
      else {
        form_set_error('thumbnail', t('The file cannot be uploaded.'));
      }
    }      
}

function khipo_form_system_theme_settings_submit(&$form, FormStateInterface $form_state) {
    $thumbnail = reset($form_state->getValue('thumbnail'));
    $thumbnail = \Drupal\file\Entity\File::load($thumbnail);    

    if($thumbnail) {
        $thumbnail->setPermanent();
        $thumbnail->status = FILE_STATUS_PERMANENT;
        $thumbnail->save();      
    }       
}
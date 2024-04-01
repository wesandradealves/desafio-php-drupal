<?php 

function khipo_preprocess_views_view__search(&$variables) {
    $variables['keys'] = \Drupal::request()->get('keys');
    $variables['total_rows'] = $variables['view']->total_rows;
}
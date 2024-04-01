<?php 

function khipo_preprocess_views_view__taxonomy_term(&$variables) {
    $tid = reset($variables['view']->args);
    $variables['term'] = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->load($tid);
}
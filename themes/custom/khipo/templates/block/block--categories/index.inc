<?php 

function khipo_preprocess_block__categories(&$variables) {
    $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadTree("category");
    $alias = \Drupal::service('path_alias.manager');
    $variables['terms'] = [];

    foreach ($terms as $key => $term) {
        $query = \Drupal::entityQuery('node')->condition("field_category", [$term->tid], 'IN')->condition('status', 1);

        $variables['terms'][] = [
            "tid" => $term->tid,
            "url" => $alias->getAliasByPath('/taxonomy/term/' . $term->tid),
            "name" => $term->name,
            "counter" => $query->count()->execute()
        ];
    }
}
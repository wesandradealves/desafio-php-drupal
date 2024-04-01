<?php 

function khipo_theme_suggestions_node_alter(
    array &$suggestions,
    array $variables, $hook
) {
    $node = \Drupal::routeMatch()->getParameter("node");
    if ($node) {
        $content_type = $node->bundle();
        $suggestions[] = $hook."__" . $content_type . "__" . $node->bundle();
    }
}

function khipo_suggestions_block_alter(array &$suggestions, array $variables, $hook) 
{
    $block = $variables['elements'];
    $blockType = $block['#configuration']['provider'];
    if ($blockType == "block_content") {
      $bundle = $block['content']['#block_content']->bundle();
      array_splice($suggestions, 2, 0, 'block__' . $bundle);
    }
}

function khipo_theme_suggestions_select_alter(
    array &$suggestions,
    array $variables,
    $hook
) {
    $element = $variables['element'];
    $suggestions[] = $hook."__".$element['#type'];
    $suggestions[] = $hook."__".$element['#name'];
    if(isset($element['#context'])) {
        $suggestions[] = $hook."__".$element['#type']."__".$element['#context']['#view_id'];
        $suggestions[] = $hook."__".$element['#type']."__".$element['#context']['#display_id'];
        $suggestions[] = $hook."__".$element['#type']."__".$element['#context']['#view_id']."__".$element['#context']['#display_id'];
        $suggestions[] = $hook."__".$element['#name']."__".$element['#type']."__".$element['#context']['#view_id']."__".$element['#context']['#display_id'];
    }
}

function khipo_theme_suggestions_page_alter(
    array &$suggestions,
    array $variables,
    $hook
) {
    $current_path = \Drupal::service('path.current')->getPath();
    $result = \Drupal::service('path_alias.manager')->getAliasByPath($current_path);
  
    $path_alias = trim($result, '/');
    $path_alias = str_replace('/', '-', $path_alias);

    $node = \Drupal::routeMatch()->getParameter("node");
    if ($node) {
        $suggestions[] = $hook."__".str_replace('-','_',$path_alias);
    }
}

function khipo_theme_suggestions_views_view_alter(
    array &$suggestions,
    array $variables, $hook
) {
    $node = \Drupal::routeMatch()->getParameter("node");
    if ($node) {
        $content_type = $node->bundle();
        $suggestions[] = $hook."__" . $content_type;
        $suggestions[] = $hook."__" . $content_type . '__' . $variables['view']->getDisplay()->display['id'];
    }
}

function khipo_theme_suggestions_views_view_unformatted_alter(
    array &$suggestions,
    array $variables, $hook
) {
    $node = \Drupal::routeMatch()->getParameter("node");
    if ($node) {
        $content_type = $node->bundle();
        $suggestions[] = $hook."__" . $content_type;
    }
}

function khipo_theme_suggestions_views_view_field_alter(
    array &$suggestions,
    array &$variables,
    $hook
) {
    if ($variables["view"]->id() && $variables["view"]->current_display) {
        $suggestions[] =
            $hook .
            "__" .
            $variables["view"]->id() .
            "__" .
            $variables["view"]->current_display .
            "__" .
            $variables["field"]->field;
    }
}

function khipo_theme_suggestions_menu_alter(
    array &$suggestions,
    array $variables, $hook
) {
    if (isset($variables["attributes"]["block"])) {
        $hook = str_replace(
            ["block-", "-"],
            ["", "_"],
            $variables["attributes"]["block"]
        );
        $suggestions[] = $variables["theme_hook_original"] . "__" . $hook;
    }
}

function khipo_theme_suggestions_views_exposed_form_alter(array &$suggestions, array $vars, $hook)
{
  $suggestions[] = $hook.'__' . str_replace(
    ['views-exposed-form-', '-'],
    ['', '_'],
    $vars['form']['#id']
  );
}

function khipo_theme_suggestions_container_alter(array &$suggestions, array &$variables, $hook)
{
  $element = $variables['element'];

  if (isset($element['#type']) && $element['#type'] == 'view') {
    $suggestions[] = $hook.'__' . $element['#name'];
    $suggestions[] = $hook.'__' . $element['#name'] . '__' . $element['#display_id'];
  }

  if (isset($element['#type']) && $element['#type'] == 'container' && isset($element['children']['#type'])) {
    $suggestions[] = $hook.'__' . $element['children']['#type'];
  }
}

function khipo_theme_suggestions_input_alter(&$suggestions, array $variables, $hook)
{
    $suggestions[] = $hook . '__' . str_replace('-', '_', $variables['element']['#id']);

    if(isset($variables['element']['#theme'])) {
        $suggestions[] = $hook . '__' . str_replace('-', '_', $variables['element']['#id']) . '__' . str_replace('-', '_', $variables['element']['#theme']);
    }

    if(isset($variables['element']['#context'])) {
        $suggestions[] = $hook . '__' . str_replace('-', '_', $variables['element']['#id']) . '__' . $variables['element']['#context']['#view_id'] . '__' . $variables['element']['#context']['#display_id'];
    }
}

function khipo_theme_suggestions_form_element_alter(&$suggestions, array $variables, $hook)
{
    $suggestions[] = $hook . '__' . str_replace('-', '_', $variables['element']['#id']);
    $suggestions[] = $hook . '__' . $variables['element']['#type'];
    if(isset($variables['element']['#context'])) {
        $suggestions[] = $hook . '__' . $variables['element']['#type'] . '__' . $variables['element']['#context']['#view_id'];
        $suggestions[] = $hook . '__' . $variables['element']['#type'] . '__' . $variables['element']['#context']['#view_id'] . '__' . $variables['element']['#context']['#display_id'];
        $suggestions[] = $hook . '__' . $variables['element']['#type'] . '__' . str_replace('-', '_', $variables['element']['#id']) . '__' . $variables['element']['#context']['#view_id'];
        $suggestions[] = $hook . '__' . $variables['element']['#type'] . '__' . str_replace('-', '_', $variables['element']['#id']) . '__' . $variables['element']['#context']['#view_id'] . '__' . $variables['element']['#context']['#display_id'];
    }
    $variables['id'] = $variables['element']['#id'];
}
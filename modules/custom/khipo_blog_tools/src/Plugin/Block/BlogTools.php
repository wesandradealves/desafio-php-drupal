<?php

namespace Drupal\khipo_blog_tools\Plugin\Block;

use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Block\BlockBase;
use Drupal\comment\Entity\Comment;

/**
 * Provides a 'Simple message' Block.
 *
 * @Block(
 *   id = "khipo_blog_tools_block",
 *   admin_label = @Translation("Blog Tools"),
 *   category = @Translation("Blog"),
 * )
 */
class BlogTools extends BlockBase
{

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration()
  {
    return ['label_display' => FALSE];
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $formState)
  {
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $formState)
  {

  }

  public function build()
  {
    $node = \Drupal::routeMatch()->getParameter('node');

    if ($node instanceof \Drupal\node\NodeInterface) {
      $uid = $node->getOwnerId();
      $user = \Drupal\user\Entity\User::load($uid);
      $user->user_picture_rendered = file_create_url($user->user_picture->entity->getFileUri());      
    }      

    $build = [
      '#theme' => 'khipo_blog_tools',
      '#attached' => array(
        'library' => array('khipo_blog_tools/khipo_blog_tools'),
      ),
      '#configuration' => $this->getConfiguration(),
      '#author' => $user,
      '#label_display' => $this->getConfiguration()['label_display']
    ];    

    return $build;
  }
}
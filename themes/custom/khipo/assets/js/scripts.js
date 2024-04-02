/**
 * @file
 * Global utilities.
 *
 */

;(function ($, Drupal) {
  'use strict'
  jQuery(document).ready(function () {
    $('[rel="top"]').click(function (e) {
      window.scrollTo({
        top: 0,
        behavior: 'smooth'
      })
    })
  })
})(jQuery, Drupal)

<?php

namespace Drupal\khipo_blog_tools;

use Twig\Extension\AbstractExtension;
use Twig\TwigFunction;

/**
 * Custom twig functions.
 */
class Utils extends AbstractExtension {
    public function getFunctions() {
        return [
            // new TwigFunction('translangobject', [$this, 'TransLangObject']),
            // new TwigFunction('getCountryLanguage', [$this, 'GetCountryLanguage'])
        ];
    }

    // public function GetCountryLanguage($str){
    //     $names = json_decode(file_get_contents("https://raw.githubusercontent.com/arash16/countries-languages/master/lib/countries.json"), true);
    //     if($names[strtoupper($str)]) {
    //         return array_pop($names[strtoupper($str)]["languages"]);
    //     }
    // }  

    // public function TransLangObject($arr){
    //     return array_map(function ($item) {
    //         return array(
    //             "id" => $item->getId(),
    //             "name" => $item->getName()
    //         );
    //     }, $arr);
    // }  
}
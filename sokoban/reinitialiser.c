#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <unistd.h>
/**
* @fn char** reinitialiser_niveau(char** map, int nblignes, int nbcolonnes, int* posx, int* posy, int* nb_deplacements, int* nb_poussees, Liste **liste, Mouvement* element)
* @brief  Réinitialise le niveau dans lequel on est en le rechargeant
* @param  map tableau en 2 dimensions représentant le niveau
* @param  nbLignes nombre de lignes dans le tableau
* @param  nbcolonnes nombre de colonnes dans le tableau
* @param  *posx passage de la position en abscisse du joueur par adresse
* @param  *posy passage de la position en ordonée du joueur par adresse
* @param  *nb_deplacements passage du nombre de déplacements effectués par adresse
* @param  *nb_poussees passage du nombre de poussées effectuées par adresse
* @param  **liste passage de la liste chaînée enregistrant les inputs, les mouvements et les poussées du joueur par adresse
* @param  *element element de type mouvement crée dans main.c afin d'initialiser la liste
* @return tableau en 2 dimensions réinitialisé
*/


char** reinitialiser_niveau(char** map, int nblignes, int nbcolonnes, int* posx, int* posy, int* nb_deplacements, int* nb_poussees, Liste **liste, Mouvement* element)
{
  (*nb_deplacements) = 0;                                   //Réinitilise le nombre de déplacements en le passant à 0
  (*nb_poussees) = 0;                                       //Réinitilise le nombre de poussées en le passant à 0
  map = creation_map(nblignes, nbcolonnes + 1);             //Recharge le niveau en recréant la map
  detection_joueur(map, nblignes, nbcolonnes, posx, posy);  //Obtient les coordonnées du joueur en détectant sa position dans la map
  if (element !=NULL){
    free(element);
  }
  *liste = initialisation(element);                         //Réinitilise la liste chaînée
  return map;
}

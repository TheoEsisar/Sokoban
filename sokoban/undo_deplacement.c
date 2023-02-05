#include <stdio.h>
#include <stdlib.h>
#include "header.h"









/**
* @fn void undo_deplacement(char **map, char** map_copie, int* posx, int* posy, Liste *liste, int * nb_deplacements, int* nb_poussees)
* @brief  Effectue le déplacement inverse au dernier déplacement effectué en prenant en compte si la caisse à été déplacé ou non
* @param  map tableau en 2 dimensions représentant le niveau
* @param  map_copie copie du tableau en 2 dimensions
* @param  *posx passage de la position en abscisse du joueur par adresse
* @param  *posy passage de la position en ordonée du joueur par adresse
* @param  *liste liste chaînée enregistrant tout les inputs, mouvements et poussées du joueur éffectués pour résoudre le niveau
* @param  *nb_deplacements passage du nombre de déplacements effectués par adresse
* @param  *nb_poussees passage du nombre de poussées effectuées par adresse
* @return void
*/

void undo_deplacement(char **map, char** map_copie, int* posx, int* posy, Liste *liste, int * nb_deplacements, int* nb_poussees)
{
  if (liste->premier == NULL)
  {
    printf("Plus aucun déplacement à annuler.\n");
  }
  else {
    Mouvement *deplacement_a_effectuer = suppression(liste);    //Récupération du dernier mouvement effectué tout en le supprimant de la liste
    int dernier_mouvement = deplacement_a_effectuer->mv;        //Enregistrement du mouvement dans une variable
    int caisse_poussee = deplacement_a_effectuer->hasPushed;    //Enregistrement de la donnée hasPushed dans une variable
    int a_bouge = deplacement_a_effectuer->hasMoved;            //Enregistrement de la donnée hasMoved dans uen variable
    free(deplacement_a_effectuer);                              //ONOUBLIEPASDEFREEBATAR
    if (a_bouge == 1) {                                         //Cas si le joueur a bougé lors du dernier déplacement
      (*nb_deplacements)--;                                     //Décrémentation du nombre de déplacements
      if (caisse_poussee == 1)  {                               //Cas si le joueur a poussé une caisse lors du dernier déplacement
        (*nb_poussees)--;                                       //Décrémentation du nombre de poussées
        if (dernier_mouvement == 1) {                           //Cas si lors du dernier déplacement le joueur est allé en haut
          aller_bas(map, map_copie,  posx, posy);               //Déplacement du joueur en bas
          if (map_copie[*posy-1][*posx] == '.') {
            map[*posy-1][*posx]= '*';                           //La caisse devient une étoile si elle se déplace sur une cible
          }
          else {
            map[*posy-1][*posx]= '$';                           //La caisse devient un dollar si elle ne se déplace pas sur une cible
          }
          map[*posy-2][*posx]= map_copie[*posy-2][*posx];       //Remplacement de l'endroit où était présente la caisse par ce qui est présent dans map_copie aux mêmes coordonnées
        }
        if (dernier_mouvement == 2) {                           //Cas si lors du dernier déplacement le joueur est allé en bas
          aller_haut(map, map_copie, posx, posy);               //Déplacement du joueur en haut
          if (map_copie[*posy+1][*posx] == '.') {
            map[*posy+1][*posx]= '*';                           //La caisse devient une étoile si elle se déplace sur une cible
          }
          else {
            map[*posy+1][*posx]= '$';                           //La caisse devient un dollar si elle ne se déplace pas sur une cible
          }
          map[*posy+2][*posx]= map_copie[*posy+2][*posx];       //Remplacement de l'endroit où était présente la caisse par ce qui est présent dans map_copie aux mêmes coordonnées
        }
        if (dernier_mouvement == 3) {                           //Cas si lors du dernier déplacement le joueur est allé à droite
          aller_gauche(map, map_copie, posx, posy);             //Déplacement du joueur à gauche
          if (map_copie[*posy][*posx+1] == '.') {
            map[*posy][*posx+1]= '*';                           //La caisse devient une étoile si elle se déplace sur une cible
          }
          else {
            map[*posy][*posx+1]= '$';                           //La caisse devient un dollar si elle ne se déplace pas sur une cible
          }
          map[*posy][*posx+2]= map_copie[*posy][*posx+2];       //Remplacement de l'endroit où était présente la caisse par ce qui est présent dans map_copie aux mêmes coordonnées
        }
        if (dernier_mouvement == 4) {                           //Cas si lors du dernier déplacement le joueur est allé à gauche
          aller_droite(map, map_copie, posx, posy);             //Déplacement du joueur à droite
          if (map_copie[*posy][*posx-1] == '.') {
            map[*posy][*posx-1]= '*';                           //La caisse devient une étoile si elle se déplace sur une cible
          }
          else {
            map[*posy][*posx-1]= '$';                           //La caisse devient un dollar si elle ne se déplace pas sur une cible
          }
          map[*posy][*posx-2]= map_copie[*posy][*posx-2];       //Remplacement de l'endroit où était présente la caisse par ce qui est présent dans map_copie aux mêmes coordonnées
        }
      }
      else if (caisse_poussee == 0)                             //Cas si le joueur n'a pas poussé une caisse lors du dernier déplacement
      {
        if (dernier_mouvement == 1) {                           //Cas si lors du dernier déplacement le joueur est allé en haut
          aller_bas(map, map_copie,  posx, posy);               //Déplacement du joueur en bas
        }
        if (dernier_mouvement == 2) {                           //Cas si lors du dernier déplacement le joueur est allé en bas
          aller_haut(map, map_copie, posx, posy);               //Déplacement du joueur en haut
        }
        if (dernier_mouvement == 3) {                           //Cas si lors du dernier déplacement le joueur est allé à droite
          aller_gauche(map, map_copie, posx, posy);             //Déplacement du joueur à gauche
        }
        if (dernier_mouvement == 4) {                           //Cas si lors du dernier déplacement le joueur est allé à gauche
          aller_droite(map, map_copie, posx, posy);             //Déplacement du joueur à droite
        }
      }
      else                                                      //Cas si le joueur n'a pas bougé lors du dernier déplacement
      {
        exit(EXIT_FAILURE);
      }
    }
  }



}

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
* @fn void detection_joueur(char** map, int nblignes, int nbcolonnes, int* posx, int* posy)
* @brief Détermine les coordonées du joueur
* @param map Matrice du niveau
* @param nblignes Nombre de lignes du niveau
* @param nbcolonnes Nombre de colonnes du niveau
* @param posx Position du manutentionnaire sur les colonnes
* @param posy Position du manutentionnaire sur les lignes
* @return void
* @details Parcours le niveau caractère par caractère et modifie posx et posy dès qu'on trouve le '@'
*/

void detection_joueur(char** map, int nblignes, int nbcolonnes, int* posx, int* posy)
{
  int i, j;
	for (i = 0; i < nblignes; i++) {
		for(j = 0; (j < nbcolonnes) && (map[i][j] != '\n'); j++){
      if(map[i][j] == '@') {
        *posx = j;
        *posy = i;
        break;
      }
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
* @fn int test_victoire(char** map, int nblignes, int nbcolonnes)
* @brief Vérifie si le joueur a réussi le niveau
* @param map Matrice du niveau
* @param nb_lignes Nombre de lignes du niveau
* @param nbcol Nombre de lignes du niveau
* @return La valeur de victoire : 1 si le joueur a gagné, 0 sinon
* @details Parcours tous les caractères du niveau et met victoire à 0 si il reste des '$' dans le niveau
*/

int test_victoire(char** map, int nblignes, int nbcolonnes)
{
  int victoire = 1; //On met victoire à 1 par défaut
  int i, j;
  //On parcours le niveau
	for (i = 0; i < nblignes; i++) {
		for(j = 0; (j < nbcolonnes) && (map[i][j] != '\n'); j++){
      if(map[i][j] == '$') {
        victoire = 0; //Si on trouve un '$', on met victoire à 0
        break;
      }
		}
	}
  return victoire;
}

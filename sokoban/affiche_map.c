#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
* @fn void affiche_map(int, int, char**)
* @brief Affiche le niveau
* @param nblignes Nombre de lignes du niveau
* @param nbcolonnes Nombre de colonnes du niveau
* @param map La matrice représenatant le niveau
* @return void
* @details Affiche le niveau caractère par caractère
*/
void affiche_map(int nblignes, int nbcolonnes, char** map)
{
	int i, j;
	for (i = 0; i < nblignes; i++) {
		for(j = 0; (j < nbcolonnes) && (map[i][j] != '\n'); j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

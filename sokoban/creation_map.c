#include <stdio.h>
#include <stdlib.h>
#include "header.h"


/**
* @fn char** creation_map(int nblignes,int nbcolonnes)
* @brief Définit une matrice avec tous les caractères du niveau
* @param nblignes Nombre de lignes du niveau
* @param nbcolonnes Nombre de colonnes du niveau
* @return La matrice avec tous les caractères du niveau
* @details Alloue dynamiquement en mémoire une matrice de la taille du niveau, puis la remplie avec tous les caractères du niveau.
*/

char** creation_map(int nblignes,int nbcolonnes) //comme les niveaux sont de tailles différentes, nous devons créer un tableau dynamique.
{
	FILE * fdin;
	const char* fichierIn = "level_charge.lvl";
	int i;
	char** map;
	char c;
	int k = 0, col = 0;


	//On alloue la mémoire pour une matrice de taille nblignes*nbcolonnes
	if ((map = malloc(sizeof(char*) * nblignes)) == NULL){
  	/* erreur */
		perror("allocation impossible");
		exit(1);
	}
	for (i = 0; i < nblignes; i++) {
  	if ((map[i] = malloc(sizeof(char) * nbcolonnes)) == NULL){
    /* erreur */
			perror("allocation impossible");
			exit(1);
		}
	}



	//Ouverture du fichier à lire
	fdin = fopen(fichierIn,"r");
	if ( NULL == fdin ){
		fprintf(stderr,"erreur ouverture %s\n",fichierIn);
		perror("");
		exit(1);
	}


	//On remplit la matrice avec les caractères du niveau
	while(((c = fgetc(fdin)) != EOF) && (k < nblignes)){
		map[k][col] = c;
		col++;
		if(c == '\n'){
			k++;
			col = 0;
		}
	}

	//Fermeture du fichier 
	if (EOF == fclose(fdin)){
			fprintf(stderr,"erreur fermeture %s\n", fichierIn);
			exit(1);
	}
	return map;
}

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

/**
* @fn void charge_niveau(int, int*, int*);
* @brief Charge le niveau passé en paramètre dans un fichier et calcule sa taille
* @param nb_niveau Le numéro du niveau choisi
* @param nb_lignes Nombre de lignes du niveau
* @param nb_colonnes_max Nombre de colonnes du niveau
* @return void
* @details Parcours l'entête du fichier et tous les niveaux sans les écrire, jusqu'au niveau choisi, qui va être écrit dans un fichier
*/

void charge_niveau(int nb_niveau, int *nb_lignes, int *nb_colonnes_max) {
  //On vérifie que le niveau entré est inférieur à 88
  if (nb_niveau > NIVEAU_MAX || nb_niveau < 1) {
    printf("Entrer un niveau entre 1 et %d\n", NIVEAU_MAX);
    exit(0);
  }

  //Ouverture du fichier
  FILE* levels = NULL;
  levels = fopen("levels.lvl", "r");

  //On ouvre un fichier dans lequel on va écrire le niveau choisi
  FILE* level_charge = NULL;
  level_charge = fopen("level_charge.lvl", "w+");

  if (levels == NULL || level_charge == NULL) {
    printf("impossible d'ouvir le fichier\n");
    exit(0);
  }


  char currentChar;
  *nb_lignes = 0;
  int nb_colonnes = 0;
  *nb_colonnes_max = 0;
  int derniers_niveaux;


  switch (nb_niveau) { //On doit parcourir plus de lignes pour les trois derniers niveaux
	case 86: derniers_niveaux = 2; break;
	case 87: derniers_niveaux = 4; break;
	case 88: derniers_niveaux = 6; break;
	default: derniers_niveaux = 0;
  }


  //On parcours l'entete et les niveaux sans les afficher jusqu'au niveau choisi
  for (int i=1; i<=(nb_niveau+NB_ENTETE+derniers_niveaux); i++) {
    while (currentChar != ';' && currentChar != EOF) {
      currentChar = fgetc(levels);
    }
    currentChar = fgetc(levels); //Sert à "enlever" le ; de currentChar pour retourner dans la boucle while
  }


  //On calcule la taille du niveau choisi et on l'ecrit dans un fichier
  while (currentChar != ';' && currentChar != EOF) {
    fputc(currentChar, level_charge);
    currentChar = fgetc(levels);


    if (currentChar == '\n') {
      (*nb_lignes)++; //On incrémente le nombre de lignes à chaque retour à la ligne

      if (nb_colonnes > *nb_colonnes_max) { //On compare le nombre de colonnes au nombre de colonnes max du niveau
        *nb_colonnes_max = nb_colonnes;
      }
      nb_colonnes = 0; //On réinitialise à 0 pour compter le nombre de colonnes sur la ligne suivante
    } else {
      nb_colonnes++; //On incrémente le nombre de colonnes à chaque caractère sauf le retour à la ligne
    }
  }

  fclose(levels);
  fclose(level_charge);

}

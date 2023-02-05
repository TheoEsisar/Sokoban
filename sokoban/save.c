#include <stdio.h>
#include <stdlib.h>
#include "header.h"


/**
* @fn void save(int nb_deplacements, Liste *liste)
* @brief  Enregistre le numéro du niveau et les déplacements effectués dans un fichier save.txt
* @param  nb_deplacements Entier correspondant au nombre de déplacements effectués jusqu'à présent dans le niveau
* @param  *liste  Liste chaînée correspondant à tous les mouvements réalisés
* @return void
*/

void save(int nb_deplacements, Liste *liste)
{
  FILE* levels = fopen("level_charge.lvl","r");
  int c, nb_niveau;
  int i = 0;
  fseek(levels,6,SEEK_SET);                                            //On se positionne juste avant le numéro du niveau
  while ((c = fgetc(levels)) != 35) {                                  //On incrémente i jusqu'à obtenir un '#'
    i++;
  }
  char* tab_niveau = malloc((i+1)*sizeof(int));
  fseek(levels, -(i+1), SEEK_CUR);                                     //On se positionne juste avant le numéro du niveau
  for (int j = 0; j < i; j++) {
    tab_niveau[j] = fgetc(levels);                                     //Insertion des chiffres dans le tableau
  }
  nb_niveau = atoi(tab_niveau);                                        //Utilisation de la fonction atoi pour récupérer le nombre d'après le tableau
  fclose(levels);
  free(tab_niveau);

  FILE* sauvegarde = NULL;
  sauvegarde = fopen("save.txt", "w+");                                 //Ouvre le fichier "save.txt" en mode w+
  int *tableau_mouvement = calloc(nb_deplacements, sizeof(int));        //Crée une liste d'entier de la taille du nombre de déplacements
  fprintf(sauvegarde, "[%d] : ", nb_niveau);                            //Ecrit le numéro du niveau effectué dans le fichier
  Mouvement *mouvement_parcouru = liste->premier;                       //Récupération du dernier mouvement effectué tout en le supprimant de la liste
  for (int i = 0; i < nb_deplacements; i++) {                           //Boucle for allant de 0 à nb_mouvements
    while (mouvement_parcouru->hasMoved != 1) {
      mouvement_parcouru = mouvement_parcouru->suivant;                 //On passe au mouvement suivant jusqu'à obtenir un mouvement ayant hasMoved égale à 1
    }
    if (mouvement_parcouru->hasMoved == 1) {
      tableau_mouvement[nb_deplacements-1-i] = mouvement_parcouru->mv;  //Remplissage du tableau en partant de la fin avec l'input réalisé pour effectuer le mouvement
    }
    mouvement_parcouru = mouvement_parcouru->suivant;                   //Récupération du dernier mouvement effectué
  }
  for (int j = 0; j < nb_deplacements; j++) {
    fprintf(sauvegarde, "%d", tableau_mouvement[j]);                    //Ecrit 1 par 1 tous les entiers présents dans le tableau dans le fichier "solution.txt"
  }
  fclose(sauvegarde);                                                   //Ferme le fichier
  free(tableau_mouvement);                                              //Free la mémoire alloué au tableau
}


/**
* @fn int recuperation_niveau()
* @brief  Récupère le numéro du niveau sauvegardé dans le fichier save.txt
* @return Un entier correspondant au numéro du niveau qui est sauvegardé dans le fichier, -1 s'il y a une erreur
*/

int recuperation_niveau() {
  FILE* sauvegarde = fopen("save.txt","r");
    int nb_niveau, c;
    int i = 0;
    fseek(sauvegarde,1,SEEK_SET);
    while ((c = fgetc(sauvegarde)) != 93) {                      //Boucle permettant de savoir sur combien de chiffres s'écrit le numéro du niveau en parcourant le fichier jusqu'à obtenir ']'
      i++;
    }
    char* tab_niveau = malloc((i+1)*sizeof(int));
    fseek(sauvegarde, -(i+1), SEEK_CUR);
    for (int j = 0; j < i; j++) {
      tab_niveau[j] = fgetc(sauvegarde);                        //Insertion des chiffres correspondant au numéro du niveau dans un tableau
    }
    nb_niveau = atoi(tab_niveau);                               //La fonction atoi nous permet d'obtenir le numéro du niveau
    fclose(sauvegarde);
    free(tab_niveau);
    if (nb_niveau < 1 || nb_niveau > NIVEAU_MAX) {              //Vérification que le niveau puisse exister
      exit(0);
    }
    else {
      return nb_niveau;
    }
  fclose(sauvegarde);
  return -1;
}


/**
* @fn int recuperation_nbdeplacements()
* @brief  Récupère le nombre de déplacements effectués qui sont sauvegardé dans le fichier save.txt
* @return Un entier correspondant au nombre de déplacements sauvegardés dans le fichier, -1 s'il y a une erreur
*/

int recuperation_nbdeplacements(){
  FILE* sauvegarde = fopen("save.txt","r");
  int compteur_deplacements = 0;
    char c = fgetc(sauvegarde);
    while (c != ':') {
      c = fgetc(sauvegarde);
    }
    fseek(sauvegarde,1, SEEK_CUR);                      //On se positionne juste avant le premier déplacement
    while (c != EOF) {                                  //On parcourt le fichier jusqu'à la fin
      c = fgetc(sauvegarde);
      compteur_deplacements++;
    }
    fclose(sauvegarde);
    return (compteur_deplacements-2);
}


/**
* @fn int* save_liste_deplacements(int nb_deplacements, int** liste_deplacements)
* @brief  Enregistre tous les déplacements sauvegardés dans le fichier save.txt dans un tableau d'entier
* @param  nb_deplacements Entier correspondant aux nombre de déplacements sauvegardés dans save.txt
* @param  **liste_deplacements  Passage par adresse du tableau d'entiers qui contiendra tous les déplacements effectués
* @return Tableau d'entiers rempli avec tous les déplacements éffectués dans la sauvegarde
*/

int* save_liste_deplacements(int nb_deplacements, int** liste_deplacements){
  FILE* sauvegarde = fopen("save.txt","r");
  int c;
    c = fgetc(sauvegarde);
    while (c != 58) {
      c = fgetc(sauvegarde);
    }
    fseek(sauvegarde,1, SEEK_CUR);                      //On se positionne juste avant le premier déplacement
    for (int i = 0; i < nb_deplacements; i++) {
      c = fgetc(sauvegarde);
      (*liste_deplacements)[i] = c-48;                  //Insertion de la valeur de l'input du déplacement dans le tableau passé en paramètre
    }
    return *liste_deplacements;
}

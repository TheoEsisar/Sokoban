#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
* @fn void enregistrement_solution(int nb_niveau, int nb_deplacements, Liste *liste)
* @brief  enregistre tous les inputs effectués dans un fichier après la résolution du niveau
* @param  nb_niveau  entier correspondant au niveau résolu
* @param  nb_deplacements entier correspondant au nombre de déplacements éffectués pour résoudre le niveau
* @param  *liste liste chaînée enregistrant tout les inputs, mouvements et poussées du joueur éffectués pour résoudre le niveau
* @return void
*/


void enregistrement_solution(int nb_niveau, int nb_deplacements, Liste *liste)
{
  FILE* solution = NULL;
  solution = fopen("solution.txt", "a");                                //Ouvre le fichier "solution.txt" en mode append
  int *tableau_mouvement = calloc(nb_deplacements, sizeof(int));        //Crée une liste d'entier de la taille du nombre de déplacements
  fprintf(solution, "[%d] : ", nb_niveau);                              //Ecrit le numéro du niveau effectué dans le fichier
  Mouvement *mouvement_parcouru = suppression(liste);                   //Récupération du dernier mouvement effectué tout en le supprimant de la liste
  for (int i = 0; i < nb_deplacements; i++) {                           //Boucle for allant de 0 à nb_mouvements
    while (mouvement_parcouru->hasMoved != 1) {
      free(mouvement_parcouru);
      mouvement_parcouru = suppression(liste);                          //On supprime les derniers mouvements effectués de la liste jusqu'à obtenir un mouvement ayant hasMoved égale à 1
    }
    if (mouvement_parcouru->hasMoved == 1) {
      tableau_mouvement[nb_deplacements-1-i] = mouvement_parcouru->mv;  //Remplissage du tableau en partant de la fin avec l'input réalisé pour effectuer le mouvement
    }
    free(mouvement_parcouru);
    mouvement_parcouru = suppression(liste);                            //Récupération du dernier mouvement effectué tout en le supprimant de la liste
  }
  for (int j = 0; j < nb_deplacements; j++) {
    fprintf(solution, "%d", tableau_mouvement[j]);                      //Ecrit 1 par 1 tous les entiers présents dans le tableau dans le fichier "solution.txt"
  }

  if (mouvement_parcouru!=NULL){
    free(mouvement_parcouru);
  }


  fprintf(solution, "\n");                                              //Réalise un saut à la ligne dans le fichier
  fclose(solution);                                                     //Ferme le fichier
  free(tableau_mouvement);                                              //Free la mémoire alloué au tableau
}

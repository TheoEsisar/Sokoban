/**
* @file main.c
* @author Robin Lafage, Rémy Pourtier, Baptiste Rosselet
* @date 10 Jun 2022
* @copyright 2022
* @brief Programme permettant de jouer au Sokoban
*/


#include <stdio.h>
#include <stdlib.h>
#include "header.h"


/**
* @fn	void jouer_sokoban()
* @brief Lance le jeu sokoban
* @return void
*/


void jouer_sokoban(){
	int nblignes, nbcolmax, posx, posy, niveau;
	int nb_deplacements = 0;
	int nb_poussees = 0;
	int will_push, will_move;
	char** map;
	char** map_copie;

	Mouvement *element;
	element = NULL;
	Mouvement *nouveau = NULL;

	Liste *maListe;
	FILE* solution = NULL;
  solution = fopen("solution.txt", "w+");
	fclose(solution);
	printf("--- Comment Jouer ? ---\n");
	printf("- U pour annuler un déplacement\n");
	printf("- R pour réinitialiser le niveau\n");
	printf("- S pour sauvegarder l'état dans lequel on se trouve\n");
	printf("- X pour charger la sauvegarde\n");
	printf("- Q pour quitter le jeu\n\n");
	printf("Choisis ton niveau:\n");
	scanf("%d", &niveau);


	if (niveau >= 1 && niveau <= NIVEAU_MAX) {														//On vérifie si le numéro du niveau entré par l'utilisateur est cohérent
		for (int i=niveau; i<=NIVEAU_MAX; i++){															//Boucle permettant d'incrémenter les niveaux 1 à 1
			configureTerminal(0);
			charge_niveau(i, &nblignes, &nbcolmax);
			map = creation_map(nblignes, nbcolmax + 1);												//Chargement du niveau dans un tableau de char de 2 dimensions
			map_copie = copie_map(nblignes, nbcolmax);

			nb_deplacements = 0;
			nb_poussees = 0;

		  detection_joueur(map, nblignes, nbcolmax, &posx, &posy);
			maListe = initialisation(element);


		  while(!test_victoire(map, nblignes, nbcolmax)) {
				printf("\e[1;1H\e[2J");																					//Permet un affichage plus lisible dans la console
		    affiche_map(nblignes, nbcolmax, map);
		    int c = litClavier();
				if (c == 1 || c == 2 || c == 3 || c ==4)												//Si l'input correspond à une des flèches
		    {
		      will_push = will_pushed(map, map_copie, &posx, &posy, c, &nb_poussees);
		      will_move = will_moved(map, map_copie, &posx, &posy, c);
		      deplacement(map, map_copie, &posx, &posy, c, &nb_deplacements, nblignes, nbcolmax);
		      insertion(maListe, c, will_push, will_move, nouveau);
		    }
		    if (c == 117) {  																								 //'u' annule le dernier déplacement réalisé
		      undo_deplacement(map, map_copie, &posx, &posy, maListe, &nb_deplacements, &nb_poussees);
		    }
		    if (c == 114) {   																							//'r' réinitialise le niveau que l'on est en train de résoudre
				for (int j=0; j<nblignes; j++) {
					free(map[j]);
				}
				free(map);
				if (element != NULL){
					free(element);

				}

				Mouvement* abc = suppression(maListe);
				while (abc != NULL){
					free(abc);
					abc = suppression(maListe);
				}
				if(maListe!=NULL){
				free(maListe);
				}


	        map = reinitialiser_niveau(map, nblignes, nbcolmax, &posx, &posy, &nb_deplacements, &nb_poussees, &maListe, element);
		   }
			 if (c == 115) {																										//'s' sauvegarde la partie
				 save(nb_deplacements, maListe);
			 }
			 if (c == 120) {																										//'x' charger la sauvegarde
				 FILE* sauvegarde_file = fopen("save.txt","r");
				 fseek(sauvegarde_file, 0, SEEK_END);
				 int taille_fichier = ftell(sauvegarde_file);
				 int condition = ((taille_fichier-1) != 0);
				 fclose(sauvegarde_file);
				 if (condition) {																									//On vérifie si le fichier de sauvegarde est vide ou non
					 int save_nb_niveau = recuperation_niveau();
					 i = save_nb_niveau;																						//Permet de passer au niveau suivant une fois le niveau résolu
					 int save_nb_deplacements = recuperation_nbdeplacements();
					 int* liste_deplacements = calloc(save_nb_deplacements, sizeof(int));			//Alloation mémoire pour le tableau qui va contenir tous les inputs
					 liste_deplacements = save_liste_deplacements(save_nb_deplacements, &liste_deplacements);

					 charge_niveau(save_nb_niveau, &nblignes, &nbcolmax);

					 for (int m=0; m<nblignes; m++) {
		 				free(map[m]);
						free(map_copie[m]);
		 				}
		 			 free(map);
					 free(map_copie);
		 			 if (element != NULL){
		 			 	free(element);
		 			}

					 Mouvement* supprime = suppression(maListe);
					 while (supprime != NULL){
						 free(supprime);
						 supprime = suppression(maListe);
					 }
					 if(maListe!=NULL){
						 if (maListe->premier != NULL){
							 free(maListe->premier);
						 }

					 free(maListe);
				 	 }

					 map = creation_map(nblignes, nbcolmax + 1);
					 map_copie = copie_map(nblignes, nbcolmax);

					 nb_deplacements = 0;
					 nb_poussees = 0;

					 detection_joueur(map, nblignes, nbcolmax, &posx, &posy);
					 maListe = initialisation(element);

					 for (int k = 0; k < save_nb_deplacements; k++) {									//Boucle permettant de réaliser tous les déplacements nécessaires d'après les inputs présents dans le tableau liste_deplacements
						 will_pushed(map, map_copie, &posx, &posy, liste_deplacements[k], &nb_poussees);
						 deplacement(map, map_copie, &posx, &posy, liste_deplacements[k], &nb_deplacements, nblignes, nbcolmax);
						 insertion(maListe, liste_deplacements[k], will_push, 1, nouveau);
					 }
					 free(liste_deplacements);
				 }
				 else {
					 printf("Aucune sauvegarde n'est disponible\n");
				 }


			 }
			 if (c == 113) { 																										//'q' Quit
				 for (int j=0; j<nblignes; j++) {
					 free(map[j]);
					 free(map_copie[j]);
				 }
				 free(map);
				 free(map_copie);
				 if (element != NULL){
	 				free(element);
	 				}
				 Mouvement* abc = suppression(maListe);
				 while (abc != NULL){
					 free(abc);
					 abc = suppression(maListe);
				 }
				 if(maListe!=NULL){
					 if (maListe->premier != NULL){
						 free(maListe->premier);
					 }

				 free(maListe);
			 	 }
				 configureTerminal(1);
				 exit(0);
			 }
		  }

			enregistrement_solution(i, nb_deplacements, maListe);									//Permet d'enregistrer les inputs effectués pour faire ce niveau lorsque celui-ci est résolu


			do {
				printf("\e[1;1H\e[2J");
				affiche_map(nblignes, nbcolmax, map);
				printf("Press n to continue\nDeplacements : %d\n", nb_deplacements);
				printf("Poussees : %d\n", nb_poussees);
			} while (litClavier() != 'n');																				//On attend que l'utilisateur appuie sur 'n' pour passer au niveau suivant


			for (int j=0; j<nblignes; j++) {
				free(map[j]);
				free(map_copie[j]);
			}
			free(map);
			free(map_copie);
			if (element != NULL){
			 free(element);
			 }

			Mouvement* abc = suppression(maListe);
			while (abc != NULL){
				free(abc);
				abc = suppression(maListe);
			}
			afficherListe(maListe);
			if (maListe->premier != NULL){
				free(maListe->premier);
			}
			if(maListe!=NULL){

			free(maListe);
			}

		}
	}

	else {																																		//Si le numéro du niveau rentré n'est pas bon
		printf("Entrer un niveau entre 1 et %d\n", NIVEAU_MAX);
    exit(0);
	}



	for (int j=0; j<nblignes; j++) {
		free(map[j]);
		free(map_copie[j]);
	}
	free(map);
	free(map_copie);
	if (element != NULL){
		free(element);
	}
	if(maListe!=NULL){
	free(maListe);
	}
	free(nouveau);
	configureTerminal(1);																											//Permet de sortir du mode canonique
}

/**
* @fn int main(void)
* @brief Fonction s'écécutant par défaut
* @return 0
*/


int main(void)
{

	jouer_sokoban();
	return 0;

}

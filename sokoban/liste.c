#include <stdio.h>
#include <stdlib.h>
#include "header.h"


/**
* @fn Liste *initialisation(Mouvement *element)
* @brief  Initialise la liste chaînée
* @param *element Element de type Mouvement utilise comme le premier objet de la liste
* @return Renvoie une liste initialisée
*/

Liste *initialisation(Mouvement *element)
{
    Liste *liste = malloc(sizeof(Liste));
    element = malloc(sizeof(Mouvement));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->mv = 0;
    element->hasPushed = 0;
    element->hasMoved =0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

/**
* @fn void insertion(Liste *liste, int nvMouvement, int nvPush, int nvMoved, Mouvement *nouveau)
* @brief  Insert 3 éléments dans la liste
* @param *liste Liste chaînée dans laquelle on va insérer les éléments
* @param nvMouvement Entier correspondant à l'input effectué avec les flèches
* @param nvPush Entier indiquant si une caisse à été poussée
* @param nvMoved Entier indiquant si le joueur s'est déplacé
* @param nouveau Element de type Mouvement devenant le premier entier de la liste
* @return void
*/

void insertion(Liste *liste, int nvMouvement, int nvPush, int nvMoved, Mouvement *nouveau)
{
    /* Création du nouvel élément */
    nouveau = malloc(sizeof(Mouvement));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->mv = nvMouvement;
    nouveau->hasPushed = nvPush;
    nouveau->hasMoved = nvMoved;
    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

/**
* @fn Mouvement *suppression(Liste *liste)
* @brief  Permet d'effectuer une suppression en tête sur la liste
* @param  *liste Liste chaînée dont l'élément en tête va être supprimer
* @return Renvoie l'élément supprimé en tête qui est de type Mouvement
*/

Mouvement *suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Mouvement *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;

        return aSupprimer;
    }
    return NULL;
}

/**
* @fn void afficherListe(Liste *liste)
* @brief  Permet d'afficher tous éléments de la liste
* @param *liste Liste chaînée
* @return void
*/

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        printf("***La liste est NULLE ***\n \n");
        exit(EXIT_FAILURE);
    }

    Mouvement *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("Mouvement : %d et hasPushed : %d et hasMoved = %d\n", actuel->mv, actuel->hasPushed, actuel->hasMoved);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

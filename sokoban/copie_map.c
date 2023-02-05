#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
* @fn char** copie_map(int nblignes, int nbcolmax)
* @brief Copie le niveau sans le joueur ni les caisses
* @param nblignes Nombre de lignes du niveau
* @param nbcolmax Nombre de colonnes du niveau
* @return La matrice représenatant la copie de la map
* @details Crée un niveau similaire au niveau actuel, en supprimant le joueur, les caisses, et en remplaçant les caisses sur des cibles par des cibles. Permet de conserver la postion des cibles dans le niveau et ainsi les réafficher si le joueur ou une caisse quitte la cible
*/

char** copie_map(int nblignes, int nbcolmax) {
    char** map_copie = creation_map(nblignes, nbcolmax+1);                      //Crée une nouvelle map
    int i,j;
    for(i = 0; i < nblignes; i++) {
      for(j = 0; (j < nbcolmax) && (map_copie[i][j] != '\n'); j++){             //Parcours la map
        if(map_copie[i][j] == '@' || map_copie[i][j] == '$')                    //Remplace le manutentionnaire et les caisses par un espace
          map_copie[i][j] = ' ';
        if (map_copie[i][j] == '*')
          map_copie[i][j] = '.';
      }
    }
    return map_copie;                                                           //Renvoie la map
}

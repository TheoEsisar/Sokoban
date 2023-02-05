#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
* @fn int will_moved(char **map, char** map_copie, int* posx, int* posy, int deplacement)
* @brief  Regarde si le joueur va se déplacer en fonction de l'input reçu
* @param  map tableau en 2 dimensions représentant le niveau
* @param  map_copie copie du tableau en 2 dimensions
* @param  *posx passage de la position en abscisse du joueur par adresse
* @param  *posy passage de la position en ordonée du joueur par adresse
* @param  entier déplacement (1, 2, 3 ou 4) correspondant à l'input effectué sur le clavier avec les flèches
* @return renvoie 1 si le joueur va se déplacer, -1 s'il y a une erreur, 0 sinon
*/

int will_moved(char **map, char** map_copie, int* posx, int* posy, int deplacement)
{
  if (deplacement == 1) {                                                       //Cas si le joueur veut se déplacer vers le haut
    if ((map[*posy-1][*posx]==' ') || (map[*posy-1][*posx] == '.'))             //Cas si la case de destination est du sol ou une cible
    {
      return 1;
    }
    else if (map[*posy-1][*posx]=='#')                                          //Cas si la case de destination est un mur
    {
      return 0;
    }
    else if (map[*posy-1][*posx]=='$' || map[*posy-1][*posx]=='*')              //Cas si la case de destination est une caisse ou une caisse sur une cible
    {
      if(map[*posy-2][*posx]=='#'){                                             //Cas si 2 cases plus loin il y a un mur
        return 0;
      }
      else if(map[*posy-2][*posx]=='$' || map[*posy-2][*posx]=='*'){            //Cas si 2 cases plus loin il y a une caisse ou une caisse sur une cible
        return 0;
      }
      else {                                                                    //Sinon
        return 1;
        }
    }
  }
  if (deplacement == 2) {                                                       //Cas si le joueur veut se déplacer vers le bas
    if ((map[*posy+1][*posx]==' ') || (map[*posy+1][*posx] == '.'))             //Cas si la case de destination est du sol ou une cible
    {
      return 1;
    }
    else if (map[*posy+1][*posx]=='#')                                          //Cas si la case de destination est un mur
    {
      return 0;
    }
    else if (map[*posy+1][*posx]=='$' || map[*posy+1][*posx]=='*')              //Cas si la case de destination est une caisse ou une caisse sur une cible
    {
      if(map[*posy+2][*posx]=='#'){                                             //Cas si 2 cases plus loin il y a un mur
        return 0;
      }
      else if(map[*posy+2][*posx]=='$' || map[*posy+2][*posx]=='*'){            //Cas si 2 cases plus loin il y a une caisse ou une caisse sur une cible
        return 0;
      }
      else {                                                                    //Sinon
        return 1;
        }
    }
  }
  if (deplacement == 3) {                                                       //Cas si le joueur veut se déplacer vers la droite
    if ((map[*posy][*posx+1]==' ') || (map[*posy][*posx+1] == '.'))             //Cas si la case de destination est du sol ou une cible
    {
      return 1;
    }
    else if (map[*posy][*posx+1]=='#')                                          //Cas si la case de destination est un mur
    {
      return 0;
    }
    else if (map[*posy][*posx+1]=='$' || map[*posy][*posx+1]=='*')              //Cas si la case de destination est une caisse ou une caisse sur une cible
    {
      if(map[*posy][*posx+2]=='#'){                                             //Cas si 2 cases plus loin il y a un mur
        return 0;
      }
      else if(map[*posy][*posx+2]=='$' || map[*posy][*posx+2]=='*'){            //Cas si 2 cases plus loin il y a une caisse ou une caisse sur une cible
        return 0;
      }
      else {                                                                    //Sinon
        return 1;
        }
    }
  }
  if (deplacement == 4) {                                                       //Cas si le joueur veut se déplacer vers la gauche
    if ((map[*posy][*posx-1]==' ') || (map[*posy][*posx-1] == '.'))             //Cas si la case de destination est du sol ou une cible
    {
      return 1;
    }
    else if (map[*posy][*posx-1]=='#')                                          //Cas si la case de destination est un mur
    {
      return 0;
    }
    else if (map[*posy][*posx-1]=='$' || map[*posy][*posx-1]=='*')              //Cas si la case de destination est une caisse ou une caisse sur une cible
    {
      if(map[*posy][*posx-2]=='#'){                                             //Cas si 2 cases plus loin il y a un mur
        return 0;
      }
      else if(map[*posy][*posx-2]=='$' || map[*posy][*posx-2]=='*'){            //Cas si 2 cases plus loin il y a une caisse ou une caisse sur une cible
        return 0;
      }
      else {                                                                    //Sinon
        return 1;
        }
    }
  }
  return -1;
  }


  /**
  * @fn int will_pushed(char **map, char** map_copie, int* posx, int* posy, int deplacement, int* nb_poussees)
  * @brief  Regarde si le joueur va déplacer une caisse lors de son mouvement
  * @param  map tableau en 2 dimensions représentant le niveau
  * @param  map_copie copie du tableau en 2 dimensions
  * @param  *posx passage de la position en abscisse du joueur par adresse
  * @param  *posy passage de la position en ordonée du joueur par adresse
  * @param  entier déplacement (1, 2, 3 ou 4) correspondant à l'input effectué sur le clavier avec les flèches
  * @param  *nb_poussees passage du nombre de poussées effectuées par adresse
  * @return renvoie 1 si le joueur va déplacer une caisse, -1 s'il y a une erreur, 0 sinon
  */

int will_pushed(char **map, char** map_copie, int* posx, int* posy, int deplacement, int* nb_poussees)
{
  if (deplacement == 1) {                                                       //Cas si le joueur veut se déplacer vers le haut
    if ((map[*posy-1][*posx]==' ') || (map[*posy-1][*posx] == '.'))             //Cas si la case de destination est du sol ou une cible
    {
      return 0;
    }
    else if (map[*posy-1][*posx]=='#')                                          //Cas si la case de destination est un mur
    {
      return 0;
    }
    else if (map[*posy-1][*posx]=='$' || map[*posy-1][*posx]=='*')              //Cas si la case de destination est une caisse ou une caisse sur une cible
    {
      if(map[*posy-2][*posx]=='#'){                                             //Cas si 2 cases plus loin il y a un mur
        return 0;
      }
      else if(map[*posy-2][*posx]=='$' || map[*posy-2][*posx]=='*'){            //Cas si 2 cases plus loin il y a une caisse ou une caisse sur une cible
        return 0;
      }
      else {                                                                    //Sinon
        (*nb_poussees)++;                                                       //Incrémentation du nombre de poussées
        return 1;
        }
    }
  }
  if (deplacement == 2) {                                                       //Cas si le joueur veut se déplacer vers le bas
    if ((map[*posy+1][*posx]==' ') || (map[*posy+1][*posx] == '.'))             //Cas si la case de destination est du sol ou une cible
    {
      return 0;
    }
    else if (map[*posy+1][*posx]=='#')                                          //Cas si la case de destination est un mur
    {
      return 0;
    }
    else if (map[*posy+1][*posx]=='$' || map[*posy+1][*posx]=='*')              //Cas si la case de destination est une caisse ou une caisse sur une cible
    {
      if(map[*posy+2][*posx]=='#'){                                             //Cas si 2 cases plus loin il y a un mur
        return 0;
      }
      else if(map[*posy+2][*posx]=='$' || map[*posy+2][*posx]=='*'){            //Cas si 2 cases plus loin il y a une caisse ou une caisse sur une cible
        return 0;
      }
      else {                                                                    //Sinon
        (*nb_poussees)++;                                                       //Incrémentation du nombre de poussées
        return 1;
        }
    }
  }
  if (deplacement == 3) {                                                       //Cas si le joueur veut se déplacer vers la droite
    if ((map[*posy][*posx+1]==' ') || (map[*posy][*posx+1] == '.'))             //Cas si la case de destination est du sol ou une cible
    {
      return 0;
    }
    else if (map[*posy][*posx+1]=='#')                                          //Cas si la case de destination est un mur
    {
      return 0;
    }
    else if (map[*posy][*posx+1]=='$' || map[*posy][*posx+1]=='*')              //Cas si la case de destination est une caisse ou une caisse sur une cible
    {
      if(map[*posy][*posx+2]=='#'){                                             //Cas si 2 cases plus loin il y a un mur
        return 0;
      }
      else if(map[*posy][*posx+2]=='$' || map[*posy][*posx+2]=='*'){            //Cas si 2 cases plus loin il y a une caisse ou une caisse sur une cible
        return 0;
      }
      else {                                                                    //Sinon
        (*nb_poussees)++;                                                       //Incrémentation du nombre de poussées
        return 1;
        }
    }
  }
  if (deplacement == 4) {                                                       //Cas si le joueur veut se déplacer vers la gauche
    if ((map[*posy][*posx-1]==' ') || (map[*posy][*posx-1] == '.'))             //Cas si la case de destination est du sol ou une cible
    {
      return 0;
    }
    else if (map[*posy][*posx-1]=='#')                                          //Cas si la case de destination est un mur
    {
      return 0;
    }
    else if (map[*posy][*posx-1]=='$' || map[*posy][*posx-1]=='*')              //Cas si la case de destination est une caisse ou une caisse sur une cible
    {
      if(map[*posy][*posx-2]=='#'){                                             //Cas si 2 cases plus loin il y a un mur
        return 0;
      }
      else if(map[*posy][*posx-2]=='$' || map[*posy][*posx-2]=='*'){            //Cas si 2 cases plus loin il y a une caisse ou une caisse sur une cible
        return 0;
      }
      else {                                                                    //Sinon
        (*nb_poussees)++;                                                       //Incrémentation du nombre de poussées
        return 1;
        }
    }
  }
  return -1;
}

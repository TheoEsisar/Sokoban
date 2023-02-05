#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
* @fn int deplacement(char **map, char** map_copie, int* posx, int* posy, int deplacement, int *nb_deplacements, int nblignes, int nbcol)
* @brief Gère les déplacements du manutentionnaire
* @param map Matrice du niveau
* @param map_copie Matrice copiée du niveau
* @see copie_map.c
* @param posx Position du manutentionnaire sur les colonnes
* @param posy Position du manutentionnaire sur les lignes
* @param deplacement Dans quelle direction déplacer le manutentionnaire
* @param nb_deplacements Nombre de déplacements depuis le début du niveau
* @param nblignes Nombre de lignes du niveau
* @param nbcol Nombre de colonnes du niveau
* @return -1 si le joueur appuie sur une touche qui ne déplace pas le manutentionnaire; 0 sinon
* @details Déplace le manutentionnaire et compte le nombre de déplacements effectués pour réussir le niveau
*/
int deplacement(char **map, char** map_copie, int* posx, int* posy, int deplacement, int *nb_deplacements, int nblignes, int nbcol)
{
  int posx1, posy1, posx2, posy2;
  detection_joueur(map, nblignes, nbcol, &posx1, &posy1); //On regarde la position initiale du joueur

  //On regarde la touche sur laquelle le joueur a appuyé
  if (deplacement == 1) {
    aller_haut(map, map_copie, posx, posy);
  }
  if (deplacement == 2) {
    aller_bas(map, map_copie, posx, posy);
  }
  if (deplacement == 3) {
    aller_droite(map, map_copie, posx, posy);
  }
  if (deplacement == 4) {
    aller_gauche(map, map_copie, posx, posy);
  }
  if (deplacement != 1 && deplacement != 2 && deplacement != 3 && deplacement != 4 ) {
    return -1;
  }


  detection_joueur(map, nblignes, nbcol, &posx2, &posy2);                       //On regarde la postion du joueur apres le déplacement
  if (posx1 != posx2 || posy1 != posy2) {                                       //On compare les deux positions pour savoir si il a bougé
    (*nb_deplacements)++;                                                       //On incrémente nb_deplacements
  }
  return 0;
}


/**
* @fn void aller_droite(char **map, char** map_copie, int* posx, int* posy)
* @brief Déplace le manutentionnaire à droite
* @param map Matrice du niveau
* @param map_copie Matrice copiée du niveau
* @see copie_map.c
* @param posx Position du manutentionnaire sur les colonnes
* @param posy Position du manutentionnaire sur les lignes
* @return void
*/
void aller_droite(char **map, char** map_copie, int* posx, int* posy)
{
  char nb_caisse = 0;
  if ((map[*posy][*posx+1]==' ') || (map[*posy][*posx+1] == '.'))
  {
    map[*posy][*posx]= map_copie[*posy][*posx];
    map[*posy][*posx+1]='@';
    *posx += 1;
  }
  else if (map[*posy][*posx+1]=='#')
  {
    map[*posy][*posx]= '@';
    map[*posy][*posx+1]='#';
  }
  else if (map[*posy][*posx+1] == '$') //peut aller sur cible
  {
    if(map[*posy][*posx+2]=='#'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx+1] == '.'){
      	map[*posy][*posx+1]='*';
        nb_caisse += 1;
      }
      else
      	map[*posy][*posx+1]='$';
      map[*posy][*posx+2]='#';
    }
    else if(map[*posy][*posx+2]=='$'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx+1] == '.'){
      	map[*posy][*posx+1]='*';
      }
      else
	map[*posy][*posx+1]='$';
      if(map_copie[*posy][*posx+2] == '.')
      	map[*posy][*posx+2]='*';
      else
      	map[*posy][*posx+2]='$';
    }
    else if(map[*posy][*posx+2]=='*'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx+1] == '.')
      	map[*posy][*posx+1]='*';
      else
	map[*posy][*posx+1]='$';
      if(map_copie[*posy][*posx+2] == '.')
      	map[*posy][*posx+2]='*';
      else
      	map[*posy][*posx+2]='$';
    }
    else {
      map[*posy][*posx]= map_copie[*posy][*posx];
      map[*posy][*posx+1]='@';
      if(map_copie[*posy][*posx+2] == '.')
      	map[*posy][*posx+2]='*';
      else
      	map[*posy][*posx+2]='$';
      *posx += 1;
      }
  }
  else if (map[*posy][*posx+1] == '*')// est déja sur cible, mais peut ne plus l'être
  {
    if(map[*posy][*posx+2]=='#'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx+1] == '.')
      	map[*posy][*posx+1]='*';
      else
      	map[*posy][*posx+1]='$';
      map[*posy][*posx+2]='#';
    }
    else if(map[*posy][*posx+2] == '$'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx+1] == '.')
      	map[*posy][*posx+1]='*';
      else
	map[*posy][*posx+1]='$';
      if(map_copie[*posy][*posx+2] == '.')
      	map[*posy][*posx+2]='*';
      else
      	map[*posy][*posx+2]='$';
    }
    else if(map[*posy][*posx+2] == '*'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx+1] == '.')
      	map[*posy][*posx+1]='*';
      else
	map[*posy][*posx+1]='$';
      if(map_copie[*posy][*posx+2] == '.')
      	map[*posy][*posx+2]='*';
      else
      	map[*posy][*posx+2]='$';
    }
    else {
      map[*posy][*posx]= map_copie[*posy][*posx];
      map[*posy][*posx+1]='@';
      if(map_copie[*posy][*posx+2] == '.')
      	map[*posy][*posx+2]='*';
      else
      	map[*posy][*posx+2]='$';
      *posx += 1;
      }
  }
}


/**
* @fn void aller_gauche(char **map, char** map_copie, int* posx, int* posy)
* @brief Déplace le manutentionnaire à gauche
* @param map Matrice du niveau
* @param map_copie Matrice copiée du niveau
* @see copie_map.c
* @param posx Position du manutentionnaire sur les colonnes
* @param posy Position du manutentionnaire sur les lignes
* @return void
*/
void aller_gauche(char **map, char** map_copie, int* posx, int* posy)
{
  if ((map[*posy][*posx-1]==' ') || (map[*posy][*posx-1] == '.'))
  {
    map[*posy][*posx]= map_copie[*posy][*posx];
    map[*posy][*posx-1]='@';
    *posx -= 1;
  }
  else if (map[*posy][*posx-1]=='#')
  {
    map[*posy][*posx]= '@';
    map[*posy][*posx-1]='#';
  }
  else if (map[*posy][*posx-1]=='$')
  {
    if(map[*posy][*posx-2]=='#'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx-1] == '.')
      	map[*posy][*posx-1]='*';
      else
      	map[*posy][*posx-1]='$';
      map[*posy][*posx-2]='#';
    }
    else if(map[*posy][*posx-2] == '$'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx-1] == '.')
      	map[*posy][*posx-1]='*';
      else
      	map[*posy][*posx-1]='$';
      if(map_copie[*posy][*posx-2] == '.')
      	map[*posy][*posx-2]='*';
      else
      	map[*posy][*posx-2]='$';
    }
    else if(map[*posy][*posx-2] == '*'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx-1] == '.')
      	map[*posy][*posx-1]='*';
      else
      	map[*posy][*posx-1]='$';
      if(map_copie[*posy][*posx-2] == '.')
      	map[*posy][*posx-2]='*';
      else
      	map[*posy][*posx-2]='$';
    }
    else {
      map[*posy][*posx]= map_copie[*posy][*posx];
      map[*posy][*posx-1]='@';
      if(map_copie[*posy][*posx-2] == '.')
      	map[*posy][*posx-2]='*';
      else
      	map[*posy][*posx-2]='$';
      *posx -= 1;
      }
  }
  else if (map[*posy][*posx-1]=='*')
  {
    if(map[*posy][*posx-2]=='#'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx-1] == '.')
      	map[*posy][*posx-1]='*';
      else
      	map[*posy][*posx-1]='$';
      map[*posy][*posx-2]='#';
    }
    else if(map[*posy][*posx-2] == '$'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx-1] == '.')
      	map[*posy][*posx-1]='*';
      else
      	map[*posy][*posx-1]='$';
      if(map_copie[*posy][*posx-2] == '.')
      	map[*posy][*posx-2]='*';
      else
      	map[*posy][*posx-2]='$';
    }
    else if(map[*posy][*posx-2] == '*'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy][*posx-1] == '.')
      	map[*posy][*posx-1]='*';
      else
      	map[*posy][*posx-1]='$';
      if(map_copie[*posy][*posx-2] == '.')
      	map[*posy][*posx-2]='*';
      else
      	map[*posy][*posx-2]='$';
    }
    else {
      map[*posy][*posx]= map_copie[*posy][*posx];
      map[*posy][*posx-1]='@';
      if(map_copie[*posy][*posx-2] == '.')
      	map[*posy][*posx-2]='*';
      else
      	map[*posy][*posx-2]='$';
      *posx -= 1;
      }
  }
}


/**
* @fn void aller_haut(char **map, char** map_copie, int* posx, int* posy)
* @brief Déplace le manutentionnaire en haut
* @param map Matrice du niveau
* @param map_copie Matrice copiée du niveau
* @see copie_map.c
* @param posx Position du manutentionnaire sur les colonnes
* @param posy Position du manutentionnaire sur les lignes
* @return void
*/
void aller_haut(char **map,char** map_copie, int* posx, int* posy)
{
  if ((map[*posy-1][*posx]==' ') || (map[*posy-1][*posx] == '.'))
  {
    map[*posy][*posx]= map_copie[*posy][*posx];
    map[*posy-1][*posx]='@';
    *posy -= 1;
  }
  else if (map[*posy-1][*posx]=='#')
  {
    map[*posy][*posx]= '@';
    map[*posy-1][*posx]='#';
  }
  else if (map[*posy-1][*posx]=='$')
  {
    if(map[*posy-2][*posx]=='#'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy-1][*posx] == '.')
      	map[*posy-1][*posx]='*';
      else
      	map[*posy-1][*posx]='$';
      map[*posy-2][*posx]='#';
    }
    else if(map[*posy-2][*posx]=='$'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy-1][*posx] == '.')
      	map[*posy-1][*posx]='*';
      else
      	map[*posy-1][*posx]='$';
      if(map_copie[*posy-2][*posx] == '.')
      	map[*posy-2][*posx]='*';
      else			//printf("%d\n", nb_deplacements);

      	map[*posy-2][*posx]='$';
    }
    else if(map[*posy-2][*posx]=='*'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy-1][*posx] == '.')
      	map[*posy-1][*posx]='*';
      else
      	map[*posy-1][*posx]='$';
      if(map_copie[*posy-2][*posx] == '.')
      	map[*posy-2][*posx]='*';
      else
      	map[*posy-2][*posx]='$';
    }
    else {
      map[*posy][*posx]= map_copie[*posy][*posx];
      map[*posy-1][*posx]='@';
      if(map_copie[*posy-2][*posx] == '.')
      	map[*posy-2][*posx]='*';
      else
      	map[*posy-2][*posx]='$';
      *posy -= 1;
      }
  }
  else if (map[*posy-1][*posx]=='*')
  {
    if(map[*posy-2][*posx]=='#'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy-1][*posx] == '.')
      	map[*posy-1][*posx]='*';
      else
      	map[*posy-1][*posx]='$';
      map[*posy-2][*posx]='#';
    }
    else if(map[*posy-2][*posx]=='$'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy-1][*posx] == '.')
      	map[*posy-1][*posx]='*';
      else
      	map[*posy-1][*posx]='$';
      if(map_copie[*posy-2][*posx] == '.')
      	map[*posy-2][*posx]='*';
      else
      	map[*posy-2][*posx]='$';
    }
    else if(map[*posy-2][*posx]=='*'){
      map[*posy][*posx]= '@';
      if(map_copie[*posy-1][*posx] == '.')
      	map[*posy-1][*posx]='*';
      else
      	map[*posy-1][*posx]='$';
      if(map_copie[*posy-2][*posx] == '.')
      	map[*posy-2][*posx]='*';
      else
      	map[*posy-2][*posx]='$';
    }
    else {
      map[*posy][*posx]= map_copie[*posy][*posx];
      map[*posy-1][*posx]='@';
      if(map_copie[*posy-2][*posx] == '.')
      	map[*posy-2][*posx]='*';
      else
      	map[*posy-2][*posx]='$';
      *posy -= 1;
      }
  }
}


/**
* @fn void aller_bas(char **map, char** map_copie, int* posx, int* posy)
* @brief Déplace le manutentionnaire en bas
* @param map Matrice du niveau
* @param map_copie Matrice copiée du niveau
* @see copie_map.c
* @param posx Position du manutentionnaire sur les colonnes
* @param posy Position du manutentionnaire sur les lignes
* @return void
*/
void aller_bas(char **map,char** map_copie, int* posx, int* posy)
{
        if ((map[*posy+1][*posx]==' ') || (map[*posy+1][*posx] == '.'))
        {
          map[*posy][*posx]= map_copie[*posy][*posx];
          map[*posy+1][*posx]='@';
          *posy += 1;
        }
        else if (map[*posy+1][*posx]=='#')
        {
          map[*posy][*posx]= '@';
          map[*posy+1][*posx]='#';
        }
        else if (map[*posy+1][*posx]=='$')
        {
          if(map[*posy+2][*posx]=='#'){
            map[*posy][*posx]= '@';
	    if(map_copie[*posy+1][*posx] == '.')
            map[*posy+1][*posx]='*';
	    else
            	map[*posy+1][*posx]='$';
            map[*posy+2][*posx]='#';
          }
          else if(map[*posy+2][*posx]=='$'){
            map[*posy][*posx]= '@';
	    if(map_copie[*posy+1][*posx] == '.')
            	map[*posy+1][*posx]='*';
	    else
            	map[*posy+1][*posx]='$';
	    if(map_copie[*posy+2][*posx] == '.')
            	map[*posy+2][*posx]='*';
	    else
            	map[*posy+2][*posx]='$';
          }
          else if(map[*posy+2][*posx]=='*'){
            map[*posy][*posx]= '@';
	    if(map_copie[*posy+1][*posx] == '.')
            	map[*posy+1][*posx]='*';
	    else
            	map[*posy+1][*posx]='$';
	    if(map_copie[*posy+2][*posx] == '.')
            	map[*posy+2][*posx]='*';
	    else
            	map[*posy+2][*posx]='$';
          }
          else {
            map[*posy][*posx]= map_copie[*posy][*posx];
            map[*posy+1][*posx]='@';
	    if(map_copie[*posy+2][*posx] == '.')
            	map[*posy+2][*posx]='*';
	    else
            	map[*posy+2][*posx]='$';
            *posy += 1;
            }
        }
        else if (map[*posy+1][*posx]=='*')
        {
          if(map[*posy+2][*posx]=='#'){
            map[*posy][*posx]= '@';
	    if(map_copie[*posy+1][*posx] == '.')
            map[*posy+1][*posx]='*';
	    else
            	map[*posy+1][*posx]='$';
            map[*posy+2][*posx]='#';
          }
          else if(map[*posy+2][*posx]=='$'){
            map[*posy][*posx]= '@';
	    if(map_copie[*posy+1][*posx] == '.')
            	map[*posy+1][*posx]='*';
	    else
            	map[*posy+1][*posx]='$';
	    if(map_copie[*posy+2][*posx] == '.')
            	map[*posy+2][*posx]='*';
	    else
            	map[*posy+2][*posx]='$';
          }
          else if(map[*posy+2][*posx]=='*'){
            map[*posy][*posx]= '@';
	    if(map_copie[*posy+1][*posx] == '.')
            	map[*posy+1][*posx]='*';
	    else
            	map[*posy+1][*posx]='$';
	    if(map_copie[*posy+2][*posx] == '.')
            	map[*posy+2][*posx]='*';
	    else
            	map[*posy+2][*posx]='$';
          }
          else {
            map[*posy][*posx]= map_copie[*posy][*posx];
            map[*posy+1][*posx]='@';
	    if(map_copie[*posy+2][*posx] == '.')
            	map[*posy+2][*posx]='*';
	    else
            	map[*posy+2][*posx]='$';
            *posy += 1;
            }
        }

}

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "header.h"
/**
* @def MAXSIZE
* @brief Définit la taille max à 10
**/
#define MAXSIZE 10

/**
* @fn int configureTerminal(int IsReset)
* @brief Configure le terminal en mode cannonique ou non cannonique
* @param IsReset Permet de choisir le mode du terminal
* @return -1 si erreur, 0 sinon
*/

int configureTerminal(int IsReset) //permet de choisir entre le mode canonique ou non canonique en fonction de si IsReset vaut 0 ou autre chose

{
        struct termios new;
        if (tcgetattr(0,&new)==-1) {
                perror("tcgetattr");
                return -1;
        }

        if (IsReset==0)
        {
                new.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
                new.c_lflag &= ~(ECHO);   // les touches tapées ne s'inscriront plus dans le terminal
        }
        else
        {
                new.c_lflag=35387;
        }

        new.c_cc[VMIN]=1;
        new.c_cc[VTIME]=0;
        if (tcsetattr(0,TCSANOW,&new)==-1) {
    perror("tcsetattr");
                return -1;
  }
        return 0;
}


/**
* @fn int litClavier()
* @brief Lit les entrées clavier
* @param Aucun
* @return Le caractère lu au clavier
*/

int litClavier()
{
	char r[MAXSIZE];
	int c;

	if ((c=read(0,r,3)) == - 1 ) return -1;

	switch (r[0]) {
		case 27 :  if ((c==3) && (r[1]==91)) return (r[2]-64); else return -1; break;
		default: return r[0]; break;
	}
}

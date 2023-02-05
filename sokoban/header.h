/**
* @def NIVEAU_MAX
* @brief Définit le nombre maximum de niveau à 88
**/
#define NIVEAU_MAX 88

/**
* @def NB_ENTETE
* @brief Définit le nombre d'entêtes du fichier à 4
**/
#define NB_ENTETE 4

/**
 * @struct Mouvement
 * @brief Pile qui stocke tous les mouvements du manutentionnaire
 */
typedef struct Mouvement Mouvement;
struct Mouvement
{
    int mv;
    int hasPushed;
    int hasMoved;
    Mouvement *suivant;
};

/**
 * @struct Liste
 * @brief Sert à accéder au permier élément de la pile
 */
typedef struct Liste Liste;
struct Liste
{
    Mouvement *premier;
};

/**
* @file header.h
* @author POURTIER Remy; ROSSELET Baptiste; GAY Theo; LAFAGE Robin
* @date 10 Juin 2022
* @brief Liste des fonctions du projet
*/

char** creation_map(int, int);
void charge_niveau(int, int*, int*);
void affiche_map(int, int, char**);
void aller_droite(char**, char**, int*, int*);
void aller_gauche(char**, char**, int*, int*);
void aller_haut(char**, char**, int*, int*);
void aller_bas(char**, char**, int*, int*);
void detection_joueur(char**, int, int, int*, int*);
char** copie_map(int, int);
int deplacement(char**, char**, int*, int*, int, int*, int, int);
int configureTerminal(int IsReset);
int litClavier();
int test_victoire(char** map, int nblignes, int nbcolonnes);
void undo_deplacement(char **map, char** map_copie, int* posx, int* posy, Liste *liste, int * nb_deplacements,int* nb_poussees);
void enregistrement_solution(int nb_niveau, int nb_deplacements, Liste *liste);
Liste *initialisation(Mouvement*);
void insertion(Liste *liste, int nvMouvement, int nvPush, int nvMoved, Mouvement*);
Mouvement *suppression(Liste *liste);
void afficherListe(Liste *liste);
char** reinitialiser_niveau(char** map, int nblignes, int nbcolonnes, int* posx, int* posy, int* nb_deplacements, int* nb_poussees, Liste **liste, Mouvement* element);
int will_moved(char **map, char** map_copie, int* posx, int* posy, int deplacement);
int will_pushed(char **map, char** map_copie, int* posx, int* posy, int deplacement, int* nb_poussees);
void save(int nb_deplacements, Liste *liste);
int recuperation_niveau();
int recuperation_nbdeplacements();
int* save_liste_deplacements(int nb_deplacements, int** liste_deplacements);
void jouer_sokoban();

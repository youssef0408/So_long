#include "so_long.h"

struct player{
int x ;
int y ;
int nb_c;

};


bool can_move();


// 1- 1er ligne  que 1
// 4- dernière ligne  que des 1
// 2- toutes les ligne commenece par 1  OK
// 3- toutes les ligne finisse par 1  OK
// 5- toutes ligne on la la taille de la 1er ligne OK
// 6- une position de depart OK
// 7- une position de sortir OK
// 8 - nb collectible > 0 OK

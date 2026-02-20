#include <math.h>
#include "Operaciones.h"

double Operaciones::dist2Point(Node* a,Node* b){
    return sqrt(pow(b->x-a->x,2)+pow(b->y-a->y,2));
}
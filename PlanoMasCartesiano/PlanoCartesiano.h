#pragma once
#include "Grupos.h"

class PlanoCartesiano{
    private:
        // Tamanio del plano
        int max_x;
        int max_y;
    public:
        PlanoCartesiano(){};
        PlanoCartesiano(int x,int y):max_x(x+1),max_y(y+1){}
        void show(Grupos&);
        void show();
        void setX(int);
        void setY(int);
        int getX();
        int getY();
};
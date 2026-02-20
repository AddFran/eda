#pragma once
#include "Node.h"

class Grupos{
    private:
        Node* head;
    public:
        Grupos():head(nullptr){}
        void add(char,int,int);
        void add(char,int,int,int);
        void show();
        int getSize();
        bool comprobarCoor(Node*); // No puede haber dos puntos con la misma coordenada (o se sobreescribe, no se)
        Node* getHead();
        ~Grupos();
};
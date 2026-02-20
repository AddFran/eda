#pragma once
#include "Node.h"

class Dic{
    public:
        Node* data;
        double distancia;
        Dic():data(nullptr),distancia(0.0) {}
        Dic(Node* valor,double dist):data(valor),distancia(dist) {}
};
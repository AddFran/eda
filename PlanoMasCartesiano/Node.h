#pragma once

class Node{
    public:
        char name;
        int x;
        int y;
        int idGrupo; // Indicamos el grupo em el que esta (0 no tiene, 1 a + el grupo en el q esta)
        Node* next;
        Node(int _x,int _y) : name('0'),x(_x),y(_y),idGrupo(0),next(nullptr){}
        Node(char _name,int _x,int _y) : name(_name),x(_x),y(_y),idGrupo(0),next(nullptr){}
        Node(int _x,int _y,int id) : name('0'),x(_x),y(_y),idGrupo(id),next(nullptr){}
        Node(char _name,int _x,int _y,int id) : name(_name),x(_x),y(_y),idGrupo(id),next(nullptr){}
};
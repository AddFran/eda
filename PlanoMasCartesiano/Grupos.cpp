#include <iostream>
#include <vector>
#include <algorithm>
#include "Grupos.h"
#include "Dic.h"
#include "Operaciones.h"
using namespace std;

void Grupos::add(char c,int x,int y){
    Node* nuevo=new Node(c,x,y);
    Node* suport=head;
    while(suport){
        if((x==suport->x && y==suport->y) || c==suport->name){
            cout<<"Error, punto ya existente."<<endl;
            return;
        }
        suport=suport->next;
    }
    nuevo->next=head;
    head=nuevo;

    Node* current=head->next;
    vector<Dic> aux; // Lista de distancias asociadas con el vector
    while(current){
        double dist=Operaciones::dist2Point(head,current);
        Dic nuevo(current,dist);
        aux.push_back(nuevo);
        current=current->next;
    }

    sort(aux.begin(),aux.end(),[](const Dic& a, const Dic& b){
        return a.distancia < b.distancia;
    });

    int k=4;

    int aux2[10]={0}; // Contador de num de elemenntos por grupos
    int mayor=0;
    int id=0;
    for(int i=0;i<k;i++)
        aux2[aux[i].data->idGrupo]++;
    for(int i=0;i<10;i++){
        if(mayor<aux2[i]){
            mayor=aux2[i];
            id=i;
        }
    }
    if(!aux[0].data){
        cout<<"Lista vacia"<<endl;
    }else
        cout<<"Distancia minima de "<<head->name<<" a "<<aux[0].data->name<<" es de: "<<aux[0].distancia<<endl;
    head->idGrupo=id;
}
void Grupos::add(char c,int x,int y,int id){
    Node* nuevo=new Node(c,x,y,id);
    nuevo->next=head;
    head=nuevo;
}
void Grupos::show(){
    Node* current=head;
    while(current){
        cout<<"("<<current->x<<","<<current->y<<")"<<" ";
        current=current->next;
    }
    cout<<endl;
}
void Grupos::showData(){
    Node* current=head;
    cout<<"Lista de puntos:"<<endl;
    while(current){
        cout<<"Punto "<<current->name<<"("<<current->x<<","<<current->y<<") pertenece al grupo "<<current->idGrupo<<endl;
        current=current->next;
    }
}
int Grupos::getSize(){
    Node* current=head;
    int count=0;
    while(current){
        count++;
        current=current->next;
    }
    return count;
}
Node* Grupos::getHead(){
    return head;
}
Grupos::~Grupos(){
    Node* current=head;
    while(head){
        Node* aux=current;
        current=current->next;
        delete aux;
    }
}
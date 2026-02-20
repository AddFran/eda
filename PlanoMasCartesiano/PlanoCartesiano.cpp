#include <iostream>
#include <vector>
#include "PlanoCartesiano.h"
using namespace std;

void PlanoCartesiano::show(Grupos& lista){
    /* 
        Idea, crea una matriz temporal de string donde dependiendo de los elementos de la lista, asigne el X
        en la casilla, cosa que mostramos la matriz normalmente. Ya no estamos recorriendo punto por punto viendo 
        si la lista de elmentos por cada casilla.
    */
    vector<vector<string>> matrix(max_y,vector<string>(max_x,"."));
    Node* current=lista.getHead();
    while(current){
        matrix[current->y][current->x]=current->name; // Considerar cambiar a futuro si se desea incluir el 0 en X y el 0 en Y (quitar los -1)
        current=current->next;
    }

    for(int i=max_y;i>0;i--){
        //cout<<"- ";
        cout<<i-1<<" ";
        if(i-1<10)
            cout<<" ";
        for(int j=0;j<max_x;j++)
            cout<<matrix[i-1][j]<<"  ";
        cout<<endl;
    }
    cout<<"  ";
    for(int i=0;i<max_x;i++){
        //cout<<"| ";
        cout<<i<<" ";
        if(i<10)
            cout<<" ";
    }
    cout<<endl;
}

void PlanoCartesiano::show(){
    for(int i=max_y;i>0;i--){
        //cout<<"- ";
        cout<<i-1<<" ";
        if(i-1<10)
            cout<<" ";
        for(int j=0;j<max_x;j++)
            cout<<".  ";
        cout<<endl;
    }
    cout<<"  ";
    for(int i=0;i<max_x;i++){
        //cout<<"| ";
        cout<<i<<" ";
        if(i<10)
            cout<<" ";
    }
    cout<<endl;
}
void PlanoCartesiano::setX(int x){
    max_x=x; 
}
void PlanoCartesiano::setY(int y){
    max_y=y;
}
int PlanoCartesiano::getX(){
    return max_x;
}
int PlanoCartesiano::getY(){
    return max_y;
}
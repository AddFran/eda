#include <iostream>
#include <conio.h>
#include "PlanoCartesiano.h"
#include "Menu.h"
using namespace std;

int main(){
    PlanoCartesiano p1(20,20);
    Grupos g1;
    // Grupos predefinido (dos grupos)
    //g1.add('A',19,17,1);
    //g1.add('B',18,18,1);
    //g1.add('C',16,20,1);
    //g1.add('D',1,2,2);
    //g1.add('E',4,5,2);
    //g1.add('F',3,3,2);
    //g1.add('G',6,1,2);
    //g1.add('X',20,20);
    //Node* g=g1.getHead();
    //cout<<"======================"<<endl;
    //cout<<g->idGrupo<<endl;
    //cout<<"======================"<<endl;
    //g1.add('Y',18,10);
    //g=g1.getHead();
    //cout<<"======================"<<endl;
    //cout<<g->idGrupo<<endl;
    //cout<<"======================"<<endl;
    //p1.show(g1); // Error en show(), despues de ejecutar se detiene la ejecucion
    //getch();
    
    Menu m1;
    m1.interfaz();
    return 0;
}
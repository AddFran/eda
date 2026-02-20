#include <iostream>
#include <conio.h>
#include "PlanoCartesiano.h"
#include "Menu.h"
using namespace std;

void Menu::interfaz(){
    PlanoCartesiano p1(20,20);
    Grupos g1;
    // Grupos predefinido (dos grupos)
    g1.add('A',19,17,1);
    g1.add('B',18,18,1);
    g1.add('C',16,20,1);
    g1.add('D',1,2,2);
    g1.add('E',4,5,2);
    g1.add('F',3,3,2);
    g1.add('G',6,1,2);
    while(true){
        system("cls");
        int choice;
        char choice2;
        cout<<"=================================="<<endl;
        cout<<"        KNN LITE"<<endl;
        cout<<"=================================="<<endl;
        cout<<"=================================="<<endl;
        p1.show(g1);
        cout<<"Elija una opcion:"<<endl;
        cout<<"=================================="<<endl;
        cout<<" 1. Ingresar un punto"<<endl;
        cout<<" 2. Ver plano"<<endl;
        cout<<"=================================="<<endl;
        cout<<"Opcion: ";
        cin>>choice;
        switch(choice){
            case 1:
                system("cls");
                char c1;
                int c2;
                int c3;
                p1.show(g1);
                cout<<"Ingrese los datos del nuevo punto:"<<endl;
                cout<<"Nombre del punto (solo un caracter): ";
                cin>>c1;
                cout<<"Ingrese coordenada X:";
                cin>>c2;
                cout<<"Ingrese coordenada Y:";
                cin>>c3;
                g1.add(c1,c2,c3);
                getch();
                break;
            case 2:
                system("cls");
                p1.show(g1);
                cout<<"Presione cualquier tecla para continuar..."<<endl;
                getch();
                break;
            default:
                break;
        }
    }
}
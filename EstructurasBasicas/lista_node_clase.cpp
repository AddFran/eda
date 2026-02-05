#include <iostream>
using namespace std;

class Contacto{
    public:
        int data;
        Contacto* next;
        Contacto(int valor):data(valor),next(nullptr) {}
};
class Lista{
    private:
        Contacto* inicio;
    public:
        Lista():inicio(nullptr) {}
        void add(int);
        void addEnd(int);
        void addPos(int,int);
        void drop();
        void dropEnd();
        void dropPos(int);
        void show();
        int size();
        bool isEmpty();
        ~Lista();
};

void Lista::add(int valor){
    Contacto* nuevo=new Contacto(valor);
    nuevo->next=inicio;
    inicio=nuevo;
}
void Lista::addEnd(int valor){
    Contacto* nuevo=new Contacto(valor);
    if(isEmpty()){
        inicio=nuevo;
        return;
    }
    Contacto* current=inicio;
    while(current->next){
        current=current->next;
    }
    current->next=nuevo;
}
void Lista::addPos(int valor,int pos){
    if(pos>size()+1){
        cout<<"Excede el tamanio"<<endl;
        return;
    }
    if(pos==1){
        add(valor);
        return;
    }
    if(pos==size()+1){   
        addEnd(valor);
        return;
    }
    Contacto* nuevo=new Contacto(valor);
    Contacto* current=inicio;
    for(int i=0;i<pos-2;i++) 
        current=current->next;
    nuevo->next=current->next;
    current->next=nuevo;
}
void Lista::drop(){
    if(isEmpty()){
        cout<<"Lista vacia"<<endl;
        return;
    }
    Contacto* aux=inicio;
    inicio=inicio->next;
    delete aux;
}
void Lista::dropEnd(){
    if(isEmpty()){
        cout<<"Lista vacia"<<endl;
        return;
    }
    Contacto* current=inicio;
    while(current->next->next){
        current=current->next;
    }
    Contacto* aux=current->next;
    current->next=nullptr;
    delete aux;
}
void Lista::dropPos(int pos){
    if(!inicio){
        cout<<"Lista vacia"<<endl;
        return;
    }
    if(pos==1){
        drop();
        return;
    }
    if(pos>size()){
        cout<<"Excede el tamanio"<<endl;
        return;
    }
    Contacto* current=inicio;
    for(int i=0;i<pos-2;i++){
        current=current->next;
    }
    Contacto* aux=current->next;
    current->next=current->next->next;
    delete aux;
}
void Lista::show(){
    Contacto* current=inicio;
    while(current){
        cout<<current->data<<" - ";
        current=current->next;
    }
    cout<<"FIN"<<endl;
}
int Lista::size(){
    Contacto* current=inicio;
    int count=0;
    while(current){
        current=current->next;
        count++;
    }
    return count;
}
bool Lista::isEmpty(){
    return (inicio==nullptr);
}
Lista::~Lista(){
    Contacto* current=inicio;
    while(current){
        Contacto* aux=current;
        current=current->next;
        delete aux;
    }
}

int main(){
    Lista l1;
    l1.add(1);
    l1.add(2);
    l1.add(3);
    l1.add(4);
    l1.add(5);
    l1.show();
    l1.addPos(10,2);
    l1.show();
    l1.dropPos(7);
    l1.show();

    return 0;
}
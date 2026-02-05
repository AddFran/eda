#include <iostream>
using namespace std;

class Contacto{
    public:
        int data;
        Contacto* next;
        Contacto* prev;
        Contacto(int valor):data(valor),next(nullptr),prev(nullptr) {}
};

class Agenda{
    private:
        Contacto* head;
    public:
        Agenda():head(nullptr) {}
        void add(int);
        void addEnd(int);
        void addPos(int,int);
        void drop();
        void dropEnd();
        void dropPos(int);
        void show();
        void showReverse();
        int size();
        ~Agenda();
};
void Agenda::add(int valor){
    Contacto* nuevo=new Contacto(valor);
    if(!head){
        head=nuevo;
        return;
    }
    nuevo->next=head;
    head->prev=nuevo;
    head=nuevo;
}
void Agenda::addEnd(int valor){
    Contacto* nuevo=new Contacto(valor);
    if(!head){
        head=nuevo;
        return;
    }
    Contacto* current=head;
    while(current->next)
        current=current->next;
    current->next=nuevo;
    nuevo->prev=current;
}
void Agenda::addPos(int valor,int pos){
    if(pos==1){
        add(valor);
        return;
    }
    if(pos==size()+1){
        addEnd(valor);
        return;
    }
    if(pos>size()+1){
        cout<<"Excede el tamanio"<<endl;
        return;
    }
    Contacto* current=head;
    for(int i=0;i<pos-2;i++)
        current=current->next;
    Contacto* nuevo=new Contacto(valor);
    nuevo->next=current->next;
    current->next->prev=nuevo;
    nuevo->prev=current;
    current->next=nuevo;
}
void Agenda::drop(){
    if(!head){
        cout<<"Lista vacia"<<endl;
        return;
    }
    Contacto* aux;
    if(size()==1){
        aux=head;
        head=nullptr;
        delete aux;
        return;
    }
    aux=head;
    head=head->next;
    head->prev=nullptr;
    delete aux;
}
void Agenda::dropEnd(){
    if(!head){
        cout<<"Lista vacia"<<endl;
        return;
    }
    Contacto* aux;
    if(size()==1){
        aux=head;
        head=nullptr;
        delete aux;
        return;
    }
    Contacto* current=head;
    while(current->next->next)
        current=current->next;
    aux=current->next;
    current->next=nullptr;
    delete aux;
}
void Agenda::dropPos(int pos){
    if(pos==1){
        drop();
        return;
    }
    if(pos==size()){
        dropEnd();
        return;
    }
    if(pos>size()){
        cout<<"Excede el tamanio"<<endl;
        return;
    }
    Contacto* current=head;
    for(int i=0;i<pos-2;i++)
        current=current->next;
    Contacto* aux=current->next;
    if(current->next->next)
        current->next->next->prev=current; 
    current->next=current->next->next;
    delete aux;
}
void Agenda::show(){
    Contacto* current=head;
    while(current){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
void Agenda::showReverse(){
    Contacto* current=head;
    while(current->next){
        cout<<current->data<<" ";
        current=current->next;
    }
    //cout<<current->data<<" | ";
    while(current){
        cout<<current->data<<" ";
        current=current->prev;
    }
    cout<<endl;
}
int Agenda::size(){
    Contacto* current=head;
    int count=0;
    while(current){
        current=current->next;
        count++;
    }
    return count;
}
Agenda::~Agenda(){
    Contacto* current=head;
    while(current){
        Contacto* aux=current;
        current=current->next;
        delete aux;
    }
}

int main(){
    Agenda l1;
    l1.add(1);
    l1.add(2);
    l1.add(3);
    l1.add(4);
    l1.add(5);
    l1.add(6);
    l1.show();
    l1.drop();
    l1.drop();
    l1.show();
    l1.add(7);
    l1.show();
    l1.addEnd(100);
    l1.addEnd(1000);
    l1.add(20);
    l1.show();
    l1.showReverse();
    l1.show();
    l1.addPos(2000,9);
    l1.show();
    //l1.showReverse();
    //l1.dropEnd();
    //l1.dropEnd();
    //l1.dropEnd();
    //l1.dropEnd();
    //l1.dropEnd();
    //l1.dropEnd();
    //l1.dropEnd();
    //l1.dropEnd();
    //l1.drop();
    l1.dropPos(1);
    l1.dropPos(1);
    l1.add(44);
    l1.show();
    l1.dropPos(7);
    l1.show();
    return 0;
}
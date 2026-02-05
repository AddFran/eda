#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int dat):data(dat),next(nullptr){}
};

class Lista{
    private:
        Node* inicio;
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
    Node* nuevo=new Node(valor);
    nuevo->next=inicio;
    inicio=nuevo;
}
void Lista::addEnd(int valor){
    Node* nuevo=new Node(valor);
    if(isEmpty()){
        inicio=nuevo;
        return;
    }
    Node* current=inicio;
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
    Node* nuevo=new Node(valor);
    Node* current=inicio;
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
    Node* aux=inicio;
    inicio=inicio->next;
    delete aux;
}
void Lista::dropEnd(){
    if(isEmpty()){
        cout<<"Lista vacia"<<endl;
        return;
    }
    Node* current=inicio;
    while(current->next->next){
        current=current->next;
    }
    Node* aux=current->next;
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
    Node* current=inicio;
    for(int i=0;i<pos-2;i++){
        current=current->next;
    }
    Node* aux=current->next;
    current->next=current->next->next;
    delete aux;
}
void Lista::show(){
    Node* current=inicio;
    while(current){
        cout<<current->data<<" - ";
        current=current->next;
    }
    cout<<"FIN"<<endl;
}
int Lista::size(){
    Node* current=inicio;
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
    Node* current=inicio;
    while(current){
        Node* aux=current;
        current=current->next;
        delete aux;
    }
}

class Pila{
    private:
        Lista elementos;
    public: 
        void push(int);
        void pop();
        void show();
};
void Pila::push(int valor){
    elementos.add(valor);
}
void Pila::pop(){
    elementos.drop();
}
void Pila::show(){
    elementos.show();
}

class Cola{
    private:
        Lista elementos;
    public:
        void push(int);
        void pop();
        void show();
};
void Cola::push(int valor){
    elementos.add(valor);
}
void Cola::pop(){
    elementos.dropEnd();
}
void Cola::show(){
    elementos.show();
}

int main(){
    cout<<"------------------------"<<endl;
    Pila p1;
    p1.push(1);
    p1.push(2);
    p1.push(3);
    p1.push(4);
    p1.show();
    p1.pop();
    p1.show();
    cout<<"------------------------"<<endl;
    Cola c1;
    c1.push(1);
    c1.push(2);
    c1.push(3);
    c1.push(4);
    c1.show();
    c1.pop();
    c1.show();
    return 0;
}
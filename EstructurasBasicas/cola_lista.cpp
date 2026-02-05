#include <iostream>
using namespace std;

struct Contacto{
    int data;
    Contacto* next;
    Contacto(int valor):data(valor),next(nullptr) {}
};

class Cola{
    private:
        Contacto* head;
    public:
        Cola():head(nullptr) {}
        void enqueue(int);
        void dequeue();
        void show();
        int size();
        ~Cola();
};

void Cola::enqueue(int valor){
    Contacto* nuevo=new Contacto(valor);
    nuevo->next=head;
    head=nuevo;
}
void Cola::dequeue(){
    if(!head){
        cout<<"Cola vacia"<<endl;
        return;
    }
    Contacto* current=head;
    while(current->next->next!=nullptr){
        current=current->next;
    }
    Contacto* aux=current->next;
    current->next=nullptr;
    delete aux;
}
void Cola::show(){
    Contacto* current=head;
    while(current){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
int Cola::size(){
    Contacto* current=head;
    int count=0;
    while(current){
        current=current->next;
        count++;
    }
    return count;
}
Cola::~Cola(){
    Contacto* current=head;
    while(current){
        Contacto* aux=current;
        current=current->next;
        delete aux;
    }
}

int main(){
    Cola c1;
    c1.enqueue(1);
    c1.enqueue(2);
    c1.enqueue(3);
    c1.enqueue(4);
    c1.enqueue(5);
    c1.show();
    c1.dequeue();
    c1.dequeue();
    c1.dequeue();
    c1.show();

    return 0;
}
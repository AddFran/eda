#include <iostream>
using namespace std;
#define MAX 5

class Cola{
    private:
        int elemento[MAX]={0};
        int inicio; 
        int fin;  
        int count;  
    public:
        Cola():inicio(0),fin(0),count(0) {}
        bool vacio();
        bool lleno();
        void push(int);
        int pop();
        void clear();
        void imprimir();
};

bool Cola::vacio(){
    return (count==0); 
}
bool Cola::lleno(){
    return (count==MAX);
}
void Cola::push(int valor){
    if(lleno()){
        cout<<"Error: Cola llena"<<endl;
        return;
    }
    elemento[fin]=valor;
    fin=(fin+1)%MAX;
    count++;               
}

int Cola::pop() {
    if (vacio()) {
        cout<<"Error: Cola vacia"<<endl;
        return -1;
    }
    int valorExtraido=elemento[inicio];
    inicio=(inicio+1)%MAX;
    count--;
    return valorExtraido;
}
void Cola::clear(){
    inicio=0;
    fin=0; 
    count=0;
}
void Cola::imprimir(){
    if(vacio()){
        cout<<"La cola esta vacia."<<endl;
        return;
    }
    for (int i=0;i<count;i++){
        int indice=(inicio+i)%MAX;
        cout<<elemento[indice]<<" ";
    }
    cout<<endl;
}

int main() {
    Cola c1;
    c1.push(10);
    c1.push(20);
    c1.push(30);
    c1.push(40);
    c1.push(50);
    c1.imprimir();
    c1.pop();
    c1.pop();
    c1.imprimir();
    c1.push(90);
    c1.push(70);
    c1.imprimir();

    return 0;
}
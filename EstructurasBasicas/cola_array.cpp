#include <iostream>
using namespace std;

class Cola{
    private:
        int elemento[10]={0};
        int inicio;
    public:
        Cola():inicio(0){}
        bool vacio();
        bool lleno();
        void push(int);
        int pop();
        void clear();
        void imprimir();
};
bool Cola::vacio(){
    return (inicio==0);
}
bool Cola::lleno(){
    return (inicio==10);
}
void Cola::push(int valor){
    if(lleno()){
        cout<<"Cola llena"<<endl;
        return;
    }
    elemento[inicio]=valor;
    inicio++;
}
int Cola::pop(){
    if(vacio()){
        cout<<"Cola vacia"<<endl;
        return -1;
    }
    for(int i=0;i<inicio;i++){
        elemento[i]=elemento[i+1];
    }
    inicio--;
    return elemento[inicio];
}
void Cola::clear(){
    inicio=0;
}
void Cola::imprimir(){
    for(int i=0;i<inicio;i++){
        cout<<elemento[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Cola p1;
    p1.push(1);
    p1.push(2);
    p1.push(3);
    p1.push(4);
    p1.push(5);
    p1.push(6);
    p1.imprimir();
    p1.pop();
    p1.imprimir();
    p1.push(1);
    p1.imprimir();
    p1.pop();
    p1.imprimir();
    p1.clear();
    p1.imprimir();
    p1.push(1);
    p1.imprimir();
    p1.pop();
    p1.imprimir();
    p1.pop();
    return 0;
}
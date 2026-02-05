#include <iostream>
using namespace std;

struct Contacto{
    int data;
    Contacto* next;
    Contacto(int valor):data(valor),next(nullptr) {}
};

class ColaCircular{
    private:
        Contacto* head;
    public:
        ColaCircular():head(nullptr) {}
        void enqueue(int);
        void dequeue();
        void show();
        ~ColaCircular(); 
};
void ColaCircular::enqueue(int valor){

}

int main(){

    return 0;
}
#include <iostream>
using namespace std;

class fraccion{
    private:
        int numerador;
        int denominador;
    public:
        fraccion():numerador(0),denominador(0) {}
        fraccion(int num,int dem):numerador(num),denominador(dem) {}
        void show();
        fraccion operator+(const fraccion &);
        fraccion operator-(const fraccion &);
        fraccion operator*(const fraccion &);
        fraccion operator/(const fraccion &);
};

void fraccion::show(){
    cout<<numerador<<"/"<<denominador<<endl;
}
fraccion fraccion::operator*(const fraccion &a){
    return fraccion(numerador*a.numerador,denominador*a.denominador);
}
fraccion fraccion::operator+(const fraccion &a){
    return fraccion((numerador*a.denominador)+(a.numerador*denominador),denominador*a.denominador);
}
fraccion fraccion::operator-(const fraccion &a){
    return fraccion((numerador*a.denominador)-(a.numerador*denominador),denominador*a.denominador);
}
fraccion fraccion::operator/(const fraccion &a){
    return fraccion(numerador*a.denominador,denominador*a.numerador);
}

int main(){
    int num1,num2,den1,den2;
    
    fraccion a(5,6),b(6,5);
    fraccion z,z1,z2,z3;
    z=a+b;
    z1=a-b;
    z2=a*b;
    z3=a/b;
    a.show();
    b.show();
    cout<<"---------------------------------"<<endl;
    cout<<"Suma: "<<endl;
    z.show();
    cout<<"Resta: "<<endl;
    z1.show();
    cout<<"Multiplicacion: "<<endl;
    z2.show();
    cout<<"Division: "<<endl;
    z3.show();

    return 0;
}
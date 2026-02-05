#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace chrono;

void BubbleSort(int array[],int tamanio){
    int aux;
    for (int i=0;i<tamanio;i++){
        for (int j=1;j<tamanio-i;j++){
            if (array[j-1]>array[j]){
                aux=array[j-1];
                array[j-1]=array[j];
                array[j]=aux;
            }
        }
    }
}

int main(){
    int N;
    cout<<"Ingrese el numero de elementos: ";
    cin>>N;

    int* array=new int[N];

    srand(time(nullptr));
    for (int i=0;i<N;i++){
        array[i]=rand()%100000;
    }

    auto inicio=high_resolution_clock::now();
    BubbleSort(array,N);
    auto fin=high_resolution_clock::now();

    auto duracion=duration_cast<milliseconds>(fin-inicio);
    cout<<"Tiempo de ejecucion del BubbleSort: "<<duracion.count()<<" ms"<<endl;
    delete[] array;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char valor):data(valor),left(nullptr),right(nullptr){}
};

struct Bloque {
    vector<string> lineas;
    int ancho;
    int centro;
};

class BinaryTree{
    private:
        Node* raiz;
        void inOrder(Node*);
        void preOrder(Node*);
        void postOrder(Node*);

        Bloque imprimirRecursivo(Node* nodo) {
            if (!nodo)
                return { {}, 0, 0 };

            Bloque izq = imprimirRecursivo(nodo->left);
            Bloque der = imprimirRecursivo(nodo->right);

            // Separación mínima dinámica (crece con la altura)
            int altura = max(izq.lineas.size(), der.lineas.size());
            int SEP = max(3, altura * 2);
            int anchoTotal = izq.ancho + SEP + der.ancho;
            int centro = izq.ancho + SEP / 2;

            vector<string> resultado;

            /* -------- Línea del nodo -------- */
            string lineaNodo(anchoTotal, ' ');
            lineaNodo[centro] = nodo->data;
            resultado.push_back(lineaNodo);

            /* -------- Línea de ramas -------- */
            string lineaRamas(anchoTotal, ' ');
            if (nodo->left) {
                int cIzq = izq.centro;
                lineaRamas[cIzq] = '/';
                for (int i = cIzq + 1; i < centro; i++)
                    lineaRamas[i] = '_';
            }
            if (nodo->right) {
                int cDer = izq.ancho + SEP + der.centro;
                lineaRamas[cDer] = '\\';
                for (int i = centro + 1; i < cDer; i++)
                    lineaRamas[i] = '_';
            }
            resultado.push_back(lineaRamas);

            /* -------- Combinar subárboles -------- */
            for (int i = 0; i < altura; i++) {
                string linea(anchoTotal, ' ');
                if (i <static_cast<int>(izq.lineas.size()))
                    linea.replace(0, izq.ancho, izq.lineas[i]);
                if (i <static_cast<int>(der.lineas.size()))
                    linea.replace(izq.ancho + SEP, der.ancho, der.lineas[i]);
                resultado.push_back(linea);
            }
            return { resultado, anchoTotal, centro };
        }

    public:
        BinaryTree():raiz(nullptr){}
        void insertar(char);
        void insertarDesdeNodo(Node*,Node*);
        void imprimir();
        void eliminar(char);
        void buscar(char);
        void inOrder();
        void preOrder();
        void postOrder();
        ~BinaryTree(){raiz=nullptr;}
};
void BinaryTree::insertar(char valor){
    Node* nuevo=new Node(valor);
    if(!raiz){
        raiz=nuevo;
        return;
    }
    Node* current=raiz;
    Node* anterior;
    while(current){
        if(nuevo->data<current->data){
            anterior=current;
            current=current->left;
        }
        else{
            anterior=current;
            current=current->right;
        }
    }
    if(nuevo->data<anterior->data)
        anterior->left=nuevo;
    else
        anterior->right=nuevo;
}
void BinaryTree::insertarDesdeNodo(Node* subraiz,Node* nuevo){ // Desde el que inica | nodo a insertar
    if(!nuevo)
        return;
    Node* current=subraiz;
    Node* anterior;
    while(current){
        if(nuevo->data<current->data){
            anterior=current;
            current=current->left;
        }
        else{
            anterior=current;
            current=current->right;
        }
    }
    if(nuevo->data<anterior->data)
        anterior->left=nuevo;
    else
        anterior->right=nuevo;
}
void BinaryTree::imprimir(){
    if(raiz==nullptr){
        cout<<"El arbol está vacio"<<endl;
        return;
    }
    Bloque arbol=imprimirRecursivo(raiz);
    for (const string& linea : arbol.lineas)
        cout<<linea<<endl;
}
void BinaryTree::eliminar(char valor){
    Node* current=raiz;
    Node* anterior;
    while(current->data!=valor){
        anterior=current;
        if(valor<current->data)
            current=current->left;
        else
            current=current->right;
    }
    // caso que se quiera eliminar la raiz
    if(current->data==raiz->data){
        Node* aux=raiz;
        raiz=current->left;
        insertarDesdeNodo(raiz,current->right);
        delete aux;
        return;
    }
    // caso que se quiera eliminar hoja
    if(current->left==nullptr && current->right==nullptr){
        if(current->data<anterior->data)
            anterior->left=nullptr;
        else
            anterior->right=nullptr;
        delete current;
        return;
    }

    Node* aux=current;
    if(current->data<anterior->data)
        if(!current->left){
            anterior->left=current->right;
            return;
        }else
            anterior->left=current->left;
    else{
        if(!current->left){
            anterior->right=current->right;
            return;
        }
        else
            anterior->right=current->left;
    }
    insertarDesdeNodo(current->left,current->right);
    delete aux;
}
void BinaryTree::buscar(char valor){
    Node* current=raiz;
    while(current){
        if(valor==current->data){
            cout<<"Valor '"<<valor<<"' encontrado"<<endl;
            return;
        }
        if(valor<current->data)
            current=current->left;
        else
            current=current->right;
    }
    cout<<"Valor '"<<valor<<"' no encontrado"<<endl;
}
void BinaryTree::inOrder(){
    inOrder(raiz);
    cout<<"END"<<endl;
}
void BinaryTree::inOrder(Node* current){
    if(current){
        inOrder(current->left);
        cout<<current->data<<" - ";
        inOrder(current->right);
    }
}
void BinaryTree::preOrder(){
    preOrder(raiz);
    cout<<"END"<<endl;
}
void BinaryTree::preOrder(Node* current){
    if(current){
        cout<<current->data<<" - ";
        preOrder(current->left);
        preOrder(current->right);
    }
}
void BinaryTree::postOrder(){
    postOrder(raiz);
    cout<<"END"<<endl;
}
void BinaryTree::postOrder(Node* current){
    if(current){
        postOrder(current->left);
        postOrder(current->right);
        cout<<current->data<<" - ";
    }
}
int main(){
    string palabra;
    getline(cin,palabra);
    BinaryTree l1;

    for(int i=0;i<static_cast<int>(palabra.length());i++){
        l1.insertar(palabra[i]);
    }
    l1.imprimir();
    l1.insertar('z');
    l1.insertar('y');
    cout<<"Inorder   : ";
    l1.inOrder();
    cout<<"Preorder  : ";
    l1.preOrder();
    cout<<"Postorder : ";
    l1.postOrder();

    l1.buscar('a');
    l1.eliminar('l');
    l1.imprimir();
    //l1.insertar('l');
    //l1.insertar('a');
    //l1.insertar('b');
    //l1.insertar('z');
    //l1.insertar('k');
    //l1.insertar('n');
    //l1.insertar('g');
    //l1.insertar('m');
    //l1.insertar('p');
    //l1.insertar('v'); // v | o
    //l1.insertar('c');
    //l1.insertar('i');
    //l1.insertar('f');
    //l1.inOrder();
    //l1.preOrder();
    //l1.postOrder();
    //l1.buscar('q');
    //l1.imprimir();
    //l1.eliminar('p');
    //l1.imprimir();
    getch();
    return 0;
}

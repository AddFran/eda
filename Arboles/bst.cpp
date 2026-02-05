#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int valor):data(valor),left(nullptr),right(nullptr) {}
};

class BST{
    private:
        Node* raiz;
        void inOrder(Node*); // left - raiz - right
        void preOrder(Node*); // raiz - left - right
        void postOrder(Node*); // left - right - raiz
    public:
        BST():raiz(nullptr){}
        void add(int);
        void delet(Node*);
        void inOrder();
        void preOrder();
        void postOrder();
        Node* getRaiz();
        ~BST();
};
Node* BST::getRaiz(){
    return raiz;
}
void BST::delet(Node* aux){
    if(!aux){
        cout<<"Arbol vacio"<<endl;
        return;
    }
    delet(aux->left);
    delet(aux->right);
    delete aux;
}
void BST::add(int valor){
    Node* nuevo=new Node(valor);
    if(!raiz){
        raiz=nuevo;
        return;
    }
    Node* ant; // anterior
    Node* current=raiz; // reco
    while(current){
        ant=current;
        if(valor<current->data)
            current=current->left;
        else
            current=current->right;
    }
    if(valor<ant->data)
        ant->left=nuevo;
    else
        ant->right=nuevo;
}
void BST::preOrder(){
    preOrder(raiz);
    cout<<endl;
}
void BST::preOrder(Node* current){
    if(current){
        cout<<current->data<<" - ";
        preOrder(current->left);
        preOrder(current->right);
    }
}
void BST::inOrder(){
    inOrder(raiz);
    cout<<endl;
}
void BST::inOrder(Node* current){
    if(current){
        inOrder(current->left);
        cout<<current->data<<" - ";
        inOrder(current->right);
    }
}
void BST::postOrder(){
    postOrder(raiz);
    cout<<endl;
}
void BST::postOrder(Node* current){
    if(current){
        postOrder(current->left);
        postOrder(current->right);
        cout<<current->data<<" - ";
    }
}
BST::~BST(){
    raiz=nullptr;
}
int main(){
    BST tree;
    tree.add(4);
    tree.add(1);
    tree.add(7);
    tree.add(2);
    tree.add(8);
    tree.add(3);
    tree.add(6);
    tree.add(5);
    tree.inOrder();
    tree.preOrder();
    tree.postOrder();
    return 0;
}
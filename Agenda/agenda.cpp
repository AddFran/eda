#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <regex>
using namespace std;

struct Contacto{
    int id;
    string ap_pat,ap_mat,names,phone,correo,direccion;
    int p_id,m_id;
    Contacto* next;
    Contacto* prev;
    Contacto(int _id,string pat,string mat,string _names,string _phone,string _correo,string _direccion,int _pid,int _mid){
        id=_id;
        ap_pat=pat;
        ap_mat=mat;
        names=_names;
        phone=_phone;
        correo=_correo;
        direccion=_direccion;
        p_id=_pid;
        m_id=_mid;
        next=nullptr;
        prev=nullptr;
    }
};

class Agenda{
    private:
        Contacto* head;
        int id_current;
    public:
        Agenda():head(nullptr),id_current(1){}
        void add(string,string,string,string,string,string,int,int);
        void saveFile();
        void recoverData();
        void resetData();
        void searchDataId(int);
        string searchId(int);
        void popId(int);
        void modifyId(int);
        bool verifyMail(string);
        bool verifyPhone(string);
        void show();
        friend void menu();
        ~Agenda();
};
string Agenda::searchId(int idb){
    Contacto* current=head;
    while(current){
        if(current->id==idb){
            return current->names;
        }
        current=current->next;
    }
    return "No data";
}
void Agenda::show(){
    Contacto* current=head;
    const int wID=5,wNom=15,wAp=15,wTel=12,wMail=25,wDir=20;
    cout<<left<<
        setw(wID)<<"ID"<<
        setw(wNom)<<"Nombres"<<
        setw(wAp)<<"A. Paterno"<<
        setw(wAp)<<"A. Materno"<<
        setw(wTel)<<"Telefono"<<
        setw(wMail)<<"Correo"<<
        setw(wDir)<<"Direccion"<<
        setw(wNom)<<"Padre"<<
        setw(wNom)<<"Madre"<<endl;

    while(current){
        cout<<left<<
        setw(wID)<<current->id<<
        setw(wNom)<<current->names<<
        setw(wAp)<<current->ap_pat<<
        setw(wAp)<<current->ap_mat<<
        setw(wTel)<<current->phone<<
        setw(wMail)<<current->correo<<
        setw(wDir)<<current->direccion<<
        setw(wNom)<<searchId(current->p_id)<<
        setw(wNom)<<searchId(current->m_id)<<endl;
        current=current->next;
    } 
}
void Agenda::add(string ap_pat,string ap_mat,string names,string phone,string correo,string direccion,int p_id,int m_id){
    Contacto* nuevo=new Contacto(id_current++,ap_pat,ap_mat,names,phone,correo,direccion,p_id,m_id);
    if(!head){
        head=nuevo;
        return;
    }
    Contacto* current=head;
    while(current->next)
        current=current->next;
    current->next=nuevo; 
    nuevo->prev=current;
    saveFile();
}
void Agenda::searchDataId(int id2){
    Contacto* current=head;
    while(current){
        if(current->id==id2){
            cout<<"Nombres    : "<<current->names<<endl;
            cout<<"A. Paterno :"<<current->ap_pat<<endl;
            cout<<"A. Materno :"<<current->ap_mat<<endl;
            cout<<"Telefono   : "<<current->phone<<endl;
            cout<<"Correo     :"<<current->correo<<endl;
            cout<<"Direccion  :"<<current->direccion<<endl;
            cout<<"Padre      :"<<searchId(current->p_id)<<endl;
            cout<<"Madre      :"<<searchId(current->m_id)<<endl;
            return;
        }
        current=current->next;
    }
    cout<<"Registro no encontrado"<<endl;
}
void Agenda::popId(int id_p){
    Contacto* current=head;
    while(current){
        if(current->id==id_p){ 
            if(current->prev) 
                current->prev->next=current->next; 
            else
                head=current->next; 
            if(current->next)
                current->next->prev=current->prev;
            delete current; 
            current=nullptr; 
            saveFile();
            cout<<"Registro eliminado con exito"<<endl;
            return; 
        }
        current=current->next;
    }
    cout<<"ID no encontrado.\n"; 
}
void Agenda::modifyId(int idb){
    Contacto* current=head;
    while(current){
        if(current->id==idb){
            cout<<"Registro encontrado"<<endl; 
            cout<<"Nombres    : "<<current->names<<endl;
            cout<<"A. Paterno :"<<current->ap_pat<<endl;
            cout<<"A. Materno :"<<current->ap_mat<<endl;
            cout<<"Telefono   : "<<current->phone<<endl;
            cout<<"Correo     :"<<current->correo<<endl;
            cout<<"Direccion  :"<<current->direccion<<endl;
            cout<<"Padre      :"<<searchId(current->p_id)<<endl;
            cout<<"Madre      :"<<searchId(current->m_id)<<endl;
            cout<<endl;
            char choice;
            cout<<"Desea modificar estos datos? (y/n): ";
            cin>>choice;
            cin.ignore();
            if(choice=='y' || choice=='Y'){
                cout<<"Actualice los datos:"<<endl;
                string nombre,ap_pat,ap_mat,phone,correo,direccion;
                char op;
                int id_p,id_m;
                cout<<"Nombre completo: ";
                getline(cin,nombre); 
                cout<<"Apeliido Paterno: ";
                getline(cin,ap_pat);
                cout<<"Apeliido Materno: ";
                getline(cin,ap_mat);
                do{
                    cout<<"Telefono: ";
                    getline(cin,phone);
                    if(!verifyPhone(phone))
                        cout<<"Error, el formato de telefono no es valido"<<endl;
                }while(!verifyPhone(phone));
                do{
                    cout<<"Correo: ";
                    getline(cin,correo);
                    if(!verifyMail(correo))
                        cout<<"Error, el formato de correo no es valido"<<endl;
                }while(!verifyMail(correo));
                cout<<"Direccion: ";
                getline(cin,direccion);
                cout<<"¿Asociar contactos paternos? (y/n): ";
                cin>>op;
                if(op=='y' || op=='Y'){
                    cout<<"ID del padre: ";
                    cin>>id_p; 
                    cout<<"ID de la madre: ";
                    cin>>id_m; 
                    cin.ignore();
                }else if(op=='n' || op=='N'){
                    id_p=0;
                    id_m=0;
                } 
                cin.ignore();
                
                current->names=nombre;
                current->ap_pat=ap_pat;
                current->ap_mat=ap_mat;
                current->phone=phone;
                current->correo=correo;
                current->direccion=direccion;
                current->p_id=id_p;
                current->m_id=id_m;
                cout<<"Datos modificados con exito"<<endl;
                return;
            }else if(choice=='n' || choice=='N')
                return;
            else{
                cout<<"Opcion no valida"<<endl;
                return;
            }
        }
        current=current->next;
    }
    cout<<"ID no encontrado"<<endl;
}
bool Agenda::verifyMail(string correo){
    const regex patron(R"((\w+)(\.{1}\w+)*@(\w+)(\.\w+)+)");
    return regex_match(correo,patron);
}
bool Agenda::verifyPhone(string phone){
    const regex patron(R"(\+?[0-9]{7,15})");
    return regex_match(phone,patron);
}
void Agenda::saveFile(){
    ofstream archivo("data.txt");
    Contacto* current=head;
    while(current){
        archivo<<current->id<<"/"<<current->ap_pat<<"/"<<current->ap_mat<<"/"
        <<current->names<<"/"<<current->phone<<"/"<<current->correo<<"/"
        <<current->direccion<<"/"<<current->p_id<<"/"<<current->m_id<<endl;
        current=current->next;
    }
    archivo.close();
}
void Agenda::recoverData(){
    ifstream archivo("data.txt"); 
    string linea;
    while(getline(archivo,linea)){ 
        stringstream ss(linea); 
        string campo; 
        int id,p_id,m_id;
        string ap_pat,ap_mat,name,phone,correo,direccion;
        getline(ss,campo,'/');
        id=stoi(campo);
        getline(ss,ap_pat,'/');
        getline(ss,ap_mat,'/');
        getline(ss,name,'/');
        getline(ss,phone,'/');
        getline(ss,correo,'/');
        getline(ss,direccion,'/');
        getline(ss,campo,'/'); 
        p_id=stoi(campo);
        getline(ss,campo,'/'); 
        m_id=stoi(campo); 
        Contacto* nuevo=new Contacto(id,ap_pat,ap_mat,name,phone,correo,direccion,p_id,m_id);
        if(!head){
            head=nuevo;
        }else{
            Contacto* current=head;
            while(current->next)
                current=current->next;
            current->next=nuevo;
            nuevo->prev=current;
        }
        if(id>=id_current)
            id_current=id+1;
    }
    archivo.close();
}
void Agenda::resetData(){
    Contacto* current=head;
    while(current){
        Contacto* aux=current;
        current=current->next;
        delete aux;
    }
    head=nullptr;
    ofstream archivo("data.txt");
    archivo.close();
}
Agenda::~Agenda(){
    Contacto* current=head;
    while(current){
        Contacto* aux=current;
        current=current->next;
        delete aux;
    }
}
void menu(){
    Agenda lista;
    int opcion;
    while(true){
        //lista.recoverData();
        system("cls");
        cout<<"\n----------  ----------\n";
        cout<<"---------------------------------------"<<endl;
        cout<<"1. Cargar registros desde el archivo\n";
        cout<<"---------------------------------------"<<endl;
        cout<<"2. Agregar nuevo contacto\n";
        cout<<"3. Eliminar por ID\n";
        cout<<"4. Buscar por ID\n";
        cout<<"5. Modificar por ID\n";
        cout<<"6. Mostrar registro\n";
        cout<<"7. Reiniciar datos\n";
        cout<<"8. Salir\n";
        cout<<"---------------------------------------"<<endl;
        cout<<"Seleccione una opcion\n";
        cin>>opcion;
        cin.ignore(); 
        if(opcion==1){
            system("cls");
            lista.recoverData();
            cout<<"Datos recuperados con exito"<<endl;
            getch();
        }
        else if(opcion==2){
            system("cls");
            string nombre,ap_pat,ap_mat,phone,correo,direccion;
            char op;
            int id_p,id_m;
            cout<<"Nombre completo: ";
            getline(cin,nombre); 
            cout<<"Apeliido Paterno: ";
            getline(cin,ap_pat);
            cout<<"Apeliido Materno: ";
            getline(cin,ap_mat);
            do{
                cout<<"Telefono: ";
                getline(cin,phone);
                if(!lista.verifyPhone(phone))
                    cout<<"Error, el formato de telefono no es valido"<<endl;
            }while(!lista.verifyPhone(phone));
            do{
                cout<<"Correo: ";
                getline(cin,correo);
                if(!lista.verifyMail(correo))
                    cout<<"Error, el formato de correo no es valido"<<endl;
            }while(!lista.verifyMail(correo));
            cout<<"Direccion: ";
            getline(cin,direccion);
            cout<<"¿Asociar contactos paternos? (y/n): ";
            cin>>op;
            if(op=='y'){
                cout<<"ID del padre: ";
                cin>>id_p; 
                cout<<"ID de la madre: ";
                cin>>id_m; 
                cin.ignore();
            }else if(op=='n'){
                id_p=0;
                id_m=0;
            } 
            cin.ignore();
            lista.add(ap_pat,ap_mat,nombre,phone,correo,direccion,id_p,id_m);
        }
        else if(opcion==3){
            system("cls");
            int id;
            char opcion;
            cout<<"ID a eliminar: ";
            cin>>id; 
            cout<<"Contacto a eliminar: "<<endl;
            lista.searchDataId(id);
            cin.ignore();
            cout<<"Seguro de la accion? (y/n): ";
            cin>>opcion;
            if(opcion=='y' || opcion=='Y'){
                lista.popId(id);
                cout<<"Contacto eliminado"<<endl;
            }else if(opcion=='n' || opcion=='N')
                cout<<"Accion revocada"<<endl;
            else
                cout<<"Opcion invalida"<<endl;
            getch();
        }
        else if(opcion==4){
            system("cls");
            int id;
            cout<<"ID a buscar: ";
            cin>>id;
            cin.ignore();
            lista.searchDataId(id);
            getch();
        }
        else if(opcion==5){
            system("cls");
            int id;
            cout<<"ID a modificar: ";
            cin>>id;
            cin.ignore();
            lista.modifyId(id);
            getch();
        }
        else if(opcion==6){
            system("cls");
            lista.show();
            getch();
        }
        else if(opcion==7){
            system("cls");
            char choice;
            cout<<"Seguro que desea reiniciar los datos? (y/n): ";
            cin>>choice;
            cin.ignore();
            if(choice=='y' || choice=='Y'){
                lista.resetData();
                cout<<"Datos reiniciados con exito"<<endl;
            }else if(choice=='n' || choice=='N'){

            }
            getch();
        }
        else if(opcion==8){
            system("cls");
            cout<<"Gracias por usar el sistema\n";
            break;
        }
        else{
            system("cls");
            cout<<"Opción no valida, intente nuevamente\n";
            getch();
        }
    }
}

int main(){
    //Agenda l1;
    //l1.add("Gomez", "Cruz", "Adrian", "5512345678", "adriangomez@gmail.com", "Av. Reforma 123", 7, 0);
    //l1.add("Martinez", "Lopez", "Elena", "5523456789", "elenamtz@gmail.com", "Calle Juarez 45", 102, 4);
    //l1.add("Rodriguez", "Sosa", "Carlos", "5534567890", "carlosrod@gmail.com", "Paseo del Sol 78", 6, 7);
    //l1.add("Hernandez", "Perez", "Sofia", "5545678901", "sofiahdez@gmail.com", "Colonia Centro 12", 1, 2);
    //l1.add("Villalobos", "Ruiz", "Javier", "5556789012", "javivilla@gmail.com", "Ruta 66 Km 5", 105, 205);
    //l1.add("Ortega", "Blanco", "Lucia", "5567890123", "luciaort@gmail.com", "Av. Universidad 500", 106, 9);
    //l1.add("Torres", "Mendez", "Ricardo", "5578901234", "ricktorres@gmail.com", "Calle del Hierro 9", 2, 4);
    //l1.add("Castillo", "Luna", "Fernanda", "5589012345", "fercas@gmail.com", "Mirador 302", 1, 2);
    //l1.add("Reyes", "Guzman", "Mauricio", "5590123456", "maureyes@gmail.com", "Privada Sauces 4", 121, 209);
    //l1.add("Peralta", "Domínguez", "Valeria", "5501234567", "valperalta@gmail.com", "Eje Central 88", 7, 8);
    //cout<<"---------------------------------------------"<<endl;
    //l1.show();
    menu();
    return 0;
}
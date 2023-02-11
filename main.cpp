#include<iostream>
#include<cstdlib>
#include<string.h>
#define maxchar 35

using namespace std;

/*Declara los nodos*/
struct nodo{
    int id;
    char nombres[maxchar];
    char apellidos[maxchar];
    struct nodo *sgte;
};


typedef struct nodo *PLista;

/*void de menu*/
void menu(void){

    cout<<"\t---------Datos de Empleado-------------\n";
    cout<<" 1.Agregar empleado."<<endl;
    cout<<" 2. Mostrar registros."<<endl;
    cout<<" 3. Salir"<<endl;
    cout<<"\n Opcion: ";

}



void Agregar(PLista &lista){
/*Creamos el nuevo nodo*/
    PLista t,q = new(struct nodo);
    /*Registro de los datos*/
    cout<<"\n\t----------Registro--------\n";
    cin.ignore();cout<<"\n\n\tID empleado:"; cin>>q->id;
    cin.ignore();cout<<"\n\tNombre:"; cin.getline(q->nombres,maxchar);
    cin.ignore();cout<<"\tApellido:"; cin.getline(q->apellidos,maxchar);
    system("cls");

    q->sgte = NULL;

    if(lista==NULL){
        lista = q;

    } else {

        t = lista;
        while(t->sgte!=NULL){
            t = t->sgte;

        }

        t->sgte = q;
    }
}


void Mostrar(PLista q){

    int i=1;

    while(q!=NULL){

        cout<<"\n\tEmpleado N°"<<i;
        cout<<"\n\tID: "<<q->id<<endl;
        cout<<"\tNombre: "<<q->nombres<<endl;
        cout<<"\tApellido: "<<q->apellidos<<endl;

        q=q->sgte;
        i++;
    }
}


int main(void){

    PLista lista=NULL;
    int opcion;

    do{
        menu();
        cin>>opcion;

        switch(opcion){

            case 1: Agregar(lista);
                break;
            case 2: if(lista==NULL){
                    cout<<"\tLa lista esta vacia.\n";

                }else {
                    Mostrar(lista);
                }
                break;
            case 3: return 0;
            default: cout<<"\nIngrese otra opcion.\n"; break;

        }

    }while(opcion!=3);

    return 0;
}
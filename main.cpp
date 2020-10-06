#include <iostream>

using namespace std;
struct vox{
    string v;
    int exp;
    string fecha;
    vox *sgt;
};
vox *peek = NULL;
void push(string nya, int e, string f){
    vox *nvox =  new vox;

    nvox-> v = nya ;
    nvox -> exp = e;
    nvox -> fecha = f;

    nvox->sgt=peek;
    peek=nvox;
}

void pop(){
    if(peek==NULL)
        cout<<"Nada que imprimir, Stack vacia \n";
    else
        peek=peek->sgt;
}
void prt(){
    vox *aux = peek;
    if(aux==NULL)
        cout<<"Nada que imprimir, Stack vacia\n";
    else
        while(aux!=NULL){
            cout<<aux->v<<" -> ";
            cout<<aux->exp<<" -> ";
            cout<<aux->fecha<<" -> ";
            aux=aux->sgt;
        }
}
int main(){
    int op, x;
    string nya;
    int e;
    string f;

    do{
        cout<<"\n(1) Push    (2) Pop    (3) Print   (4) Salir \n ";
        cout<<"\n Elija opción  ?: ",cin>>op;
        switch (op){
            case 1:
                cout<<"Ingresa tu nombre y apellido (todo junto):  ",cin>>nya;
                cout<<"Ingresa tu número de expediente: ",cin>>e;
                cout<<"Ingresa tu fecha de nacimiento (dia/mes/año): ",cin>>f;
                push(nya, e, f);
                break;
            case 2:
                cout<<"Eliminando ..... : ";
                pop();
                break;
            case 3:
                cout<<"Imprimiendo..... : ";
                prt();
                break;
            case 4:
                cout<<"------Bye--------";
        }
    }while(op!=4);
}
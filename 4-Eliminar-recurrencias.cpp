#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *ant;
    nodo *sig;
};

class ListaDoble{
    private:
        nodo *pInicio;
    
    public:
        ListaDoble();
        ~ListaDoble();
        void insertarEnLista(void);
        void insFinal(int);
        void mostrarLista(void);
        void EliminarOcurrencias(int);
};

ListaDoble::ListaDoble(void)
{
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void)
{
    nodo *p;

    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertarEnLista(void)
{
    int dato = 0;

    cout << "Digite un entero o Ctrl-Z para terminar: ";
    while(cin >> dato){
        insFinal(dato);
        cout << "Digite un entero o Ctrl-D para terminar: ";
    }
}

void ListaDoble::insFinal(int dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    if(!pInicio){
        nuevo->ant = NULL;
        pInicio = nuevo;
    }else{
        nodo *s = pInicio;

        while(s->sig)
            s = s->sig;
        
        s->sig = nuevo;
        nuevo->ant = s;
    }
}

void ListaDoble::mostrarLista(void)
{
    nodo *p = pInicio;
    if(!p){
        cout << endl << "La lista esta vacia!" << endl;
        return;
    }
    cout << endl << "Los elementos de la lista son: ";
    while(p){
        cout << p->dato << " ";
        p = p->sig;
    }
    cout << endl;
}

void ListaDoble::EliminarOcurrencias(int datoRef)
{
    nodo *s = pInicio;

    while(s){
        if(s->dato == datoRef){
            if(s == pInicio){
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                s = pInicio;
                delete s;
            }else{
                nodo *aux = s;
                s->ant->sig = s->sig;
                if(s->sig)
                    s->sig->ant = s->ant;
                s = s->sig;
                delete aux;
            }
    }
}

int main(void)
{
    int opcion = 0, datoRef = 0;
    bool continuar = true;
    ListaDoble objListaDoble;

    cout << endl << "ELIMINAR POR BUSQUEDA EL NODO ANTERIRO AL DATO DE REFERENCIA" << endl;

    while(continuar){
        cout << "\n\t***** Menu de opciones *****" << endl;
        cout << "1) Agregar elementos al final (Cola)" << endl;
        cout << "2) Mostrar la lista" << endl;
        cout << "3) Eliminar dato. Se eliminaran todas las ocurrencias" << endl;
        cout << "4) Salir del programa" << endl << endl;
        cout << "Ingresa la opcion: ";
        cin.clear();
        cin >> opcion;

        switch(opcion){
            case 1:
                cout << endl << "Insertando datos al final de la lista" << endl;
                objListaDoble.insertarEnLista();
                break;
            case 2:
                objListaDoble.mostrarLista();
                break;
            case 3:
                cout << endl << "Ingresa el dato a borrar: ";
                cin >> datoRef;
                objListaDoble.EliminarOcurrencias(datoRef);
                break;
            case 4:
                cout << endl << "Fin del programa" << endl << endl;
                continuar = false;
                break;
            default:
                cout << endl << "Opcion Invalida!" << endl;
                break;
        }
    }
    return 0;
}

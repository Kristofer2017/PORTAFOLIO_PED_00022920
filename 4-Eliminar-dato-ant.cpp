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
        bool buscarEnLista(int);
        void EliminarElemento(int);
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

bool ListaDoble::buscarEnLista(int datoB)
{
    nodo *s = pInicio;

    while (s && s->dato != datoB)
        s = s->sig;
    if(s)
        return true;
    else
        return false;
}

void ListaDoble::EliminarElemento(int datoRef){
    if(!pInicio){
        cout << endl << "Dato no elimindao, la lista esta vacia!" << endl;
    }else if(pInicio->dato == datoRef){
        cout << endl << "Dato no eliminado, no hay elementos antes del dato ingresado" << endl;
    }else if(buscarEnLista(datoRef)){ //Aseguramos que el dato esta en la lista
        nodo *s = pInicio;
        while(s->sig && s->sig->dato != datoRef)
            s = s->sig;
        if(s == pInicio){ //Si vamos a eliminar el primer nodo
            pInicio = pInicio->sig;
            delete s;
            pInicio->ant = NULL;
            cout << endl << "Dato eliminado!" << endl;
        }else{ // Si el dato existe, estamos parados uno antes de el, y no eliminaremos pInicio
            s->ant->sig = s->sig;
            s->sig->ant = s->ant;
            delete s;
            cout << endl << "Dato eliminado!" << endl;
        }
    }else{
        cout << endl << "Dato no eliminado, no se encontro el elemento" << endl;
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
        cout << "3) Buscar elemento" << endl;
        cout << "4) Eliminar dato antes de un elemento en especifico" << endl;
        cout << "5) Salir del programa" << endl << endl;
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
                cout << "Ingrese el dato a buscar: ";
                cin >> datoRef;
                if(objListaDoble.buscarEnLista(datoRef))
                    cout << endl << "El dato SI se encuentra en la lista" << endl;
                else
                    cout << endl << "El dato NO se encuentra en la lista" << endl;
                break;
            case 4:
                cout << endl << "Ingresa un dato de referencia: ";
                cin >> datoRef;
                objListaDoble.EliminarElemento(datoRef);
                break;
            case 5:
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

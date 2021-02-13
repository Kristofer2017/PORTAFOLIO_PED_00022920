#include <iostream>
#include <cstring>
using namespace std;

struct pedido{
   string nombrePlato, composicion;
   int id;
   float costo;
};

struct nodo{
    pedido dato;
    nodo *sig;
};

class ListaSimple{
    private:
        nodo *pInicio;
    
    public:
        ListaSimple();
        ~ListaSimple();
        void insertarEnLista(void);
        void insertarPrincipio(pedido);
        void mostrarLista(void);
        void buscarEnLista(int);
        void EliminarElemento(int);
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

ListaSimple::~ListaSimple(void)
{
    nodo *p;

    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaSimple::insertarEnLista(void)
{
   int opcion = 0;
   pedido elPedido;

   do{
      cout << "Ingrese el nombre del plato: ";
      cin.ignore(1000, '\n');
      getline(cin, elPedido.nombrePlato, '\n');
      cout << "Ingrese el costo del plato ($): ";
      cin >> elPedido.costo;
      cout << "Ingrese la composicion del plato: ";
      cin.ignore(1000, '\n');
      getline(cin, elPedido.composicion, '\n');
      cout << "Ingrese el ID del plato: ";
      cin >> elPedido.id;
      
      insertarPrincipio(elPedido);
      
      cout << "1-> Ingresar mas datos | 2-> Volver al menu: ";
      cin >> opcion;
   }while(opcion == 1);
}

void ListaSimple::insertarPrincipio(pedido elPedido)
{
    nodo *nuevo = new nodo;
    nuevo->dato = elPedido;
    nuevo->sig = NULL;

    if(!pInicio){
        pInicio = nuevo;
    }else{
        nodo *s = pInicio;

        while(s->sig)
            s = s->sig;
        
        s->sig = nuevo;
    }
}

void ListaSimple::mostrarLista(void)
{
   nodo *p = pInicio;
   if(!p){
      cout << endl << "No hay platos para mostrar!" << endl;
      return;
   }
   cout << endl << "Mostrando los platos en la pila:" << endl;
   while(p){
      cout << endl << "Nombre del plato: " << p->dato.nombrePlato;
      cout << endl << "Costo del plato: " << p->dato.costo;
      cout << endl << "Composicion del plato: " << p->dato.composicion;
      cout << endl << "ID: " << p->dato.id;
      cout << endl;
      p = p->sig;
   }
}

void ListaSimple::buscarEnLista(int datoRef)
{
   nodo *s = pInicio;

   while (s && s->dato.id != datoRef)
      s = s->sig;
   
   if(s){
      cout << endl << "El plato se ha encontrado!" << endl;
      cout << endl << "Nombre del plato: " << s->dato.nombrePlato;
      cout << endl << "Costo del plato: $" << s->dato.costo;
      cout << endl << "Composicion del plato: " << s->dato.composicion;
      cout << endl << "ID: " << s->dato.id << endl;
   }else{
      cout << endl << "No se ha encontrado el plato" << endl;
   }
}

int main(void)
{
   int opcion = 0, datoRef = 0;
   bool continuar = true;
   ListaSimple objListaSimple;

   cout << endl << "MANEJO DE UN MENU DE PLATOS PARA UN RESTAURANTE" << endl;

   while(continuar){
      cout << "\n\t***** Menu *****" << endl;
      cout << "1) Agregar un nuevo plato" << endl;
      cout << "2) Mostrar la pila de platos" << endl;
      cout << "3) Buscar plato por ID" << endl;
      cout << "4) Salir del programa" << endl << endl;
      cout << "Ingresa la opcion: ";
      cin.clear();
      cin >> opcion;

      switch(opcion){
         case 1:
            cout << endl;
            objListaSimple.insertarEnLista();
            break;
         case 2:
            objListaSimple.mostrarLista();
            break;
         case 3:
            cout << "Ingresa el ID del plato a buscar: ";
            cin >> datoRef;
            objListaSimple.buscarEnLista(datoRef);
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

#include<iostream>
using namespace std;

//Pila
struct Nodo{
    int dato;
    Nodo *siguiente;
};


//Prototipo de funciones 


void agregar(Nodo *&,int);
void sacar(Nodo *&,int &);
void disponibilidad();

int main()
{   
	//creamo la pila
	Nodo *pila = NULL;
    int dato=0;
	int opc;
	int cont=0;
	do{
		cout<<"1.Ingresar"<<endl;
		cout<<"2.Sacar (Salir)\n"<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		
 		switch(opc)
		{
			case 1:
				
				cout<<"Ingrese el codigo de la caja"<<endl; 
				cin>>dato;
				if(dato>99999999) //validar para que no se pase de los 8 digitos 
				cout<<"el codigo excede los 8 digitos"<<endl;
			
			else if(dato<10000000) //validar para que no sea menor de  8 digitos 
				cout<<"el codigo es menor de los 8 digitos"<<endl;
			else
				agregar(pila,dato);
				
  		    break;
  			
  			case 2:
  				
  				while(pila!=NULL){
				  sacar(pila,dato);
				  	if(pila!=NULL)
					{
				  		cout<<dato<<" , ";
        			}
					else{
					cout<<dato<<" . ";
        			}
    			}
    		break;
    		default:
    			cout<<"Opcion no valida"<< endl;
    		break;
  
 }
}while(opc!=2);
   

}


void agregar(Nodo *&pila,int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->siguiente = pila;
    pila=nuevo_nodo;
    cout<<"\nElmento "<<n<< " ingresada correctamente\n"<<endl;
}

void sacar(Nodo *&pila,int &n){
    Nodo *aux=pila;
    n=aux->dato;
    pila=aux->siguiente;
    delete aux;
}



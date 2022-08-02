#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char tString[30];

typedef struct 
{
	int codProducto, codRubro, cantidad;
	tString descripcion;
	float precioUnitario;
}tElem;

typedef struct nodo
{
	tElem datos;
	struct nodo * siguiente;
}tPila;

tPila * pila;

void InicializarPila();
bool PilaVacia();
void Apilar(tElem);
void Desapilar();
void VisualizarElementos();
float MontoRecaudado();
void Menu();
tElem Cima();

void InicializarPila()
{
	pila = NULL;
}

bool PilaVacia()
{
	return (pila == NULL);
}

void Apilar(tElem pDatos)
{
	tPila *nuevoNodo;
	nuevoNodo = pila;
	pila = (tPila *) malloc(sizeof(tPila));
	pila->datos.codProducto = pDatos.codProducto;
	pila->datos.codRubro = pDatos.codRubro;
	pila->datos.cantidad = pDatos.cantidad;
	strcpy(pila->datos.descripcion, pDatos.descripcion);
	pila->datos.precioUnitario = pDatos.precioUnitario;
	pila->siguiente = nuevoNodo;
	printf("Elemento insertado!\n");
}

void Desapilar()
{
	if(PilaVacia() == true)
	{
	printf("No hay elementos en la pila!\n\n");
	system("pause");
	system("cls");
	}
	else
	{
	tPila *nodoSuprimir;
	nodoSuprimir = pila;
	pila = pila->siguiente;
	free(nodoSuprimir);
	printf("Elemento eliminado!\n");
	}	
	system("pause"); system("cls");
}

void VisualizarElementos()
{
	tPila *aux;
	aux = pila;
	if(!PilaVacia())
	{
		printf("Elementos en la pila:\n\n");
		while (aux != NULL)
		{
			printf("Codigo de Producto: %d\nCodigo de rubro: %d\nCantidad: %d\nPrecio Unitario: %.2f\nDescripcion: %s\n\n", aux->datos.codProducto, aux->datos.codRubro, aux->datos.cantidad, aux->datos.precioUnitario, aux->datos.descripcion);
			aux = aux->siguiente;
		}
		system("pause"); system("cls");
	}
	else
	printf("La pila esta vacia\n");
}

float MontoRecaudado()
{
	float total;
	tPila *aux;
	aux = pila;
	if(!PilaVacia())
	{
		while(aux != NULL)
		{
			total = total + (aux->datos.precioUnitario*aux->datos.cantidad);
			aux = aux->siguiente;
		}
		printf("El monto recaudado es: %.2f\n\n", total);			
	}
	system("pause"); system("cls");
	return total;
}

tElem Cima()
{
	tElem datosCima;
	datosCima.codProducto = pila->datos.codProducto;
	datosCima.codRubro = pila->datos.codRubro;
	datosCima.cantidad = pila->datos.cantidad;
	strcpy(datosCima.descripcion, pila->datos.descripcion);
	datosCima.precioUnitario, pila->datos.precioUnitario;
	return datosCima;
}

void Menu()
{
	int opcion;
	tElem dato, datosC;
	printf("Menu de opciones:\n");
	printf("1-Agregar datos\n");
	printf("2-Desapilar un elemento\n");
	printf("3-Elemento de la cima\n");
	printf("4-Visualizar elementos de la pila\n");
	printf("5-Monto recaudado\n");
	printf("Elija una opcion: ");
	
	scanf("%d", &opcion); fflush(stdin);
	system("cls");
	
	while (opcion != 0)
	{
		switch (opcion)
		{
			case 1:
				{
					char respuesta;
					do
					{					
					printf("Ingrese codigo de producto:\n");
					scanf("%d", &dato.codProducto); fflush(stdin);
					printf("Ingrese codigo de rubro:\n");
					scanf("%d", &dato.codRubro); fflush(stdin);
					printf("Ingrese cantidad:\n");
					scanf("%d", &dato.cantidad); fflush(stdin);
					printf("Ingrese el precio unitario:\n");
					scanf("%f", &dato.precioUnitario); fflush(stdin);
					printf("Ingrese descripcion del producto:\n");
					scanf("%s", &dato.descripcion); fflush(stdin);
					
					Apilar(dato);
					printf("Desea seguir ingresando datos? s/n\n");
					scanf("%s", &respuesta); fflush(stdin);
					}while (respuesta != 'n');
					system("pause");
					system("cls");
					Menu();
				}
				break;
				
				case 2:
					{
						Desapilar();
						Menu();						
					}
					break;
				
				case 3:
					{						
						datosC = Cima();
						printf("Elemento de la cima:\nCodigo de Producto: %d\nCodigo de rubro: %d\nCantidad: %d\nDescripcion: %s\nPrecio Unitario: %.2f\n", datosC.codProducto, datosC.codRubro, datosC.cantidad, datosC.descripcion, datosC.precioUnitario);
						system("pause");
						Menu();
					}
					break;
					
				case 4:
					{
						VisualizarElementos();
						Menu();
					}
					break;
				
				case 5:
					{
						MontoRecaudado();
						Menu();
					}
		}
	printf("Menu de opciones:\n");
	printf("1-Agregar datos\n");
	printf("2-Desapilar un elemento\n");
	printf("3-Elemento de la cima\n");
	printf("4-Visualizar elementos de la pila\n");
	printf("5-Monto recaudado\n");
	printf("Elija una opcion: ");
	
	scanf("%d", &opcion); fflush(stdin);
	system("cls");	
	}
}

int main()
{
	InicializarPila();
	Menu();
	return 0;
}





















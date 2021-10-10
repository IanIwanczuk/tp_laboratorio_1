#include "ArrayEmployees.h"
#include "functions.h"
#define TAM 51
#define QTYEMPL 6

int main(void) {
	setbuf(stdout, NULL);
	Employee listaEmployees[QTYEMPL] = {{1010, "Ian", "Iwanczuk", 85000, 1, CARGADO},{1011, "Juan", "Gomez", 15830, 1, CARGADO},	{1012, "Ada", "Arrazo", 73796, 4, CARGADO},{1013, "Maria", "Gomez", 34376, 2, CARGADO},{1014, "Aaron", "Gomez", 53742, 4, CARGADO},{1015, "Polimorfica", "Gomez", 24367, 3, CARGADO}};
	initEmployees(listaEmployees, QTYEMPL);
	char opcion[TAM];
	int flagEmptyMsg;
	int flagEmptyList;
	int intOpcion;
	int countId;
	int removeById;
	flagEmptyMsg = 1;
	countId = 1000;

	do {
		EmptySpaces(listaEmployees, QTYEMPL, &flagEmptyList);
		if(flagEmptyList == VACIO && flagEmptyMsg == 1){
			printf(">>> La lista esta vacia.\n");
		}
		printf("_________________________\n"
			   "1| ALTA empleado. %8s\n"
			   "2| BAJA empleado. %8s\n"
			   "3| MODIFICAR empleado. %3s\n"
			   "4| INFORMAR (Submenu). %3s\n"
			   "0| Salir. %16s\n"
			   "_|_______________________|\n", "|", "|", "|", "|", "|");

		GetOption(opcion, TAM, &intOpcion);
		while(intOpcion < 0 || intOpcion > 4){
			printf(">>> Error. Ingrese un numero valido.\n");
			GetOption(opcion, TAM, &intOpcion);
		}
		printf("\n");

		if(flagEmptyList == VACIO && intOpcion != 0 && intOpcion != 1){
			printf(">>> La lista esta vacia.\n");
			flagEmptyMsg = 0;
		} else {
			switch (intOpcion){
				case 1:
					if(GetEmployee(listaEmployees, QTYEMPL, &countId) != 0){
						printf(">>> Error. La lista ya esta llena.\n");
					}
				break;

				case 2:
					SortById(listaEmployees, QTYEMPL);
					printEmployees(listaEmployees, QTYEMPL);
					GetIntNoVerification(">>> Ingrese el ID a eliminar: ", &removeById);
					if(removeEmployee(listaEmployees, QTYEMPL, removeById) == 0){
						printf(">>> Se elimino el empleado con exito.\n");
					}
				break;

				case 3:
					if(ModifyEmployee(listaEmployees, QTYEMPL, TAM) == -1){
						printf(">>> Ocurrio un error inesperado.\n");
					}
				break;

				case 4:
					printf(">>> Submenu INFORMAR.\n");
					InformSubMenu(listaEmployees, QTYEMPL, TAM, &intOpcion);
				break;

				case 0:
					printf(">>> Exit.\n");
				break;
			}
		}
	} while(intOpcion != 0);
	return 0;
}

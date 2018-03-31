//Programa para reservar plaza de aparcamiento, dejarla libre o ver su estado, pone la hora en el menu, 
//colores personalizados, tambien pone el precio dependiendo del tiempo.
// Desarrolador: Miguel Jiménez Sarria



#include <stdio.h>
#include <stdlib.h> 
#include <windows.h> 
#include <time.h>

struct plaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipo; // M - Moto / C - Coche
	char matricula[8]; // Formato de la matrícula: NNNNLLL
	int inicio;
	int final;


};

#define NPLAZAS 10
#define NPLAZASM 10


void main() {

	struct plaza aparcamiento[NPLAZAS] = { 0,"C", "inicio" };
	struct plaza aparcamientom[NPLAZASM] = { 0,"M", "inicio" };

	char opcion;
	char matriculaaux[8];
	char tipo[20];

	int libre = 1;
	int librem = 1;
	float precio;
	int salir = 0;
	char usuario[8];
	char contrasena[8];
	char principio = 0;
	int numero = 1, estado = 1, buscar = 1, numerom = 1, estadom = 1, buscarm = 1;
	aparcamiento[NPLAZAS].estado = 0;
	aparcamientom[NPLAZASM].estado = 0;

	system("color 0A");
	





	for (principio; principio < 3; principio++) {


		printf("Introduzca el usuario: ");

		gets(usuario);


		printf("Introduzca la contraseña: ");
		gets(contrasena);

		if (strcmp(usuario, "admin") == 0 && strcmp(contrasena, "admin") == 0) {

			printf("Usuario correcto\n\n");

			break;

		}

		else {

			printf("Usuario o contraseña no valido\n");

		}

	}


	if (principio == 3) {

		printf("Ha usado todos los intentos\n");
		Sleep(2000);
		salir = 1;
	}



	while (salir == 0) {

		system("color 0A");
		printf("MENU\n\n");



		time_t result = time(NULL);
		char str[26];
		ctime_s(str, sizeof str, &result);
		printf("%s\n", str);







		opcion = 'A';
		printf("Seleccione una de estas opciones:\n");
		printf("R - Reservar plaza\n");
		printf("A - Abandonar plaza\n");
		printf("E - Estado del aparcamiento\n");
		printf("B - Buscar vehiculo por matricula\n");
		printf("S - Salir del aparcamiento\n");



		//getchar();
		scanf_s("%c", &opcion, 1);


		if (opcion >= 'a' && opcion <= 'z') {

			opcion -= 32;

		}


		switch (opcion) {

		case 'R':


			printf("Elija el tipo de vehiculo, moto o coche\n");

			scanf_s("%s", tipo, 20);

			if (strcmp(tipo, "coche") == 0) {
				for (numero; numero <= NPLAZAS; numero++) {

					if (aparcamiento[numero].estado == 0) {

						printf("Reservando plaza %d para coches\n", numero);

						printf("Ponga el numero de matricula\n");

						getchar();

						gets(aparcamiento[numero].matricula);

						printf("Ha reservado la plaza %d con la matricula %s\n", numero, aparcamiento[numero].matricula);

						aparcamiento[numero].inicio = time(NULL);


						aparcamiento[numero].estado = 1;





						Sleep(2000);
						break;

					}
				}
					if (aparcamiento[numero].estado == 1) {

						printf("Plaza %d para coches y las anteriores estan ocupadas\n", numero);


					}

				}


				if (strcmp(tipo, "moto") == 0) {

					for (numerom; numero <= NPLAZASM; numerom++) {

						if (aparcamientom[numerom].estado == 0) {

							printf("Reservando plaza %d para motos\n", numerom);

							printf("Ponga el numero de matricula\n");

							getchar();

							gets(aparcamientom[numerom].matricula);

							printf("Ha reservado la plaza %d con la matricula %s\n", numerom, aparcamientom[numerom].matricula);

							aparcamientom[numerom].inicio = time(NULL);


							aparcamientom[numerom].estado = 1;





							Sleep(2000);
							break;
						}

						if (aparcamientom[NPLAZASM].estado == 1) {

							printf("Lo sentimos no tenemos plazas libres\n");
							Sleep(2000);
						}
						

					}


				}






				numero = 1;
				numerom = 1;
				break;



		case 'A':


			printf("Elija el tipo de vehiculo, moto o coche\n");

			scanf_s("%s", tipo, 20);



			printf("Seleccione el numero de plaza que desea dejar libre\n");

			scanf_s("%d", &libre);
			libre = librem;

			if (strcmp(tipo, "coche") == 0) {

				if (aparcamiento[libre].estado == 1) {

					printf("Dejando la plaza %d con la matricula %s libre\n", libre, aparcamiento[libre].matricula);

					aparcamiento[libre].estado = 0;

					aparcamiento[libre].final = time(NULL);
					printf("Tiempo: %d segundos\n", aparcamiento[libre].final - aparcamiento[libre].inicio);
					printf("Precio por segundo 0.2 euros\n");
					precio = 0.2*(aparcamiento[libre].final - aparcamiento[libre].inicio);
					printf("Total a pagar : %.2f euros\n", precio);
					Sleep(2000);
				}

				else {

					printf("La plaza %d ya esta libre\n", libre);

				}
			}

			if (strcmp(tipo, "moto") == 0) {

				if (aparcamientom[librem].estado == 1) {

					printf("Dejando la plaza %d con la matricula %s libre\n", librem, aparcamientom[librem].matricula);

					aparcamientom[librem].estado = 0;

					aparcamientom[librem].final = time(NULL);
					printf("Tiempo: %d segundos\n", aparcamientom[librem].final - aparcamientom[librem].inicio);
					printf("Precio por segundo 0.2 euros\n");
					precio = 0.2*(aparcamientom[librem].final - aparcamientom[librem].inicio);
					printf("Total a pagar : %.2f euros\n", precio);
					Sleep(2000);
				}

				else {

					printf("La plaza %d ya esta libre\n", librem);

				}
			}

			libre = 1;
			librem = 1;
			Sleep(2000);
			break;


		case 'E':

			printf("Comprobando estado del aparcamiento\n");

			for (estado; estado <= NPLAZAS; estado++) {
				if (aparcamiento[estado].estado == 0) {
					printf("La plaza %d esta LIBRE\n", estado);
				}

				else {
					printf("La plaza %d esta OCUPADA y tiene el numero de matricula %s\n", estado, aparcamiento[estado].matricula);

				}

			}
			for (estadom; estadom <= NPLAZASM; estadom++) {
				if (aparcamientom[estadom].estado == 0) {
					printf("La plaza %d para motos esta LIBRE\n", estadom);
				}

				else {
					printf("La plaza %d para motos esta OCUPADA y tiene el numero de matricula %s\n", estadom, aparcamientom[estadom].matricula);

				}

			}
			estado = 1;
			estadom = 1;
			Sleep(4000);
			break;



		case 'S':

			printf("Saliendo del aparcamiento\n");
			Sleep(1000);

			salir = 1;



			break;

		case 'B':

			printf("Elija el tipo de vehiculo que desea buscar: ");

			scanf_s("%s", tipo, 20);



			printf("Escriba la matricula del vehiculo que desea buscar: ");

			scanf_s("%s", matriculaaux, 8);


			if (strcmp(tipo, "coche") == 0) {
				printf("Buscando vehiculo con matricula %s\n", matriculaaux);


				for (buscar; buscar <= NPLAZAS; buscar++) {

					if (strcmp(aparcamiento[buscar].matricula, matriculaaux) == 0) {

						printf("El coche con la matricula %s esta aparcado en la plaza %d\n ", aparcamiento[buscar].matricula, buscar);

						Sleep(4000);

						break;
					}
				}
				if (buscar = NPLAZAS && strcmp(aparcamiento[NPLAZAS].matricula, matriculaaux) == 1) {

					printf("El coche con la matricula %s no esta en nuestro aparcamiento \n", matriculaaux);
					Sleep(3000);
				}

			}

			if (strcmp(tipo, "moto") == 0) {
				printf("Buscando moto con matricula %s\n", matriculaaux);


				for (buscarm; buscarm <= NPLAZASM; buscarm++) {

					if (strcmp(aparcamientom[buscarm].matricula, matriculaaux) == 0) {

						printf("La moto con la matricula %s esta aparcado en la plaza %d\n ", aparcamientom[buscarm].matricula, buscarm);

						Sleep(4000);

						break;
					}
				}
				if (buscarm = NPLAZASM && strcmp(aparcamientom[NPLAZASM].matricula, matriculaaux) == 1) {

					printf("La moto con la matricula %s no esta en nuestro aparcamiento \n", matriculaaux);
					Sleep(3000);
				}

			}

			buscar = 1;
			buscarm = 1;
			break;

		default:

			printf("Esta opcion no esta permitida\n");

			break;


		}


			printf("Volviendo al menu\n");
			Sleep(500);
			system("cls");

		

	}
}
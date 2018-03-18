//Programa para reservar plaza de aparcamiento, dejarla libre o ver su estado, pone la hora en el menu, 
//colores personalizados, tambien pone el precio dependiendo del tiempo.
// Desarrolador: Miguel Jim�nez Sarria



#include <stdio.h>
#include <stdlib.h> 
#include <windows.h> 
#include <time.h>



void main() {




	char opcion;
	char matricula1[8];
	char matricula2[8];
	char matricula3[8];
	char matriculaaux[8];
	char tipo[20];
	char estado1[6] = "LIBRE";
	char estado2[6] = "LIBRE";
	char estado3[6] = "LIBRE";
	int estadoapar1 = 0;
	int estadoapar2 = 0;
	int estadoapar3 = 0;
	int libre = 0;
	float hora1;
	float hora2;
	float hora3;
	int inicio1, final1, inicio2, final2, inicio3, final3=0;
	float precio;
	int salir = 0;


	while (salir==0) {

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



			if (estadoapar1 == 0 && strcmp(tipo, "coche") == 0) {

				printf("Reservando plaza 1 para coches\n");
				printf("Ponga el numero de matricula\n");
				getchar();
				scanf_s("%s", matricula1, 8);

				



				estado1[8] = "OCUPADA";
				estadoapar1 = 1;
				printf("Ha reservado la plaza 1 con la matricula %s\n", matricula1);
				inicio1 = time(NULL);


				Sleep(2000);
				break;
			}

			if (estadoapar1 == 1) {

				printf("Plaza 1 para coches ocupada\n");


			}



			if (estadoapar2 == 0 && strcmp(tipo, "coche") == 0) {

				printf("Reservando plaza 2 para coches\n");
				printf("Ponga el numero de matricula\n");
				getchar();
				scanf_s("%s", matricula2, 8);
				estado2[8] = "OCUPADA";
				estadoapar2 = 1;
				printf("Ha reservado la plaza 2 con la matricula %s\n", matricula2);
				inicio2 = time(NULL);
				Sleep(2000);
				break;
			}

			if (estadoapar2 == 1) {

				printf("Plaza 2 para coches ocupada\n");


			}

			if (estadoapar3 == 0 && strcmp(tipo, "moto") == 0) {

				printf("Reservando plaza 3\n");
				printf("Ponga el numero de matricula\n");
				getchar();
				scanf_s("%s", matricula3, 8);
				estado2[8] = "OCUPADA";
				estadoapar3 = 1;
				printf("Ha reservado la plaza 3 con la matricula %s\n", matricula3);
				inicio3 = time(NULL);
				Sleep(2000);
				break;
			}


			if (estadoapar3 == 1) {

				printf("Plaza 3 para motos ocupada\n");


			}

			if (estadoapar3 == 1 && estadoapar2 == 1 && estadoapar1 == 1) {

			printf("Lo sentimos no tenemos plazas libres\n");
			Sleep(2000);
		}

		else {
		
			printf("Seleccione una opcion valida\n");

		}
			break;



		case 'A':


			printf("Elija 1 para dejar libre la plaza 1 para coches\n");
			printf("Elija 2 para dejar libre la plaza 2 para coches\n");
			printf("Elija 3 para dejar libre la plaza 3 para motos\n");
			scanf_s("%d", &libre);
			switch (libre)
			{
			case 1:

				if (estadoapar1 == 1) {
					printf("Dejando la plaza 1 libre\n");
					estado1[8] = "LIBRE";
					estadoapar1 = 0;
					final1 = time(NULL);
					printf("Tiempo: %d segundos\n", final1 - inicio1);
					printf("Precio por segundo 0.2 euros\n");
					precio = 0.2*(final1 - inicio1);
					printf("Total a pagar : %.2f euros\n", precio );
					Sleep(2000);
				}

				else {

					printf("La plaza 1 ya esta libre\n");

				}

				break;
			case 2:

				if (estadoapar2 == 1) {
					printf("Dejando la plaza 2 libre\n");
					estado2[8] = "LIBRE";
					estadoapar2 = 0;
					final2 = time(NULL);
					printf("Tiempo: %d segundos\n", final2 - inicio2);
					printf("Precio por segundo 0.2 euros\n");
					precio = 0.2*(final2 - inicio2);
					printf("Total a pagar : %.2f euros\n", precio);
					Sleep(2000);
				}

				else {

					printf("La plaza 2 ya esta libre\n");

				}

				break;


			case 3:

				if (estadoapar3 == 1) {
					printf("Dejando la plaza 3 libre\n");
					estado1[8] = "LIBRE";
					estadoapar1 = 0;
					final3 = time(NULL);
					printf("Tiempo: %d segundos\n", final3 - inicio3);
					printf("Precio por segundo 0.2 euros\n");
					precio = 0.2*(final3 - inicio3);
					printf("Total a pagar : %.2f euros\n", precio);
					Sleep(2000);
				}

				else {

					printf("La plaza 3 para motos ya esta libre\n");

				}

				break;
			default:

				printf("No tenemos esa opcion\n");

				break;
			}



			Sleep(2000);
			break;
		case 'E':

			printf("Comprobando estado del aparcamiento\n");

			if (estadoapar1 == 0) {
				printf("La plaza 1 esta LIBRE\n");
			}

			else {
				printf("La plaza 1 esta OCUPADA y tiene el numero de matricula %s\n", matricula1);

			}

			if (estadoapar2 == 0) {
				printf("La plaza 2 esta LIBRE\n");
			}

			else {
				printf("La plaza 2 esta OCUPADA y tiene el numero de matricula %s\n", matricula2);

			}

			if (estadoapar3 == 0) {
				printf("La plaza 3 para motos esta LIBRE\n");
			}

			else {
				printf("La plaza 3 esta OCUPADA por una moto y tiene el numero de matricula %s\n", matricula3);

			}

			Sleep(2000);
			break;

		case 'S':

			printf("Saliendo del aparcamiento\n");
			Sleep(1000);

			salir = 1;



			break;

		case 'B':

			printf("Escriba la matricula del vehiculo que desea buscar: ");

			scanf_s("%s", matriculaaux,8);

			printf("Buscando vehiculo con matricula %s\n", matriculaaux);


			if (strcmp(matricula1, matriculaaux) == 0) {

				printf("El coche con la matricula %s esta aparcado en la plaza 1\n ", matricula1);

				Sleep(4000);
			}

			else if (strcmp(matricula2, matriculaaux) == 0) {

				printf("El coche con la matricula %s esta aparcado en la plaza 2 \n", matricula2);

				Sleep(4000);
			}

			else if (strcmp(matricula3, matriculaaux) == 0) {

				printf("La moto con la matricula %s esta aparcada en la plaza 3 \n", matricula3);

				Sleep(4000);
			}
			
			else {

				printf("El coche con la matricula %s no esta en nuestro aparcamiento \n", matriculaaux);
				Sleep(3000);
			}
			



			break;

		default:

			printf("Esta opcion no esta permitida\n");

			break;


		}
		printf("Volviendo al menu\n");
		Sleep(500);
		system("cls");
		getchar();
	}

}
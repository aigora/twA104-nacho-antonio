#include<stdio.h>
#include<windows.h>
#include<stdlib.h>//Biblioteca para asignación dinámica de memoria
#include<conio.h>//Biblioteca para el temporizador

void Estado1(int *);
void semaforo(void);
void espera(void);

void main(void)
{
	int pulsador = 0, *ppulsador, dim = 1, contador = 0;
	//Con asignacion dinamica de memoria reservo 4 bytes de memoria (equivalente del int)
	ppulsador = (int*)malloc(dim * sizeof(int));
	if (ppulsador == NULL)
	{
		printf("No hay espacio");
		exit(-1);
	}
	ppulsador = &pulsador;
	do
	{
		Estado1(ppulsador);
		if (*ppulsador != 0)
		{
			espera();
			semaforo();
			contador++;
		}
	} while (*ppulsador != 0);
	printf("\n\nSe ha pulsado un total de %d veces el pulsador del semaforo", contador);
	//Libero el espacio reservado
	//free(ppulsador);
	printf("\n\n");
	system("pause");
}

void Estado1(int *x)
{
	printf("\nSemaforo 1\nVerde\n\nSemaforo 2\nVerde\n\nSemaforo 3\nRojo");
	printf("\n\n\nPulse peaton\n");
	scanf_s("%d", x);
	system("cls");//comando para borrar lo impreso en pantalla anteriormente
}

void semaforo()
{
	int color = 2, seg;
	while (color != 0)
	{
		if (color == 2)
		{
			for (seg = 10; seg >= 0; seg--)
			{
				printf("\t\nSemaforo 1\nRojo %d\t\n\nSemaforo 2\nRojo %d\t\n\nSemaforo 3\nVerde %d", seg, seg, seg);
				Sleep(999);//999 milisegundos 
				system("cls");
			}
		}
		else if (color == 1)
		{
			for (seg = 5; seg >= 0; seg--)
			{
				printf("\t\nSemaforo 1\nAmbar %d\t\n\nSemaforo 2\nAmbar %d\t\n\nSemaforo 3\nVerde Intermitente %d", seg, seg, seg);
				Sleep(999);
				system("cls");
			}
		}
		color--;
	}
}

void espera(void)
{
	int seg;
	for (seg = 5; seg >= 0; seg--)
	{
		printf("\t\nSemaforo 1\nAmbar %d\t\n\nSemaforo 2\nAmbar %d\t\n\nSemaforo 3\nRojo %d", seg, seg, seg);
		Sleep(999);
		system("cls");
	}
}
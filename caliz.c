#include <stdio.h>

#define BUENA 'B'
#define REGULAR 'R'
#define MALA 'M'

#define EDAD_MINIMA 17

#define CUALIDAD_SUPERIOR 1
#define CUALIDAD_INDIFERENTE 0
#define CUALIDAD_INFERIOR -1

#define APTO_CAMPEON 1
#define NO_APTO_CAMPEON 0

#define LIM_INTELIGENCIA_SUPERIOR 10
#define LIM_INTELIGENCIA_INFERIOR 0

#define LIM_FUERZA_SUPERIOR 10
#define LIM_FUERZA_INFERIOR 0

/* PRE: Pide y recibe un caracter. */
/* POST: Devuelve el caracter ingresado mediante un puntero. */

void interaccion_usuario(char *nuevo_alumno){
	
	printf("¿Desea ingresar un alumno? (N para NO, cualquier otra tecla para si)\n");
	scanf(" %c", nuevo_alumno);

}

/* PRE: Pide y recibe un numero, verifica que este entre los valores designados. */
/* POST: Devuelve el numero ingresado mediante un puntero. */

void pedir_edad(int *edad){

	printf("Ingrese la edad del alumno:\n");
	scanf(" %i", edad);
	while (*edad < 0){
		printf("Por favor, reingrese correctamente el valor: \n");
		scanf(" %i", edad);
	}

}

/* PRE: Pide y recibe un numero, verifica que este entre los valores designados. */
/* POST: Devuelve el numero ingresado mediante un puntero. */

void pedir_inteligencia(int *inteligencia_alumno){

	printf("Ingrese la inteligencia del alumno: \n");
	scanf(" %i", inteligencia_alumno);
	while ((*inteligencia_alumno < LIM_INTELIGENCIA_INFERIOR) || (*inteligencia_alumno > LIM_INTELIGENCIA_SUPERIOR)){
		printf("Por favor, reingrese correctamente el valor: \n");
		scanf(" %i", inteligencia_alumno);
	}

}

/* PRE: Pide y recibe un numero, verifica que este entre los valores designados. */
/* POST: Devuelve el numero ingresado mediante un puntero. */

void pedir_fuerza(int *fuerza_alumno){

	printf("Ingrese la fuerza del alumno: \n");
	scanf(" %i", fuerza_alumno);
	while ((*fuerza_alumno < LIM_FUERZA_INFERIOR) || (*fuerza_alumno > LIM_FUERZA_SUPERIOR)){
		printf("Por favor, reingrese correctamente el valor: \n");
		scanf(" %i", fuerza_alumno);
	}

}

/* PRE: Pide y recibe un caracter, verifica que este entre los valores designados. */
/* POST: Devuelve el caracter ingresado mediante un puntero. */

void pedir_capacidad_magica(char *capacidad_magica_alumno){

	printf("Ingrese la habilidad como mago de alumno: \n");
	scanf(" %c", capacidad_magica_alumno);
	while ((*capacidad_magica_alumno != BUENA) && (*capacidad_magica_alumno != REGULAR) && (*capacidad_magica_alumno != MALA)){
		printf("Por favor, reingrese correctamente el valor: \n");
		scanf(" %c", capacidad_magica_alumno);
	}

}

/* PRE: Recibe 2 numeros. */
/* POST: Devuelve un valor dependiendo del resultado de la comparacion. */

int comparar_inteligencia(int inteligencia_alumno, int inteligencia_campeon){

	if (inteligencia_alumno > inteligencia_campeon)
		return CUALIDAD_SUPERIOR;
	else if (inteligencia_alumno == inteligencia_campeon)
		return CUALIDAD_INDIFERENTE;
	else
		return CUALIDAD_INFERIOR;

}

/* PRE: Recibe 2 numeros. */
/* POST: Devuelve un valor dependiendo del resultado de la comparacion. */

int comparar_fuerza(int fuerza_alumno, int fuerza_campeon){

	if (fuerza_alumno > fuerza_campeon)
		return CUALIDAD_SUPERIOR;
	else if (fuerza_alumno == fuerza_campeon)
		return CUALIDAD_INDIFERENTE;
	else
		return CUALIDAD_INFERIOR;

}

/* PRE: Recibe 1 caracter. */
/* POST: Devuelve un valor dependiendo del resultado de la comparacion. */

int asignar_valor_char(char caracter){

	if (caracter == 'B')
		return 3;
	else if (caracter == 'R')
		return 2;
	else
		return 1;

}

/* PRE: Recibe 2 caracteres. */
/* POST: Devuelve un valor dependiendo del resultado de la comparacion. */

int comparar_capacidad_magica(char capacidad_magica_alumno, char capacidad_magica_campeon){

	int valor_alumno = asignar_valor_char(capacidad_magica_alumno);
	int valor_campeon = asignar_valor_char(capacidad_magica_campeon);

	if (valor_alumno > valor_campeon)
		return CUALIDAD_SUPERIOR;
	else if (valor_alumno == valor_campeon)
		return CUALIDAD_INDIFERENTE;
	else
		return CUALIDAD_INFERIOR;

}

/* PRE: Recibe 4 numeros y 2 caracteres. */
/* POST: Devuelve un valor dependiendo del resultado de la comparacion. */

int comparador(int inteligencia_alumno, int inteligencia_campeon, int fuerza_alumno, int fuerza_campeon, char capacidad_magica_alumno, char capacidad_magica_campeon){

	int valor_inteligencia = comparar_inteligencia(inteligencia_alumno, inteligencia_campeon);
	int valor_fuerza = comparar_fuerza(fuerza_alumno, fuerza_campeon);
	int valor_capacidad_magica = comparar_capacidad_magica(capacidad_magica_alumno, capacidad_magica_campeon);

	if (valor_inteligencia == 1)
		return APTO_CAMPEON;
	else if ((valor_inteligencia == 0) && (valor_fuerza == 1))
		return APTO_CAMPEON;
	else if ((valor_inteligencia == 0) && (valor_fuerza == 0) && (valor_capacidad_magica == 1))
		return APTO_CAMPEON;
	else
		return NO_APTO_CAMPEON;

}

/* PRE: Recibe 7 numeros y 2 caracteres. */
/* POST: Segun el resultado de la comparacion devuelve valores mediante punteros. */

void es_campeon(int inteligencia_alumno, int *inteligencia_campeon, int fuerza_alumno, int *fuerza_campeon, char capacidad_magica_alumno, char *capacidad_magica_campeon, int orden_alumno, int *nmr_campeon, int *edad){

	int campeon = comparador(inteligencia_alumno, *inteligencia_campeon, fuerza_alumno, *fuerza_campeon, capacidad_magica_alumno, *capacidad_magica_campeon);
	if ((campeon == APTO_CAMPEON) && (*edad >= 17)){
		*inteligencia_campeon = inteligencia_alumno;
		*fuerza_campeon = fuerza_alumno;
		*capacidad_magica_campeon = capacidad_magica_alumno;
		*nmr_campeon = orden_alumno;
	}

}

/* PRE: Recibe 1 numero. */
/* POST: El programa devuelve una instruccion segun el resultado de la comparacion. */

void mostrar_campeon(int nmr_campeon){

	if (nmr_campeon > 0)
		printf("El campeón es el número %i :)\n", nmr_campeon);
	else
		printf("No hay campeón :(\n");

}

/* PRE: El programa va a interactuar con el usuario y solicitar diversos valores durante su ejecucion para poder realizar su tarea. */
/* POST: El programa devuelve en consola el numero del campeon o por el contrario un mensaje si no hay alguno. */

int main(){

	int edad = 0, inteligencia_alumno = 0, fuerza_alumno = 0, orden_alumno = 0;
	int inteligencia_campeon = (-1), fuerza_campeon = (-1), nmr_campeon = 0;
	char nuevo_alumno, capacidad_magica_alumno, capacidad_magica_campeon;

	interaccion_usuario(&nuevo_alumno);
	while (nuevo_alumno != 'N'){
		orden_alumno++;
		pedir_edad(&edad);
		if (edad < EDAD_MINIMA){
			printf("El alumno es muy joven\n");
		}else{
			pedir_inteligencia(&inteligencia_alumno);
			pedir_fuerza(&fuerza_alumno);
			pedir_capacidad_magica(&capacidad_magica_alumno);
		}
		es_campeon(inteligencia_alumno, &inteligencia_campeon, fuerza_alumno, &fuerza_campeon, capacidad_magica_alumno, &capacidad_magica_campeon, orden_alumno, &nmr_campeon, &edad);
		interaccion_usuario(&nuevo_alumno);
	}
	mostrar_campeon(nmr_campeon);

	return 0;

}

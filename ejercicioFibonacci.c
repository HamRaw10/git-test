#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"

int estrellasDadas = 0;
int menuVariable = 0;
int contadorDePrimeraOpcion = 0;
int guardadoEstrellas[1000];
int guardadoERROR[1000];
int guardadoAlfajores[1000];
int guardadoTipoAlfajor[1000];
int guardadoTipoOperador[1000];
int alfajores = 0, tipoAlfajor = 0, tipoOperador = 0, ERROR = 0;

void MENU() {
    puts("-----------------------------------------------------------");
    puts(CYAN"  B I E N V E N I D O ! !"RESET);
    puts(MAGENTA"a ALFAJORES GALVANICOS"RESET);
    puts("Comprar(1)");
    puts("Estadisticas(2)");
    puts("Estrellas(3)");
    puts("Salir(4)");
    printf("Eliga una opcion del menu: ");
    scanf("%d", &menuVariable);
    puts("-----------------------------------------------------------");
}

void operador() {
    do {
        puts(CYAN"Por favor, ingrese en que operador compra sus alfajores (del 1 al 6)"RESET);
        scanf("%d", &tipoOperador);
        if(tipoOperador < 1 || tipoOperador > 6) {
            system("clear");
            puts(RED"Por favor, ingrese un operador valido"RESET);
        }
    } while(tipoOperador < 1 || tipoOperador > 6);
    guardadoTipoOperador[contadorDePrimeraOpcion - 1] = tipoOperador;
}

void tipo() {
    do {
        puts("Ingrese el tipo de alfajor");
        puts(CYAN"Recuerde que el orden es: Chocolate(1), Dulce de leche(2), Fruta(3), Mixto(4)"RESET);
        scanf("%d", &tipoAlfajor);
        if(tipoAlfajor < 1 || tipoAlfajor > 4) {
            system("clear");
            puts(RED"Por favor, ingrese un tipo valido"RESET);
        }
    } while(tipoAlfajor < 1 || tipoAlfajor > 4);
    guardadoTipoAlfajor[contadorDePrimeraOpcion - 1] = tipoAlfajor;
}

void cajaAlfajores() {
    puts(CYAN"Ingrese la cantidad de alfajores que quiere: "RESET);
    scanf("%d", &alfajores);
    if(alfajores % 6 != 0) {
        ERROR = alfajores % 6;
    }
    alfajores = alfajores - ERROR;
    guardadoAlfajores[contadorDePrimeraOpcion-1] = alfajores;
}

void laPrimeraOpcion() {
    contadorDePrimeraOpcion++;
    operador(); 
    tipo(); 
    cajaAlfajores();
    puts("Muchas gracias por comprar en Alfajores Galvanicos, por favor, si le gusto los alfajores...");
    puts(MAGENTA"Puede dejarnos su puntuacion aqui!"RESET);
    scanf("%d", &estrellasDadas);
    guardadoEstrellas[contadorDePrimeraOpcion - 1] = estrellasDadas;
}

void laSegundaOpcion() {
    puts("---------------------------------------------------");
    puts("Las estaditicas son: ");
    printf(CYAN"Operador: %d, Tipo: %d, Cantidad: %d"RESET, tipoOperador, tipoAlfajor, alfajores);
    printf(RED" Alfajores en ERROR: %d \n"RESET, ERROR);
    puts("---------------------------------------------------");
    puts(MAGENTA"Las estadisticas generales son: "RESET);
    for(int i = 0; i < contadorDePrimeraOpcion; i++) {
        printf(CYAN"Operador: %d ", guardadoTipoOperador[i]);
        printf("Tipo Alfajor: %d ", guardadoTipoAlfajor[i]);
        printf("Cantidad Alfajor: %d ", guardadoAlfajores[i]);
        printf(RED"Error %d "RESET, guardadoERROR[i]);
        puts(" ");
    }
}

void laTerceraOpcion() {
    printf(CYAN"Las estrellas que han brindado actualmente son: %d\n", estrellasDadas);
    printf(MAGENTA"Las estrellas generales han sido: "RESET);
    for(int i = 0; i < contadorDePrimeraOpcion; i++) {
        printf("%d ", guardadoEstrellas[i]);
    }
    puts(" ");
}

int main() {
    while(1) {
      do {
        MENU();
        } while(menuVariable < 1 || menuVariable > 4);
        if(menuVariable == 1)
            laPrimeraOpcion();
        if(menuVariable == 2)
            laSegundaOpcion();
        if(menuVariable == 3)
            laTerceraOpcion();
        if(menuVariable == 4) {
            printf(CYAN"Muchas gracias por comprar en Alfajores Galvanicos,"); puts(MAGENTA" Vuelva pronto! !"RESET);
            return 0;
        }
    }
}

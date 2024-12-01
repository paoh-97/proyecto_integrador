#include <stdio.h>
#define MAX_PRODUCTOS 5
#define MAX_CARACTERES 50

char nombres[MAX_PRODUCTOS][MAX_CARACTERES];
int cantidades[MAX_PRODUCTOS];
int recursos[MAX_PRODUCTOS];
int tiempos[MAX_PRODUCTOS];
int total_productos = 0;

void ingresar_producto();
void editar_producto();
void eliminar_producto();
void calcular_tiempo_y_recursos(int tiempo_disponible, int recursos_disponibles);
int buscar_producto(char nombre[]);
void mostrar_productos();
void vaciar_entrada();
int comparar_cadenas(char *cadena1, char *cadena2);
void copiar_cadena(char *destino, char *origen);

int main() {
    int opcion, tiempo_disponible, recursos_disponibles;
    do {
        printf("\nMenu de opciones:\n");
        printf("1. Ingresar un producto\n");
        printf("2. Editar un producto\n");
        printf("3. Eliminar un producto\n");
        printf("4. Calcular tiempo y recursos\n");
        printf("5. Verificar si la demanda es posible\n");
        printf("6. Mostrar productos\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        vaciar_entrada();

        switch(opcion) {
            case 1:
                ingresar_producto();
                break;
            case 2:
                editar_producto();
                break;
            case 3:
                eliminar_producto();
                break;
            case 4:
                printf("Ingrese el tiempo disponible: ");
                scanf("%d", &tiempo_disponible);
                printf("Ingrese los recursos disponibles: ");
                scanf("%d", &recursos_disponibles);
                calcular_tiempo_y_recursos(tiempo_disponible, recursos_disponibles);
                break;
            case 5:
                printf("Ingrese el tiempo disponible: ");
                scanf("%d", &tiempo_disponible);
                printf("Ingrese los recursos disponibles: ");
                scanf("%d", &recursos_disponibles);
                calcular_tiempo_y_recursos(tiempo_disponible, recursos_disponibles);
                break;
            case 6:
                mostrar_productos();
                break;
            case 7:
                printf("Saliendo....\n");
                break;
            default:
                printf("La opcion es invalida. Intente de nuevo.\n");
        }

    } while (opcion != 7);  
    return 0;
}


void ingresar_producto() {
    if (total_productos < MAX_PRODUCTOS) {
        printf("Ingrese el nombre del producto: ");
        scanf("%49s", nombres[total_productos]);  

        printf("Ingrese la cantidad demandada de %s: ", nombres[total_productos]);
        scanf("%d", &cantidades[total_productos]);

        printf("Ingrese el tiempo de fabricación por unidad de %s (en horas): ", nombres[total_productos]);
        scanf("%d", &tiempos[total_productos]);

        printf("Ingrese los recursos necesarios para %s: ", nombres[total_productos]);
        scanf("%d", &recursos[total_productos]);

        total_productos++;
    } else {
        printf("No se pueden ingresar más productos. La capacidad máxima fue alcanzada\n");
    }
}

void editar_producto() {
    char nombre[MAX_CARACTERES];
    int indice;

    printf("Ingrese el nombre del producto a editar: ");
    scanf("%49s", nombre);  

    indice = buscar_producto(nombre);
    if (indice != -1) {
        printf("Ingrese una nueva cantidad: ");
        scanf("%d", &cantidades[indice]);

        printf("Ingrese un nuevo tiempo de fabricación por unidad (en horas): ");
        scanf("%d", &tiempos[indice]);

        printf("Ingrese nuevos recursos necesarios: ");
        scanf("%d", &recursos[indice]);
    } else {
        printf("El producto no fue encontrado\n");
    }
}


void eliminar_producto() {
    char nombre[MAX_CARACTERES];
    int indice, i;

    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%49s", nombre);  

    indice = buscar_producto(nombre);
    if (indice != -1) {
        for (i = indice; i < total_productos - 1; i++) {
            copiar_cadena(nombres[i], nombres[i + 1]);
            cantidades[i] = cantidades[i + 1];
            recursos[i] = recursos[i + 1];
            tiempos[i] = tiempos[i + 1];
        }
        total_productos--;
        printf("El producto fue eliminado\n");
    } else {
        printf("El producto no fue encontrado\n");
    }
}


void calcular_tiempo_y_recursos(int tiempo_disponible, int recursos_disponibles) {
    int tiempo_total = 0, recursos_totales = 0, i;

    for (i = 0; i < total_productos; i++) {
        tiempo_total += tiempos[i] * cantidades[i];
        recursos_totales += recursos[i] * cantidades[i];
    }

    printf("Tiempo total necesario: %d horas\n", tiempo_total);
    printf("Recursos totales necesarios: %d unidades\n", recursos_totales);

    if (tiempo_total <= tiempo_disponible && recursos_totales <= recursos_disponibles) {
        printf("La fabrica si puede cumplir con la demanda\n");
    } else {
        printf("La fabrica no puede cumplir con la demanda\n");
    }
}

int buscar_producto(char nombre[]) {
    int i;
    for (i = 0; i < total_productos; i++) {
        if (comparar_cadenas(nombres[i], nombre) == 0) {
            return i;
        }
    }
    return -1;
}

void mostrar_productos() {
    int i;
    if (total_productos == 0) {
        printf("No hay productos registrados\n");
    } else {
        for (i = 0; i < total_productos; i++) {
            printf("Producto: %s, Cantidad: %d, Tiempo: %d horas, Recursos: %d unidades\n",
                nombres[i], cantidades[i], tiempos[i], recursos[i]);
        }
    }
}

void vaciar_entrada() {
    while (getchar() != '\n');
}


int comparar_cadenas(char *cadena1, char *cadena2) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return 1;
        }
        i++;
    }
    if (cadena1[i] != cadena2[i]) {
        return 1;
    }
    return 0;
}

void copiar_cadena(char *fin, char *inicio) {
    int i = 0;
    while (inicio[i] != '\0') {
        fin[i] = inicio[i];
        i++;
    }
    fin[i] = '\0';
}

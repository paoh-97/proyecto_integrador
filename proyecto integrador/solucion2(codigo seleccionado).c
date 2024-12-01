#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define LONGITUD_NOMBRE 50

char nombres_productos[MAX_PRODUCTOS][LONGITUD_NOMBRE];
int cantidades[MAX_PRODUCTOS];
float tiempo_por_unidad[MAX_PRODUCTOS];
int recursos_por_unidad[MAX_PRODUCTOS];
int cantidad_productos = 0;

void agregar_producto() {
    if (cantidad_productos >= MAX_PRODUCTOS) {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombres_productos[cantidad_productos]);
    printf("Ingrese la cantidad demandada: ");
    scanf("%d", &cantidades[cantidad_productos]);
    printf("Ingrese el tiempo por unidad (en horas): ");
    scanf("%f", &tiempo_por_unidad[cantidad_productos]);
    printf("Ingrese los recursos por unidad: ");
    scanf("%d", &recursos_por_unidad[cantidad_productos]);

    cantidad_productos++;
    printf("Producto agregado exitosamente.\n");
}

void editar_producto() {
    char nombre[LONGITUD_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombre);

    for (int i = 0; i < cantidad_productos; i++) {
        if (strcmp(nombres_productos[i], nombre) == 0) {
            printf("Editar cantidad demandada: ");
            scanf("%d", &cantidades[i]);
            printf("Editar tiempo por unidad (en horas): ");
            scanf("%f", &tiempo_por_unidad[i]);
            printf("Editar recursos por unidad: ");
            scanf("%d", &recursos_por_unidad[i]);
            printf("Producto editado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminar_producto() {
    char nombre[LONGITUD_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombre);

    for (int i = 0; i < cantidad_productos; i++) {
        if (strcmp(nombres_productos[i], nombre) == 0) {
            for (int j = i; j < cantidad_productos - 1; j++) {
                strcpy(nombres_productos[j], nombres_productos[j + 1]);
                cantidades[j] = cantidades[j + 1];
                tiempo_por_unidad[j] = tiempo_por_unidad[j + 1];
                recursos_por_unidad[j] = recursos_por_unidad[j + 1];
            }
            cantidad_productos--;
            printf("Producto eliminado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void calcular_requerimientos() {
    float tiempo_total = 0;
    int recursos_totales = 0;

    for (int i = 0; i < cantidad_productos; i++) {
        tiempo_total += cantidades[i] * tiempo_por_unidad[i];
        recursos_totales += cantidades[i] * recursos_por_unidad[i];
    }

    printf("Tiempo total requerido: %.2f horas\n", tiempo_total);
    printf("Recursos totales necesarios: %d unidades\n", recursos_totales);
}

int main() {
    int opcion;

    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular requerimientos\n");
        printf("5. Salir\n");

        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: agregar_producto(); break;
            case 2: editar_producto(); break;
            case 3: eliminar_producto(); break;
            case 4: calcular_requerimientos(); break;
            case 5: printf("Saliendo...\n"); break;
            default: printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTICULOS 5 

struct Articulo {
    char titulo[50];
    char fecha[50];
    char directorio[50];
};

struct Articulo articulos[MAX_ARTICULOS];
int contador_articulos = 0;

void agregar_articulo();
void actualizar_articulo();
void eliminar_articulo();
void mostrar_articulos();
void abrir_archivo(int index);

int main() {
    int opcion;

    do {
        printf("\n--- Menú de Gestión de Artículos ---\n");
        printf("1. Agregar Artículo\n");
        printf("2. Actualizar Artículo\n");
        printf("3. Eliminar Artículo\n");
        printf("4. Mostrar Artículos\n");
        printf("5. Abrir Artículo PDF\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1:
                agregar_articulo();
                break;
            case 2:
                actualizar_articulo();
                break;
            case 3:
                eliminar_articulo();
                break;
            case 4:
                mostrar_articulos();
                break;
            case 5: {
                int index;
                mostrar_articulos();
                printf("Ingrese el número del artículo para abrir el archivo PDF: ");
                scanf("%d", &index);
                getchar();
                if (index > 0 && index <= contador_articulos) {
                    abrir_archivo(index - 1);
                } else {
                    printf("Índice no válido.\n");
                }
                break;
            }
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida, por favor intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}

void agregar_articulo() {
    if (contador_articulos >= MAX_ARTICULOS) {
        printf("No se pueden agregar más artículos.\n");
        return;
    }

    printf("Ingrese el título del artículo: ");
    fgets(articulos[contador_articulos].titulo, 50, stdin);
    articulos[contador_articulos].titulo[strcspn(articulos[contador_articulos].titulo, "\n")] = 0;

    printf("Ingrese la fecha de publicación (DD/MM/AAAA): ");
    fgets(articulos[contador_articulos].fecha, 50, stdin);
    articulos[contador_articulos].fecha[strcspn(articulos[contador_articulos].fecha, "\n")] = 0;

    printf("Ingrese el nombre del archivo PDF (ejemplo: articulo.pdf): ");
    fgets(articulos[contador_articulos].directorio, 50, stdin);
    articulos[contador_articulos].directorio[strcspn(articulos[contador_articulos].directorio, "\n")] = 0;

    contador_articulos++;
    printf("Artículo agregado exitosamente.\n");
}

void actualizar_articulo() {
    mostrar_articulos();
    int index;
    printf("Ingrese el número del artículo a actualizar: ");
    scanf("%d", &index);
    getchar(); 

    if (index > 0 && index <= contador_articulos) {
        printf("Ingrese el nuevo título del artículo: ");
        fgets(articulos[index - 1].titulo, 50, stdin);
        articulos[index - 1].titulo[strcspn(articulos[index - 1].titulo, "\n")] = 0;

        printf("Ingrese la nueva fecha de publicación (DD/MM/AAAA): ");
        fgets(articulos[index - 1].fecha, 50, stdin);
        articulos[index - 1].fecha[strcspn(articulos[index - 1].fecha, "\n")] = 0;

        printf("Ingrese el nuevo nombre del archivo PDF: ");
        fgets(articulos[index - 1].directorio, 50, stdin);
        articulos[index - 1].directorio[strcspn(articulos[index - 1].directorio, "\n")] = 0;

        printf("Artículo actualizado exitosamente.\n");
    } else {
        printf("Índice no válido.\n");    }
}

void eliminar_articulo() {
    mostrar_articulos();
    int index;
    printf("Ingrese el número del artículo a eliminar: ");
    scanf("%d", &index);
    getchar(); 

    if (index > 0 && index <= contador_articulos) {
        for (int i = index - 1; i < contador_articulos - 1; i++) {
            articulos[i] = articulos[i + 1];
        }
        contador_articulos--;
        printf("Artículo eliminado exitosamente.\n");
    } else {
        printf("Índice no válido.\n");
    }
}

void mostrar_articulos() {
    if (contador_articulos == 0) {
        printf("No hay artículos almacenados.\n");
        return;
    }

    printf("\nLista de artículos:\n");
    for (int i = 0; i < contador_articulos; i++) {
        printf("%d. Título: %s, Fecha: %s, Archivo: %s\n", 
               i + 1, articulos[i].titulo, articulos[i].fecha, articulos[i].directorio);
    }
}

void abrir_archivo(int index) {
    char comando[100] = "start "; 
    strcat(comando, articulos[index].directorio);
    
    system(comando); 
}
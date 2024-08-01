#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

#define MAX_PRODUCTOS 100  
#define NOMBRE_LENGTH 50  

typedef struct {  
    int id;  
    char nombre[NOMBRE_LENGTH];  
    int cantidad;  
} Producto;  

Producto inventario[MAX_PRODUCTOS];  
int contador_productos = 0;  

void agregar_producto() {  
    if (contador_productos >= MAX_PRODUCTOS) {  
        printf("No se puede agregar más productos, inventario lleno.\n");  
        return;  
    }  

    Producto nuevo_producto;  
    nuevo_producto.id = contador_productos + 1;  // ID único  
    printf("Ingrese el nombre del producto: ");  
    scanf("%s", nuevo_producto.nombre);  
    printf("Ingrese la cantidad del producto: ");  
    scanf("%d", &nuevo_producto.cantidad);  

    inventario[contador_productos] = nuevo_producto;  
    contador_productos++;  
    printf("Producto agregado exitosamente.\n");  
}  

void modificar_producto() {  
    int id, encontrado = 0;  
    printf("Ingrese el ID del producto a modificar: ");  
    scanf("%d", &id);  

    for (int i = 0; i < contador_productos; i++) {  
        if (inventario[i].id == id) {  
            printf("Ingrese el nuevo nombre del producto: ");  
            scanf("%s", inventario[i].nombre);  
            printf("Ingrese la nueva cantidad del producto: ");  
            scanf("%d", &inventario[i].cantidad);  
            encontrado = 1;  
            printf("Producto modificado exitosamente.\n");  
            break;  
        }  
    }  

    if (!encontrado) {  
        printf("Producto no encontrado.\n");  
    }  
}  

void eliminar_producto() {  
    int id, encontrado = 0;  
    printf("Ingrese el ID del producto a eliminar: ");  
    scanf("%d", &id);  

    for (int i = 0; i < contador_productos; i++) {  
        if (inventario[i].id == id) {  
            for (int j = i; j < contador_productos - 1; j++) {  
                inventario[j] = inventario[j + 1];  
            }  
            contador_productos--;  
            encontrado = 1;  
            printf("Producto eliminado exitosamente.\n");  
            break;  
        }  
    }  

    if (!encontrado) {  
        printf("Producto no encontrado.\n");  
    }  
}  

void consultar_inventario() {  
    printf("\nInventario:\n");  
    for (int i = 0; i < contador_productos; i++) {  
        printf("ID: %d, Nombre: %s, Cantidad: %d\n", inventario[i].id, inventario[i].nombre, inventario[i].cantidad);  
    }  
}  

int main() {  
    int opcion;  

    do {  
        printf("\n--- Sistema de Almacén ---\n");  
        printf("1. Agregar Producto\n");  
        printf("2. Modificar Producto\n");  
        printf("3. Eliminar Producto\n");  
        printf("4. Consultar Inventario\n");  
        printf("5. Salir\n");  
        printf("Seleccione una opción: ");  
        scanf("%d", &opcion);  

        switch (opcion) {  
            case 1:  
                agregar_producto();  
                break;  
            case 2:  
                modificar_producto();  
                break;  
            case 3:  
                eliminar_producto();  
                break;  
            case 4:  
                consultar_inventario();  
                break;  
            case 5:  
                printf("Saliendo del sistema...\n");  
                break;  
            default:  
                printf("Opción no válida. Intente de nuevo.\n");  
        }  
    } while (opcion != 5);  

    return 0;  
} // sistema de almacen
#include <stdio.h>
#include <string.h>

#define NOMBRE 50
#define CEDULA 11
#define MAX_CLIENTES 100
#define MAX_PRODUCTOS 100
#define MAX_FACTURAS 100

int main() {
    char productos[MAX_PRODUCTOS][NOMBRE];
    int cantidad_productos[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    char caducidades[MAX_PRODUCTOS][NOMBRE];
    int num_productos = 0;

    char clientes[MAX_CLIENTES][CEDULA];
    char nombres_clientes[MAX_CLIENTES][NOMBRE];
    int num_clientes = 0;

    char facturas[MAX_FACTURAS][NOMBRE];
    char fechas[MAX_FACTURAS][NOMBRE];
    char cedulas_facturas[MAX_FACTURAS][CEDULA];
    char nombres_facturas[MAX_FACTURAS][NOMBRE];
    float valores_pagados[MAX_FACTURAS];
    int cantidades_compradas[MAX_FACTURAS];
    int num_facturas = 0;

    int opcion;
    do {
        printf("---------Bienvenido a MediStor----------\n");
        printf("1. Ingresar Producto\n");
        printf("2. Modificar Producto\n");
        printf("3. Eliminar Producto\n");
        printf("4. Consultar Producto\n");
        printf("5. Adicionar compra Producto\n");
        printf("6. Ver Productos\n");
        printf("7. Ingresar Cliente\n");
        printf("8. Modificar Cliente\n");
        printf("9. Consultar cliente\n");
        printf("10. Ver listado de clientes\n");
        printf("11. Facturar\n");
        printf("12. Buscar Factura\n");
        printf("13. Ver listado de facturas\n");
        printf("14. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: // Ingresar Producto
                if (num_productos < MAX_PRODUCTOS) {
                    printf("Nombre del producto: ");
                    scanf("%s", productos[num_productos]);
                    printf("Cantidad: ");
                    scanf("%d", &cantidad_productos[num_productos]);
                    printf("Precio: ");
                    scanf("%f", &precios[num_productos]);
                    printf("Fecha de caducidad (DD/MM/AAAA): ");
                    scanf("%s", caducidades[num_productos]);
                    num_productos++;
                } else {
                    printf("No se pueden agregar más productos.\n");
                }
                break;
            case 2: // Modificar Producto
                printf("Ingrese el nombre del producto a modificar: ");
                char nombre_producto[NOMBRE];
                scanf("%s", nombre_producto);
                for (int i = 0; i < num_productos; i++) {
                    if (strcmp(productos[i], nombre_producto) == 0) {
                        printf("Nuevo nombre: ");
                        scanf("%s", productos[i]);
                        printf("Nueva cantidad: ");
                        scanf("%d", &cantidad_productos[i]);
                        printf("Nuevo precio: ");
                        scanf("%f", &precios[i]);
                        printf("Nueva fecha de caducidad (DD/MM/AAAA): ");
                        scanf("%s", caducidades[i]);
                        break;
                    }
                }
                break;
            case 3: // Eliminar Producto
                printf("Ingrese el nombre del producto a eliminar: ");
                char nombre_producto_eliminar[NOMBRE];
                scanf("%s", nombre_producto_eliminar);
                for (int i = 0; i < num_productos; i++) {
                    if (strcmp(productos[i], nombre_producto_eliminar) == 0) {
                        for (int j = i; j < num_productos - 1; j++) {
                            strcpy(productos[j], productos[j + 1]);
                            cantidad_productos[j] = cantidad_productos[j + 1];
                            precios[j] = precios[j + 1];
                            strcpy(caducidades[j], caducidades[j + 1]);
                        }
                        num_productos--;
                        break;
                    }
                }
                break;
            case 4: // Consultar Producto
                printf("Ingrese el nombre del producto a consultar: ");
                char nombre_producto_consultar[NOMBRE];
                scanf("%s", nombre_producto_consultar);
                for (int i = 0; i < num_productos; i++) {
                    if (strcmp(productos[i], nombre_producto_consultar) == 0) {
                        printf("Nombre: %s\n", productos[i]);
                        printf("Cantidad: %d\n", cantidad_productos[i]);
                        printf("Precio: %.2f\n", precios[i]);
                        printf("Fecha de caducidad: %s\n", caducidades[i]);
                        break;
                    }
                }
                break;
            case 5: // Adicionar compra Producto
                printf("Ingrese el nombre del producto a adicionar: ");
                char nombre_producto_adicionar[NOMBRE];
                scanf("%s", nombre_producto_adicionar);
                for (int i = 0; i < num_productos; i++) {
                    if (strcmp(productos[i], nombre_producto_adicionar) == 0) {
                        printf("Cantidad a adicionar: ");
                        int cantidad_adicionar;
                        scanf("%d", &cantidad_adicionar);
                        cantidad_productos[i] += cantidad_adicionar;
                        break;
                    }
                }
                break;
            case 6: // Ver Productos
                printf("---------Productos---------\n");
                for (int i = 0; i < num_productos; i++) {
                    printf("Nombre: %s\n", productos[i]);
                    printf("Cantidad: %d\n", cantidad_productos[i]);
                    printf("Precio: %.2f\n", precios[i]);
                    printf("Fecha de caducidad: %s\n", caducidades[i]);
                    printf("------------------------\n");
                }
                break;
            case 7: // Ingresar Cliente
                if (num_clientes < MAX_CLIENTES) {
                    printf("Cédula: ");
                    scanf("%s", clientes[num_clientes]);
                    printf("Nombre: ");
                    scanf("%s", nombres_clientes[num_clientes]);
                    num_clientes++;
                } else {
                    printf("No se pueden agregar más clientes.\n");
                }
                break;
            case 8: // Modificar Cliente
                printf("Ingrese la cédula del cliente a modificar: ");
                char cedula_cliente_modificar[CEDULA];
                scanf("%s", cedula_cliente_modificar);
                for (int i = 0; i < num_clientes; i++) {
                    if (strcmp(clientes[i], cedula_cliente_modificar) == 0) {
                        printf("Nuevo nombre: ");
                        scanf("%s", nombres_clientes[i]);
                        break;
                    }
                }
                break;
            case 9: // Consultar cliente
                printf("Ingrese la cédula del cliente a consultar: ");
                char cedula_cliente_consultar[CEDULA];
                scanf("%s", cedula_cliente_consultar);
                for (int i = 0; i < num_clientes; i++) {
                    if (strcmp(clientes[i], cedula_cliente_consultar) == 0) {
                        printf("Nombre: %s\n", nombres_clientes[i]);
                        break;
                    }
                }
                break;
            case 10: // Ver listado de clientes
                printf("---------Clientes---------\n");
                for (int i = 0; i < num_clientes; i++) {
                    printf("Cédula: %s\n", clientes[i]);
                    printf("Nombre: %s\n", nombres_clientes[i]);
                    printf("------------------------\n");
                }
                break;
            case 11: // Facturar
                if (num_facturas < MAX_FACTURAS) {
                    printf("Fecha (DD/MM/AAAA): ");
                    scanf("%s", fechas[num_facturas]);
                    printf("Cédula del cliente: ");
                    scanf("%s", cedulas_facturas[num_facturas]);
                    printf("Nombre del cliente: ");
                    scanf("%s", nombres_facturas[num_facturas]);
                    printf("Valor pagado: ");
                    scanf("%f", &valores_pagados[num_facturas]);
                    printf("Cantidad de productos comprados: ");
                    scanf("%d", &cantidades_compradas[num_facturas]);
                    num_facturas++;
                } else {
                    printf("No se pueden agregar más facturas.\n");
                }
                break;
            case 12: // Buscar Factura
                printf("Ingrese la fecha de la factura a buscar (DD/MM/AAAA): ");
                char fecha_factura_buscar[NOMBRE];
                scanf("%s", fecha_factura_buscar);
                for (int i = 0; i < num_facturas; i++) {
                    if (strcmp(fechas[i], fecha_factura_buscar) == 0) {
                        printf("Cédula del cliente: %s\n", cedulas_facturas[i]);
                        printf("Nombre del cliente: %s\n", nombres_facturas[i]);
                        printf("Valor pagado: %.2f\n", valores_pagados[i]);
                        printf("Cantidad de productos comprados: %d\n", cantidades_compradas[i]);
                        break;
                    }
                }
                break;
            case 13: // Ver listado de facturas
                printf("---------Facturas---------\n");
                for (int i = 0; i < num_facturas; i++) {
                    printf("Fecha: %s\n", fechas[i]);
                    printf("Cédula del cliente: %s\n", cedulas_facturas[i]);
                    printf("Nombre del cliente: %s\n", nombres_facturas[i]);
                    printf("Valor pagado: %.2f\n", valores_pagados[i]);
                    printf("Cantidad de productos comprados: %d\n", cantidades_compradas[i]);
                    printf("------------------------\n");
                }
                break;
            case 14: // Salir
                printf("Adiós!\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 14);

    return 0;
}


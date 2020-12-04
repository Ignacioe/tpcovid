#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./Database/database.h"
#include "./Ciudad/ciudad.h"
#include "./Registro/registro.h"

#define MAXBUFFER 100

void imprimir_datos_depto (Departamento *depto);

void imprimir_menu(){
    printf("\nFormatos validos de comandos:\n");
    printf("    - Carga de datos:\n        cargar_dataset archivo_entrada.csv\n\n");
    printf("    - Imprimir los datos:\n        imprimir_dataset archivo_salida.csv\n\n");
    printf("    - Agregar un registro a los datos:\n        agregar_registro fecha,departamento,localidad,confirmados,descartados,enEstudio\n\n");
    printf("    - Eliminar un registro de los datos:\n        eliminar_registro fecha,departamento,localidad\n\n");
    printf("    - Buscar el pico de la curva de una ciudad:\n        buscar_pico departamento,localidad\n\n");
    printf("    - Mostrar los casos acumulados de una ciudad:\n        casos_acumulados fecha,departamento,localidad\n\n");
    printf("    - Mostrar el tiempo de duplicacion de casos de una ciudad:\n        tiempo_duplicacion fecha,departamento,localidad\n\n");
    printf("    - Mostrar la grafica de la curva de una ciudad:\n        graficar fechaInicio,fechaFinal,departamento,localidad\n\n");
    printf("    - Salir del interprete:\n        salir\n\nIngrese su comando: ");
}

int main(){
    int input = 0;
    Database datos = database_inicializar();
    char comando[MAXBUFFER], buffer[MAXBUFFER], fechaInicio[MAXBUFFER], fechaFin[MAXBUFFER], deptoNombre[MAXBUFFER], localidadNombre[MAXBUFFER],confirmados[MAXBUFFER], descartados[MAXBUFFER], enEstudio[MAXBUFFER];
    while(input != -1){
        imprimir_menu();
        fgets(buffer, MAXBUFFER, stdin);
        sscanf(buffer, "%s %[^\n]", comando, buffer);

        if(strcmp(comando, "carga") == 0){
            FILE * fp;
            fp = fopen(buffer, "r");
            if( fp == NULL ) {
                printf("Error cargando en el archivo %s\n", buffer);
            } else {
                printf("Cargando el archivo %s\n", buffer);
            }
            fclose(fp);
        }

        if(strcmp(comando, "imprimir") == 0){
            printf("Imprimiendo los datos en %s\n", buffer);
            FILE *fp;
            fp = fopen(buffer, "w+");
            database_imprimir(datos, fp);
            fclose(fp);
        }

        if(strcmp(comando, "agregar") == 0){
            sscanf(buffer, "%[^,],%[^\n]", fechaInicio, buffer);
            sscanf(buffer, "%[^,],%[^\n]", deptoNombre, buffer);
            sscanf(buffer, "%[^,],%[^\n]", localidadNombre, buffer);
            sscanf(buffer, "%[^,],%[^\n]", confirmados, buffer);
            sscanf(buffer, "%[^,],%[^\n]", descartados, enEstudio);
            if(0){ //validacion del registro
                printf("Error en los datos del registro a agregar\n");
            } else {
                printf("Agregando a los datos el registro:\n    Fecha: %s\n    Departamento: %s\n    Localidad: %s\n    Confimados: %s\n    Descartados: %s\n    En estudio: %s\n", fechaInicio, deptoNombre, localidadNombre, confirmados, descartados, enEstudio);
                Registro *registroNuevo = registro_crear(fechaInicio, confirmados, descartados, enEstudio);
                Departamento *depto = departamento_buscar(datos, deptoNombre);
                if(!depto){
                    printf("No existe el depto, lo creo\n");
                    depto = departamento_crear(deptoNombre);
                    datos = database_agregar_depto(datos, depto);
                }
                imprimir_datos_depto(depto);
                Ciudad *ciudad = ciudad_buscar(depto->ciudades, localidadNombre);
                if(!ciudad){
                    printf("No existe la ciudad, la creo\n");
                    ciudad = ciudad_crear(localidadNombre);
                    depto->ciudades = depto_agregar_ciudad(depto, ciudad);
                }
                imprimir_datos_depto(depto);
                Registro *registroAntiguo = registro_buscar(ciudad->registros, registroNuevo->fecha);
                if(registroAntiguo){
                    printf("Encontre un registro antiguo\n");
                    registro_destruir(registroAntiguo);
                }
                ciudad->registros = ciudad_agregar_registro(ciudad, registroNuevo);
                imprimir_datos_depto(depto);
            }
        }

        if(strcmp(comando, "eliminar_registro") == 0){
            sscanf(buffer, "%[^,],%[^\n]", fechaInicio, buffer);
            sscanf(buffer, "%[^,],%[^\n]", deptoNombre, localidadNombre);
            if(0){ //validacion del registro
                printf("Error en los datos del registro a eliminar\n");
            } else {
                printf("Eliminando el registro:\n    fecha: %s\n    Departamento: %s\n    Localidad: %s\n", fechaInicio, deptoNombre, localidadNombre);
                Departamento *depto = departamento_buscar(datos, deptoNombre);
                Ciudad *ciudad = ciudad_buscar(depto->ciudades, localidadNombre);
                Registro *registro = registro_buscar(ciudad->registros, fechaInicio);
                if(registro){
                    registro_destruir(registro);
                    if(ciudad->registros == NULL) ciudad_destruir(ciudad);
                    if(depto->ciudades == NULL) departamento_destruir(depto);
                }
            }
        }

        if(strcmp(comando, "pico") == 0){
            sscanf(buffer, "%[^,],%[^\n]", fechaInicio, localidadNombre);
            if(1){ //validacion del registro
                printf("Error en los datos ingresados\n");
            } else {
                printf("Buscando el pico de la ciudad %s, del departamento %s\n", localidadNombre,deptoNombre);
            }
            //buscar el pico
        }

        if(strcmp(comando, "casos") == 0){
            sscanf(buffer, "%[^,],%[^\n]", fechaInicio, buffer);
            sscanf(buffer, "%[^,],%[^\n]", deptoNombre, localidadNombre);
            if(1){ //validacion del registro
                printf("Error en los datos ingresados\n");
            } else {
                printf("Mostrando los casos acumulados de la ciudad %s, del departamento %s\n", localidadNombre, deptoNombre);
            }
            //imprimir los casos acumulados
        }

        if(strcmp(comando, "doble") == 0){
            sscanf(buffer, "%[^,],%[^\n]", fechaInicio, buffer);
            sscanf(buffer, "%[^,],%[^\n]", deptoNombre, localidadNombre);
            if(1){ //validacion del registro
                printf("Error en los datos ingresados\n");
            } else {
                printf("Mostrando el tiempo de duplicacion de la ciudad %s, del departamento %s\n", localidadNombre,deptoNombre);
            }
            //imprimir el tiempo de duplicacion
        }

        if(strcmp(comando, "graficar") == 0){
            sscanf(buffer, "%[^,],%[^\n]", fechaInicio, buffer);
            sscanf(buffer, "%[^,],%[^\n]", fechaFin, buffer);
            sscanf(buffer, "%[^,],%[^\n]", deptoNombre, localidadNombre);
            if(1){ //validacion del registro
                printf("Error en los datos ingresados\n");
            } else {
                printf("Dibujando las graficas de la ciudad %s, del departamento %s\n", localidadNombre,deptoNombre);
            }
            //dibujar las graficas
        }

        if(strcmp(comando, "salir") == 0){
            printf("\nSaliendo del interprete\n");
            input = -1;
            database_destruir(datos);
        }
    }

    return 0;
}

void imprimir_datos_depto (Departamento *depto){
  Ciudad *iter1 = depto->ciudades;
  Registro *iter2 = NULL;
  printf("\nImprimiendo datos depto: |%s|\n", depto->nombre);
  while (iter1 != NULL){
    printf("\tNombre ciudad: |%s|\n", iter1->nombre);
    iter2 = iter1->registros;
    while (iter2 != NULL){
      printf("\t\tfecha: |%s|\n", iter2->fecha);
      iter2 = iter2->sig;
    }
    iter1 = iter1->sig;
  }

  free(iter1);
  free(iter2);
}

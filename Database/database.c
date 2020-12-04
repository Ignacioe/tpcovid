#include "database.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Database database_inicializar(){
  return NULL;
}

void database_destruir(Database datos){
  Departamento *aux;
  while(datos != NULL){
    aux = datos;
    datos = datos->sig;
    ciudades_destruir(aux->ciudades);
    free(aux->nombre);
    free(aux);
  }
  free(datos);
}

Database database_agregar_depto(Database datos, Departamento *depto){
  depto->sig = datos;
  if(datos){
    datos->ant = depto;
  } else {
    datos = depto;
  }
  return datos;
}

Departamento *departamento_crear(char *nombre){
    Departamento *nuevo = malloc(sizeof(Departamento));
    nuevo->nombre = nombre;
    nuevo->ciudades = NULL;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    return nuevo;
}

void departamento_destruir(Departamento *depto){
  if(depto->ant)
    depto->ant->sig = depto->sig;
  if(depto->sig)
    depto->sig->ant = depto->ant;
  ciudades_destruir(depto->ciudades);
  free(depto->nombre);
  free(depto);
}

void database_imprimir(Database datos, FILE *fp){
  Departamento *depto = datos;
  while(depto != NULL){
    ciudades_imprimir( depto->nombre, depto->ciudades, fp);
    depto = depto->sig;
  }
}

Ciudades depto_agregar_ciudad(Departamento *depto, Ciudad *ciudad){
  ciudad->sig = depto->ciudades;
  if(depto->ciudades){
    depto->ciudades->ant = ciudad;
  } else {
    depto->ciudades = ciudad;
  }
  return depto->ciudades;
}

Departamento *departamento_buscar(Database datos, char *nombre){
    Departamento *aux = datos;
    while(aux != NULL){
      printf("aux->nombre:%s, nuevoNombre:%s\n", aux->nombre, nombre);
      if(strcmp(aux->nombre, nombre) == 0) return aux;
      aux = aux->sig;
    }
    return NULL;
}

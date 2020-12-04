#include "ciudad.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Ciudad *ciudad_crear(char *nombre){
    Ciudad *nuevo = malloc(sizeof(Ciudad));
    nuevo->nombre = nombre;
    nuevo->registros = NULL;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    return nuevo;
}

void ciudades_destruir(Ciudades ciudades){
  Ciudad *aux;
  while(ciudades != NULL){
    aux = ciudades;
    ciudades = ciudades->sig;
    registros_destruir(aux->registros);
    free(aux->nombre);
    free(aux);
  }
  free(ciudades);
}

void ciudad_destruir(Ciudad *ciudad){
    if(ciudad->ant)
      ciudad->ant->sig = ciudad->sig;
    if(ciudad->sig)
      ciudad->sig->ant = ciudad->ant;
    free(ciudad->nombre);
    free(ciudad);
}

Registros ciudad_agregar_registro(Ciudad *ciudad, Registro *registro){
    registro->sig = ciudad->registros;
    if(ciudad->registros){
        ciudad->registros->ant = registro;
    } else {
        ciudad->registros = registro;
    }
    return ciudad->registros;
}

void ciudades_imprimir(char *deptoNombre, Ciudades ciudades, FILE *fp){
  Ciudad *ciudad = ciudades;
  while(ciudad != NULL){
    registros_imprimir( deptoNombre, ciudad->nombre, ciudad->registros, fp);
    ciudad = ciudad->sig;
  }
}

Ciudad *ciudad_buscar(Ciudades ciudades, char *nombre){
    Ciudad *aux = ciudades;
    while(aux != NULL){
      printf("aux->nombre:%s, nuevoNombre:%s\n", aux->nombre, nombre);
      if(strcmp(aux->nombre, nombre) == 0) return aux;
      aux = aux->sig;
    }
    return NULL;
}

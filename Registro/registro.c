#include "registro.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Registro *registro_crear(char *fecha, char *confirmados, char *descartados, char *enEstudio){
    Registro *nuevo = malloc(sizeof(Registro));
    nuevo->fecha = fecha;
    nuevo->confirmados = atoi(confirmados);
    nuevo->descartados = atoi(descartados);
    nuevo->enEstudio = atoi(enEstudio);
    nuevo->ant = NULL;
    nuevo->sig = NULL;
    return nuevo;
}

void registros_destruir(Registros registros){
  Registro *aux;
  while(registros != NULL){
    aux = registros;
    registros = registros->sig;
    free(aux->fecha);
    free(aux);
  }
  free(registros);
}

void registro_destruir(Registro *registro){
  if(registro->ant)
    registro->ant->sig = registro->sig;
  if(registro->sig)
    registro->sig->ant = registro->ant;
  free(registro->fecha);
  free(registro);
}

void registros_imprimir(char *deptoNombre, char *localidadNombre, Registros registros, FILE *fp){
  Registro *registro = registros;
  int total;
  while(registro != NULL){
    total = registro->confirmados + registro->descartados + registro->enEstudio;
    fprintf(fp, "%s,%s,%s,%d,%d,%d,%d\n", registro->fecha, deptoNombre, localidadNombre, registro->confirmados, registro->descartados, registro->enEstudio, total);
    registro = registro->sig;
  }
}

Registro *registro_buscar(Registros registros, char *fecha){
    Registro *aux = registros;
    while(aux != NULL){
      if(strcmp(aux->fecha, fecha) == 0) return aux;
      aux = aux->sig;
    }
    return NULL;
}

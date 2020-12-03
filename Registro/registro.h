#ifndef __REGISTRO_H__
#define __REGISTRO_H__

#include <stdio.h>

typedef struct _GNodoR {
  char *fecha;
  int confirmados;
  int descartados;
  int enEstudio;
  struct _GNodoR *sig;
  struct _GNodoR *ant;
} Registro;

typedef Registro *Registros;

/**
 * Crea una nueva ciudad a partir de la fecha, la cantidad de
 * casos confirmados, descartados y en estudio.
 */
Registro *registro_crear(char *fecha, char *confirmados, char *descartados, char *enEstudio);

/**
 * Libera una lista de registros.
 */
void registros_destruir(Registros registros);

/**
 * Libera un registro.
 */
void registro_destruir(Registro *registro);

/**
 * Maneja la impresion de los datos de una lista de registros a csv
 */
void registros_imprimir(char *deptoNombre, char *localidadNombre,Registros registros, FILE *fp);

/**
 * Busca (y devuelve si existe) un registro para una fecha dada en una ciudad dada.
 */
Registro *registro_buscar(Registros registros, char *fecha);

#endif                          /* __REGISTRO_H__ */

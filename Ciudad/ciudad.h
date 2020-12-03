#ifndef __CIUDAD_H__
#define __CIUDAD_H__

#include <stdio.h>
#include "../Registro/registro.h"

typedef struct _GNodoC {
  char *nombre;
  Registros registros;
  struct _GNodoC *sig;
  struct _GNodoC *ant;
} Ciudad;

typedef Ciudad *Ciudades;

/**
 * Crea una nueva ciudad a partir del nombre.
 */
Ciudad *ciudad_crear(char *nombre);

/**
 * Elimina una lista de ciudades.
 */
void ciudades_destruir(Ciudades ciudades);

/**
 * Elimina una ciudad (se usa si no tiene registros asociados).
 */
void ciudad_destruir(Ciudad *ciudad);

/**
 * Agrega un registro a una ciudad.
 */
Registros ciudad_agregar_registro(Ciudad *ciudad, Registro *registro);

/**
 * Maneja la impresion de los datos de una lista de ciudades a csv
 */
void ciudades_imprimir(char *nombreDepartamento, Ciudades ciudades, FILE *fp);

/**
 * Busca (y devuelve si existe) una ciudad con un nombre dado en un departamento dado.
 */
Ciudad *ciudad_buscar(Ciudades ciudades, char *nombre);

#endif                          /* __CIUDAD_H__ */

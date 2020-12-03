#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <stdio.h>
#include "../Ciudad/ciudad.h"

typedef struct _GNodoD {
  char *nombre;
  Ciudades ciudades;
  struct _GNodoD *sig;
  struct _GNodoD *ant;
} Departamento;

typedef Departamento *Database;

/**
 * Crea una nueva estructura de datos vacia.
 */
Database database_inicializar();

/**
 * Libera todo la memoria utilizada por la database.
 */
void database_destruir(Database datos);

/**
 * Agrega un nuevo departamento al principio de la database, y la devuelve.
 */
Database database_agregar_depto(Database datos, Departamento *depto);

/**
 * Crea un nuevo departamento a partir del nombre.
 */
Departamento *departamento_crear(char *nombre);

/**
 * Libera un departamento (se usa si no tiene ciudades asociadas).
 */
void departamento_destruir(Departamento *depto);

/**
 * Devuelve un intervalo formado por los extremos dados.
 */
void database_imprimir(Database datos, FILE *fp);

/**
 * Agrega una nueva ciudad al principio de la lista de ciudades de un depto.
 */
Ciudades depto_agregar_ciudad(Departamento *depto, Ciudad *ciudad);

/**
 * Busca (y devuelve si existe) un departamento con un nombre dado en la database.
 */
Departamento *departamento_buscar(Database datos, char *nombre);

#endif                          /* __DATABASE_H__ */

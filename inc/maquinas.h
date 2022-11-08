#ifndef _MAQUINAS_H_
#define _MAQUINAS_H_

typedef enum {
    EST_A = 0,
    EST_B = 1,
    EST_C = 2,
    EST_D = 3,
} nombre_est;

typedef enum {
    SUCCESS = 0,
    FAILURE = 1,
} valor_ret;

typedef struct {
    nombre_est origen;
    valor_ret  retorno;
    nombre_est destino;
} transicion;

transicion transiciones[] = {
    {EST_A, SUCCESS, EST_B},
    {EST_A, FAILURE, EST_C},
    {EST_B, SUCCESS, EST_C},
    {EST_B, FAILURE, EST_A},
    {EST_C, SUCCESS, EST_D},
    {EST_C, FAILURE, EST_B},
};

#define ESTADO_ENTRADA EST_A
#define ESTADO_SALIDA  EST_D


valor_ret est_a(void);

valor_ret est_b(void);

valor_ret est_c(void);

valor_ret est_d(void);

nombre_est buscar_transicion(nombre_est, valor_ret);


/* estados: array de punteros a función que toma void y devuelve valor_ret */
valor_ret (* estados[])(void) = {est_a, est_b, est_c, est_d};

#endif

#include <stdio.h>
#include <unistd.h> /* sleep */
#include <stdlib.h> /* rand */
#include <time.h>   /* time */

#include "inc/maquinas.h"

valor_ret est_a(void) {
    printf("Estamos en A\n");
    return (valor_ret) rand() % 2;
}

valor_ret est_b(void) {
    printf("Estamos en B\n");
    return (valor_ret) rand() % 2;
}

valor_ret est_c(void) {
    printf("Estamos en C\n");
    return (valor_ret) rand() % 2;
}

valor_ret est_d(void) {
    printf("Estamos en D\n");
    return (valor_ret) rand() % 2;
}

nombre_est buscar_transicion(nombre_est est_act, valor_ret ret) {
    nombre_est retorno;
    if (est_act == ESTADO_SALIDA)
        retorno = est_act;
    else
        retorno = transiciones[2 * (est_act) + ret].destino;

    return retorno;
}

int main(void) {
    int continuar      = 1;
    nombre_est est_act = ESTADO_ENTRADA;
    valor_ret  ret;

    srand(time(NULL));

    while (continuar == 1) {
        switch(est_act) {
        case EST_A:
            ret = est_a();
            est_act = buscar_transicion(est_act, ret);
            break;
        case EST_B:
            ret = est_b();
            est_act = buscar_transicion(est_act, ret);
            break;
        case EST_C:
            ret = est_c();
            est_act = buscar_transicion(est_act, ret);
            break;
        case EST_D:
            ret = est_d();
            continuar = 0;
            break;
        }
    }

    return 0;
}

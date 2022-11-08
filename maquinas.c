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
    if (est_act == ESTADO_SALIDA)
        return est_act; /* No debería pasar nunca */
    
    /* Truco mañoso que sólo nos vale ahora por tal y como hemos puesto las
     * transiciones y los estados en el array *transiciones* */
    return transiciones[2 * (est_act) + ret].destino;
}

int main(void) {
    nombre_est est_act = ESTADO_ENTRADA;
    valor_ret  ret;

    valor_ret (* fun_est)(void);

    srand(time(NULL));

    while (1) {
        fun_est = estados[est_act];
        ret = fun_est();
        if (est_act == ESTADO_SALIDA) {
            return ret;
        }
        est_act = buscar_transicion(est_act, ret);
    }

    return 0;
}

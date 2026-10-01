#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "POLY.h"

struct polynomial_t {
    size_t n;       /* maior ordem armazenada */
    double *xs;     /* [x_0, x_1, ..., x_n] */
    double *ds;     /* coeficientes de Newton */
};
void POLY_interpolate(Polynomial ans, const double *xs, const double *ys, size_t n) {
    
    ans->n = n;
    size_t j = (n+1);
    
    free( ans->xs );
    free( ans->ds );
    ans->xs = malloc(j * sizeof(double));
    ans->ds = malloc(j * sizeof(double));
    
    for( size_t i = 0 ; i < j ; i++ ) {
        ans->xs[i] = xs[i];
        ans->ds[i] = ys[i];
    }
    
    for( size_t i = 1 ; i < j ; i++ ) {
        for( size_t k = n ; k >= i ; k-- ){
            ans->ds[k] = (ans->ds[k] - ans->ds[k - 1])/(ans->xs[k]-ans->xs[k-i]);
        }
    }
}

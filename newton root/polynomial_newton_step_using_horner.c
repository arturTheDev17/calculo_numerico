#include <float.h>
#include <math.h>
bool polynomial_newton_step(const double *coefficients, size_t degree,
                            double *x) {
    double fx = coefficients[degree];
    double dfx = fx;
    for ( size_t i = degree - 1 ; i > 0 ; i-- ){
        fx = coefficients[i] + (*x) * fx;   
        dfx = fx + (*x) * dfx;
    }
    fx = coefficients[0] + (*x) * fx;

    if ( dfx == 0.0 || fabs(*x - fx/dfx) > DBL_MAX ) return false;
    *x = *x - fx/dfx;
    return true;
}

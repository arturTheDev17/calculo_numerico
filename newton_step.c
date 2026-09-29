#include <float.h>
#include <math.h>
bool newton_step(double x, double fx, double dfx, double *next) {
    if ( dfx == 0.0 || fabs(x - fx/dfx) > DBL_MAX ) return false;
    *next = x - fx/dfx;
    return true;
}

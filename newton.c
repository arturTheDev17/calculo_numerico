#include <math.h>
#include <float.h>

bool newton(DifferentiableFunction f, double x0, double tol,
            size_t max_iter, double *root) {
    double fx , fx1 , dfx;
 
    for ( int i = 0 ; i <= max_iter ; i++ ){
        fx = DF_eval(f , x0);
        if ( fx == 0 || fabs(fx1 - fx) <= tol ) {
            *root = x0;
            return true;
        }
        
        dfx = DF_derivative (f , x0);
        
        if ( dfx == 0.0 || fabs(x0 - fx/dfx) > DBL_MAX ) return false;
       
        x0 -= fx/dfx;
        fx1 = fx;
    }
    
    return false;
}

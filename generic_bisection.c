#include <stdbool.h>
#include "CONTINUOUS_FUNCTION.h"
#include <math.h>

bool opposite_sign(double x, double y) {
    return (x < 0 && y > 0) || (x > 0 && y < 0);
}

double safe_midpoint(double a, double b) {
    
    // if (opposite_sign(a,b)) return a/2.0 + b/2.0;
    
    return a + (b-a)/2.0;
}

bool bisection(ContinuousFunction f, double a, double b,
               double tol, double *root) {

    double m , fm , fa = CF_eval( f , a ) , fb = CF_eval( f , b );
    
    if(fa == 0 ){
        *root = a;
        return true;
    }
    
    if( fb == 0 ){
        *root = b;
        return true;
    }
    
    if(!opposite_sign(fa , fb)) return false;
    
    while ( fabs(b-a) > tol ){
        m = safe_midpoint( a , b );
        fm = CF_eval( f , m );   
        fa = CF_eval( f , a );
        
        if ( fm == 0 ) {
            *root = m; 
            return true;
        }
         
        if( opposite_sign( fa , fm)){
            b = m;
        } else {
            a = m;
            *root = m;
        }
    }
    
    return true;
}

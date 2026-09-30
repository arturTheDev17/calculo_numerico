#include <stdbool.h>
#include <stddef.h>
#include "CONTINUOUS_FUNCTION.h"

bool find_bracket(ContinuousFunction f, double x0, double step,
                  size_t max_steps, double *a, double *b) {
    double x , fx0 = CF_eval( f, x0 ) , fx;
    for ( int i = 0 ; i < max_steps ; i++ ){
        if( fx0 == 0 ){
            *a = x0;
            *b = x0;
            return true;
        }
        x = x0 + step;
        fx = CF_eval(f , x);
        if ( fx > 0 && fx0 < 0 || fx < 0 && fx0 > 0 ){
            *a = x0;
            *b = x;
            return true;
        }
        x0 = x;
        fx0 = fx;
        
        
    }
    return false;
}

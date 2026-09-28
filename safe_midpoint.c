#include <stdbool.h>
#include <math.h>

bool opposite_sign(double x, double y) {
    
    if( fabs(x) + x == 0 && fabs(y) + y == 0 ) return false;
    if( fabs(x) + x == 2*x && fabs(y) + y == 2*y ) return false;
    return true;
}

double safe_midpoint(double a, double b) {
    
    if (opposite_sign(a,b)) return a/2 + b/2;
    
    return a + (b-a)/2;
}

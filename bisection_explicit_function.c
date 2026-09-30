double f ( double y , double root ){
    return exponential(y) - root;
}

double natural_log(double x, double tol) {
    
    double a = -16 , b = 16 , m;
    double fa = f(a , x) , fm = f(b , x);
    
    if( fa == 0 ) return a;
    if( fm == 0 ) return b;
    
    double diff = (b >= a) ? (b - a) : (a - b);
    
    while ( diff >= tol ) {
        
        m = a + (b-a)/2.0;
    
        fm = f(m , x);
        if ( fm == 0 ) return m;

        if ( fm > 0 && fa < 0 ) b = m;
        else a = m;
        
        diff = (b >= a) ? (b - a) : (a - b);
        fa = f(a , x);
    }
    
    return m;
}

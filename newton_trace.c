void newton_trace(DifferentiableFunction f, double x0, size_t steps,
                  double *trace) {
    double fx , dfx;
    for ( int i = 0 ; i <= steps ; i++ ){
        fx = DF_eval(f , x0);
        dfx = DF_derivative (f , x0);
        trace[i] = x0;
        x0 -= fx/dfx;
    }
}

void forward_difference(ContinuousFunction f, double x, double h,
  double * derivative) {
        //otimizar ao inverter h (pra outras coisas pode funcionar, aqui acho que nao)
        double inv_h = 1.0 / h;
        *derivative = (CF_eval(f, x + h) - CF_eval(f, x)) * inv_h;
  }

Spline SPLINE_periodic(size_t n, const double x[n+1],
    const double y[n+1]) {
    Spline S = malloc(sizeof *S);
    S->n = n;
    S->x = malloc((n + 1) * sizeof *S->x);
    S->a = malloc(n * sizeof *S->a);
    S->b = malloc(n * sizeof *S->b);
    S->c = malloc(n * sizeof *S->c);
    S->d = malloc(n * sizeof *S->d);

    for (size_t i = 0; i <= n; i++) S->x[i] = x[i];

    double h[n], delta[n], D[n], r1[n], r2[n], s[n+1];

    //subintervalos e deltas
    for (size_t i = 0; i < n; i++) {
        h[i] = x[i + 1] - x[i];
        delta[i] = (y[i + 1] - y[i]) / h[i];
    }

    if (n == 2) {
        //caso simples
        double H = h[0] + h[1], r0 = 6.0 * (delta[0] - delta[1]), r_1 = 6.0 * (delta[1] - delta[0]);
        s[0] = (2.0 * r0 - r_1) / (3.0 * H);
        s[1] = (2.0 * r_1 - r0) / (3.0 * H);
    } else {
        
        //sistema linear dos nos
        for (size_t i = 1; i < n; i++) {
            D[i] = 2.0 * (h[i - 1] + h[i]);
            r1[i] = 6.0 * (delta[i] - delta[i - 1]);
            r2[i] = 0.0; //ja prepara r2
        }
        
        r2[1] = -h[0]; r2[n - 1] = -h[n - 1];
        
        //thomas pt1
        for (size_t i = 2; i < n; i++) {
            double m = h[i - 1] / D[i - 1];
            D[i] -= m * h[i - 1];
            r1[i] -= m * r1[i - 1];
            r2[i] -= m * r2[i - 1];
        }

        r1[n - 1] /= D[n - 1];
        r2[n - 1] /= D[n - 1];
        
        //thomas pt2
        for (size_t i = n - 2; i >= 1; i--) {
            r1[i] = (r1[i] - h[i] * r1[i + 1]) / D[i];
            r2[i] = (r2[i] - h[i] * r2[i + 1]) / D[i];
        }

        double D0 = 2.0 * (h[n - 1] + h[0]), r0 = 6.0 * (delta[0] - delta[n - 1]);
        s[0] = (r0 - h[0] * r1[1] - h[n - 1] * r1[n - 1]) / (D0 + h[0] * r2[1] + h[n - 1] * r2[n - 1]);

        //segunda derivada
        for (size_t i = 1; i < n; i++) s[i] = r1[i] + s[0] * r2[i];
    }

    s[n] = s[0];

    for (size_t i = 0; i < n; i++) {
        S->a[i] = y[i];
        S->b[i] = delta[i] - h[i] * (2.0 * s[i] + s[i + 1]) / 6.0;
        S->c[i] = s[i] / 2.0;
        S->d[i] = (s[i + 1] - s[i]) / (6.0 * h[i]);
    }
    return S;
}

void solve_many_from_compact_LU(size_t n, const double LU[n][n], size_t r, double B[n][r]) {

	double *y = malloc(n * sizeof(double));

    //adaptei a funcao fornecida pelo professor para usar uma matriz e operar varias vezes sobre a matriz B
	for( size_t c = 0 ; c < r ; c++ ) {
		for (size_t i = 0; i < n; i++) {
			y[i] = B[i][c];
			for (size_t j = 0; j < i; j++) {
				y[i] -= LU[i][j] * y[j];
			}
			y[i] /= LU[i][i];
		}

		for (size_t i = n; i-- > 0;) {
			B[i][c] = y[i];
			for (size_t j = i + 1; j < n; j++) {
				B[i][c] -= LU[i][j] * B[j][c];
			}
		}
	}
	
	free(y);

}
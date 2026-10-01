#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool opposite_sign(double x, double y) {
    return (x < 0 && y > 0) || (x > 0 && y < 0);
}

size_t *sign_change_indices(const double *values, size_t n,
                            size_t *count) {
    
    (*count) = 0;
    size_t * vetor = malloc( n * sizeof(size_t) );
    
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        if ( opposite_sign( values[i+1], values[i] ) ){
            vetor[(*count)] = i;
            (*count)++;
        }
    }
    
    if( *count == 0 ){
        free(vetor);
        return NULL;
    }

    return vetor;
}

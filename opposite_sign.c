#include <stdbool.h>
#include <math.h>

bool opposite_sign(double x, double y) {
    return (x < 0 && y > 0) || (x > 0 && y < 0);
}

#include "plane.h"
/*
    a, b, c - point for set palne
    vectors x, y: 
        x = {b0 - a0, b1 - a1, b2 - a2}
        y = {c0 - a0, c1 - a1, c2 - a2}
    Plane:
        Ax + By + Cz + D = 0
    |x - a0  x0  y0 |          (x - a0)|x1  y1| - (y - a1)|x0  y0| + (z - a2)|x0  y0| = 0  =>
    |y - a1  x1  y1 | = 0  =>          |x2  y2|           |x2  y2|           |x1  y1|
    |z - a2  x2  y2 |          

    x|x1  y1| - y|x0  y0| + z|x0  y0| - a0|x1  y1| + a1|x0  y0| - a2|x0  y0| = 0  =>
     |x2  y2|    |x2  y2|    |x1  y1|     |x2  y2|     |x2  y2|     |x1  y1|
    
    A = |x1  y1|  B = -|x0  y0|  C = |x0  y0|
        |x2  y2|       |x2  y2|      |x1  y1|
    D = -a0|x1  y1| + a1|x0  y0| - a2|x0  y0|
           |x2  y2|     |x2  y2|     |x1  y1|
    D = -a0*A + a1*B - a2*C
*/
double det2(double a00, double a01, double a10, double a11) {
    return a00*a11 - a10*a01;
}
plane :: plane(double* a, double* b, double* c) {
    double x[3] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
    double y[3] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};

    A = det2(x[1], y[1], x[2], y[2]);
    B = -det2(x[0], y[0], x[2], y[2]);
    C = det2(x[0], y[0], x[1], y[1]);
    D = -a[0]*A - a[1]*B - a[2]*C;
}
int plane :: check(double* x) {
    double position = A*x[0] + B*x[1] + C*x[2] + D;
    if (position > 0)
        return 1;
    else if (position < 0)
        return -1;
    else 
        return 0;
}

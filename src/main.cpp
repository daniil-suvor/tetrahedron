#include "tetrahedron.h"
#include <iostream>

int main() {
    double a[3] = {5, 0, 0};
    double b[3] = {0, 9, 0};
    double c[3] = {0, 0, 11};
    double d[3] = {0, 0, 0};
    tetrahedron t(a, b, c, d);
    double x1[3] = {100, 19, 0};
    double x2[3] = {0, 0, 0};
    double x3[3] = {1, 2, 3};
    double x4[3] = {-1, -2, -3};
    std:: cout << t.check_point(x1) << std :: endl;
    std:: cout << t.check_point(x2) << std :: endl;
    std:: cout << t.check_point(x3) << std :: endl;
    std:: cout << t.check_point(x4) << std :: endl;
    t.print_centr();
    return 0;
}

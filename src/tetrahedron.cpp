#include "tetrahedron.h"
/*
    planes - for plane of tetrahedron
    points_position - position opposite point for each planes
    if position some point is like position opposite point for each planes 
    it is in tetrahedron

    Heron's formula states that the area of a triangle whose sides have lengths ab, bc, and ca is
    S = 1/4sqrt((ab + bc + ca)(-ab + bc + ca)(ab - bc + ca)(ab + bc - ca))

    Inscribed sphere center coordinates: {x_r, y_r, z_r}
    Si - area of the face opposite the i vertex

    x_r = (S1*x1 + S2*x2 + S3*x3 + S4*x4)/(S1 + S2 + S3 + S4)

    by analogy for other coordinates
*/

double triangle_area(double* a, double* b, double* c) {
    double ab = sqrt(pow(b[0] - a[0], 2) + pow(b[1] - a[1], 2) + pow(b[2] - a[2], 2));
    double bc = sqrt(pow(c[0] - b[0], 2) + pow(c[1] - b[1], 2) + pow(c[2] - b[2], 2));
    double ca = sqrt(pow(a[0] - c[0], 2) + pow(a[1] - c[1], 2) + pow(a[2] - c[2], 2));
    return sqrt((ab + bc + ca)*(-ab + bc + ca)*(ab - bc + ca)*(ab + bc - ca))/4;
}
tetrahedron :: tetrahedron(double* a, double* b, double* c, double* d) {
    vertex = {a, b, c, d};
    planes = {plane(a, b, c), plane(b, c, d),
              plane(a, c, d), plane(a, b, d)};
    vertex_position = {planes[0].check(d), planes[1].check(a),
                       planes[2].check(b), planes[3].check(c)};
}
int tetrahedron :: check_point(double* x) {
    for (int i = 0; i < 4; i++) {
        if (planes[i].check(x)*vertex_position[i] < 0)
            return 0;
    }
    return 1;
}
void tetrahedron :: centr() {
    std :: vector<double> area = {
        triangle_area(vertex[1], vertex[2], vertex[3]),
        triangle_area(vertex[0], vertex[2], vertex[3]),
        triangle_area(vertex[0], vertex[1], vertex[3]),
        triangle_area(vertex[0], vertex[1], vertex[2])
    };
    double sum_area = 0;
    std :: for_each(area.begin(), area.end(), [&](double si){sum_area += si;});
    double r_i;
    for (int i = 0; i < 3; i++) {
        r_i = 0;
        auto area_i = area.begin();
        for (auto vertex_i: vertex) {
            r_i += vertex_i[i] * (*area_i);
            area_i++;
        }
        coordinat_of_centr.push_back(r_i / sum_area);
    }
}
void tetrahedron :: print_centr() {
    if (coordinat_of_centr.empty()) {
        centr();
    }
    for (auto iter : coordinat_of_centr) {
        std :: cout << iter << std :: endl;
    }
}

#ifndef _TETRAHEDRON_H_
#define _TETRAHEDRON_H_
#include "plane.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
class tetrahedron {
    public:
        tetrahedron(double* a, double* b, double* c, double* d);
        int check_point(double* x);
        void centr();
        void print_centr();
    private:
        std :: vector <plane> planes;
        std :: vector <int> vertex_position;
        std :: vector <double*> vertex;
        std :: vector <double> coordinat_of_centr;
};
#endif  // _TETRAHEDRON_H_
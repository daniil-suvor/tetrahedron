#ifndef _PLANE_H_
#define _PLANE_H_
class plane {
    public:
        plane(double* a, double* b, double* c);
        int check(double* x);
    private:
        double A, B, C, D;
};
#endif  // _PLANE_H_

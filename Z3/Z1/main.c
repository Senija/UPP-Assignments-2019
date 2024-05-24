#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define delta 0.01

double f(double x){
    return x*x-2*x+3;
}

double g(double x){
    return 2*x;
}

double h(double x){
    return f(x)-g(x);
}

double presjek(double A, double B, int* status){
    double H=(A+B)/2.;
    if(fabs(h(A)-0)<epsilon && fabs(h(B)-0)<epsilon && fabs(h(H)-0)<epsilon) {
        *status=2;
        return 0;
    } 
    else if(fabs(h(A)-0)<=epsilon) {
        *status=0;
        return A;
    } 
    else if(fabs(h(B)-0)<=epsilon) {
        *status=0;
        return B;
    } 
    else if(fabs(h(H)-0)<=epsilon) {
        *status=0;
        return H;
    } 
    else if(h(A)*h(H)<=0) {
        return presjek(A, H, status);
    } 
    else if(h(H)*h(B)<=0) {
        return presjek(H, B, status);
    }

    else if((h(A)>0 && h(B)>0 && h(H)>=0) || (h(A)<0 && h(B)<0 && h(H)<=0)) {
        if(fabs(A-B)<delta) {
            *status=1;
            return 0;
        }
        double rez1 = presjek(A, H, status);
        if(*status == 1) {
            return presjek(H, B, status);
        } else
            return rez1;
    }
    
}
int main()
{
    int status=-1;
    double rez = presjek(0, 100, &status);
    printf("%.3f %d\n", rez, status);

    return 0;
}

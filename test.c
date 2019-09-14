#include <math.h>
#include <stdio.h>

double (*f)(double)=sin;
double (*g())(double){return sin;}

int main(){
    int i;
    printf("%f,%f\n",f(0.5),g()(0.5));
    return 0;
}

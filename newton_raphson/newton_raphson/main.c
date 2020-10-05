//
//  main.c
//  newton_raphson
//
//  Created by William Hutzel on 5/7/20.
//  Copyright © 2020 William Hutzel. All rights reserved.
//
//THIS NOW HAS TRACEBACk!
#include <stdio.h>
#include <math.h>

double df(double,double);
double df2(double,double);
double funct(double);
double funct2(double);

double eps = 1e-8, E0 = 10;

int main() {
    double dx = 1e-2,dfun = 0,x=5,funval_new,funval_old=0;
    int it,itmax=10, iter=0;
    for (it=1;it<=itmax;it++){
        if (fabs(funct2(x)) < eps){
            funval_new = funct2(x);
            printf("the root has been found\n");
            printf("it: %d\tfunct: %.12f\tx: %.12f\n",iter,funval_new,x);
            break;
        }
        else{
            funval_old = funct2(x);
            x+=dx;
            funval_new = funct2(x);
            printf("dfun: %f\t x: %f\t dx: %f\n",dfun,x,dx);
            if (pow(fabs(funval_old),2)<pow(fabs(funval_new),2) || fabs(x+dx)>E0){
                x-=dx;
                dx*=.5;
                iter+=1;
                printf("new dx: %f\n",dx);
            }
            else{
            printf("it: %d\t dx: %f\tfunct: %f\n",it,dx,funval_new);
                dfun = df2(x,dx);
                dx = (-1)*funct2(x)/dfun;
                iter = it+1;
            }
        }
    }
    return 0;
}

double df(double x,double dx){
    double fplus,fminus;
    fplus = sqrt(E0-(x+dx/2))*tan(sqrt(E0-(x+dx/2)));
    fminus = sqrt(E0-(x-dx/2))*tan(sqrt(E0-(x-dx/2)));
    return (fplus-fminus)/dx ;
}

double df2(double x,double dx){
    double fplus,fminus;
    fplus = sqrt((x+dx/2))*(cos(sqrt(E0-(x+dx/2)))/sin(sqrt(E0-(x+dx/2))))-sqrt(E0-(x+dx/2));
    fminus = sqrt((x-dx/2))*(cos(sqrt(E0-(x-dx/2)))/sin(sqrt(E0-(x-dx/2))))-sqrt(E0-(x-dx/2));
    return (fplus-fminus)/dx ;
}

double funct(double x){
    double fun;
    fun = sqrt(E0-x)*tan(sqrt(E0-x));
    return fun;
}

double funct2(double x){
    double fun;
    fun = sqrt(x)*(cos(sqrt(E0-x))/sin(sqrt(E0-x)))-sqrt(E0-x);
    return fun;
}

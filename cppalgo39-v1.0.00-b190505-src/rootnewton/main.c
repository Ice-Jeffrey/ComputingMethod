/*
 *����ֵ���������̳�(�ڶ���)�����ܳ�����
 *
 * Beijing University of Chemical Technology
 * March 1st, 2013 
 */

#include <stdio.h>
#include <math.h>
double f(double x);
double df(double x);


void main(void) {
    double epsilon,x0,x1,fx0,dfx0;
    long i,maxi;
    printf("\n������x�ľ���Ҫ��");
    scanf("%lf",&epsilon);
    printf("\n�����������ֵ��");
    scanf("%lf",&x1);
    printf("\n������������������");
    scanf("%ld",&maxi);

    for(i=0; i<maxi; i++) {
        x0=x1;
        fx0=f(x0);
        dfx0=df(x0);
        x1=x0-fx0/dfx0;
        if(fabs(x1-x0)<=epsilon)
            break;
    }

    if(i<maxi)
        printf("\n����f(x)=0�ĸ�x=%lf��",x1);
    else
        printf("\n���������ѳ������ޡ�");
}


double f(double x) {
    return x*exp(x) - 1;    /*���㲢���غ���ֵf(x)*/
}
double df(double x) {
    return exp(x) + x*exp(x);    /*���㲢���غ���ֵf��(x)*/
}

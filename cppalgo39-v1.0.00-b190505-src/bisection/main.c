/*
 *����ֵ���������̳�(�ڶ���)�����ܳ�����
 *
 * Beijing University of Chemical Technology
 * March 1st, 2013 
 */

#include <stdio.h>

double f(double x) {
    return x*x - 4;    /*���㲢���غ���ֵf(x)*/
}

void main(void) {
    double a,b,epsilon,x,middle;
    printf("\n������x�ľ���Ҫ��");
    scanf("%lf",&epsilon);
    printf("\n�������и�����ı߽�a,b��");
    scanf("%lf,%lf",&a,&b);
    if(f(a)==0)x=a;
    else if(f(b)==0)	x=b;
    else {
        while((b-a)/2>epsilon) {
            middle=(a+b)/2;
            if(f(middle)==0)	break;
            else if(f(a)*f(middle)>0)	a=middle;
            else	b=middle;
        }
        x=(a+b)/2;
    }
    printf("\n����f(x)=0�ĸ�x=%lf��",x);
}

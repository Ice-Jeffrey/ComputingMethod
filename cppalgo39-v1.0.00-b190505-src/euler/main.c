/*
 *����ֵ���������̳�(�ڶ���)�����ܳ�����
 *
 * Beijing University of Chemical Technology
 * March 1st, 2013 
 */

#include <stdio.h>
#define MAXSIZE 50

double f(double x,double y);

void main(void) {
    double a,b,h,x[MAXSIZE],y[MAXSIZE];
    long i,n;
    printf("\n�������������a,b��");
    scanf("%lf,%lf",&a,&b);
    printf("\n�����벽��h��");
    scanf("%lf",&h);
    n=(long)((b-a)/h);
    x[0]=a;

    printf("\n���������x[0]=%lf����������y[0]��",x[0]);
    scanf("%lf",&y[0]);
    for(i=0; i<n; i++) {
        x[i+1]=x[i]+h;
        y[i+1]=y[i]+h*f(x[i],y[i]);
    }
	
    printf("\n������Ϊ��");

    for(i=0; i<=n; i++)
        printf("\nx[%ld]=%lf,y[%ld]=%lf",i,x[i],i,y[i]);
}

double f(double x,double y) {
    return y - 2*x/y;    /*���㲢���غ���ֵf(x,y)*/
}

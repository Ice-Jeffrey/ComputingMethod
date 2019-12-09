/*
 *����ֵ���������̳�(�ڶ���)�����ܳ�����
 *
 * Beijing University of Chemical Technology
 * March 1st, 2013 
 */

#include "stdio.h"

double compositeSimpson(double(*f)(double),double a,double b,int n);
double myfun(double x);

void main() {
    double(*fun)(double);
    double a,b,S4;
    int n;

    a=0;
    b=1;
    n=4;
    fun=myfun;
    S4=compositeSimpson(fun,a,b,n);
    printf("/n����ֵΪ:%f/n",S4);

}


/*
 * �ø��������������㺯��f(x)��a��b�Ļ���ֵ
 * ����: f--����f(x)��ָ��
 *       a--��������
 *       b--��������
 *       n--�ֶ���
 * ���: ����ֵΪf(x)��a�㵽b��Ļ���ֵ
 */
double compositeSimpson(double(*f)(double),double a,double b,int n) {
    double s,h,x;
    int i;
    printf("x/t/tf(x)/t/ts/n");
    s=(*f)(a)-(*f)(b);
    h=(b-a)/(2*n);
    x=a;
    for(i=1; i<2*n; i+=2) {
        x+=h;
        s+=4*(*f)(x);
        printf("%f/t%f/t%f/n",x,(*f)(x),s*h/3);
        x+=h;
        s+=2*(*f)(x);
        printf("%f/t%f/t%f/n",x,(*f)(x),s*h/3);

    }
    return(s*h/3);
}


double myfun(double x) {
    double y;

    y=4.0/(1+x*x);

    return(y);

}
/*
 *����ֵ���������̳�(�ڶ���)�����ܳ�����
 *
 * Beijing University of Chemical Technology
 * March 1st, 2013 
 */

#include <stdio.h>
#include <math.h>
#define MAXSIZE 50

void input(double x[MAXSIZE], double y[MAXSIZE], long n);

void main(void) {
    double x[MAXSIZE], y[MAXSIZE], _x, _y, t;
    long n, i, j;
    printf("\n�������ֵ�ڵ�ĸ���: ");
    scanf("%ld", &n);
    input(x, y, n);
    printf("\n�������ֵ�㣺");
    scanf("%lf", &_x);
    _y = 0;
    for(i = 0; i <= n - 1; i++) {
        t = 1;
        for(j = 0; j <= n-1; j++)
            if(j != i)
                t*=(_x-x[j])/(x[i] - x[j]);
        _y+= t*y[i];
    }
    printf("\n��ֵ��(x,y) = (%lf, %lf)��",_x, _y);
}

void input(double x[MAXSIZE], double y[MAXSIZE], long n) {
    long i;
    for(i = 0; i <= n-1; i++) {
        printf("\n�������ֵ�ڵ�x[%ld], y[%ld]:", i,i);
        scanf("%lf, %lf", &x[i], &y[i]);
    }
}
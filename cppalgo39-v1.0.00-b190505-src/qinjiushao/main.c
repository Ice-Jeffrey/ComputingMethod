/*
 *����ֵ���������̳�(�ڶ���)�����ܳ�����
 *
 * Beijing University of Chemical Technology
 * March 1st, 2013 
 */

/*�ؾ����㷨*/

#include "stdio.h"
#define N 100
int main() {
    int n,k,i;
    float a[N],x;
    double v;

    /*��������*/
    printf("please input n= ");
    scanf("%d",&n);
    printf("please input fator a0,a1,...,a%d= ",n);
    for(i=0; i<=n; i++) {
        scanf("%f",&a[i]);
    }
    printf("please input x= ");
    scanf("%f",&x);
    v=a[0];

    /*�ж� k�Ƿ���� n*/
    for(k=1; k<=n; k++)
        v=x*v+a[k];   // ��һ���ǳ��ؼ�

    /*�������*/
    printf("the answer is v=%lf",v);
    getch();
    return 0;
}

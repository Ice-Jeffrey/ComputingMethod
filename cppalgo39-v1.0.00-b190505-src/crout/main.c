/*
 *����ֵ���������̳�(�ڶ���)�����ܳ�����
 *
 * Beijing University of Chemical Technology
 * March 1st, 2013 
 */

#include "stdio.h"
#include "math.h"//ͷ�ļ�
#define N 20//�Զ���N=20

int main() { //������
    int i,j,k;
    int size;
    float a[N][N],l[N][N],u[N][N];
    float b[N],x[N],y[N];//�������
    printf("\t\t\tCrout�ֽⷨ�ⷽ����\n");
    printf("�����뷽��A��n��");
    scanf("%d",&size);
    printf("\n");
    printf("�����뷽�����ϵ��:\n");
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            scanf("%f",&a[i][j]);//���뷽����ϵ������a[][]
        }
    }
    printf("\n�����뷽�����y:\n");
    for(i=0; i<size; i++)
        scanf("%f",&b[i]);//����������b[]
    printf("\n����A[][]Ϊ��\n");
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            printf("%f  ",a[i][j]);//���a[][]
        }
        printf("\n");
    }
    printf("\n������yΪ:\n");
    for(i=0; i<size; i++)
        printf("%f  ",b[i]);//���b[]
    printf("\n");
    for(i=0; i<size; i++) {
        u[i][i]=1;//����ʼֵ ��u[i][i]=1
    }
    for(i=0; i<size; i++)
        for(j=i+1; j<size; j++) {
            l[i][j]=0;//����ʼֵ ��l[i][j]=0
        }
    for(j=0; j<size; j++)
        for(i=j+1; i<size; i++) {
            u[i][j]=0;//����ʼֵ ��u[i][j]=0
        }
    l[0][0]=a[0][0];
    for(i=1; i<size; i++) {
        l[i][0]=a[i][0];//�����һ�е�l[][]
        u[0][i]=a[0][i]/l[0][0];//�����һ�е�u[][]
    }
    for(i=1; i<size-1; i++) {
        for(j=1; j<=i; j++) { //�����2�е���size-1�е�l[][]
            l[i][j]=a[i][j];
            for(k=0; k<j; k++) {
                l[i][j]=l[i][j]-l[i][k]*u[k][j];
            }
        }
        printf("\n");
        for(j=i+1; j<size; j++) { //�����2�е���size�е�u[][]
            u[i][j]=a[i][j];
            for(k=0; k<=i-1; k++) {
                u[i][j]=u[i][j]-l[i][k]*u[k][j];

            }
            u[i][j]=u[i][j]/l[i][i];
        }
        printf("\n");
    }
    for(j=1; j<size; j++) { //�����size�е�l[][]
        l[size-1][j]=a[size-1][j];
        for(k=0; k<=j-1; k++) {
            l[size-1][j]=l[size-1][j]-l[size-1][k]*u[k][j];
        }
    }
    printf("\n");
    printf("�������L[i][j]\n");
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            printf("%f",l[i][j]);
            printf("   ");//��������Ǿ���l[][]
        }
        printf("\n");
    }
    printf("�������U[i][j]\n");
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            printf("%f",u[i][j]);
            printf("   ");//�����λ�����Ǿ���u[][]
        }
        printf("\n");
    }
    y[0]=b[0]/l[0][0];//��y[0]��ʼֵ
    for(i=1; i<size; i++) { //����y[i]��ֵ
        y[i]=b[i];
        for(k=0; k<=i-1; k++) {
            y[i]=y[i]-l[i][k]*y[k];//���㹫ʽ
        }
        y[i]=y[i]/l[i][i];
    }
    printf("\n");
    printf("yֵ:\n");
    for(i=0; i<size; i++)
        printf("y[%d]=%f  ",i+1,y[i]);//���y[i]�Ľ��
    printf("\n\n");
    printf("x��ֵ:\n");
    x[size-1]=y[size-1];//��x[size-1]��ֵ
    for(i=size-2; i>=0; i--) {
        x[i]=y[i];
        for(k=i+1; k<size; k++) {
            x[i]=x[i]-u[i][k]*x[k];//����x[]
        }
    }
    for(i=0; i<size; i++) {
        printf("x[%d]=%f\n",i+1,x[i]);//���x[i]�Ľ��
    }
}

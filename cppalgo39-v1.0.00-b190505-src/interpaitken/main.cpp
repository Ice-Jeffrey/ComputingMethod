#include<iostream>
#include <iomanip>

using namespace std;
#define SIZE 10
int main() {
    int n,i,j,k=2;
    double xx;
    double x[SIZE];
    double y[SIZE];
    double a[SIZE][SIZE];
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++)
            a[i][j]=0;
    i=1;
    j=1;
    cout<<"**********���ؽ��ֵ***********"<<endl<<endl;
    cout<<"������֪��ֵ�����Ŀ:   ";
    cin>>n;
    cout<<"���������������:   x y"<<endl;
    while(i<=n) {
        cout<<"�� "<<i<<"���������Ϊ  ";
        cin>>x[i]>>y[i];
        a[i-1][0]=x[i];
        a[i-1][1]=y[i];
        i++;
    }
    cout<<"���������ֵ���x����:   ";
    cin>>xx;
    for(i=1; i<=n; i++) {
        for(j=i+1; j<=n; j++) {
            y[j]=(xx-x[i])*y[j]/(x[j]-x[i])+(xx-x[j])*y[i]/(x[i]-x[j]);
        }
        for(k=n-i; k>0; k--)
            a[n-k][i+1]=y[n-k+1];
    }
    cout<<"����y����Ϊ:  "<<y[n]<<endl;
    cout<<"��ֵ��Ϊ��"<<endl;
    for(i=0; i<n; i++) {
        for(j=0; j<n+1; j++)
            cout<<setw(10)<<a[i][j];
        cout<<endl;
    }
}


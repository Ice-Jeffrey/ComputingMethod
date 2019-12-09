/*
 *����ֵ���������̳�(�ڶ���)�����ܳ�����
 *
 * Beijing University of Chemical Technology
 * March 1st, 2013 
 */

#include<iostream>
#include<math.h>
#include<process.h>
using namespace std;

/*
 * Ҫ��Գ�ϵ������
 */


class Cholesky {
private:
    int i,j,k,n;
    double sum,*b,*d,*x,**a,eps;
public:
    void choleskyInput();
    void choleskyDecomposition();
    void choleskyOutput();
    ~Cholesky() {
        delete []b;
        delete []d;
        delete []x;
        for(i=0; i<n; i++) {
            delete [] a[i];
        }
        delete []a;
    }

};

void main() {
    Cholesky solution;
    solution.choleskyInput();
    solution.choleskyDecomposition();
    solution.choleskyOutput();
}

void Cholesky::choleskyInput() {
    cout<<"���뷽�̵ĸ���";
    cin>>n;
    b=new double[n];
    d=new double[n];
    x=new double[n];
    a=new double*[n];

    for(i=0; i<n; i++) {
        a[i] = new double[n];
    }

    for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            cout<<"/n����a["<<i<<"]["<<j<<"]=";
            cin>>a[i][j];
        }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            if(a[i][j] != a[j][i]) {
                cout<<"/nϵ�����󲻶Գ�.ʧ��..."<<endl;
                exit(0);
            }
        }
    for(i=0; i<n; i++) {

        cout<<"/n���� b["<<i<<"]=";
        cin>>b[i];
    }
    cout<<"/n������С��Ԫ��";
    cin>>eps;		//����ν���
}
void Cholesky::choleskyDecomposition() {
    for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            sum=a[i][j];
            for(k=0; k<i; k++) {
                sum -= a[i][k]*a[j][k];
            }
            if( i==j) {
                if(sum <= 0) {
                    cout<<"/n���������.ʧ��..."<<endl;
                    exit(0);
                }
                d[i]=sqrt(sum);
            } else {
                a[j][i] = sum/d[i];
            }

        }

    for(i=0; i<n; i++) {
        sum=b[i];
        for(k=0; k<i; k++) {
            sum -= a[i][k]*x[k];
        }
        x[i] = sum/d[i];
    }

    for(i=(n-1); i>=0; i--) {
        sum = x[i];
        for(k=(i+1); k<n; k++) {
            sum -= a[k][i]*x[k];
        }
        x[i] = sum/d[i];
    }
}
void Cholesky::choleskyOutput() {
    cout<<"/n:����ǣ�"<<endl;
    for(i=0; i<n; i++) {
        cout<<"x["<<i<<"]="<<x[i]<<endl;
    }

}
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

//gauss ˳����Ԫ��ⷽ����
class Gauss {
private:
    int i,j,k,n;
    double eps,ratio,sum,*x,**a;
    /*
    i,j     Ϊ�����±�
    k       Ϊ����������������±�
    n       ��ʾ���̸���
    eps     ��ʾ��Ԫ�ص���С����ֵ
    ratio   ���ڴ洢��ֵa[i][k]/a[k][k]
    sum     �ۼ���
    x[i]    ��ʾ������δ֪��
    a[i][j] ��ʾ��������Ԫ��
    */
public:
    void gaussInput();         //��������
    void gaussElimination();   //��Ԫ����
    void gaussOutput();        //������

    ~Gauss() {
        delete [] x;
        for(i = 0; i < n; i++) {
            delete [] a[i];
        }
        delete [] a;
    }
};

void main() {
    Gauss solution;
    solution.gaussInput();
    solution.gaussElimination();
    solution.gaussOutput();
}

void Gauss::gaussInput() {
    cout<<"���뷽�̵ĸ���";
    cin>>n;
    x=new double[n];
    a=new double*[n];

    for(i=0; i<n; i++) {
        a[i] = new double[n+1];
    }

    for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            cout<<"/n����a["<<i<<"]["<<j<<"]=";
            cin>>a[i][j];
        }

    for(i=0; i<n; i++) {
        cout<<"/n���� b["<<i<<"]=";
        cin>>a[i][n];
    }
    cout<<"/n������С��Ԫ��";
    cin>>eps;     //����ν���
}

void Gauss::gaussElimination() { //gauss ��ȥ����
    for(k=0; k<(n-1); k++) {
        for(i=(k+1); i<n; i++) {
            if(fabs(a[k][k])<eps) {
                cout<<"/n��Ԫ��̫С.ʧ��...."<<endl;
                exit(0);
            }
            ratio = a[i][k]/a[k][k];
            for(j=(k+1); j<(n+1); j++) {
                a[i][j] -= ratio*a[k][j];
            }
            a[i][k] = 0;
        }
    }
    x[n-1] = a[n-1][n]/a[n-1][n-1];//�ش�
    for(i=(n-2); i>=0; i--) {
        sum = 0.0;
        for(j=(i+1); j<n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum)/a[i][i];
    }
}

void Gauss::gaussOutput() { //����������
    cout<<"/n����ǣ�"<<endl;
    for(i=0; i<n; i++) {
        cout<<"/nx["<<i<<"]="<<x[i]<<endl;
    }
}
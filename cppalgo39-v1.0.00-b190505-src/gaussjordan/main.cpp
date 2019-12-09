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

class Jordan {
private:
    int i,j,k,n,flag,scani,scanj,*row,*col;
    double eps,pivot,aijcolk,*x,**a;
public:
    void jordanInput();//��������ĺ�������
    void jordanReduction();//��ȥ����������
    void jordanOutput();//�������ĺ�������
    ~Jordan() {
        delete [] row;
        delete [] col;
        delete [] x;
        for(i=0; i<n; i++) {
            delete [] a[i];
        }
        delete []a;
    }
};

void main() {
    Jordan solution;
    solution.jordanInput();
    solution.jordanReduction();
    solution.jordanOutput();
}

void Jordan::jordanInput() {
    cout<<"���뷽�̵ĸ���:";
    cin>>n;
    row = new int[n];
    col = new int[n];
    x = new double[n];
    a = new double* [n];

    for(i=0; i<n; i++) {
        a[i] = new double[n+1];
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            cout<<"/n���� a["<<i<<"]["<<j<<"]=";
            cin>>a[i][j];
        }
    for(i=0; i<n; i++) {
        cout<<"/n���� b["<<i<<"]=";
        cin>>a[i][n];
    }
    cout<<"/n������С��Ԫ��";
    cin>>eps;
}

void Jordan::jordanReduction() {
    for(k=0; k<n; k++) {
        pivot = 0.0;
        for(i=0; i<n; i++) {
            flag = 0;
            for(j=0; j<n; j++) {
                flag = 0;
                if(k>0) {
                    for(scani=0; scani<k; scani++)
                        for(scanj=0; scanj<k; scanj++) {
                            if((i==row[scani])||(j==col[scanj])) {
                                flag = 1;//��Ǽ�¼�����к���
                            }
                        }
                } else {

                    flag = 0;//���ΪδΪ����
                }
                if(flag == 0) {
                    if(fabs(a[i][j])>fabs(pivot)) {
                        pivot = a[i][j];
                        row[k] = i;
                        col[k] = j;
                    }
                }//��¼��Ԫ��Ϣ����
            }
        }

        if(fabs(pivot)>eps) {
            for(j=0; j<(n+1); j++) {
                a[row[k]][j]/=pivot;
            }
            for(i=0; i<n; i++) {
                aijcolk=a[i][col[k]];
                if(i!=row[k]) {
                    for(j=0; j<(n+1); j++) {
                        a[i][j] = a[i][j] - aijcolk * a[row[k]][j];
                    }
                }
            }
        } else {
            cout<<"/n������Ԫ�� = "<<pivot<<endl;
            cout<<"/n�����������.ʧ��..."<<endl;
            exit(0);
        }
    }
    for(i=0; i<n; i++) {
        x[col[i]] = a[row[i]][n];
    }
}

void Jordan::jordanOutput() {
    cout<<"/n�����:"<<endl;
    for(i=0; i<n; i++) {
        cout<<"/nx["<<i<<"]="<<x[i]<<endl;
    }
}
#include <iostream>
#include <cmath>
using namespace std;

const int MAX_N = 20;

int main() {
    int n;
    double a[MAX_N][MAX_N], b[MAX_N], x[MAX_N], y[MAX_N];
    double l[MAX_N][MAX_N], u[MAX_N][MAX_N];
    cout << "�����뷽�����ά��:"; 
    cin >> n;
    cout << "�����뷽������������:" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cin >> a[i][j];
        cin >> b[i];
    }
        
    //����L����ĶԽ���Ԫ��Ϊ1
    for(int i=0; i<n; i++)
        l[i][i] = 1; 

    //����Doolittle�ֽ�
    for(int k=0; k<n; k++) {
        //�ֽ����u�������н��д���
        for(int j=k; j<n; j++) {           
            u[k][j] = a[k][j];
            for(int i=0; i<k; i++)
                u[k][j] -= l[k][i] * u[i][j];
        }
        //�ֽ����l�������н��д���
        for(int i=k+1; i<n; i++) {
            l[i][k] = a[i][k];
            for(int j=0; j<k; j++)
                l[i][k] -= l[i][j] * u[j][k];
            l[i][k] /= u[k][k];
        }
    }

    //���з�����Ļش�����
    for(int i=0; i<n; i++) {
        y[i] = b[i];
        for(int j=0; j<=i-1; j++)
            y[i] -= l[i][j] * y[j];
    }
    for(int i=n-1; i>=0; i--){
        x[i] = y[i];
        for(int j=i+1; j<n; j++)
            x[i] -= u[i][j]*x[j];
        x[i] /= u[i][i];
    }

    cout << "��÷�����ĸ�Ϊ��";
    for(int i=0; i<n; i++)
        cout << x[i] << " ";
    cout << endl;
    return 0;
}
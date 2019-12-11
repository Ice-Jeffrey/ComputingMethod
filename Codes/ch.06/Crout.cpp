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
        
    //����u����ĶԽ���Ԫ��Ϊ1
    for(int i=0; i<n; i++)
        u[i][i] = 1; 

    //����Crout�ֽ�
    for(int k=0; k<n; k++) {
        //�ֽ����l�������н��д���
        for(int i=0; i<n; i++) {           
            l[i][k] = a[i][k];
            for(int j=0; j<k; j++)
                l[i][k] -= l[i][j] * u[j][k];
        }
        //�ֽ����u�������н��д���
        for(int j=0; j<n; j++) {
            u[k][j] = a[k][j];
            for(int i=0; i<k; i++)
                u[k][j] -= l[k][i] * u[i][j];
            u[k][j] /= l[k][k];
        }
    }

    //���з�����Ļش�����
    for(int i=0; i<n; i++) {
        y[i] = b[i];
        for(int j=0; j<=i-1; j++)
            y[i] -= l[i][j] * y[j];
        y[i] /= l[i][i];
    }
    for(int i=n-1; i>=0; i--){
        x[i] = y[i];
        for(int j=i+1; j<n; j++)
            x[i] -= u[i][j]*x[j];
    }

    cout << "��÷�����ĸ�Ϊ��";
    for(int i=0; i<n; i++)
        cout << x[i] << " ";
    cout << endl;
    return 0;
}
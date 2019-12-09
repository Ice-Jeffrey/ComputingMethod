#include<iostream>
using namespace std;

const int MAXSIZE = 50;

int main() {
    double a[MAXSIZE][MAXSIZE], x[MAXSIZE];
    int n;
    cout << "������ԭ���̵Ľ���: ";
    cin >> n;

    cout << "������ԭ���̵��������: " << endl;
    for(long i=0; i<n; i++) {
        for(long j=0; j<n; j++)
            cin >> a[i][j];
        cin >> x[i];
    }

    //���зֽ�Ĺ���
    for(int k=0; k<n-1; k++) {
        for(int i=k+1; i<n; i++) {
            double temp = 0;
            for(int j=0; j<k; j++)
                temp += a[i][k] * a[k][j];
            a[i][k] = (a[i][k] - temp) / a[k][k];
        }
        for(int j=k+1; j<n; j++) {
            double temp = 0;
            for(int i=0; i<=k; i++)
                temp += a[k+1][i] * a[i][j];
            a[k+1][j] -= temp;
        }
    }

    //���лش�
    for(int i=1; i<n; i++) {
        double temp = 0;
        for(int j=0; j<i; j++) 
            temp += a[i][j] * x[j];
        x[i] -= temp;
    }
    for(int i=n-1; i>=0; i--) {
        double temp = 0;
        for(int j=i+1; j<n; j++) 
            temp += a[i][j] * x[j];
        x[i] = (x[i] - temp) / a[i][i];
    }

    cout << "ԭ������Ľ�Ϊ��";
    for(int i=0; i<n; i++)
        cout << x[i] << " ";
    cout << endl;

    return 0;
}
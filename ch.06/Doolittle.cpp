#include<iostream>
using namespace std;

const int MAXSIZE = 50;

int main() {
    double a[MAXSIZE][MAXSIZE], x[MAXSIZE];
    int n;
    cout << "请输入原方程的阶数: ";
    cin >> n;

    cout << "请输入原方程的增广矩阵: " << endl;
    for(long i=0; i<n; i++) {
        for(long j=0; j<n; j++)
            cin >> a[i][j];
        cin >> x[i];
    }

    //进行分解的过程
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

    //进行回代
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

    cout << "原方程组的解为：";
    for(int i=0; i<n; i++)
        cout << x[i] << " ";
    cout << endl;

    return 0;
}
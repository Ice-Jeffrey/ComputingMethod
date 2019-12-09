#include<iostream>
using namespace std;

int main() {
    //确定方程的阶数
    int n;
    cout << "请输入方程的阶数：";
    cin >> n;

    //为各个矩阵申请空间
    double** A = new double*[n];
    for(int i=0; i<n; i++) 
        A[i] = new double[n];
    double *b = new double[n];
    double *x = new double[n];

    //输入增广矩阵
    cout << "请输入方程组的增广矩阵：" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cin >> A[i][j];
        cin >> b[i];
    }

    //迭代求出消元后的增广矩阵
    for(int k=0; k<n-1; k++) {
        for(int i=k+1; i<n; i++) {
            for(int j=k+1; j<n; j++)
                A[i][j] -= A[k][j] * A[i][k] / A[k][k];
            b[i] -= b[k] * A[i][k] / A[k][k];
            A[i][k] /= -A[k][k];
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++)
    //         cout << A[i][j] << " ";
    //     cout << b[i] << endl;
    // }

    //进行回代
    for(int i=n-1; i>=0; i--) {
        double temp = b[i];
        for(int j=i+1; j<n; j++)
            temp -= A[i][j] * x[j];
        x[i] = temp / A[i][i];
    }

    cout << "高斯消元法求出方程的根为：";
    for(int i=0; i<n; i++)
        cout << x[i] << " ";
    cout << endl;

    return 0;
}
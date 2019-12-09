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
    
    //输入迭代初始向量
    cout << "请输入迭代初始向量：" << endl;
    for(int i=0; i<n; i++)
        cin >> x[i];

    //输入最大迭代上限
    cout << "请输入最大迭代上限：";
    int iter_num;
    cin >> iter_num;

    //输入误差上限
    double precision;
    cout << "请输入误差上限：";
    cin >> precision;

    //开始迭代
    for(int k=0; k<iter_num; k++) {
        double e = 0;   //e为更新后向量x中的最大误差
        for(int i=0; i<n; i++) {
            double temp = x[i];
            x[i] = b[i];
            for(int j=0; j<n; j++) 
                if(j != i)
                    x[i] -= A[i][j] * x[j];
            x[i] /= A[i][i];
            if(e < abs(temp - x[i]))
                e = abs(temp - x[i]);
        }
        if(e <= precision) {
            cout << "最终求得的x向量为：";
            for(int cnt=0; cnt<n; cnt++)
                cout << x[cnt] << " ";
            cout << endl;
            return 0;
        }
    }

    cout << "迭代次数超过上限！" << endl;
    return 0;
}
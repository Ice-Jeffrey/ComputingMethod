//此处用多点的拉格朗日的插值法做示例
#include<iostream>
using namespace std;

int main() {
    int n;
    float **a, *b, x;
    cout << "请输入进行插值的点的数目：";
    cin >> n;
    b = new float [n];
    a = new float* [n];
    for(int i=0; i<n; i++)
        a[i] = new float[2];
    cout << "请按照x, y的顺序依次输入这些点：" << endl;
    for(int i=0; i<n; i++) 
        cin >> a[i][0] >> a[i][1];
    cout << "请输入需要预测的点的自变量的值：";
    cin >> x;
    
    //进行插值法迭代
    for(int i=0; i<n; i++) {
        float fi = 1;
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            fi *= (x - a[j][0]) * 1.0 / (a[i][0] - a[j][0]);
        }
        b[i] = fi;
    }
    float result = 0;
    for(int i=0; i<n; i++)
        result += b[i] * a[i][1];
    cout << "该点y的预测值为：" << result << endl;
    return 0;
}
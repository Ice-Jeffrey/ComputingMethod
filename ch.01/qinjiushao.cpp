//功能：计算一元多项式的值 p(x) = a0 + a1 * x ^ 1 + a2 * x ^ 2 + ... + an * x ^ n

#include<iostream>
using namespace std;

int main() {
    //程序对应的输入输出
    int n;
    float *a, x;
    cout << "请输入自变量的值：";
    cin >> x;
    cout << "请输入自变量的最高阶数: ";
    cin >> n;
    a = new float[n + 1];
    
    cout << "请依次输入各个系数：";
    for(int i=0; i<=n; i++)
        cin >> a[i];

    //开始迭代
    int count = n;
    float temp = a[n];
    while(count > 0) {
        temp = temp * x + a[count-1];
        count--;
    }
    cout << temp << endl;
    return 0;
}
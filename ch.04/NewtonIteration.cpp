#include<iostream>
#include<cmath>
using namespace std;

double f(double x) {
    return x * exp(x) - 1;
}

double df(double x) {
    return exp(x) * (x + 1);
}

int main() {
    double x, precision, iter_num, temp;
    cout << "请输入精度要求: ";
    cin >> precision;
    cout << "请输入迭代初值: ";
    cin >> x;
    cout << "请输入最大迭代次数: ";
    cin >> iter_num; 
    
    for(int i=0; i<iter_num; i++) {
        temp = x;
        x = x - f(x) / df(x);
        if(abs(temp - x) <= precision) {
            cout << "迭代之后求得方程的根为：" << x << endl;
            return 0;
        }
    }

    cout << "迭代次数已超过上限！" << endl;
    return 0; 
}
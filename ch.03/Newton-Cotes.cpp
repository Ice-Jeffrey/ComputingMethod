#include<iostream>
using namespace std;

double k[10][10] = {
    {0.5, 0.5},
    {1.0/6, 2.0/3, 1.0/6},
    {1.0/8, 3.0/8, 3.0/8, 1.0/8},
    {7.0/90, 16.0/45, 2.0/15, 16.0/45, 7.0/90}
};

int main() {
    //输入求积结点个数并申请内存空间
    int n;
    cout << "请输入求积结点的个数：";
    cin >> n;

    //输入积分区间的端点
    double a, b;
    cout << "请输入积分区间的端点a, b: ";
    cin >> a >> b;

    //计算每个子区间的长度
    double h = (b - a) / (n - 1);

    double result = 0;
    //输入求积节点的纵坐标
    cout << "请输入对应求积节点的纵坐标：" << endl;
    double* y = new double[n];
    for(int i=0; i<n; i++) {
        cout << "横坐标：" << a + i * h << ", " << "纵坐标: ";
        cin >> y[i];
        result += k[n - 2][i] * y[i];
    } 

    cout << "对应的积分值为: " << result * (b - a) << endl;

    return 0;
}
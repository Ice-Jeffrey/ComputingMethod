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
    cout << "�����뾫��Ҫ��: ";
    cin >> precision;
    cout << "�����������ֵ: ";
    cin >> x;
    cout << "����������������: ";
    cin >> iter_num; 
    
    for(int i=0; i<iter_num; i++) {
        temp = x;
        x = x - f(x) / df(x);
        if(abs(temp - x) <= precision) {
            cout << "����֮����÷��̵ĸ�Ϊ��" << x << endl;
            return 0;
        }
    }

    cout << "���������ѳ������ޣ�" << endl;
    return 0; 
}
#include<iostream>
using namespace std;

double k[10][10] = {
    {0.5, 0.5},
    {1.0/6, 2.0/3, 1.0/6},
    {1.0/8, 3.0/8, 3.0/8, 1.0/8},
    {7.0/90, 16.0/45, 2.0/15, 16.0/45, 7.0/90}
};

int main() {
    //��������������������ڴ�ռ�
    int n;
    cout << "������������ĸ�����";
    cin >> n;

    //�����������Ķ˵�
    double a, b;
    cout << "�������������Ķ˵�a, b: ";
    cin >> a >> b;

    //����ÿ��������ĳ���
    double h = (b - a) / (n - 1);

    double result = 0;
    //��������ڵ��������
    cout << "�������Ӧ����ڵ�������꣺" << endl;
    double* y = new double[n];
    for(int i=0; i<n; i++) {
        cout << "�����꣺" << a + i * h << ", " << "������: ";
        cin >> y[i];
        result += k[n - 2][i] * y[i];
    } 

    cout << "��Ӧ�Ļ���ֵΪ: " << result * (b - a) << endl;

    return 0;
}
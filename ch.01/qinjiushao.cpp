//���ܣ�����һԪ����ʽ��ֵ p(x) = a0 + a1 * x ^ 1 + a2 * x ^ 2 + ... + an * x ^ n

#include<iostream>
using namespace std;

int main() {
    //�����Ӧ���������
    int n;
    float *a, x;
    cout << "�������Ա�����ֵ��";
    cin >> x;
    cout << "�������Ա�������߽���: ";
    cin >> n;
    a = new float[n + 1];
    
    cout << "�������������ϵ����";
    for(int i=0; i<=n; i++)
        cin >> a[i];

    //��ʼ����
    int count = n;
    float temp = a[n];
    while(count > 0) {
        temp = temp * x + a[count-1];
        count--;
    }
    cout << temp << endl;
    return 0;
}
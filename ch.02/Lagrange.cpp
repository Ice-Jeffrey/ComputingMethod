//�˴��ö����������յĲ�ֵ����ʾ��
#include<iostream>
using namespace std;

int main() {
    int n;
    float **a, *b, x;
    cout << "��������в�ֵ�ĵ����Ŀ��";
    cin >> n;
    b = new float [n];
    a = new float* [n];
    for(int i=0; i<n; i++)
        a[i] = new float[2];
    cout << "�밴��x, y��˳������������Щ�㣺" << endl;
    for(int i=0; i<n; i++) 
        cin >> a[i][0] >> a[i][1];
    cout << "��������ҪԤ��ĵ���Ա�����ֵ��";
    cin >> x;
    
    //���в�ֵ������
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
    cout << "�õ�y��Ԥ��ֵΪ��" << result << endl;
    return 0;
}
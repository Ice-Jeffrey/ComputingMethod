#include<iostream>
using namespace std;

int main() {
    cout << "��������в�ֵ�ĵ����Ŀ���ĸ�����";
    int n;
    cin >> n;
    float *x, *y, *cs;
    x = new float[n];
    y = new float[n];
    cs = new float[n];
    cout << "���������������Ա���ֵ�ͺ���ֵ��" << endl;
    for(int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }        
    
    //��ʼ����ţ�ٲ�ֵ��������̣����������ʽ�ĸ���ϵ��
    for(int k=0; k<n; k++) {
        //��ǰҪ����ǵ�k�ײ���
        cs[k] = 0;
        //k����ǰ����ʽ�ۼӵ�ֵ
        for(int i=0; i<k+1; i++) {
            float temp = y[i];
            for(int j=0; j<k+1; j++) {
                if(j == i) continue;
                temp *= 1.0 / (x[i] - x[j]);
            }
            cs[k] += temp;
        }
        cout << k << " " << cs[k] << endl;
    }

    cout << "������Ҫ����Ԥ����Ա�����ֵ��";
    float test;
    cin >> test;
    float result = 0;
    for(int i=0; i<n; i++){
        float temp = cs[i];
        for(int j=0; j<i; j++) 
            temp *= (test - x[j]);
        result += temp;
    }
    cout << "�ò�ֵ������Ľ��Ϊ��" << result << endl;
    return 0;
}
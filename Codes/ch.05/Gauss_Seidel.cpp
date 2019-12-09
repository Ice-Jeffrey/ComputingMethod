#include<iostream>
using namespace std;

int main() {
    //ȷ�����̵Ľ���
    int n;
    cout << "�����뷽�̵Ľ�����";
    cin >> n;

    //Ϊ������������ռ�
    double** A = new double*[n];
    for(int i=0; i<n; i++) 
        A[i] = new double[n];
    double *b = new double[n];
    double *x = new double[n];

    //�����������
    cout << "�����뷽������������" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cin >> A[i][j];
        cin >> b[i];
    }
    
    //���������ʼ����
    cout << "�����������ʼ������" << endl;
    for(int i=0; i<n; i++)
        cin >> x[i];

    //��������������
    cout << "���������������ޣ�";
    int iter_num;
    cin >> iter_num;

    //�����������
    double precision;
    cout << "������������ޣ�";
    cin >> precision;

    //��ʼ����
    for(int k=0; k<iter_num; k++) {
        double e = 0;   //eΪ���º�����x�е�������
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
            cout << "������õ�x����Ϊ��";
            for(int cnt=0; cnt<n; cnt++)
                cout << x[cnt] << " ";
            cout << endl;
            return 0;
        }
    }

    cout << "���������������ޣ�" << endl;
    return 0;
}
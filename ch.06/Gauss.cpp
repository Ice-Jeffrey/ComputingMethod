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

    //���������Ԫ����������
    for(int k=0; k<n-1; k++) {
        for(int i=k+1; i<n; i++) {
            for(int j=k+1; j<n; j++)
                A[i][j] -= A[k][j] * A[i][k] / A[k][k];
            b[i] -= b[k] * A[i][k] / A[k][k];
            A[i][k] /= -A[k][k];
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++)
    //         cout << A[i][j] << " ";
    //     cout << b[i] << endl;
    // }

    //���лش�
    for(int i=n-1; i>=0; i--) {
        double temp = b[i];
        for(int j=i+1; j<n; j++)
            temp -= A[i][j] * x[j];
        x[i] = temp / A[i][i];
    }

    cout << "��˹��Ԫ��������̵ĸ�Ϊ��";
    for(int i=0; i<n; i++)
        cout << x[i] << " ";
    cout << endl;

    return 0;
}
/*
 *����ֵ���������̳�(�ڶ���)�����ܳ�����
 *
 * Beijing University of Chemical Technology
 * March 1st, 2013 
 */

// ����Ӧ���ι�ʽ(�䲽��)

#include<iostream>
#include<math.h>

using namespace std;

int n;
float f(float);
void main() {
    float s;
    float autoTrap(float (*)(float),float,float);
    s=autoTrap(f,0.0,1.0);
    cout<<"T("<<n<<")="<<s<<endl;
}
float autoTrap(float (*)(float),float a,float b) {
    int i;
    float x,s,h=b-a;
    float t1,t2=h/2.0*(f(a)+f(b));
    n=1;
    do {
        s=0.0;
        t1=t2;
        for(i=0; i<=n-1; i++) {
            x=a+i*h+h/2;
            s+=f(x);
        }
        t2=(t1+s*h)/2.0;
        n*=2;
        h/=2.0;
    } while( fabs(t2-t1)>1e-6);
    return t2;
}

float f(float x) {
    return 1/(1+x*x);
}
//�ñ䲽�����η�������ֻ���ֻҪ����������Ϊ

/*float f(float x)
{
	if(x==0)
		return 1;
	else
		return sin(x)/x;
}*/

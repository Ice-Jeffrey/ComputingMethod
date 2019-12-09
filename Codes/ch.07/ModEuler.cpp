#include<iostream>
using namespace std;

const int n = 20;

double f(double x, double y) {
    return y - 2 * x / y;
}

void ModEuler(double (*f)(double, double), double x0, double y0, double xn, int n) {
    double h = (xn - x0) / n;
    double x = x0, y = y0;
    cout << "x[0]=" << x << ", y[0]=" << y << endl;
    for(int i=0; i<n; i++) {
        double yp = y + h * f(x, y);
        x += h;
        double yc = y + h * f(x, yp);
        y = (yp + yc) / 2;
        cout << "x[" << i+1 << "]=" << x << ", "
            << "y[" << i+1 << "]=" << y << endl;
    }
}

int main() {
    double x0 = 0, y0 = 1, xn = 1;
    ModEuler(f, x0, y0, xn, n);

    return 0;
}
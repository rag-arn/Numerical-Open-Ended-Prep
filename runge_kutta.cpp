#include<bits/stdc++.h>
using namespace std;

double f(double x, double y) {
    return 2*x+1;
}

void rk(double x0, double y0, double h, double target) {
    int n = (target-x0)/h;
    double x = x0, y = y0;

    for (int i=0; i<n; i++) {
        double k1 = h*f(x, y);
        double k2 = h*f(x+(h/2), y+(k1/2));
        double k3 = h*f(x+(h/2), y+(k2/2));
        double k4 = h*f(x+h, y+k3);

        y = y+(1/6.0)*(k1+2*k2+2*k3+k4);
        x += h;
    }
    cout << y << endl;
}

int main() {
    double x0, y0, h, target;
    cin >> x0 >> y0 >> h >> target;

    rk(x0, y0, h, target);
}
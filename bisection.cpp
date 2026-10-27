#include<bits/stdc++.h>
using namespace std;

#define eps 1e-4

int n;
vector<double> a(n);

double f (double x) {
    double ans = 0;

    for (int i=0; i<n; i++) {
        ans += a[i]*pow(x, n-i-1);
    }

    return ans;
}

double bisection (double x1, double x2) {
    int iteration = 0;
    
    
    

    if (f(x1)*f(x2)>0) {
        return 0;
    }

    double x0;
    while (fabs(x2-x1)>=eps) {
        x0 = (x1+x2)/2;

        if (f(x0)==0) {
            break;
        }
        if (f(x0)*f(x1)>0) {
            x1 = x0;
        }
        else x2 = x0;
        iteration++;
    }

    cout << "Root : " << x0 << endl;
    cout << "Iteration : " << iteration << endl;
    cout << "Interval : " << x1 << " " << x2 << endl;
    cout << endl;
    return 0;
}

int main() {
    cin >> n;
    n++;
    a.resize(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    double xmax = sqrt(pow(a[1]/a[0], 2) - 2*a[2]/a[0]);
    
    double x1 = -xmax;
    double x2 = x1+0.5;
    while (x2<=xmax) {
        bisection(x1, x2);
        x1 = x2;
        x2+=0.5;
    }
}
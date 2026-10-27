#include<bits/stdc++.h>
using namespace std;

#define eps 1e-4

int n;
map<double, int> mp;
vector<double> a;

double f (double x) {
    double ans = 0;

    for (int i=0; i<n; i++) {
        ans += a[i]*pow(x, n-i-1);
    }

    return ans;
}

void secant (double x0, double x1) {
    double x2;
    double orig_x0 = x0, orig_x1 = x1;
    int iter = 100;

    while (iter--) {
        x2 = x1-f(x1)*((x1-x0)/(f(x1)-f(x0)));
        if (fabs(x2-x1)<eps) {
            break;
        }
        x0 = x1;
        x1 = x2;
    }
    x2 = round(x2*1000)/1000;
    mp[x2]++;
    if (iter and mp[x2]==1) {
        cout << fixed << setprecision(3) << "Root : " << x2 << endl;
        cout << "Iteration : " << 100-iter << endl;
        cout << "Interval : " << orig_x0 << " " << orig_x1 << endl;
        cout << endl;
    }
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
        secant(x1, x2);
        x1 = x2;
        x2+=0.5;
    }
}

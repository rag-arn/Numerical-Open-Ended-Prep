#include<bits/stdc++.h>
using namespace std;
int n;

void dd (vector<double> x, vector<double> y) {
    vector<vector<double>> table(n, vector<double> (n, 0));

    for (int i=0; i<n; i++) {
        table[i][0] = y[i];
    }

    for (int j=1; j<n; j++) {
        for (int i=0; i<n-j; i++) {
            table[i][j] = (table[i+1][j-1]-table[i][j-1])/(x[i+j]-x[i]);
        }
    }

    cout << "Table : " << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            cout << table[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "\n\nEquation : " << endl;

    for (int i=0; i<n; i++) {
        if (i>0) cout << " + ";
        double coeff = table[0][i];
        cout << coeff;
        for (int j=0; j<i; j++) {
            cout  << "(x - " << x[j] << ")";
        }
    }
    cout << endl;
}

int main() {
    cin >> n;
    vector<double> x(n), y(n);
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }    
    
    for (int i=0; i<n; i++) {
        cin >> y[i];
    }    

    dd (x, y);
}
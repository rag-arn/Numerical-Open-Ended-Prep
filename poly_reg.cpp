#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9



vector<double> gj (vector<vector<double>> arr, int n) {
    int row = 0;
    for (int col=0; col<n and row<n; col++) {
        int prow = row;
        for (int i=row+1; i<n; i++) {
            if (fabs(arr[i][col])>fabs(arr[prow][col])) prow = i;
        }
        if (fabs(arr[prow][col])<eps) continue;
        swap(arr[row], arr[prow]);

        double pivot = arr[row][col];
        for (int i=0; i<=n; i++) {
            arr[row][i] /= pivot;
        }

        for (int i=0; i<n; i++) {
            if (i==row) continue;
            double m = arr[i][col];

            for (int j=0; j<=n; j++) {
                arr[i][j] -= arr[row][j]*m;
            }
        }
        row++;
    }

    vector<double> ans(n);
    for (int i=0; i<n; i++) {
        if (fabs(arr[i][n])<eps) arr[i][n] = 0;
        ans[i] = arr[i][n];
    }
    return ans;
}

int n;

void poly(vector<double> x, vector<double> y) {
    int deg;
    cin >> deg;
    vector<vector<double>> arr(deg+1, vector<double> (deg+2));

    vector<double> xi(deg*2, 0), yi(deg+1, 0);

    for (int i=0; i<deg*2; i++) {
        for (int j=0; j<n; j++) {
            xi[i] += pow(x[j], i+1);
        }
    }
    
    for (int i=0; i<deg+1; i++) {
        for (int j=0; j<n; j++) {
            yi[i] += pow(x[j], i)*y[j];
        }
    }

    arr[0][0] = n;
    for (int i=1; i<deg+1; i++) {
        arr[i][0] = xi[i-1];
    }
    for (int i=0; i<deg+1; i++) {
        for (int j=1; j<deg+1; j++) {
            arr[i][j] = xi[i+j-1];
        }
    }
    for (int i=0; i<deg+1; i++) {
        arr[i][deg+1] = yi[i];
    }

    vector<double> ans = gj(arr, deg+1);

    cout << "Equation : " << endl;
    cout << "y = ";
    for (int i=0; i<ans.size(); i++) {
        if (i>0) cout << " + ";
        cout << ans[i];
        if (i==1) cout << "x";
        else if (i>1) cout << "x^" << i;
    }
    cout << endl;
}

int main() {
    cin >> n;
    vector<double> x(n);
    vector<double> y(n);

    for (int i=0; i<n; i++) {
        cin >> x[i];
    }
    
    for (int i=0; i<n; i++) {
        cin >> y[i];
    }

    poly(x, y);
    return 0;
}
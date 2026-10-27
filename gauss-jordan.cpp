#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9

int n;

void print (vector<vector<double>> arr) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<=n; j++) {
            if (fabs(arr[i][j])<eps) arr[i][j] = 0;
            cout << fixed << setprecision(3) << arr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

void gj(vector<vector<double>> &arr) {
    cout << "Augmented matrix : " << endl;
    print(arr);

    int row = 0;
    for (int col=0; row<n and col<n; col++) {
        int prow = row;
        for (int i=row+1; i<n; i++) {
            if (fabs(arr[i][col])>fabs(arr[prow][col])) prow = i;
        }

        if (fabs(arr[prow][col])<eps) continue;
        swap (arr[row], arr[prow]);

        double pivot = arr[row][col];
        for (int i=0; i<=n; i++) {
            arr[row][i]/=pivot;
        }

        for (int i=0; i<n; i++) {
            if (i==row) continue;

            double m = arr[i][col];
            for (int j=0; j<=n; j++) {
                arr[i][j] -= m*arr[row][j];
            }
        }
        row++;
    }
    cout << "Reduced row : " << endl;
    print(arr);
    
    int rank = row;
    for (int i=rank; i<n; i++) {
        if (fabs(arr[i][n])>eps) {
            cout << "No solution\n";
            return;
        }
    }
    if (rank<n) {
        cout << "Infinite solution\n";
        return;
    }
    cout << "Unique solutions : " << endl;
    for (int i=0; i<n; i++) {
        cout << arr[i][n] << "   ";
    }
    cout << endl;
}

int main() {
    cin >> n;
    vector<vector<double>> arr(n, vector<double> (n+1));

    for (int i=0; i<n; i++) {
        for (int j=0; j<=n; j++) {
            cin >> arr[i][j];
        }
    }

    gj(arr);
}
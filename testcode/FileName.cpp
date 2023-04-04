#include<iostream>
using namespace std;

const int MAXN = 22;

long long f[MAXN][4];

void prework() {
    f[0][0] = 1;
    for (int i = 1; i <= 20; i++) {
        f[i][3] = f[i - 1][2] + 10 * f[i - 1][3];
        f[i][2] = f[i - 1][1];
        f[i][1] = f[i - 1][0];
        f[i][0] = 9 * (f[i - 1][0] + f[i - 1][1] + f[i - 1][2]);
    }
}

int n, t;

int main() {
    prework();
    cin >> t;
    while (t--) {
        cin >> n;
        int len = 3;
        while (f[len][3] < n) len++;
        int k = 0;
        for (int i = len; i; i--) {
            for (int j = 0; j <= 9; j++) {
                long long cnt = f[i - 1][3];
                if (j == 6 || k == 3) {
                    for (int l = max(3 - k - (j == 6), 0); l < 3; l++) {
                        cnt += f[i - 1][l];
                    }
                }
                if (cnt < n) n -= cnt;
                else {
                    if (k < 3) {
                        if (j == 6) k++;
                        else k = 0;
                    }
                    cout << j;
                    break;
                }
            }
        }
        cout << endl;

    }
    return 0;
}
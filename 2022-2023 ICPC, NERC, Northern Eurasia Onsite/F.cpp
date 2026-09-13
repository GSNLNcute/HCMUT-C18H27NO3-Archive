#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if (n == 1) {
        cout << (a == b) << endl;
        cout << a << ":" << b << endl;
        return 0;
    }

    vector<int> x(n, 0);
    vector<int> y(n, 0);

    int d = max(0, n - a - b);

    if (d > 0) {
        for (int k = 0; k < a; k++) {
            x[d + k] = 1;
        }

        for (int k = 0; k < b; k++) {
            y[d + a + k] = 1;
        }
    }
    else {
        int p = min(a, n);
        int q = n - p;

        for (int i = 0; i < p; i++) {
            x[i] = 1;
        }

        for (int i = p; i < q + p; i++) {
            y[i] = 1;
        }

        int ra = a - p;
        int rb = b - q;

        if (p == n) {
            x[0] += ra;

            if (rb == 1) {
                x[1] = 0;
                y[1] = 1;
                x[0] += 1;
            }
            else if (rb > 0) {
                y[1] = rb;
            }
        }
        else {
            y[p] += rb;
        }
    }

    cout << d << endl;

    for (int i = 0; i < n; i++) {
        cout << x[i] << ":" << y[i] << endl;
    }

    return 0;
}
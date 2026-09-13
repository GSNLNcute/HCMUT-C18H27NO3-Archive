#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }

        if (n == 1) {
            cout << "Impossible" << endl;
            continue;
        }

        vector<int> cnt(n, 0);
        vector<int> pos(n, -1);

        for (int i = 0; i < n; i++) {
            int k = (a[i] - i + n) % n;

            if (k != 0) {
                cnt[k]++;
                pos[k] = i;
            }
        }

        int k = 1;

        for (int i = 2; i < n; i++) {
            if (cnt[i] < cnt[k]) {
                k = i;
            }
        }

        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            s[i] = (i + k) % n;
        }

        bool possible = true;

        if (cnt[k] == 0) {
            possible = true;
        }

        else if (cnt[k] == 1) {
            int i = pos[k];

            bool fixed = false;

            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }

                int ni = s[j];
                int nj = s[i];

                if (ni != i && ni != a[i] &&
                    nj != j && nj != a[j]) {

                    swap(s[i], s[j]);
                    fixed = true;
                    break;
                }
            }

            if (!fixed) {
                possible = false;
            }
        }

        else {
            possible = false;
        }

        if (!possible) {
            cout << "Impossible" << endl;
            continue;
        }

        vector<int> ainv(n);
        vector<int> p(n);
        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            ainv[a[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            p[i] = ainv[s[i]];
        }

        for (int i = 0; i < n; i++) {
            q[s[i]] = i;
        }

        cout << "Possible" << endl;

        for (int i = 0; i < n; i++) {
            cout << p[i] + 1 << " ";
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << q[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
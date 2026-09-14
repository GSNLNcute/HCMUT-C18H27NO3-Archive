#include <bits/stdc++.h>
#include <cassert>
using namespace std;
const int N = 1e6 + 3e5;
const long long INF = 1e18;
const unsigned long long mod = 1e9 + 7;
#define MOD 998244353*1LL
#define Mod 123456789*1LL
//typedef unsigned long long ll;
#define i64 int64_t
#define ll long long
const long inf = 1e9 + 10;
const int base = 31;
ll n, m, k, q;
#define MASK(i) (1LL*1<<(i))
#define ld long double
#define eps 1e-9
#define all(s) (s).begin(), (s).end()
#define getbit(mask, i) ((mask)>>(i)&1)
#define turnoff(mask, i) (1LL*(mask)-MASK(i))
#define turnon(mask, i) ((mask)+MASK(i))
#define fullmask(i) (MASK(i)-1)
#define lastbit(mask) ((mask)&(-mask))
#define clz(mask) __builtin_clzll(mask)
#define lg(mask) 63-clz(mask)
#define LG 20
#define fi first
#define se second
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define pop_cnt(mask) __builtin_popcount(mask)
template <class X, class Y>
inline bool minimize(X &x, Y y)
{
    if (x > y) return x = y, true;
    return false;
}
template <class X, class Y>
inline bool maximize(X &x, Y y)
{
    if (x < y) return x = y, true;
    return false;
}
template <class X>
inline void compress(vector <X> &a)
{
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
}
inline void add(ll &x, ll y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}
inline void sub(ll &x, ll y)
{
    x -= y;
    if (x < 0) x += MOD;
}
#define S 633
#define Z 90000
long timer = 0;
ll b[N];
ll a[10001][10001];
void solve()
{
    cin >> n;

    vector <long> val;

    for (long i = 1; i <= n; i++) {
        long x;
        cin >> x;
        b[i] = x;
        for (long j = 1; j <= x; j++) {
            cin >> a[i][j];
            val.push_back(a[i][j]);
        }
    }

    compress(val);

    for (long i = 1; i <= n; i++) {
        for (long j = 1; j <= b[i]; j++) {
            a[i][j] = lower_bound(all(val), a[i][j]) - val.begin() + 1;
        }
    }

    ll ans = 0;

    for (long i = 1; i <= n; i++) {
        for (long j = 1; j <= b[i]; j++) {
            if (j < b[i] && a[i][j + 1] - a[i][j] != 1) ans++;
        }
    }

    cout << ans << " " << ans + n - 1;

}
int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define TASK "sumk"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}

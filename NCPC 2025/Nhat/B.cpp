// Source : 
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define pii  pair<int,int>
#define fi   first
#define se   second
#define ve   vector
#define vi   ve<int>
#define vll  ve<ll>
#define el   '\n'
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define __builtin_popcount __builtin_popcountll
template<class T> bool minimize(T &a, T b){ return (a > (b) ? a = (b), 1 : 0); }
template<class T> bool maximize(T &a, T b){ return (a < (b) ? a = (b), 1 : 0); }
template<class T> T Abs(const T &x) { return (x<0?-x:x);}

const int N = 100 + 5;
const int LG = 17;
const ll INF = 1e17 + 7;
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, H, W;

struct Books{
	int h, t, id;
	bool operator < (const Books& other) const{
		return h > other.h;
	}
} a[N];

int dp[N][4 * N];
int trace[N][4 * N];

bool process(const int& tmp){
	if (a[tmp].h > W) return false;

	memset(dp, 0x3f, sizeof(dp));
	memset(trace, -1, sizeof(trace));
	dp[0][0] = 0;

	REP(i, n) FOR(j, 0, H){
		if (i + 1 >= tmp && j + a[i + 1].t <= H && minimize(dp[i + 1][j + a[i + 1].t], dp[i][j]))
			trace[i + 1][j + a[i + 1].t] = 0;
		if (i + 1 != tmp && a[i + 1].h <= H && minimize(dp[i + 1][j], dp[i][j] + a[i + 1].t))
			trace[i + 1][j] = 1;
	}

	int _j = -1;
	FOR(j, 0, H) if (dp[n][j] <= W - a[tmp].h){
		_j = j; break;
	}

	if (_j == -1) return false;

	vector <int> upright, stacked;
	FORD(i, n, 1){
		if (trace[i][_j] == 0){
			stacked.pb(a[i].id);
			_j -= a[i].t;
		} else{
			upright.pb(a[i].id);
		}
	}

	if (stacked.empty() || upright.empty())
		return false;

	reverse(ALL(stacked));
	reverse(ALL(upright));
	cout << "upright ";
	for(const int& x : upright) cout << x << " ";
	cout << el << "stacked ";
	for(const int& x : stacked) cout << x << " ";

	return true;
}
void solve(){
	sort(a + 1, a + n + 1);

	bool hasAns = false;
	FOR(i, 1, n) if (process(i)){
		hasAns = true; break;
	}

	if (!hasAns){
		cout << "impossible";
	}
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #define NAME "B"
    if (fopen(NAME".inp", "r")){
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }

    bool multiTest = 0;
    int numTest = 1;

    if (multiTest) cin >> numTest;
    while(numTest--){
        cin >> n >> H >> W;
        FOR(i, 1, n){
        	cin >> a[i].h >> a[i].t;
        	a[i].id = i;
        }
        solve();
    }

    cerr << "\nTime used: " << clock() << "ms\n";
    return 0;
}

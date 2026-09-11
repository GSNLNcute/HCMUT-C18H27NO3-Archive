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

const int N = 600 + 5;
const int LG = 17;
const ll INF = 1e17 + 7;
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;

int n;
char a[N][N];

int cnt[N];

void solve(){
	int total = 0;
	FOR(i, 1, n) total += cnt[i];
	if (total & 1){
		cout << "impossible";
		return;
	}

	int numA = cnt[1], rowA = 1;
	int numB = cnt[n], rowB = n;
	while(numA + cnt[rowA + 1] <= total / 2){
		numA += cnt[rowA + 1];
		++rowA;
	}
	while(numB + cnt[rowB - 1] <= total / 2){
		numB += cnt[rowB - 1];
		--rowB;
	}

	if (numA == numB && numA == total / 2){
		rowA = rowB - 1;
		FOR(i, 1, rowA) FOR(j, 1, 2 * n - 1) 
			if (a[i][j] != '#') a[i][j] = 'A';
		FOR(i, rowB, n) FOR(j, 1, 2 * n - 1) 
			if (a[i][j] != '#') a[i][j] = 'B';
		FOR(i, 1, n) FOR(j, 1, 2 * n - 1){
			cout << a[i][j];
			if (j == 2 * n - 1) cout << el;
		}
	} else if (numA + 1 == total / 2){
		int pos = -1, hasL = false, hasR = false;
		FOR(j, 1, 2 * n - 1) if (a[rowA + 1][j] == 'C' && a[rowA][j] != '#'){
			pos = j; break;
		}

		if (pos == -1){
			if (a[rowA + 1][n - rowA] == 'C') pos = n - rowA, hasL = true;
			else if (a[rowA + 1][n - rowA] == 'C') pos = n + rowA, hasR = true;
		}

		FOR(i, 1, rowA) FOR(j, 1, 2 * n - 1) 
			if (a[i][j] != '#') a[i][j] = 'A';
		FOR(i, rowB, n) FOR(j, 1, 2 * n - 1) 
			if (a[i][j] != '#') a[i][j] = 'B';
		FOR(j, 1, 2 * n - 1) if (a[rowA + 1][j] != '#'){
			if (j != pos) a[rowA + 1][j] = 'B';
			else a[rowA + 1][j] = 'A';
		}
		if (hasL) a[rowA + 1][pos + 1] = 'A';
		else if (hasR) a[rowA + 1][pos - 1] = 'A';
		FOR(i, 1, n) FOR(j, 1, 2 * n - 1){
			cout << a[i][j];
			if (j == 2 * n - 1) cout << el;
		}
	} else{
		numB += cnt[rowB - 1];
		int pos = -1;
		FOR(j, 1, 2 * n - 1) if (a[rowA + 1][j] == 'C'){
			numA++; numB--;
			if (numA == numB){
				pos = j;
				break;
			}
		}

		FOR(i, 1, rowA) FOR(j, 1, 2 * n - 1) 
			if (a[i][j] != '#') a[i][j] = 'A';
		FOR(i, rowB, n) FOR(j, 1, 2 * n - 1) 
			if (a[i][j] != '#') a[i][j] = 'B';
		FOR(j, 1, 2 * n - 1) if (a[rowA + 1][j] != '#'){
			if (j <= pos) a[rowA + 1][j] = 'A';
			else a[rowA + 1][j] = 'B';
		}
		FOR(i, 1, n) FOR(j, 1, 2 * n - 1){
			cout << a[i][j];
			if (j == 2 * n - 1) cout << el;
		}
	}
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #define NAME "E"
    if (fopen(NAME".inp", "r")){
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }

    bool multiTest = 0;
    int numTest = 1;

    if (multiTest) cin >> numTest;
    while(numTest--){
        cin >> n;
        FOR(i, 1, n) FOR(j, 1, 2 * n - 1){
        	cin >> a[i][j];
        	if (a[i][j] == 'C') cnt[i]++;
        } 
        solve();
    }

    cerr << "\nTime used: " << clock() << "ms\n";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, s1[N], s2[N], memo[N][N];

int lcs(int n, int m) {
	if (~memo[n][m]) return memo[n][m];
	if (n == 0 or m == 0) return memo[n][m] = 0;
	if (s1[n-1] == s2[m-1]) return memo[n][m] = 1 + lcs(n-1,m-1);
	return memo[n][m] = max(lcs(n-1,m),lcs(n,m-1));
}

int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) 
		scanf("%d",&s1[i]), s2[i] = s1[i];

	sort(s2,s2+n);
	cl(memo, -1);

	printf("%d\n",lcs(n,n));
	
	return 0;
}

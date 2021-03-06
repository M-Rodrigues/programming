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

int n, inc[N], m, a, total, vis[N];
vi adj[N];

int dfs(int x) {
	int sum = 0;
	if (!vis[x]) {
		vis[x] = sum = 1;
		for (int i = 0; i < adj[x].size(); i++)
			sum += dfs(adj[x][i]);
	}
	return sum;
}

int main() {
	while (scanf("%d",&n) and n) {
		cl(inc, 0);
		for (int i = 0; i < N; i++) adj[i].clear();

		for (int i = 1; i <= n; i++) {
			scanf("%d",&m);
			while (m--) {
				scanf("%d",&a);
				adj[i].pb(a);
				inc[a]++;
			}
		}

		int ans = 0;
		int index = 0;
		for (int i = 1; i <= n; i++) if (!inc[i]) {
			cl(vis, 0);
			total = dfs(i);
			if (total > ans) ans = total, index = i;
		}

		printf("%d\n",index);

	}
	return 0;
}
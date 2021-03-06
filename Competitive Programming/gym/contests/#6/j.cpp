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
const int N = 2e5+5;

int q, n, a[N], l, r;
ll ps[N];


int main() {
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);

	while (q--) {
		scanf("%d%d",&l,&r);
		ps[l]++;
		ps[r+1]--;

	}
	for (int i = 2; i <= n; i++) ps[i] += ps[i-1];
	// for (int i = 1; i <= n; i++) printf("%lld ",ps[i]); printf("\n\n");

	sort(ps, ps+n+1);
	sort(a, a+n+1);

	// for (int i = 1; i <= n; i++) printf("%d ",a[i]); printf("\n");
	// for (int i = 1; i <= n; i++) printf("%lld ",ps[i]); printf("\n\n");
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans += ((ll)ps[i])*((ll)a[i]);

	cout<<ans<<endl;

	return 0;
}

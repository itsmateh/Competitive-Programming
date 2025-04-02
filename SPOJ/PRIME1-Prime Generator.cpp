#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vb = vector<bool>; 
using vl = vector<ll>;
using vi = vector<int>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
const ll MOD = 1e9+7;
const int INF = 1<<30; 
const int MAXN  = 2e5+5;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define raya cerr << "=================" << endl;
#define forn(i,n) for(ll i=0;i<ll(n);i++)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define dforn(i,n) for(ll i=ll(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define endl "\n";
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define esta(x, c) ((c).find(x) != (c).end())



vi simple_sieve(ll limit) {
    vb is_prime(limit + 1, true);
    vi primes;
    is_prime[0] = is_prime[1] = false;
    for (ll p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (ll i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (ll p = 2; p <= limit; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
    return primes;
}

void segmented_sieve(ll m, ll n) {
    ll limit = sqrt(n);
    vi primes = simple_sieve(limit);
    vb is_prime(n - m + 1, true);

    for (ll p : primes) {
        ll start = max(p * p, (m + p - 1) / p * p); // Primer múltiplo de p dentro del rango
        for (ll j = start; j <= n; j += p) {
            is_prime[j - m] = false;
        }
    }
    if (m == 1) is_prime[0] = false; 

    for (ll i = 0; i <= n - m; i++) {
        if (is_prime[i]) cout << (m + i) << "\n";
    }
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) {
        ll m, n; cin >> m >> n;
        segmented_sieve(m, n);
        if (t) cout << "\n"; 
    }
    return 0;
}

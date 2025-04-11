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

int main() {
    FIN;
    int n; cin >> n; 

    vb ans1(n, 0);  
    vb ans2(n, 0); 
    vector<tuple<int, int, int>> rangos(n); // {left, right, index}

    forn(i,n){
        int l, r;
        cin >> l >> r;
        rangos[i] = make_tuple(l, r, i);
    }

    sort(rangos.begin(), rangos.end(), [](const auto &a, const auto &b) {
        if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    int minR = 1e9+50;
    dforn(i,n){
        int r = get<1>(rangos[i]);
        int idx = get<2>(rangos[i]);
        if (r >= minR)
            ans1[idx] = 1; 
        minR = min(minR, r);
    }
  
    int maxR = 0; 
    forn(i,n){
        int r = get<1>(rangos[i]);
        int idx = get<2>(rangos[i]);
        if (r <= maxR)
            ans2[idx] = 1;
        maxR = max(maxR, r); 
    }

    forn(i,n) cout << ans1[i] << " ";
    cout << endl;
    forn(i,n) cout << ans2[i] << " ";
    
    return 0;
}

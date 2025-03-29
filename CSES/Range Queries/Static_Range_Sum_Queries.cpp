#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
const ll MOD = 1e9+7;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define raya cerr << "=================" << endl;
#define forn(i,n) for(ll i=0;i<ll(n);i++)
#define dforn(i,n) for(ll i=ll(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define endl "\n";


int main(){
    FIN;
 
    ll n,q; cin >> n >> q; 
    vl nros(n); forn(i,n) cin >> nros[i];
 
    vl pref(n+1);
    pref[0] = 0; 
    for(int i=1; i<=n; i++){
        pref[i] = pref[i-1]+ nros[i-1];
    }
    while(q--){
        ll L, R; cin >> L >> R; 
        ll ans = pref[R] - pref[L-1];
        cout << ans << endl;
    }
 
 
    return 0; 
}
 
 
 

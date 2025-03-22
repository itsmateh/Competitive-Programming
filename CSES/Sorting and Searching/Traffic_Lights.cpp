#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define raya cerr << "=================" << endl;
#define forn(i,n) for(ll i=0;i<ll(n);i++)
#define pb push_back
#define mp make_pair
#define endl "\n";
 
 
int main(){
    FIN;
   
    ll x, n; 
    cin >> x >> n;
 
    set<ll>luces{0, x}; // almacenar las luces 
    multiset<ll>distancias{x}; // almacenar futuras distancias / encontrar la maxima
 
    for(int i = 0; i<n; i++){
        ll pos; cin >> pos;
        
        auto r = luces.upper_bound(pos); 
        auto l = r; 
        l--; // l -> pos -> r 
 
        distancias.erase(distancias.find(*r - *l)); 
        // actualizar l - pos - r
        distancias.insert(pos - *l); 
        distancias.insert(*r - pos); 
 
        luces.insert(pos);
 
        auto ans = distancias.end();
        ans--; // apunta al final+1 del multiset, por eso --
        cout << *ans << " ";
 
    }
    return 0;
}

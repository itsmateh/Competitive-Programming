#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vi = vector<int>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
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
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main(){
    FIN;
    
    int n,x; cin >> n >> x; 
    vi price(n); 
    vi pages(n);
    forn(i,n) cin >> price[i]; 
    forn(i,n) cin >> pages[i];
 
 
    // para cada cantidad i de dinero -> max. paginas puedo comprar
    vl dp(x+1, 0);
    for(int i=0; i<n; i++){
        for(int j=x; j>0; j--){
            if(price[i] > j) continue;
            dp[j] = max(dp[j], pages[i] + dp[j - price[i]]);
            // cant actual = max(paginas_actual, paginas_nuevas + cant. de pags. que tenia previo a gastar price[i])
        }
    }
    
 
    cout << dp[x] << endl;
 
    return 0; 
}
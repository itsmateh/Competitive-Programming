#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vi = vector<int>;
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
    vi coins(n); 
    forn(i,n) cin >> coins[i]; 

    vl dp(x+1); 
    dp[0] = 1; 
    
    // iterate over all coins 
    for(int i=0; i<n; i++){
        // iterate over all sums j coins[i] to X
        for(int j=coins[i]; j<=x; j++){
            dp[j] = (dp[j] + dp[j-coins[i]]) % MOD; 
        }
    }

    cout << dp[x] << endl;

    return 0; 
}

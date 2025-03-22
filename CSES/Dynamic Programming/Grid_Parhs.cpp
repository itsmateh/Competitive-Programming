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

    int n; cin >> n;
    vector<string>path(n);
    forn(i,n) cin >> path[i];
    vll dp(n, vl(n,0));

    // cant. primera columna 
    forn(i,n){
        if(path[i][0] == '*') break; 
        dp[i][0] = 1; 
    }

    // cant. primera fila 
    forn(i,n){
        if(path[0][i] == '*') break; 
        dp[0][i] = 1; 
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(path[i][j] == '*') continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[n-1][n-1]<< endl;


    return 0; 
}

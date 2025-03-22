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
const ll bigbig = 1e18; 
const ll INF = 1LL<<60;
 
 
 
void floyd(vector<vector<ll>>&grafo,ll n){
   forn(k,n)forn(i,n)forn(j,n){
      grafo[i][j]=min(grafo[i][j],grafo[i][k]+grafo[k][j]);
   }
}
 
 
int main(){
    FIN;
    
    ll n,m,q; 
    cin >> n >> m >> q; 
    vector<vector<ll>>grafo(n,vector<ll>(n,bigbig)); 
 
    forn(i,m){
        int a,b,c; 
        cin >> a >> b >> c; 
        a--; b--; 
        if(grafo[a][b] > c) grafo[a][b] = grafo[b][a] = c; // matriz no lista 
    }
 
    // floyd - warshall
    // for (int k = 0; k < n; k++) {
	// 	for (int i = 0; i < n; i++) {
	// 		for (int j = i + 1; j < n; j++) {
	// 			ll dist = grafo[i][k] + grafo[k][j];
	// 			if (dist < grafo[i][j]) {
	// 				grafo[i][j] = grafo[j][i] = dist;
	// 			}
	// 		}
	// 	}
	// }
 
    floyd(grafo, n); 
    while(q--){
        int ini,fini; 
        cin >> ini >> fini; 
        ini--; fini--; 
 
        // casos "invalidos"
        if(ini == fini) grafo[ini][fini] = 0; 
        else if(grafo[ini][fini] == bigbig) grafo[ini][fini] = -1;
       
       cout << grafo[ini][fini] << endl;
    }
    return 0;
}
 
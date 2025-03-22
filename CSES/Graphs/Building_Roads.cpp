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
 
const int maxN = 1e5+100; 
vector<vector<int>>grafo(maxN); 
vector<bool>visitado(maxN, false); 
 
void dfs(int nodo_act){
    visitado[nodo_act] = true; 
    for(int siguientes : grafo[nodo_act]){
        if(!visitado[siguientes]){
            dfs(siguientes); 
        }
    }
}
 
int main(){
    FIN;
    
    int n,m; 
    cin >> n >> m; 
 
    for(int i=0; i<m; ++i){
        int a,b; 
        cin >> a >> b; 
        grafo[a].pb(b); 
        grafo[b].pb(a); 
    }
    
    vector<int>componentes; 
    for(int i = 1; i<=n; ++i){
        if(!visitado[i]){
            componentes.pb(i); 
            dfs(i); 
        }
    }
 
    cout << componentes.size() - 1 << endl;
    for(int i = 1; i<componentes.size(); ++i){
        cout << componentes[i-1] << " " << componentes[i] << endl;
    }
    return 0;
}
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
 
 
int n, m; 
vector<vector<int>> grafo;
vector<bool>visitado;
vector<int> path;
vector<int> dist;
 
void bfs(int source){
    queue<int> q; 
    q.push(source);
    visitado[source] = true;
    path[source] = -777;
    dist[source] = 0;
 
    while(!q.empty()){
        int act = q.front();
        q.pop();
        for(int u : grafo[act]){
            if(!visitado[u]){ 
                visitado[u] = true; 
                path[u] = act;
                dist[u] = dist[act] + 1;
                q.push(u); 
            }
        }
    }
}
 
int main(){
    FIN;
    
    cin >> n >> m;
     
    grafo.resize(n+1);
    visitado.resize(n+1);
    path.resize(n+1); 
    dist.resize(n+1);
 
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        grafo[a].pb(b); 
        grafo[b].pb(a);
    }
 
    int source = 1; 
    bfs(source); 
 
    if(!visitado[n]) cout << "IMPOSSIBLE";
    else{ 
        int ans = dist[n]+1; 
        cout << ans << endl;
 
        // REVERSE PATH N -> SOURCE 
        vector<int> de_pe_a_pa; 
        for(int at = n; at != -777; at = path[at]){
            de_pe_a_pa.pb(at);
        }
        reverse(de_pe_a_pa.begin(), de_pe_a_pa.end()); 
 
        for(int a : de_pe_a_pa){
            cout << a << " ";
        }
    }
 
    return 0;
}
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


int n,m,a,b; 
bool puede;
vector<bool> visitado; 
vector<bool> color;  
vector<vector<int>>grafo; 

void dfs(int nodo, int father = 0){
    for(int v : grafo[nodo]){
        if(v != father){
            if(!visitado[v]){
                visitado[v] = true;
                color[v] = !color[nodo]; 
                dfs(v,nodo); 
            }
            else if(color[v] == color[nodo]){
                puede = false; // no es bipartito
            }
        }
    }

}

int main(){
    FIN;

    cin >> n >> m; 
    puede = true;
    grafo.resize(n+1);
    visitado.resize(n+1, false);
    color.resize(n+1, false); 

    for(int i=0; i<m; i++){
        cin >> a >> b; 
        grafo[a].pb(b);
        grafo[b].pb(a); 
    } 

    for(int i=1; i<=n; i++){
        if(!visitado[i]){
            visitado[i] = true;
            dfs(i);
        }
    }
    
    if(!puede){cout << "IMPOSSIBLE" << endl;}
    else{
        for(int i=1; i<=n; i++){
            cout << (color[i] ? 1 : 2) << " ";
        }
    }

    return 0; 
}

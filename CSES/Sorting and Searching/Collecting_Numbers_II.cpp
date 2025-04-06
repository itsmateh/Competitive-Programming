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

    int n, m; 
    cin >> n >> m; 
    vl arr(n); forn(i,n) cin >> arr[i]; 
    vl ind(n+1); forn(i,n) ind[arr[i]] = i;  
    

    int pasadas = 1; 
    for(int i=0; i<n; i++){
        if(ind[i] > ind[i+1]) pasadas++;
    }
    
    
    while(m--){
        int a,b; cin >> a >> b; 
        a--; b--; 

        map<int, int> pares_numeros;    
        if(arr[a] - 1 >= 1) pares_numeros.insert({arr[a] - 1, arr[a]});
        if(arr[a] + 1 <= n) pares_numeros.insert({arr[a], arr[a] + 1});

        if(arr[b] - 1 >= 1) pares_numeros.insert({arr[b] - 1 , arr[b]});
        if(arr[b] + 1 <= n) pares_numeros.insert({arr[b], arr[b] + 1});

        // check previo al swap para ver cuantas relaciones de consecutivos estan rotas (ya contadas)
        for(auto iter = pares_numeros.begin(); iter != pares_numeros.end(); iter++){
            if(ind[iter->first] > ind[iter->second]) pasadas--; 
        }

        // swapeo 
        swap(arr[a], arr[b]); 
        ind[arr[a]] = a; ind[arr[b]] = b; 

        // check posterior al swap para sumarle las relaciones rotas 
        for(auto iter = pares_numeros.begin(); iter != pares_numeros.end(); iter++){
            if(ind[iter->first] > ind[iter->second]) pasadas++; 
        }

        int ans = pasadas; 
        cout << ans << endl;
    }

    return 0;
}

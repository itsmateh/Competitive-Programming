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
#define esta(x, c) ((c).find(x) != (c).end())


struct segtree{
    vector<ll> t; 
    int tam; ll neutro = 0; // neutro para la suma 
    ll operation(ll a, ll b){return a+b;}

    void build(vl v, int n){
        // la potencia de 2 >= n
        tam = sizeof(int) *8 -  __builtin_clz(n); 
        tam = 1<<tam; 

        t.resize(2*tam, neutro); 
        forn(i,n) t[tam+i] = v[i];
        
        // construir el arbol de abajo para arriba
        for(int i=tam-1; i>0; i--){
            t[i] = operation(t[i<<1], t[i<<1|1]); 
            // forma optimizada de t[i] = t[2*i] + t[2*i+1]   
        }
    }

     void update(int p, ll value) {
        for (t[p += tam] = value; p>1; p>>=1) t[p>>1] = operation(t[p],t[p^1]); // right shift -> n/2 en cada desplazamiento
    }
    
    ll query(int l, int r){
        ll res = neutro; 
        for(l += tam , r +=tam; l <= r; l>>=1, r>>=1){
            if(l & 1) res = operation(res, t[l++]); 
            if(!(r & 1)) res = operation(res, t[r--]);  
        }
        return res; 
        // si l impar -> es un h.der, no incluimos al padre pq esta fuera de rango. Incluimos actual y vamos al Sig. nodo
        // si r es par -> es un h.izq, no incluimos al padre pq esta fuera de rango. Inlcuimos actual y vamos al anterior nodo
        // l & 1 detecta borde izquierdo y !(r & 1) detecta borde derecho 
    }


};

int main(){
    FIN;
    
    ll n, q; cin >> n >> q; 
    vl x(n); forn(i,n) cin >> x[i]; 

    segtree s; 
    s.build(x,n); 

    while(q--){
        int first; cin >> first; 
        if(first == 1){
            int k, u; cin >> k >> u; 
            k--; s.update(k, u); 
        }
        else{
            int a,b; cin >> a >> b; 
            a--; b--; 
            cout << s.query(a,b) << endl;
        }
    }

    return 0; 
}
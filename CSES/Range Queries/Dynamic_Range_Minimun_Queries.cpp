#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vi = vector<int>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
const ll MOD = 1e9+7;
const ll MAXN = 2e5+5;
const int INF = 1<<30; 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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


const ll NEUT = INF;
struct node {
   int l, r; ll ans;
   node() {ans = NEUT, l = r = -1;} // REMINDER !!! Set NEUT
   node(ll val, int pos): l(pos), r(pos),ans(val) {} // Set node
   void update(ll val) {ans = val;} // Define update function
};

struct segtree { // Segtree for Sum Range Query
   #define l(x) int(x<<1)
   #define r(x) int(x<<1|1)
   
   vector<node> t; int tam;

   node op(node a, node b) { //Operacion de query
       node aux; aux.ans = min(a.ans, b.ans); 
       aux.l = a.l; aux.r = b.r;
       return aux;
   }

  node query(int l, int r, int p = 1) {
     node &cur = t[p];
     if(l > cur.r || r < cur.l) return node(); // Return NEUT
     if(l <= cur.l && cur.r <= r) return cur;
     return op(query(l,r,l(p)),query(l,r,r(p)));
   }

  void update(int pos, ll val, int p = 1) { // root at p = 1
       node &cur = t[p];
     if(cur.r < pos || cur.l > pos) return;
     if(cur.l == cur.r) { cur.update(val); return; }
     update(pos, val, l(p)); update(pos, val, r(p));
     cur = op(t[l(p)], t[r(p)]);
  }

   void build(vector<ll> v, int n) { // iterative build
       tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
       t.resize(2*tam); v.resize(tam);
       forn(i,tam) t[tam+i] = node(v[i],int(i));
       for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
   }
};
 
int main(){
   FIN;    

   int n, q; 
   cin >> n >> q;
   vl v(n);
   forn(i,n) cin >> v[i]; 
   segtree s;
   s.build(v, n);
   
   while(q--){ 
      ll op, a,b; 
      cin >> op >> a >> b;
      a--;
      if(op == 1){
         s.update(a,b); 
      }else{ 
         b--;
         cout << s.query(a,b).ans << endl;
         
      }
   } 
   return 0; 
}
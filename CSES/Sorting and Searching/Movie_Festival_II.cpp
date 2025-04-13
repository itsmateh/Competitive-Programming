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
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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


bool compare(pii &f, pii &s){return f.second < s.second;}
 
int main() {
   FIN; 

   int n, k; cin >> n >> k; 
   vector<pii>hs(n); 
   forn(i,n) cin >> hs[i].first >> hs[i].second; 

   sort(hs.begin(), hs.end(), compare);
   multiset<int> dispo; forn(i,k) dispo.insert(0); 
   /* van a haber K ceros representando la cantidad de personas */

   int ans = 0; 
   forn(i,n){
      // quiero la primera persona que se pase del horario de inicio
      auto it = dispo.upper_bound(hs[i].first);
      // si apunta al inicio -> todas terminan despues del arranque de la peli[i]
      if(it == dispo.begin()) continue; 
      
      // retrocedo 1 pos -> la que terminó lo más cerca de inicio pero sin pasarse y la elimino
      dispo.erase(--it); 
      // agrego el final de la pelicula actual (o sea el chabon la puede ver y va terminar a esa hora)
      dispo.insert(hs[i].second); 
      ans++;
   }
   cout << ans << endl;
   
   return 0; 
}
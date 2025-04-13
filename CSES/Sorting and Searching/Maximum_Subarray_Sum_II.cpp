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

/* 

8 1 2
-1 3 -2 5 3 -5 2 2

*/
int main() {
   FIN; 

   int n, a, b; cin >> n >> a >> b; 
   vl arr(n); forn(i,n) cin >> arr[i]; 

   vl pref(n+1, 0); 
   forn(i,n) pref[i+1] = pref[i] + arr[i];

   // LONG LONG NO INT ME COMI 3 WA POR ESE DETALLE !! 

   ll ans = LONG_MIN; 

   multiset<ll> win; 
   for(int i=a; i<=n; i++){
      if(i > b) win.erase(win.find(pref[i-b-1])); // si me pase del rango borro el primer elemento
      win.insert(pref[i-a]); 
      ans = max(ans, pref[i] - *win.begin()); 
   }

   cout << ans << endl;
   return 0; 
}
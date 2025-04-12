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

int main() {
   FIN;

   int n,k;
   cin >> n >> k; 
   int index = 0;
   ordered_set inset; 
   vector<int> arr(n); 

   forn(i,n){
      ll value; cin >> value; 
      arr[i] = value; 
      inset.insert({value, index++}); 
        // si es mayor/igual a K+1 -> borramos el ultimo elemento. Reminder: 0index, por lo que si i >= k, inserto k+1 elementos
      if(i >= k) inset.erase(inset.lower_bound({arr[i-k],0})); 
        // si es mayor/igual a K -> sacamos la media e imprimimos
      if(i >= k-1) cout << (*inset.find_by_order(((k-1)/2))).first << " ";
   }
   return 0;
}

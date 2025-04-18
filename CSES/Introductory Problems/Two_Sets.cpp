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
   ll n; 
   cin >>n; 

   ll sum = (n * (n+1))/ 2;
   if(sum % 2 != 0){
      cout << "NO" << endl;
      return 0;
   }

   ll target = sum/2;
   vi c1, c2; 
   vb visto(n+1, false);
   for(ll i = n; i >= 1; i--){
      if(target - i >= 0){
         target -= i;
         c1.pb(i);
         visto[i] = true;
      }
   }

   for(int i=1; i<=n; i++){
      if(!visto[i]) c2.pb(i);
   }


   cout << "YES" << endl;
   cout << sz(c1) << endl;
   for(int n:c1) cout << n << " ";

   cout << endl;

   cout << sz(c2) << endl;
   for(int n:c2) cout << n << " ";
   

   return 0; 
}
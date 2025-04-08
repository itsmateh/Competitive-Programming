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
 
 
vector<int> KMP(string s){ 
   int n = (int)s.length(); 
   vector<int> pi(n); 
 
   for(int i=1; i<n; i++){ 
      int j = pi[i-1]; 
      while(j > 0 && s[i] != s[j]) j = pi[j-1];  
         if(s[i] == s[j]) j++;
         pi[i] = j;
   }
   return pi; 
}
 
 
int main(){
   FIN; 
 
   string n, m; 
   cin >> n >> m; 
 
   string txt = m + '#' + n; 
   vi pref = KMP(txt); 
 
   int cont = 0; 
   for(auto x : pref){
      if(x == m.length()) cont++; 
   }
   cout << cont << endl;
 
   return 0; 
}

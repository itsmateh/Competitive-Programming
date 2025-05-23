#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vb = vector<bool>; 
using vl = vector<ll>;
using vi = vector<int>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
const double EPS = 1e-10;
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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    forr(i,1,n) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}


int main() {
   FIN;

   string s; cin >> s;
   vector<int> pf = prefix_function(s); 

   vector<int> ans; 
   int borde = pf[pf.size()-1]; // a b c a b a b c a b  
                                 // 0 0 0 1 2 1 2 3 4 5 --> index = 5, despues voy al 2 y luego al 0, finalizando
   while(borde > 0){
      ans.pb(borde);
      borde = pf[borde-1];
   }

   sort(ans.begin(), ans.end()); 
   for(int a : ans){
      cout << a << " ";
   }
   cout << endl;

   return 0;
}
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

struct sparse_table {
    vll tab;

    void build(vl &arr) {
        int n = arr.size();
        int k = 32 - __builtin_clz(n);
        tab.assign(n, vl(k));
        forn(i,n) tab[i][0] = arr[i];
        
        for(int j = 1; (1 << j) <= n; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                tab[i][j] = min(tab[i][j-1], tab[i + (1 << (j-1))][j-1]);
            }
        }
    }
    
    ll range_min(int L, int R) {
        int j = 32 - __builtin_clz(R - L + 1) - 1;
        return min(tab[L][j], tab[R - (1 << j) + 1][j]);
    }
};


int main(){
    FIN;
    int n,q; cin >> n >> q; 
    vl x(n); forn(i,n) cin >> x[i]; 
    sparse_table st; 
    st.build(x); 
    while(q--){
        ll a, b; cin >> a >> b; 
        a--; b--; 
        cout << st.range_min(a,b) << endl;
    }
    return 0; 
}
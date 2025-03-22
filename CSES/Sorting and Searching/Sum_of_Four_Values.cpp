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


int main(){
    FIN;

    
    int n, x; cin >> n >> x; 
    vi v(n);
    vll vec(n, vl(2));
    
    forn(i,n){
        cin >> v[i]; 
        vec[i][0] = v[i];
        vec[i][1] = i+1;
    }

    sort(vec.begin(), vec.end());
    for(int p1 = 0; p1<n-3; p1++){
        for(int p2 = p1+1; p2<n-2; p2++){
            int p3 = p2+1; int p4 = n-1; 
            while(p4 > p3){
                int sum = vec[p1][0] + vec[p2][0] + vec[p3][0] + vec[p4][0];
                if(sum > x) p4--; 
                else if(sum < x) p3++; 
                else{
                    cout <<  vec[p1][1] << " " <<  vec[p2][1] << " " << vec[p3][1] << " " << vec[p4][1]; 
                    return 0;
                }
            } 
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0; 
}

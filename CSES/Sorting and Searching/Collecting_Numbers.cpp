#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define raya cerr << "=================" << endl;
#define forn(i,n) for(ll i=0;i<ll(n);i++)
#define pb push_back
#define mp make_pair
#define endl "\n";


int main(){
    FIN;

    int n; cin>>n;
    vector<int> arr(n);
    forn(i,n){cin>>arr[i];}

    // ind_X > ind_X+1 -> pasadas+1 
    vector<ll>ind(n);
    forn(i,n){ind[arr[i]] = i;}

    ll ans = 1;
    forn(i,n){if(ind[i] > ind[i+1]){ans++;}}
    cout<<ans<<endl;

    return 0;
}
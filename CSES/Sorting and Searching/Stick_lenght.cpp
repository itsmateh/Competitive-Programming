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
    vector<ll>arr(n);
    forn(i,n){cin>>arr[i];}
    sort(arr.begin(), arr.end());
    ll mid = arr[n/2];
    ll ans = 0;
    forn(i,n){ 
        ans += abs(mid-arr[i]);
    }

    cout<<ans<<endl;
    return 0;
}
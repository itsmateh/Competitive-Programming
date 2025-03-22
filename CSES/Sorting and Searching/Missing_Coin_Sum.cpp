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

    ll ans = 0;
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        if(arr[i] > ans+1){
            break;
        }
        ans += arr[i]; 
    }
    cout<<ans+1<<endl;
    return 0;
}
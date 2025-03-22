#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define raya cerr << "=================" << endl;
#define forn(i,n) for(ll i=0;i<ll(n);i++)
#define pb push_back
#define mp make_pair
#define endl "\n";
 
 
int main(){
    FIN 
 
    ll n,x; 
    cin>>n>>x;
    vector<int> w(n);
    forn(i,n) cin>>w[i];
    sort(w.begin(),w.end());
 
    ll l = 0;
    ll r = n-1;
    ll ans = 0;
 
    while(r>=l){
        if(w[r] + w[l] <= x){
            r--;
            l++;
            ans++;
        }else{
            r--;
            ans++;
        }
    }
    cout<<ans<<endl;
 
    return 0;

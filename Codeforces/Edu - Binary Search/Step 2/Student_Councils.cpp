#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define raya cerr << "=================" << endl;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define pb push_back
#define endl "\n";


int k,n;
vector<ll>arr;
bool valid(ll x){ 
    ll sum = 0;
    forn(i,n){
        sum = sum + min(x,arr[i]);
    }
    return (sum/x) >= k;
}

int main(){
    FIN 

    cin>>k>>n;
    forn(i,n){
        int a; cin>>a;
        arr.pb(a);
    }

    ll l = 0;
    ll r = 30*1e9;
    while(r>l+1){
        ll m = (r+l)/2;
        if(valid(m)){l = m;}
        else{r=m;}
    }
    cout<<l<<endl;
    return 0;
}
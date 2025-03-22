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

ll n,k;
vector<ll>arr;

bool valid(ll m){
    ll cont = 1;
    ll ult_pos = arr[0];
    bool ok = false;
    forn(i,n){
        if(arr[i] - ult_pos >= m){
            cont++;
            ult_pos = arr[i];
        }
        if(cont >= k){ok = true;}
    }
    return ok;
}


int main(){
    FIN 
    
    cin>>n>>k; 
    arr.resize(n);
    forn(i,n){
        cin>>arr[i];
    }

    ll l = 0;
    ll r = 1e10;
    while(r > l+1){
        ll mid = (r+l)/2;
        if(valid(mid)){l = mid;}
        else{r = mid;}
    }
    cout<< l <<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define raya cerr << "=================" << endl;
#define forn(i,n) for(ll i=0;i<ll(n);i++)
#define endl "\n";

string hamburguesa; 
ll nb, ns, nc;
ll pb, ps, pc;
ll b = 0; ll s = 0; ll c = 0;
ll plata;

bool valid(ll m){
    ll a1 = max(b*m-nb,(ll)0);
    ll a2 = max(s*m-ns,(ll)0);
    ll a3 = max(c*m-nc,(ll)0);

    ll total = a1 * pb + a2 * ps + a3 * pc;
    return plata >= total;
}


int main(){
    FIN 
    cin>> hamburguesa;
    cin>> nb >> ns >>nc;
    cin>> pb >> ps >>pc;
    cin>> plata;
    
    for(auto &a : hamburguesa){
        if(a == 'B')b++;
        else if( a == 'C') c++;
        else s++;
    }

    ll l = 0; 
    ll r = 1e14;
    ll ans;
    while(r >= l){
        ll mid = l+(r-l)/2;
        if(valid(mid)){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }

    cout<<r<<endl;
    return 0;
}
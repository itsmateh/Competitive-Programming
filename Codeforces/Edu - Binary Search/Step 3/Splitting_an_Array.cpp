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
    bool ok = true;
    ll segmento = 1;
    ll aux = 0;
    forn(i,n){
        if(arr[i] > m){
            ok = false;
            break;
        }
        if(aux + arr[i] <= m){
            aux+= arr[i];
        }else{
            aux = arr[i];
            segmento++;
        }
    }
    if(ok == true){
        return segmento <= k;
    }else{
        return false;
    }
    
}

int main(){
    FIN 
    cin>>n>>k; 
    arr.resize(n);
    ll suma  = 0;    
    forn(i,n){
        cin>>arr[i];
        suma+=arr[i];
    }
    ll l = 0; 
    ll r = suma+1000;
    while(r > l+1){
        ll mid = (r+l)/2;
        if(valid(mid)){r = mid;}
        else{l = mid;}
    }
    cout<<r<<endl;
    return 0;
}
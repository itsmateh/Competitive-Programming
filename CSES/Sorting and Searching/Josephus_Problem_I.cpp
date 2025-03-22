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
    
    ll n; cin >> n;
    queue<ll> qu;
    for(int i = 1; i<=n; i++){
        qu.push(i);
    }
 
    bool orden = false;
 
    while(!qu.empty()){
        ll ch = qu.front();
        qu.pop();
 
        if(orden){cout << ch << " ";}
        else{qu.push(ch);}
        orden = not orden;    
    }
 
    return 0;
}

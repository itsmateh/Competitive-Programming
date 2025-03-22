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
    vector<ll>time(n);
    forn(i,n) cin >> time[i];
 
    sort(time.begin(), time.end());
    ll denso = time[n-1];
    ll suma_menores = accumulate(time.begin(), time.end()-1, 0LL);
 
    if(suma_menores < denso){cout << denso * 2;}
    else{cout << suma_menores + denso;}
 
    return 0;
}
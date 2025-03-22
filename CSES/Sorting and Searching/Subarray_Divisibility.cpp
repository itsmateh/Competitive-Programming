#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define raya cerr << "=================" << endl;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define pb push_back
#define mp make_pair
#define endl "\n";
 
int main(){
    FIN;    
 
    ll n; cin >> n; 
    vector<ll>arr(n);
    ll psums = 0;
    arr[psums] = 1;
    forn(i,n){
        int num; 
        cin >> num; 
        psums+=num; 
        arr[(psums%n+n)%n]++; // para los negativos ese +n % n
    }
    ll ans = 0; 
    for(auto &x : arr){
        ans += x * (x-1) / 2; 
    }
    cout << ans << endl;
    return 0;
}

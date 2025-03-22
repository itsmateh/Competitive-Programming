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
 
 
 
ll n,k;
vector<ll>arr;
bool valid(ll mid){
    /* contador de particiones, funciona como un divisor automatico del array
    no hay que pensar como dividirlo en K partes, solo contar y ver si es menor 
    o igual a K. Particiones <= k */ 
    ll particiones = 0; ll curr = 0;
    for(const ll &a : arr){
        if(a > mid) return false;
 
        if(a + curr > mid){
            particiones++;
            curr = 0;
        }
        curr += a;
    }
    if(particiones > 0) particiones++;
    return (particiones <= k);
}
 
 
int main(){
    FIN;    
 
    cin >> n >> k;
    arr.resize(n); 
    forn(i,n){cin >> arr[i];}
 
    ll l = 0; 
    ll r = 10e15; 
    ll ans = 0;
    while(r > l){
        ll mid = (r+l)/2;
        if(valid(mid)){
            r = mid;
        }
        else l = mid+1;
    }
    
    cout << l << endl;
 
    return 0;
}
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


ll w,h,n; 
bool valid(ll x){
    return (x/w)*(x/h) >= n;
}

int main(){
    FIN
    cin>>w>>h>>n; 

    ll l = 0; 
    ll r = 1;
    while(!valid(r)){r*=2;}
    while(r > l+1){
        ll mid = (r+l)/2;
        if(valid(mid)) r = mid;
        else l = mid;
    }   
    cout<<r<<endl;

    return 0;
}
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
    int n; cin>>n;
    vector<ll>towers;
    forn(i,n){
        int cube; 
        cin>>cube; 
        int l = 0; int r = towers.size();
        while(r > l){
            int m = (r+l)/2;
            if(towers[m] > cube){r = m;}
            else l = m+1;
        }     
        if(l == towers.size()){towers.pb(cube);}
        else {towers[l] = cube;}
    }
    cout<< towers.size() << endl;
    return 0;
}
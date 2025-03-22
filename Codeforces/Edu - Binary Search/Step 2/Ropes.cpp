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

int n,k; 
vector<ll>arr;

bool valid(double x){
    double sum = 0;
    forn(i,n){
        sum += floor(arr[i]/x);
    }
    return sum>=k;
}

int main(){
    FIN
    cin>>n>>k;

    for(int i=0; i<n; i++){
        int s; cin>>s;
        arr.pb(s);
    }

    double l = 0; // bueno
    double r = 1e8; // malo
    
    for(int i=0; i<100; i++){
        double m = (r+l)/2;
        if(valid(m)) l = m;
        else r = m;
    }

    cout<<setprecision(20)<<l<<endl;
    return 0;
}
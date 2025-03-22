#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define raya cerr << "=================" << endl;
#define forn(i,n) for(ll i=0;i<ll(n);i++)
#define pb push_back
#define endl "\n";


struct datos{
    ll t,z,y;
};

ll m,n;
vector<datos>info;
vector<ll>temp;
vector<ll>globito_time;


bool valid(ll T){
    ll cant_globos = 0;
    for(ll i=0; i<n; i++){
        ll total = (info[i].t * info[i].z)+info[i].y;
        temp[i] = (T/total) * info[i].z + min(ll(info[i].z), ((T%total)/info[i].t));
        cant_globos += temp[i];
    }
    if(cant_globos >= m){
		globito_time = temp;
        return true;
    }
    else{
        return false;
    }
}
int main(){
    FIN 

    cin>>m>>n;
    info.resize(n);
    temp.resize(n);
    globito_time.resize(n);
    forn(i,n){cin >> info[i].t >> info[i].z >> info[i].y;}   

    if(m != 0){
       ll l = 0; 
       ll r = 1e9+5;
       while(r-l>1){
            ll m = l+((r-l)/2);
            if(valid(m)){
                r = m;
            }else{l = m;}
       } 
       cout<<r<<endl;
       for(ll a:globito_time){
            if(m-a < 0){a -= a-m;}
            cout<<a<<" ";
            m -= a;
        }     
    }
    else{
        cout<<'0'<<endl;
        forn(i,n){cout<<'0'<<' ';}
    }

    return 0;
}
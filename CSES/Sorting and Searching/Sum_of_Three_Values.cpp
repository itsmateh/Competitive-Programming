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


int main(){
    FIN;

    ll n,x; 
    cin>>n>>x;
    vector<pair<ll,ll>>valores(n);
    forn(i,n){
        cin>>valores[i].first;
        valores[i].second = i+1; // 1 indexado 
    }
    
    sort(valores.begin(), valores.end());

    for(int i= 0; i<n-2; i++){
        ll objetivo = x - valores[i].first;
        ll l = i+1; 
        ll r = n-1; 
        while(l < r){
            ll suma = valores[l].first + valores[r].first;
            if(suma == objetivo){
                cout<< valores[i].second << ' ' << valores[l].second << ' ' << valores[r].second << endl;
                return 0;
            }
            else if(suma > objetivo){r--;}
            else{l++;}
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
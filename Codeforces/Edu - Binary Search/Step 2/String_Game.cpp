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

string t, p; 
vector<int>nros;

bool valid(int m){
    vector<bool>afuera(t.size(),false);
    forn(i,m){
        afuera[nros[i]] = true;
    }   

    int ind = 0;
    forn(i, t.size()){
        if(ind < p.size() && !afuera[i] && t[i] == p[ind]){
            ind++;
        }
    }
    return (ind == p.size());
}


int main(){
    FIN 
    cin>>t>>p;
    int n = t.size();
    nros.resize(n);
    for(int i=0; i<n; i++){
        cin>>nros[i];
        nros[i]--;
    }

    int l = 0; 
    int r = n;
    while(r > l+1){
        int m = l+(r-l)/2;
        if(valid(m)){
            l = m;
        }else{
            r = m;
        }
    }
    
    cout<<l<<endl;
    return 0;
}
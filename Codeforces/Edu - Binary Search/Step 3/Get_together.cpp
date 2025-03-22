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


ll n; 
vector<ll>x; 
vector<ll>v;

bool valid(double tiempo){
    // ... L ----- R ...
    double maxIzq = INT_MIN; // punta izq del intervalo 
    double minDer = INT_MAX; // punta der del intervalo
    forn(i,n){
        double izq = x[i] - tiempo*v[i];
        double der = x[i] + tiempo*v[i];
        maxIzq = max(maxIzq, izq);
        minDer = min(minDer, der);
    } 
    return (minDer - maxIzq >= 0); // si existe un X que se encuentre entre ambos intervalos
}

int main(){
    FIN 

    cin>>n;
    x.resize(n);
    v.resize(n);
    forn(i,n){
        cin>>x[i]>>v[i];
    }

    double l = 0; 
    double r = 1e11; 

    for(int i=0; i<100; i++){
        double mid = (r+l)/2;
        if(valid(mid)){r = mid;}
        else{l = mid;}
    }
    cout<< setprecision(15) << r << endl;
    return 0;
}
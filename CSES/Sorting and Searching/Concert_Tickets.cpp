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

    int n,m; 
    cin>>n>>m;
    multiset<int>tickets;
    forn(i,n){
        int a; cin>>a; 
        tickets.insert(a);
    }

    // encontrar el primero elemento no menor que X con lower bound 
    // si el primer elemento mayor que X esta al inicio del multiset
    // entonces no hay solucion, cout -1

    forn(i,m){
        ll precio; cin>>precio; 
        auto p = tickets.upper_bound(precio); 
        if(p == tickets.begin()){
            cout<< -1 << endl;
        }
        else{
            cout<< *(--p) <<endl;
            tickets.erase(p);
        }
    }


    return 0;
}
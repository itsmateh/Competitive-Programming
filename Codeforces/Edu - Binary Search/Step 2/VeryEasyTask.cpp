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

ll n, x, y;
bool valid(ll t){
    return (t/x)+(t/y) >= n-1; /* n-1 pq despues tengo q sumarle el min(x,y) 
                                siendo ese tiempo donde solo se pudo usar 1 maquina 
                                ya que solo estaba el papel original y 0 copias para usar 
                                la otra maquina*/
}

int main(){
    FIN
    
    cin>>n>>x>>y;
    
    ll l = 0;
    ll r = 2*1e9;
    ll ans = 0;
    while(r>=l){
        ll m = (l+r)/2;
        if(valid(m)){
            ans = m; // me quedo con el mejor tiempo
            r = m-1; // voy a ver si hay un tiempo menor
        }
        else{
            l = m+1; // si todavia no cumple con este m, me paro en el siguiente
        }
    }
    cout<<ans+min(x,y)<<endl;
    return 0;
}
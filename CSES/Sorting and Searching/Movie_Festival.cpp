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
    vector<pair<int,int>>movies(n);
    forn(i,n){
        int a,b; cin>>a>>b;
        movies[i] = mp(a,b);
    }

    sort(movies.begin(), movies.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }); // ordenado por tiempo de finalizacion
    
    int ans = 0; int maximo = 0;
    forn(i,n){
        if(movies[i].first >= maximo){
            ans++;
            maximo = movies[i].second;
        }
    }
    cout<<ans<<endl;
    return 0;
}
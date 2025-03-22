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

    
    ll n;
    cin>>n;
    vector<ll>songs(n);
    forn(i,n)cin>>songs[i];
    set<ll>curr_songs; 
    
    int best = 0;
    int inicio = 0;
    for(int fin = 0; fin<n; fin++){
        while(curr_songs.count(songs[fin])){
            curr_songs.erase(songs[inicio]);
            inicio++;
        }

        curr_songs.insert(songs[fin]);
        best = max(best, fin-inicio+1);
    }

    cout<<best<<endl;
    return 0;
}
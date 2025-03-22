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
 
    int n; cin >> n; 
    vector<pair<int, int>>tareas;
    forn(i,n){
        int start, finish; 
        cin >> start >> finish; 
        tareas.pb(mp(start, finish));
    }
    sort(tareas.begin(), tareas.end());
 
    /* si hubieran 2 taras nada mas (t1, t2) como seria la cosa
    primer orden: t1 -> t2
 
        rew1 = d(t1) - fn(t1) + d(t2) - fn(t2) - fn(t1)
               d(t1) + d(t2) - 2 * fn(t1) - fn(t2)
 
    segundo orden: t2 -> t1
        rew2 = d(t2) - fn(t2) + d(t1) - fn(t1) - fn(t2)
               d(t1) + d(t2) - 2 * fn(t2) - fn(t1)
       
        entonces como las rew1 y rew2 son practicamente iguales 
        diferenciandose en 2 * fn(ti), hay que priorizar
        la tarea que dure menos, para que -castigo -> +recompensa
    
    */
 
    ll rew = 0; ll curr = 0;
    forn(i,n){
        curr += tareas[i].first;
        rew += tareas[i].second - curr;
    }
 
    cout << rew;
    return 0;
}
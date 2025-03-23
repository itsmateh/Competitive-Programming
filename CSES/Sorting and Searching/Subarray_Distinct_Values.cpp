#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vi = vector<int>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
const ll MOD = 1e9+7;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define raya cerr << "=================" << endl;
#define forn(i,n) for(ll i=0;i<ll(n);i++)
#define dforn(i,n) for(ll i=ll(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define endl "\n";
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define esta(x, c) ((c).find(x) != (c).end())


int main(){
    FIN;
    int n,k; cin >> n >> k; 
    vl arr(n); 
    forn(i,n) cin >> arr[i];

    map<ll, ll>freq; 
    ll l = 0; 
    ll r = 0; 
    ll distinct_numbers = 0; 
    ll ans = 0;
    while(r<n){
        // si el numero es nuevo o si estaba guardado pero su contador es 0 -> aumento los distintos numeros
        if(freq.find(arr[r]) == freq.end() || freq[arr[r]] == 0){
            distinct_numbers++;
        }
        // aumento la frecuencia del numero actual
        freq[arr[r]]++;
        // hasta que distintos_numeros sea menor que k
        while(distinct_numbers > k){
            // disminuyo el numero que se va ir de la ventana
            freq[arr[l]]--;
            // si ese numero su cantidad es 0, disminuyo los distintos numeros diferentes que hay en la ventana
            if(freq[arr[l]] == 0){
                distinct_numbers--;
            }
            // aumento left para seguir iterando hasta que distintic_numbers sea menor que k
            l++;
        }

        // salgo del loop, por lo que una vez hay distintics_numbers < k, cuento todos los subarrays nuevos de l -> r
        ans += r - l +1; 
        // aumento right para seguir con la ventana
        r++;
    }

    cout << ans << endl;
    return 0; 
}

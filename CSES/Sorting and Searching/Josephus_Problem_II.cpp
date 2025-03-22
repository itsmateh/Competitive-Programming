#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
const ll MOD = 1e9+7;
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define raya cerr << "=================" << endl;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define endl "\n";
 
int main(){
    FIN;    
 
    indexed_set s; 
    int n, k; cin >> n >> k; 
    for(int i=1; i<=n; i++) s.insert(i);
 
    int ind = k%n;
    while(n--){
        auto x = s.find_by_order(ind);
        cout << *x << " ";
        s.erase(x);
        if(n) ind = (ind%n+k)%n;
    }
 
    return 0;
}

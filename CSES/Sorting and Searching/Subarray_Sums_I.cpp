#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define raya cerr << "=================" << endl;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define pb push_back
#define mp make_pair
#define endl "\n";
 
int main(){
    FIN;    
 
    
    int n,x; cin >> n >> x;
    vector<int>arr(n);
    forn(i,n){
        cin >> arr[i];
    } 
 
    int l,r,curr,ans; 
    l = 0; 
    r = 0; 
    curr = 0; 
    ans = 0; 
 
    while(r < n){
        while(r < n && curr < x){
            curr+= arr[r];
            r++;
        }
 
        while(l <= r && curr > x){
            curr -= arr[l];
            l++;
        }
 
        if(curr == x){
            ans++;
            curr -= arr[l];
            l++;
        }
    }
 
 
    cout << ans << endl;
    return 0;
}
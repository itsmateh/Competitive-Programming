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

int main(){
   FIN
   
   int n, k;
   cin>>n>>k;
   vector<int>arr(n);
   vector<int>nums(k);
   forn(i,n){cin>>arr[i];}
   forn(i,k){cin>>nums[i];}

   for(int i=0; i<k; i++){
      int l = -1; 
      int r = n;
      while(r>l+1){
         int m = (l+r)/2;
         if(arr[m] <= nums[i]){l = m;}
         else {r = m;}
      }
      cout<<l+1<<endl;
   }     
      return 0;

}
 

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

int bsearchL(int num, vector<ll>&arr){
   int l = -1;
   int r = arr.size();
   while(r>l+1){
      int mid = (r+l)/2;
      if(arr[mid]>=num){r = mid;}
      else{l = mid;}
   }
   return r;
}

int bsearchR(int num, vector<ll>&arr){
   int l = -1;
   int r = arr.size();
   while(r>l+1){
      int mid = (r+l)/2;
      if(arr[mid]>num){r = mid;}
      else{l = mid;}
   }
   return r;
}


int main(){
   FIN

   int n; 
   cin>>n;

   vector<ll>arr(n);
   forn(i,n){cin>>arr[i];}
   sort(arr.begin(), arr.end());
   
   int k; 
   cin>>k;

   while(k--){
      int l,r; 
      cin>>l>>r;
      int a = bsearchL(l,arr); 
      int b = bsearchR(r,arr);

      cout<<b-a<<" ";
   }

   return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(){
  ll n,prod;
  cin>>n>>prod;
 
  vector<ll>k(n);
  for(int i = 0; i<n; i++){
    cin>>k[i];
  }
 
 
  ll inicio=0;
  ll fin=1e18;
  ll ans=0;
  while(inicio<=fin){
    ll mid=(inicio+fin)/2;
    ll suma=0;
 
    for(int j=0; j<n; j++){
      suma+=(mid/k[j]);
      if(suma>=prod){
        break;
      }
    }
    if(suma>=prod){
      ans=mid;
      fin=mid-1;
    }
    else{
      inicio=mid+1;
    }
  }
 
  cout<<ans<<"\n";
}
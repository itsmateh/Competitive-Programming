#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;


ll exp(ll a, ll b, ll m){
  if(b == 0) return 1;
  ll aux = exp(a,b/2,m);
  if(b%2==0) return (aux*aux)%m;
  else return (((aux*aux)%m) * a)%m;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t,a,b,c;
  cin>>t;
  while(t--){
    cin>>a>>b>>c;
    ll ans = exp(b,c,MOD-1);
    cout<<exp(a,ans,MOD)<<"\n";
  }
  return 0;
}
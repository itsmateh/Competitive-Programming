#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 1e9;

ll solve(ll n, ll x){

  vector<ll>monedas(n);
  vector<ll>dp(x+1, INF); 
  
  for(int i=0; i<n; i++){
    cin>>monedas[i];
  }
  dp[0] = 0;

  for(ll i = 1; i<=x; i++){
    for(ll m : monedas){
      if(i-m >=0){
        dp[i] = min(dp[i], dp[i-m] + 1);
      }
    }
  }

  if(dp[x] == INF){
    return -1;
  }else{
    return dp[x];
  }

}


int main(){
  FIN
  ll n, x;
  cin>> n >> x;

  cout<<solve(n,x)<<"\n";
  return 0;
}
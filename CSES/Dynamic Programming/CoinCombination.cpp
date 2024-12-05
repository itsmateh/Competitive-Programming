#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9+7;

ll solve(ll n, ll x){
  vector<ll>monedas(n);
  vector<ll>dp(x+1);
  for(int i=0; i<n; i++){
    cin>>monedas[i];
  }

  dp[0] = 1;
  for(ll i = 1; i<=x; i++){
    for(ll m : monedas){
      if(i-m >= 0){
        dp[i] = (dp[i] + dp[i-m]) % mod;
      }
    }  
  }
  return dp[x];
}

int main(){
  ll n, x;
  cin>> n >> x;

  cout<<solve(n,x)<<"\n";
}

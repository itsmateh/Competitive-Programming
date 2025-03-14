#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIN ios:sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9+7;


ll solve(ll n){
  vector<int> dp(n+1);

  dp[0] = 1;
  for(ll i=1; i<=n; i++){
    for(ll j=1; j<=6; j++){
      if((i-j) >= 0){
        dp[i] = (dp[i] + dp[i-j]) % mod;
      }
    }
  }

  return dp[n];
}


int main(){

  ll n; cin>>n;

  cout<<solve(n)<<"\n";
  return 0;


}


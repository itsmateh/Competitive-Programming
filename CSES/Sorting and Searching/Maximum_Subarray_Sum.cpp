#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(){
  ll n; cin>>n;
  
  vector<ll>vec(n); 
  
  for(ll i=0; i<n; i++) cin>>vec[i];
  
  ll actual = 0;
  ll max_suma = INT_MIN;

  for(ll i=0; i<n; i++){
    actual += vec[i];
    if(actual > max_suma){
      max_suma = actual;
    }
    if(actual < 0){
      actual = 0;
    }
  }
  return max_suma;
}

int main(){
  cout<<solve()<<"\n";

  return 0;

}
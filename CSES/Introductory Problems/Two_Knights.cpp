#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  ll n;
  cin>>n;

  for(ll i=1; i<=n; i++){
    ll pos_totales = (i*i) * (i*i-1) / 2; 
    ll pos_invalidas = 4 * (i-1) * (i-2);
    cout<< pos_totales - pos_invalidas << "\n";
  }
  return 0;
}

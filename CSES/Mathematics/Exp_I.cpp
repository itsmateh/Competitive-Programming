#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;


ll exp(ll a, ll b){
  if(b == 0) return 1;
  ll aux = exp(a,b/2);
  if(b%2==0) return (aux*aux)%MOD;
  else return (((aux*aux)%MOD) * a)%MOD;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t,a,b,c;
  cin>>t;
  while(t--){
    cin>>a>>b;
    cout<<exp(a,b)<<"\n";
  }
  return 0;
}

for i in range(1, 51):
    s = '':
    if i % 3 == 0:
        s += 'mono'
    if i % 5 == 0:
        s += 'noki'
    print(s or i)
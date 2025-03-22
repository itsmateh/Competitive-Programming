#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
  FIN

  ll n, m;
  cin>>n>>m;
  vector<ll> a(n); 
  vector<ll> b(m);

  for(ll i=0; i<n; i++){cin>>a[i];}
  for(ll i=0; i<m; i++){cin>>b[i];}
 
  ll total = 0; ll j = 0; ll i = 0;
  while(i<n && j<m){
    if(a[i]<b[j]){i++;}
    else if(a[i]>b[j]){j++;}
    else{
      ll cantA = 0; ll cantB = 0;
      ll valA = a[i]; ll valB = b[j];

      while(i<n && a[i] == valA){
        cantA++;
        i++;
      }

      while(j<m && b[j] == valB){
        cantB++;
        j++;
      }

      total+= cantA * cantB;

    }
  }
  cout<<total<<endl;
  return 0;
}
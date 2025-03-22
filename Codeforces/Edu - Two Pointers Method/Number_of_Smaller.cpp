#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIN ios::sync_with_stdio(0); cin.tie(0); 

int main(){
  FIN

  ll n, m;
  cin>>n>>m;
  vector<ll> a(n); 
  vector<ll> b(m);

  for(ll i=0; i<n; i++){cin>>a[i];}
  for(ll i=0; i<m; i++){cin>>b[i];}
 
  vector<ll>resp(m,0);
  ll i = 0; 
  for(ll k=0; k<m; k++){
    while( i < n && a[i] < b[k]){i++;}
    cout<<i<<" ";
  }  

  cout<<endl;
  return 0;
}
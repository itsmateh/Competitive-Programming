#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
 
 
int main(){
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll>a(n);
  vector<ll>b(m);
 
  for(ll i=0; i<n; i++){
    cin>>a[i];
  }
  for(ll j=0; j<m; j++){
    cin>>b[j];
  }
 
  sort(b.begin(), b.end());
  sort(a.begin(), a.end());
  ll ai,bi,respuesta; 
  ai = 0; 
  bi = 0; 
  respuesta = 0;
 
 
  while(ai<n && bi<m) {
    if(abs(a[ai] - b[bi])<=k){
      respuesta +=1;
      ai+=1;
      bi+=1;
    }
    else if(a[ai]<b[bi]){
      ai+=1;
    }
    else bi+=1;
  }
  cout<<respuesta<<"\n";
  return 0;
 
}
 

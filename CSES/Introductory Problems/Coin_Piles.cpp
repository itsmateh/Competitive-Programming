#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll t,a,b; cin>>t;

  while(t--){
    cin>>a>>b;

    if((a == 0) and (b == 0)){
      cout<<"YES"<<"\n";
      continue;
    }  
    
    if((a==0) or (b==0)){ 
      cout<<"NO"<<"\n";
      continue;
    }

    ll maximo = max(a,b);
    ll minimo = min(a,b);
    if(maximo/2 > minimo){
      cout<<"NO"<<"\n";
      continue;
    }

    if(((a+b) % 3) != 0){
      cout<<"NO"<<endl;
      continue;
    }

    cout<<"YES"<<"\n";

  }

  return 0;

}

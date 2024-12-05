#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll number_spiral(ll x, ll y){
  if(x>y){
    if(x%2==0){return (x*x) - y + 1;}
    else{return (x-1)*(x-1) + y;}
  }
  else{
    if(y%2==0){return (y-1)*(y-1) + x;}
    else{return (y*y) - x + 1;}
  } 
}
int main(){
  int tamaño_test;
  cin>>tamaño_test;
 
  while(tamaño_test--){
    ll x,y;
    cin>>x>>y;
    cout<<number_spiral(x,y)<<endl;
  }
  return 0;
}

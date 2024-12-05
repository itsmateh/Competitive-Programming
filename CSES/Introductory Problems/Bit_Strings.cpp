#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main() {
 
  ll n,x;
  cin>>n;
  
  for(ll i=0; i<n; i++){ 
      x = x*2;
      x = x % 1000000007;
  }
  cout<<x<<"\n";
}
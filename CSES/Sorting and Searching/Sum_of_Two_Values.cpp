#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main() {
 
  ll n,x; 
  cin>>n>>x;
  vector<ll>a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
 
  map<ll,ll>values;
  for(int j=0; j<n; j++){
    if(values.count(x - a[j])){
      cout<< j + 1 <<" "<<values[x-a[j]]<<"\n";
      return 0;
    }
    values[a[j]] = j+1; 
  }
  
  cout<<"IMPOSSIBLE"<<"\n";
 
}
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){

  ll n,dif= 0,resp = 0;
  cin>>n;
  vector<int>vec(n);

  for(int i = 0; i<n; i++){
    cin>>vec[i];
  }

  for(int i = 1; i<n; i++){
    if(vec[i] < vec[i-1]){
      dif= (abs(vec[i] - vec[i-1]));
      resp = resp + dif;
      vec[i] = vec[i] + dif;
    }
    dif = 0;
  }

  cout<<resp<<endl;
}
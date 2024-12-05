#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
int main(){
  ll n; 
  cin>>n;
  vector<ll>vec[n]; 
 
  if(n == 1){
    cout<<n<<endl;
  }else if(n <=3){
    cout<<"NO SOLUTION";
  }else{
    for(int i = 2; i<=n; i=i+2){
      cout<<i<<" ";
    }
    for(int i=1; i<=n; i=i+2){
      cout<<i<<" ";
    }
 
  }
 return 0;
}
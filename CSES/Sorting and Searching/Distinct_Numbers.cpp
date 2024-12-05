#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define forn(i,n) for(int i=0;i<int(n);i++)
 
int main(){
  int n;
  cin>>n;
  vector<int>v(n);

  forn(i,n){cin>>v[i];}
 
  int contador=0;
  sort(v.begin(),v.end()); 
  forn(i,n){
    if(v[i] != v[i+1]){
      contador++;
    }
  }
  cout<<contador;
}
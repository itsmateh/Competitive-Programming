#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n; 
  cin>>n;
  vector<pair<int,int>> horarios;
 
  for(int i = 0; i<n; i++){
    int a,b;
    cin >> a >> b;
 
    horarios.push_back({a, 1});
    horarios.push_back({b, -1});
  }
 
  sort(horarios.begin(),horarios.end());
 
 
  int act=0,mayor = 0;
  for(const pair<int, int> &h : horarios){
    act += h.second;
    mayor = max(mayor,act);
  }  
 
  cout << mayor << endl;
}

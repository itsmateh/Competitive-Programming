#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

vector<ll> padre;
vector<ll> tam;

void crear_set(ll n){
  padre.resize(n);
  tam.resize(n,1);
  for(ll i=0; i<n; i++){padre[i] = i;}
}

int find(ll x){
  if(x == padre[x]){return x;}
  return padre[x] = find(padre[x]);
}

void unite(ll a, ll b){
  a = find(a);
  b = find(b);

  if(a != b){
    if(tam[a] < tam[b]) swap(a,b);
    tam[a] += tam[b];
    padre[b] = a; 
  }
}

string solve(ll v, ll u){
  if(find(v) == find(u)){return "YES";}
  else {return "NO";}
}

int main(){
  ll n,m,v,u;
  string text; 
  cin>>n>>m;

  crear_set(n);

  while(m--){
   cin>>text>>v>>u;
   v--;
   u--;

   if(text == "union"){unite(v,u);}
   else if(text == "get"){cout<<solve(v,u)<<"\n";}
  }

  return 0;
}
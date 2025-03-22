#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
   ll n, m; 
   cin>> n >> m; 
   vector<ll> a(n);
   vector<ll> b(m);
   ll capacidad = n+m;
   vector<ll> c(capacidad);
   for(ll i=0; i<n; i++){cin>>a[i];}
   for(ll i=0; i<m; i++){cin>>b[i];}
   
   ll i = 0; ll j=0; ll k = 0;
   while(i < a.size() || j < b.size()){
      if(j == b.size() || i < a.size() && a[i]<b[j]){
         c[k] = a[i];
         i++; 
         k++;
      }
      else{
         c[k] = b[j];
         j++;
         k++;
      } 
   }
   for(ll v : c){cout<<v<<" ";}

   return 0;
}
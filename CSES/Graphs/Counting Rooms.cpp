#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define raya cerr << "=================" << endl;
#define forn(i,n) for(int i=0;i<int(n);i++)
 
// connected component counting problem
int dist_y[4] = {0,0,1,-1};
int dist_x[4] = {1,-1,0,0};
 
int n;
int m; 
int resp = 0;
 
bool visitado[1000][1000];
char mapa[1000][1000];
 
bool valido(int x, int y){
  return (x >= 0 && x < n && y >= 0 && y < m && mapa[x][y] != '#');
}
 
void dfs(int x, int y){
  visitado[x][y] = true;
  for(int i=0; i<4; i++){
    int act_x = x + dist_x[i];
    int act_y = y + dist_y[i];
    if(valido(act_x, act_y) && !visitado[act_x][act_y]){
      dfs(act_x, act_y);
    }
  }
}
 
int main(){
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>mapa[i][j];  
    }
  }
 
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(mapa[i][j] == '.' && !visitado[i][j]){
        dfs(i,j); 
        resp++;
      }
    }
  }
  
  cout<<resp<<endl;
  return 0;
 
}
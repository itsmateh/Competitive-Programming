#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define raya cerr << "=================" << endl;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define pb push_back
#define mp make_pair
#define endl "\n";
 
int main(){
    FIN;    
 
    int n; cin >> n; 
    vector<int>arr(n); 
    forn(i,n){
        cin >> arr[i];
    }
 
    // monotonic stack, specifically monotonic increasing stack
    
    /* apilamos los indices del vector, y como siempre vamos a guardar el mas a la izquierda arriba, 
        podemos desapilar hasta encontrar un indice en el stack cuyo valor en el vector sea menor
        al elemento actual a chequear de mi vector 
    */
    stack<ll>monotonic_stack; 
    forn(i,n){
        while(!monotonic_stack.empty() && arr[monotonic_stack.top()] >= arr[i]){
            monotonic_stack.pop();
        }
 
        if(monotonic_stack.empty()){cout << "0" << " ";}
        
        else{cout << monotonic_stack.top() + 1 << " ";}
 
        monotonic_stack.push(i);
    }
    
    return 0;
}
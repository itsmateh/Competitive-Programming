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
    vector<tuple<int,int,int>>customers;    
    forn(i,n){
        int a, b; cin >> a >> b;
        customers.pb(make_tuple(a,b,i));
    }
    sort(customers.begin(), customers.end());

    // pq -> par:horario salida - room, donde guardo la pq, criterio de orden
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>rooms_ocupadas;

    int cant = 0; 
    vector<int>ans(n);

    forn(i,n){
        int entrada = get<0>(customers[i]);
        int salida =  get<1>(customers[i]);
        int indice =  get<2>(customers[i]);


        if(rooms_ocupadas.empty() || rooms_ocupadas.top().first >= entrada){
            cant++;
            rooms_ocupadas.push({salida, cant}); // push horario salida - su habitacion
            ans[indice] = cant;
        }else{
            int room_disp = rooms_ocupadas.top().second;
            rooms_ocupadas.pop();
            rooms_ocupadas.push({salida, room_disp});
            ans[indice] = room_disp;
        }
    }
    
    cout << cant << endl;
    forn(i,ans.size()){
        cout << ans[i] << " ";
    }


    return 0;
}

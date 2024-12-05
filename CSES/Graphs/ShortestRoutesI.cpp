#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 1LL<<60;
 
 
struct arista{
  ll start; 
  ll end; 
  ll weight;
};
 
struct nodo{
  ll vertice;
  ll distancia; // distancia minima desde el nodo ORIGEN hasta este nodo
  ll padre_nodo; // el padre del este nodo en su camino mas corto. SIRVE PARA LA RECONSTRUCCION del camino
 
  bool operator < (const nodo &siguiente) const{
    return distancia > siguiente.distancia;
  }
};
 
 
vector<ll> Dijkstra(vector<vector<arista>>&grafo, ll n_cities, ll start){
  /* 
  dist: vector que almacena la distancia mínima desde el nodo fuente (start) a cada nodo. 
  Se inicializa con INF.
  
  Se inicializa la cola de prioridad q con el nodo fuente (start), 
  su distancia inicial (0) y su padre (-1 porque no tiene padre).
  */
  vector<ll>dist(n_cities, INF);
  vector<nodo>respuestas(n_cities);
 
  priority_queue<nodo> pq;
  pq.push({start,0,-1});
 
  /*
  El bucle sigue ejecutándose mientras la cola no esté vacía.
 
  Se extrae el nodo con la menor distancia de la cola de prioridad
 
  Si el nodo actual (cur) ya fue procesado (es decir, si dist[cur] != INF), se omite.
 
  Se actualiza la distancia mínima del nodo actual (cur) con d y se guarda en el vector ans.
  */
 
  while(!pq.empty()){
    // auto [actual, distancia, padre] = pq.top()
    ll actual = pq.top().vertice;
    ll distancia = pq.top().distancia;
    ll padre = pq.top().padre_nodo;
    pq.pop();
 
    if(dist[actual] != INF) continue; // si ya lo visitamos, lo ignoramos
 
    dist[actual] = distancia; // en el array[actual] seteamos la distancia
    respuestas[actual] = {actual, distancia, padre};
    // Exploración de vecinos
    for(auto [from,next,w] : grafo[actual]){
      if(dist[next] == INF){
        pq.push({next, dist[actual]+w, actual});
      }
    }
  }
  return dist;
}
 
int main(){
  FIN;
 
  ll n_cities, m_flights, inicio, fin, recorrido;
 
  cin>>n_cities>>m_flights;
  vector<vector<arista>>grafo(n_cities);
  for(ll i=0; i<m_flights; i++){
    cin>>inicio>>fin>>recorrido;
    inicio--; fin--;
    grafo[inicio].push_back({inicio,fin,recorrido});
  }
 
  vector<ll> ans = Dijkstra(grafo,n_cities,0);
  for(auto &i: ans) cout<<i<<" ";
 
  return 0;
}
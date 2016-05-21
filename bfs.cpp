/*el bfs se usa para recorrer un grafo, este nos dara el camino mas corto de un nodo a otro.*/

#define INF 0x3f3f3f3f //infinito no tan grande para dar overflow ni muy peque;o para no funcionar
int vis[100100] //arreglo de visitados así evitamos ciclos infinitos y almacenar las distancias
vector <int> adj[100100]; 

void BFS(int x){
    memset(vis,INF,sizeof(vis)) 
    queue < pair<int,int> > cola; //la cola es la estructura elegida para almacenar nodos
    cola.push(make_pair(x,0)); 
    vis[x]=0;

    while (!cola.empty()){ //mientras la cola no sea vacia
        pair<int,int> y = cola.front(); //exploramos un nodo que no ha sido visitado.
        cola.pop();
        for (int i=0;i<adj[y.first].size();++i){
            int z = adj[y.first][i];
            
            if (vis[z]!=INF) continue;
            vis[z] = y.second+1;
            cola.push(make_pair(z,vis[z]));
        }
    }
}

//el dfs se utiliza para recorrer un grafo.
vector<int> adj[10001];
bool vis[10001];

void DFS(int x){
  vis[x] = true;
  
  for(unsigned i=0; i<adj[x].size(); ++i){
    int y = adj[x][i];
    if(vis[y])continue;
    DFS(y);
  }
}

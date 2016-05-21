//el topological sort se usa para ordenar los nodos de un grafo (DAG) de manera que los primeros son los no tengan aristas apuntandolos.

vector<int > graph[100001];
vector<int > inOrder;
bool vis[100001];
stack<int > orderStack;
void topoSortNormal(int x){
  vis[x] = true;
  
  for(unsigned i=0; i<graph[x].size(),++i){
    int y = graph[x][i];
    if(vis[y])continue;
    topoSortNormal(y);
  }
  orderStack.push(y);
}

void indegreeSort(){
 queue<pair<int,int > > p;
    for(int i=0;i<n;++i){
        for(unsigned j=0; j<graph[i].size(); ++j)
            indegree[ graph[i][j] ]++;
    }
    
    for( int i=0; i<n; ++i ){
        if(indegree[ i ] == 0){
            p.push({i,1});
        }
    }
    
    while(p.size() > 0) {
        pair<int, int> currentNode = p.front();
        inOrder.push_back(currentNode);
        p.pop();
        for(int j = 0; j < graph[currentNode.first].size(); j++) {
            int newNode = graph[currentNode.first][j];
            indegree[newNode]--;
            if(indegree[newNode] == 0) {
                p.push({newNode, currentNode.second + 1});
            }
        }
    }

}

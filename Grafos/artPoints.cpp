//los puntos de articualcion son los puntos de un grafo que al quitar uno crea un grafo disconexo

int Dtime[1100]={0} ,low[1100]={0}, parent[1100]={0};
bool vis[1100];
vector<int > adj[1100];
queue<int > artPoints;

void artP(int x, int dfsCount){
	bool flag = false;
	vis[x] = true;
	Dtime[x] = low[x] = dfsCount;
	int childCount = 0;
	for(unsigned i=0;i<adj[x].size(); ++i){
		int y = adj[x][i];
		if(!vis[y]){
			parent[y] = x;
			artP(y,dfsCount + 1);
			++childCount;
			if(low[y] >= Dtime[x])
				flag = true;
			low[x] = min(low[y], low[x]);
		}else if(y != parent[x]){
			low[x] = min(low[x], Dtime[y])
		}
	}

	if((parent[x] == -1 && childCount > 1) || (parent[x] != -1 && flag))artPoints.push(x);
}
//ejemplo de como usarlo
int main(){
	memset(vis,false,sizeof(vis));
	parent[0] = -1;
	artP(0,0);
	while(!artPoints.empty()){
		printf("%d", artPoints.front());
		artPoints.pop();
	}
	return 0;
}

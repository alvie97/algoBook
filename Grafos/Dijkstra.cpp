
/*
El algoritmo de Dijkstra es un algoritmo greedy diseñado para encontrar el camino más corto de un nodo a todos los demás en un 
grafo ponderado, es decir donde las aristas tengan un costo. El algoritmo es muy similar al algoritmo de Prim.
 
Dijkstra solo funciona si todos los costos son son positivos, esto es débido a algo llamado "ciclo negativo", en el cual sin 
importar cuantas veces pasemos por un nodo siempre conseguiremos (es decir infinitamente) un costo menor para llegar a ese nodo, 
en ese momento el algoritmo no funciona. 
*/

int dist[100010];

int Dijkstra (int origen,int destino){
    for (int i=0;i<n;++i){
        dist[i]=0x3f3f3f3f; //etiquetas en infinito
    }
    priority_queue <node> pq;
    pq.push(node(origen,0));
    dist[origen]=0;
    
    while (!pq.empty()){
        node v = pq.top(); pq.pop();

        if (v.x == destino) return v.c;
        
        for (int i=0;i<adj[v.x].size();++i){
            int y = adj[v.x][i].x;
            int c = adj[v.x][i].c + v.c;
            
            if (c < dist[y]){
                dist[y]=c;
                pq.push(node(y,c));
            }
        }
    }

    return -1; // no se encontro camino
}

//O( (N+E)*Log(N))

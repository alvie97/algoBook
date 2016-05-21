/*
Bellman-Ford, este es un algoritmo de DP el cualse utiliza para encontrar el camino más corto de un nodo a todos los demás.
Lo que hace este algoritmo es iterar cada nodo una cantidad fija de veces (n-1), e ir revisando cada arista del grafo haciendo una "relajacion" lo cual es simplemente verificar que costo final
es el apropiado para un nodo.
*/

void BellmanFord (int origen){
    memset(dist,0x3f3f3f3f,sizeof(dist));
    dist[origen]=0;

    for (int i=1;i<=n-1;++i){
        for (int j=0;j<aristas.size();++j){
            int x = aristas[j].x;
            int y = aristas[j].y;
            int c = aristas[j].c;

            if (dist[x]!=0x3f3f3f3f && dist[x] + c < dist[y]){
                dist[y] = dist[x]+c; 
            } 
        }
    }

    //O(N*E)

    //por que usar esto si tenemos Dijkstra? bueno bellman ford permite finalizar aunque hayan ciclos negativos
    // y no solo eso si no que puede decirnos si el grafo tiene o no un ciclo negativo

    for (int j=0;j<aristas.size();++j){
        int x = aristas[j].x;
        int y = aristas[j].y;
        int c = aristas[j].c;
        if (dist[x]!=0x3f3f3f3f && dist[x]+c <dist[y]){ //el algoritmo esta dise;ado para terminar luego de n-1 iteraciones
            printf("HAY UN CICLO NEGATIVO\n"); //si se sigue podiendo actualizar entonces definitivamente hay un ciclo negativo
        }
    }
}

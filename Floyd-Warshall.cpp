/*
El algoritmo de Floyd-Warshall es un algoritmo de DP que tiene el objetivo de encontrar el camino mas corto desde cualquier nodo a
cualquier otro en O(N^3) , el algoritmo es sumamente sencillo.
*/

int dist[501][501];

void FloydWarshall(){
    memset(dist,0x3f3f3f3f,sizeof(dist));
    for (int i=0;i<m;++i){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        dist[x][y]=c; dist[y][x]=c;
    }

    for (int k=0;k<n;++k)
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]); //que es mejor, ir directo con lo que tengo o pasar por un k intermedio?
            }

}

void TransitiveClossure(){
    //AdjMat es una matriz de adyacencia de 1's para conexion y 0's para no conexion

    for (int k=0;k<n;++k)
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j){
                AdjMat[i][j] |= (AdjMat[i][k] && AdjMat[j][k]);
            }
}

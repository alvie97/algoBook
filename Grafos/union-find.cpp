int P[100001];

void init(){
    for (int i=0;i<100001;++i)
        P[i]=i; //todos los nodos son padres de si mismos lo que representa un grafo disconexo
}

int Find(int x){
    if (P[x]==x) return x;

    return P[x] = Find(x);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    P[x]=y;
}

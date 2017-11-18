// first implementation
int P[100001];

void init(){
    for (int i=0;i<100001;++i)
        P[i]=i;
}

int find(int x){
    if (P[x]==x) return x;

    return P[x] = Find(P[x]);
}

void merge(int x, int y){
    x = Find(x);
    y = Find(y);
    P[x]=y;
}

//second implementation - rank - path compression

class ufd{
    private:
        vi p, rank;
    public:
        ufd(int n){
            rank.assign(n, 0);
            p.assign(n, 0);
            for(int i = 0; i < n; i++)
                    p[i] = i;
        }
        int find(int i){ return (p[i] == i)? i: (p[i] = find(p[i])); }
        bool same_set(int x, int y) { return find(x) == find(y); }
        void merge(int x, int y){
            if (!same_set(x, y)){
                int u = find(x); int v = find(y);
                if (rank[u] > rank[v])
                    p[v] = u;
                else {
                    p[u] = v;
                    if (rank[u] == rank[v])
                        ++rank[v];
                }
            }
        }
};

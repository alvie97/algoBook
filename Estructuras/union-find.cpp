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
    public:
        vi p, rank, set_size;
	int disj_sets;
        ufd(int n){
            rank.assign(n, 0);
            p.assign(n, 0);
	    set_size.assign(n, 1);
            for(int i = 0; i < n; i++)
                    p[i] = i;
	    disj_sets = n;
        }
        int find(int i){ return (p[i] == i)? i: (p[i] = find(p[i])); }
        bool same_set(int x, int y) { return find(x) == find(y); }
        void merge(int x, int y){
            if (!same_set(x, y)){
                int u = find(x); int v = find(y);
                if (rank[u] > rank[v]) {
                    p[v] = u;
		    set_size[u] += set_size[v];
		} else {
                    p[u] = v;
		    set_size[v] += set_size[u];
                    if (rank[u] == rank[v])
                        ++rank[v];
                }
		--disj_sets;
            }
        }
	int num_disj_sets() { return disj_sets; }
	int set_size_of(int i) { return set_size[find(i)]; }
};

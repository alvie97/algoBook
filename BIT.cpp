#define N 10
int tree[(1 << N) + 1];
int arr[N];
int n = 1 << N;
int sum (int x) {
	int ret = 0;
	while(x) {
		ret += tree[x];
		x -= (x & -x);
	}
	return ret;
}

void set( int x, int v) {
	while(x <= n) {
		tree[x] += v;
		x += (x & -x);
	}
}	

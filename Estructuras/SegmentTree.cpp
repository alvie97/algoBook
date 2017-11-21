class segment_tree{
  private: 
    vector<int> st, A, lazy;
  public:
    int n;
    int left(int p){ return p << 2;}
    int right(int p){ return (p << 2) + 1;}
    segment_tree(const vector<int> &_A) {
      A = _A; n = (int)A.size();
      st.assign(4 * n, 0);
      lazy.assign(4 * n, 0);
      build(1, 0, n - 1);
    }
    void build(int p, int l, int r){
      if (l == r)
        st[p] = l;
      else {
        build(left(p), l, (l + r) / 2);
        build(right(p), (l + r) / 2 + 1, r);
        int p1 = st[left(p)], p2 = st[right(p)];
        st[p] = (A[p1] <= A[p2])? p1 : p2;
      }
    }

    void update(int p, int start, int end, int l, int r, int val){
      if (lazy[p] != 0) {
        // this node needs to be updated
        st[p] += lazy[p];
        if (start != end) {
          lazy[left(p)] += lazy[p]; // mark child as lazy
          lazy[right(p)] += lazy[p]; // mark child as lazy
        }
        lazy[p] = 0; // reset it
      }

      if (start > end || start > r || end < l)
        return; // current node is not within range
      
      if (start >= l && end <= r) {
        // segment is fully within range
        st[p] += val;

        if (start != end) {
          // not leaf node
          lazy[left(p)] += val;
          lazy[right(p)] += val;
        }
        return;
      }

      int mid = (start + end) / 2;
      update(left(p), start, mid, l, r, val); // update left child
      update(right(p), mid + 1, end, l , r, val); // update right child
      int p1 = st[left(p)], p2 = st[right(p)];
        st[p] = (A[p1] <= A[p2])? p1 : p2;
    }

    int query(int p, int start, int end, int l, int r) {
      if (start > end || start > r || end < l)
        return -1;
      if (lazy[p] != 0) {
        // this node needs to be updated
        st[p] += lazy[p]; // update it
        if(start != end) {
          lazy[left(p)] += lazy[p]; // mark child as lazy
          lazy[right(p)] += lazy[p]; // mark child as lazy
        }
        lazy[p] = 0; // reset it
      }

      if (start >= l && end <= r)
        return st[p]; // current segment is totally within range [l, r]

        int mid = (start + end) / 2;
        int p1 = query(left(p), start, mid, l, r); // query left child
        int p2 = query(right(p), mid + 1, end, l,  r);

        if (p1 == -1) return p2;
        if (p2 == -1) return p1;

        return (A[p1] <= A[p2])? p1 : p2;
    }
};



















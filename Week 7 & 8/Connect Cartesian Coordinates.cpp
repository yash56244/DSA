struct DSU {
    vector<int> e;
    void init(int N) {
        e = vector<int>(N, -1);
    }
    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
    bool sameSet(int a, int b) {
        return get(a) == get(b);
    }
    int size(int x) {
        return -e[get(x)];
    }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};
int cost(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
int solve(vector<vector<int>>& points) {
    int n = points.size();
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({cost(points[i][0], points[i][1], points[j][0], points[j][1]), {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    DSU d;
    d.init(n);
    for (int i = 0; i < edges.size(); i++) {
        if (d.unite(edges[i].second.first, edges[i].second.second)) {
            cost += edges[i].first;
        }
    }
    return cost;
}

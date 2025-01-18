#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int>> iii;
priority_queue<iii, vector<iii>, greater<iii>> graph;
vector<int> parent;

int find(int i) {
    if (i == parent[i])
        return i;
    return parent[i] = find(parent[i]);
}

void union_set(int u, int v) {
    parent[find(u)] = find(v);
}

long long kruskal(int n) {
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    long long mst_cost = 0;
    int edges = 0;
    while (!graph.empty() && edges < n - 1) {
        iii edge = graph.top();
        graph.pop();
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;
        
        if (find(u) != find(v)) {
            union_set(u, v);
            mst_cost += w;
            edges++;
        }
    }
    return mst_cost;
}

int main() {
    int n;
    bool first = true;
    
    while (cin >> n) {
        if (!first) cout << endl;
        first = false;
        
        while (!graph.empty()) graph.pop();
        
        long long original_cost = 0;
        for (int i = 0; i < n-1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            original_cost += w;
        }
        
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.push({w, {u, v}});
        }
        
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.push({w, {u, v}});
        }
        
        cout << original_cost << endl;
        cout << kruskal(n) << endl;
    }
    return 0;
}
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
using namespace std;

map<int,int> bfs(map<int,vector<int>> &graph, int source) {
    queue<int> q;
    map<int,int> dist;
    
    q.push(source);
    dist[source] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : graph[u]) {
            if (!dist.count(v)) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist;
}

int main() {
    int nc, caseNum = 1;
    
    while(cin >> nc && nc) {
        map<int,vector<int>> graph;
        set<int> nodes;
        
        for(int i = 0; i < nc; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            nodes.insert(u);
            nodes.insert(v);
        }
        
        int start, ttl;
        while(cin >> start >> ttl && (start || ttl)) {
            map<int,int> distances = bfs(graph, start);
            
            int unreachable = 0;
            for(int node : nodes) {
                if (!distances.count(node) || distances[node] > ttl) {
                    unreachable++;
                }
            }
            
            cout << "Case " << caseNum++ << ": " 
                 << unreachable << " nodes not reachable from node " 
                 << start << " with TTL = " << ttl << "." << endl;
        }
    }
    return 0;
}

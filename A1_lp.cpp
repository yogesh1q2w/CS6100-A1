#include <bits/stdc++.h>
using namespace std;

int t;
vector<int> pred;
vector<bool> vis;
int bfs(unordered_map<int, vector<int>> &adj,int s) {
    queue<int> q;
    q.push(s);
    int noc = 1;
    vis[s] = true;
    pred[s] = -1;
    int f;
    while(!q.empty()) {
        int noc2 = 0;
        for(int i = 0; i < noc; i++) {
            f = q.front();
            q.pop();
            for(auto &j:adj[f]) {
                if(!vis[j]) {
                    pred[j] = f;
                    vis[j] = true;
                    q.push(j);
                    noc2++;
                }
            }
        }
        noc = noc2;
    }
    return f;
}

int main() {
    int n;
    cin >> n;
    pred.resize(n);
    vis.resize(n);
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(vis.begin(),vis.end(),false);
    int u = bfs(adj,0);
    fill(vis.begin(),vis.end(),false);
    int v = bfs(adj,u);
    while(v != -1) {
        cout << v << " ";
        v = pred[v];
    }
    cout << endl;
}
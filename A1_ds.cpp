#include <bits/stdc++.h>
using namespace std;
set<int> sol;
vector<bool> cov;
vector<int> deg;
int ds(unordered_map<int, vector<int>> &adj) {
    if(adj.size() == 0)
    return 0;
    int x = 0;
    for(auto &i:adj) {
        if(deg[i.first] == 1 && !cov[i.first]) {
            cov[i.first] = true;
            sol.insert(adj[i.first][0]);
            cov[adj[i.first][0]] = true;
            x++;
            for(auto &j:adj[adj[i.first][0]]) {
                cov[j] = true;
                deg[j]--;
                if(deg[j] == 0 && j != i.first)
                    adj.erase(j);
            }
            adj.erase(adj[i.first][0]);
            adj.erase(i.first);
        }
        else if(deg[i.first] == 1 && cov[i.first])
            adj.erase(i.first);
        if(adj.size() == 0)
        break;
    }
    return x + ds(adj);
}

int main() {
    int n;
    cin >> n;
    cov.resize(n);
    fill(cov.begin(),cov.end(),false);
    deg.resize(n);
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    cout <<"Dominating set: " << ds(adj) << endl;
    for(auto &i:sol)
        cout << i << " ";
    cout << endl;
    return 0;
}
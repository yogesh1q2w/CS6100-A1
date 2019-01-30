#include <bits/stdc++.h>
using namespace std;

vector<int> sol;
set<int>vcover;
int vc(unordered_map<int, vector<int>> &adj,int s) {
    if(adj[s].size() == 0 && s != 0) {
        sol[s] = 0;
        return 0;
    }
    int x = 1, y = adj[s].size();
    for(auto &i:adj[s]) {
        for(auto &j:adj[i]) {
            if(sol[j] == -1) 
                y = y + vc(adj,j);
            else
                y = y + sol[j];
        }
    }
    for(auto &i:adj[s]) {
        if(sol[i] == -1)
            x = x + vc(adj,i);
        else
            x = x + sol[i];
    }
    if(x <= y)
        vcover.insert(s);
    else
        for(auto &i:adj[s])
            vcover.insert(i);
    sol[s] = min(x,y);
    return sol[s];
}

int main() {
    int n;
    cin >> n;
    unordered_map<int, vector<int>> adj;
    sol.resize(n);
    fill(sol.begin(),sol.end(),-1);
    for(int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    cout <<"Vertex cover: ";
    cout << vc(adj,0) << endl;
    vector<bool> isind(n,true);
    for(auto &i:vcover) {
        isind[i] = false;
        cout << i << " ";
    }
    cout << endl;
    cout <<"Independent set: ";
    cout << (n - vcover.size()) << endl;
    for(int i = 0;i < n; i++)
        if(isind[i])
        cout << i << " ";
    cout << endl;
    return 0;
}


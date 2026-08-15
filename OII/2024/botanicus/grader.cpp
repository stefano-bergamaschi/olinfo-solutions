#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adj, vector<int>& da, int level, int node){
    int maxx = level;
    for(int i: adj[node]){
        maxx = max(maxx, dfs(adj, da, level + 1, i));
    }
    
    da[level]++;
    da[maxx + 1]--;
    
    return maxx;
}

int pota(int N, vector<int> P){
    vector<vector<int>> adj(N);
    vector<int> da(N + 1, 0);
    
    for(int i = 1; i < N; i++) adj[P[i]].push_back(i);

    dfs(adj, da, 0, 0);

    int maxx = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) maxx = max(maxx, sum += da[i]);
    
    return N - maxx;
}


int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int soluzione = pota(N, P);
    cout << soluzione << "\n";
}

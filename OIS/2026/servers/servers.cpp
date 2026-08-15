#include <bits/stdc++.h>
using namespace std;


struct node{
    int latency;
    int hosts;
    bool under;
};

node dfs(vector<vector<int>>& adj, int n, int ans, int parent){
    int maxlatency = 0;
    int hosts = 0;
    bool under = false;
    for(int i: adj[n]){
        if(i == parent) continue;
        node info = dfs(adj, i, ans, n);
        maxlatency = max(maxlatency, info.latency);
        hosts += info.hosts;
        if(info.under) under = true;
    }

    if(under) return {0, hosts, true};
    if(maxlatency >= ans) return {0, hosts + 1, true};
    return {maxlatency + 1, hosts, false};
}


int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;

    vector<vector<int>> adj(N);
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    


    int l = 0, r = INT_MAX;
    int ans = 0;
    while(l <= r){
        int m = (l + r) / 2;
        if(dfs(adj, 0, m, 0).hosts <= K){
            ans = m;
            r = m - 1;
        } else{
            l = m + 1;
        }
    }

    cout << ans << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<long long> distance_0(N, -1);
    queue<long long> q;
    q.push(0);
    distance_0[0] = 0;

    while(!q.empty()){
        long long n = q.front();
        q.pop();
        for(long long i: adj[n]) if(distance_0[i] == -1) { 
            q.push(i); 
            distance_0[i] = distance_0[n] + 1; 
        }
    }
    
    vector<long long> distance_N(N, -1);
    q.push(N - 1);
    distance_N[N - 1] = 0;

    while(!q.empty()){
        long long n = q.front();
        q.pop();
        for(long long i: adj[n]) if(distance_N[i] == -1) { 
            q.push(i); 
            distance_N[i] = distance_N[n] + 1; 
        }
    }

    vector<long long> sum_0(N);
    vector<long long> sum_N(N);

    for(long long i: distance_0) sum_0[i]++;
    for(long long i: distance_N) sum_N[i]++;

    vector<long long> ps_0(N, 0);
    vector<long long> ps_N(N, 0);

    ps_0[0] = 1;
    ps_N[0] = 1;
    for(long long i = 1; i < N; i++) ps_0[i] = ps_0[i - 1] + sum_0[i];
    for(long long i = 1; i < N; i++) ps_N[i] = ps_N[i - 1] + sum_N[i];

    
    long long ris = N * (N - 1) / 2 - M;
    long long no = 0;
    long long dist = distance_0[N - 1];
    for(long long i = 0; i < N; i++){
        if(dist - distance_0[i] - 2 >= 0){
            no += ps_N[dist - distance_0[i] - 2];
        }
        if(dist - distance_N[i] - 2 >= 0){
            no += ps_0[dist - distance_N[i] - 2];
        }
    }

    cout << ris - no / 2 << endl;

    return 0;
}

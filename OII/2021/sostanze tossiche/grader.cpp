#include <bits/stdc++.h>
using namespace std;

long long smaltisci(int N, int M, vector<int> A, vector<vector<int>> B){
    vector<vector<int>> adj(N); // sostnza -> processi coinvolti
    vector<long long> d(N, LLONG_MAX); // costo per smaltire sostanza
    vector<int> r(M); // sostance da scoprire restanti per processo
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for(int i = 0; i < M; i++){ // scorro i processi
        r[i] = B[i].size();
        if(!B[i].size()){
            d[A[i]] = 1;
            pq.push({1, A[i]});
        } else for(int j = 0; j < B[i].size(); j++){ // scorro i prodotti
            adj[B[i][j]].push_back(i); // associo il processo al prodotto
        } 
    }
    
    while(!pq.empty()){
        if(pq.top().first > d[pq.top().second]){ pq.pop(); continue; }
         
        for(int i: adj[pq.top().second]){ // scorro processi coinvolti
            r[i]--;
            if(!r[i]){
                long long c = 1;
                for(int j = 0; j < B[i].size(); j++) c += d[B[i][j]];
                if(c < d[A[i]]){
                    d[A[i]] = c;
                    pq.push({c, A[i]});
                }
            }
        }
        
        pq.pop();
    }

    return d[0];
}

int main() {
    int N, M;

    cin >> N >> M;

    vector<int> A(M), K(M);
    vector<vector<int>> B(M);

    for (int i = 0; i < M; i++) {
        cin >> A[i] >> K[i];

        B[i].resize(K[i]);
        for (int j = 0; j < K[i]; j++) {
            cin >> B[i][j];
        }
    }

    cout << smaltisci(N, M, A, B) << "\n";
}

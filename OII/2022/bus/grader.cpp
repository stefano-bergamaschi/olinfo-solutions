#include <bits/stdc++.h>

using namespace std;

int pianifica(int N, int L, vector<vector<int>> F){
    vector<vector<pair<int, int>>> adj(N);
    vector<int> last(L);

    for(int i = 0; i < L; i++){
        for(int j = 0; j < F[i].size(); j++){
            adj[F[i][j]].push_back({j, i});
        }
    }

    for(int i = 0; i < L; i++) last[i] = F[i].size();

    queue<int> q;
    vector<int> distance(N, -1);
    q.push(0);
    distance[0] = 0;

    while(!q.empty() and distance[N - 1] == -1){
        int n = q.front();
        q.pop();
        for(pair<int, int> i: adj[n]){
            if(i.first >= last[i.second]) continue;
            for(int j = i.first; j < last[i.second]; j++){
                if(distance[F[i.second][j]] == -1) { q.push(F[i.second][j]); distance[F[i.second][j]] = distance[n] + 1; }
            }
            last[i.second] = i.first;
        }
    }

    if(distance.back() == -1) return -1;
    return distance.back() - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    // se preferisci leggere e scrivere da file ti basta decommentare le seguenti due righe:
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, L;
    cin >> N >> L;

    vector<vector<int>> F(L);
    for (int i = 0; i < L; i++) {
        int K;
        cin >> K;
        F[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> F[i][j];
        }
    }

    cout << pianifica(N, L, F) << endl;

    return 0;
}

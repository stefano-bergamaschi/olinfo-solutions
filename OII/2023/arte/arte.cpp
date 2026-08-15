#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, vector<int>& b, int l, int r){
    for (int i = 0; i <= r - l; i++) {
        if (a[l + i] != b[r - i]) {
            return false;
        }
    }

    return true;
}

bool ordina(int N, vector<int> V, vector<int> &L){
    vector<int> S(V.begin(), V.end());
    sort(S.begin(), S.end());

    int l = 0;
    int r = 1;
    for(; r < N; r++){
        if(V[r] > V[r - 1]){
            if(!check(V, S, l, r - 1)){
                L.resize(0);
                return false;
            }
            L.push_back(r - l);
            l = r;
        } 

    }

    if(!check(V, S, l, N - 1)) {
        L.resize(0);
        return false;
    }

    L.push_back(N - l);
    return true;
}

int main() {
    int N;
    cin >> N;
  
    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    vector<int> L;
    bool risposta = ordina(N, V, L);

    if (risposta == true) {
        cout << "YES" << endl;

        int M = L.size();
        cout << M << endl;

        for (int i = 0; i < M; ++i) {
            cout << L[i] << " ";
        }
        cout << endl;

    } else {
        cout << "NO" << endl;
    }
}

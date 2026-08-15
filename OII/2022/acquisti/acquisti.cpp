#include <bits/stdc++.h>
using namespace std;

vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P) {
    vector<long long> R(M, 0);
    
    vector<long long> e(T);
    vector<long long> p(T);
    e[0] = S[0];
    p[0] = 0;
    for(long long i = 1; i < T; i++){
        e[i] = e[i - 1] + S[i];
        p[i] = p[i - 1] + S[i] * i;
    }

    for(long long i = 0; i < M; i++){
        long long indx = lower_bound(p.begin(), p.end(), P[i]) - p.begin();
        
        if(indx == T){
            R[i] = e.back();
            continue;
        }

        if(indx == 0){
            R[i] = e.front();
            continue;
        }

        R[i] = e[indx - 1];
        R[i] += (P[i] - p[indx - 1]) / indx;
    }

    return R;
}

int main(){
    int T, M;
    cin >> T >> M;

    vector<long long> S(T);
    for (int i = 0; i < T; i++) cin >> S[i];
    
    vector<long long> P(M);
    for (int i = 0; i < M; i++) cin >> P[i];

    for(long long r : calcola(T, M, S, P)) cout << r << endl;
}

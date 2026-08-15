#include <bits/stdc++.h>
using namespace std;

long long carica(int N, int K, vector<int> A) {
    long long ans = 0;
    for(int i = 0; i < N; i++){
        if(A[i] < K) ans += A[i];
        else ans += K;
    }
    if(A.back() > K) ans += A.back();
    return ans;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> V(N);
    for (int &i: V) cin >> i;

    cout << carica(N, K, V) << endl;
    return 0;
}
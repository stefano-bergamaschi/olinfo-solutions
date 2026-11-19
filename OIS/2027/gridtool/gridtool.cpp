#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        long long N, M, K;
        cin >> N >> M >> K;

        if(K == N * M - 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
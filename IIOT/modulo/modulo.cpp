#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int test = 0; test < T; test++){
        long long N, a;
        cin >> N >> a;

        long long ans = 0;
        if(a <= 1) ans = N * N;
        else for(long long i = 1; i <= N; i = N / (N / i) + 1) ans += (N / i) * (N / (N / i) - i + 1);

        cout << ans << endl;
    }
}
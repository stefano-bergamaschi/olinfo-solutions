#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> C(N + 2);
    for(int i = 0; i < N; i++) cin >> C[i + 1];
    
    C[0] = 0;
    C[N + 1] = INT_MAX;
    
    long long sum = 0;
    long long best = 0;
    
    for(int i = 1; i < N + 1; i++) {
        if(C[i - 1] > C[i]) sum += C[i - 1] - C[i];
        if(C[i - 1] > C[i] and C[i] < C[i + 1]) best = max(best, C[i - 1] - C[i] - max(0LL, C[i - 1] - C[i + 1]));
        if(C[i - 1] < C[i] and C[i] > C[i + 1]) best = max(best, C[i] - C[i + 1] - max(0LL, C[i - 1] - C[i + 1]));
    }
    
    cout << sum - best << endl;
    return 0;
}
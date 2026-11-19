#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int N = 0;
    cin >> N;

    vector<int> jump(N);
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;

        jump[i] = i + n;
    }
    
    vector<int> wet(N);
    for(int i = 0; i < N; i++){
        cin >> wet[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> hi(N, INT_MAX);
    hi[0] = 0;

    for(int i = 0; i < N - 1; i++){        
        while(!pq.empty() and pq.top().second < i) pq.pop();
        
        int value = pq.empty()? hi[i]: min(hi[i], pq.top().first);
        if(value == INT_MAX) continue;
        
        if(wet[i] != -1) hi[wet[i]] = min(hi[wet[i]], value); 
        else pq.push({value + 1, jump[i]});
    }

    while(!pq.empty() and pq.top().second < N - 1) pq.pop();
    
    int ans = pq.empty()? hi.back(): min(hi.back(), pq.top().first);
    if(ans == INT_MAX) ans = -1;

    cout << ans << endl;
}
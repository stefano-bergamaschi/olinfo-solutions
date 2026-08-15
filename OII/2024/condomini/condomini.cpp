#include <bits/stdc++.h>
using namespace std;

int sbugiarda(int N, vector<int> H){
    stack<pair<int, int>> sx;
    stack<pair<int, int>> dx;
    vector<int> s(N);

    for(int i = 0; i < N; i++){
        int maxx = 1;
        while(!sx.empty() and sx.top().first < H[i]){
            maxx = max(maxx, sx.top().second + 1);
            sx.pop();
        }
        sx.push({H[i], maxx});
        s[i] = maxx;
    }

    int ans = 0;
    for(int i = N - 1; i >= 0; i--){
        int maxx = 1;
        while(!dx.empty() and dx.top().first < H[i]){
            maxx = max(maxx, dx.top().second + 1);
            dx.pop();
        }
        if(!dx.empty() and dx.top().first == H[i]){
            ans = max(ans, dx.top().second + s[i]);
            maxx = max(maxx, dx.top().second);
        } 
        dx.push({H[i], maxx});
        ans = max(ans, s[i] + maxx - 1);
    }

    return ans;
}   

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int soluzione = sbugiarda(N, H);
    cout << soluzione << "\n";
}

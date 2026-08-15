#include <bits/stdc++.h>
using namespace std;

vector<int> verifica(int N, vector<int> T){
    vector<int> ans;
    int s = 0, d = N - 1;

    for(int i = N - 1; s < d; i--){
        if(T[s] >= i) ans.push_back(s++);
        else if(T[d] >= i) ans.push_back(d--);
        else return {};
    }

    ans.push_back(s);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    int N;
    cin >> N;

    vector<int> T(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];

    vector<int> P = verifica(N, T);
    
    cout << P.size() << '\n';
    for (int i = 0; i < P.size(); i++)
        cout << P[i] << ' ';
    cout << '\n';
}

#include <bits/stdc++.h>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H){
    vector<int> a(X);
    for(int i : H) a[i]++;
    
    vector<int> m(X + 1);
    vector<int> f(X + 1);
    m[X] = 0;
    f[X] = 0;

    for(int t = X - 1; t >= 0; t--){
        m[t] = max(0, min(K, m[t + 1] + 1) - a[t]);
        if(a[t]) f[t] = f[t + 1] + min(m[t + 1] + 1, min(K, a[t]));
        else f[t] = f[t + 1];
    }

    f.resize(X);
    return f;
}

int main() {
    // se preferisci leggere e scrivere da file ti basta decommentare le seguenti due righe:
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, K, X;
    cin >> N >> K >> X;

    vector<int> H(N);
    for (int& h : H) {
        cin >> h;
    }

    vector<int> res = cucina(N, K, X, move(H));
    for (int r : res) {
        cout << r << ' ';
    }
    cout << endl;

    return 0;
}

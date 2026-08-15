#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];

    int maxx = -1;
    int l = 0;
    for(int i = 0; i < N; i++) if(P[i] > maxx){
        maxx = P[i];
        l++;
    }
    
    maxx = -1;
    int r = 0;
    for(int i = N - 1; i >= 0; i--) if(P[i] > maxx){
        maxx = P[i];
        r++;
    }
    

   

    cout << N - (l + r - 1) << endl;
    return 0;
}

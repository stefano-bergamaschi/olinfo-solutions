#include <bits/stdc++.h>
using namespace std;

void brucia(int N, vector<int>& M, vector<int>& B, vector<long long>& T){
	T.assign(N, LLONG_MAX);

    vector<pair<long long, long long>> s(N);
    for(int i = 0; i < N; i++) s[i] = {M[i], i};
    sort(s.begin(), s.end());

    vector<vector<pair<long long, long long>>> adj(N);

    stack<long long> st;
    for(auto i = s.begin(); i != s.end(); i = next(i)){
        while(!st.empty() and B[st.top()] < M[i -> second]) st.pop();
        if(!st.empty()) adj[st.top()].push_back({i -> second, abs(M[st.top()] - M[i -> second])});
        if(M[i -> second] < B[i -> second]){
            while(!st.empty() and B[st.top()] < B[i -> second]) st.pop();
            st.push(i -> second);
        }
    }

    st = stack<long long>();
    for(auto i = s.rbegin(); i != s.rend(); i = next(i)){
        while(!st.empty() and B[st.top()] > M[i ->second]) st.pop();
        if(!st.empty()) adj[st.top()].push_back({i -> second, abs(M[st.top()] - M[i -> second])});
        if(M[i -> second] > B[i -> second]){
            while(!st.empty() and B[st.top()] > B[i -> second]) st.pop();
            st.push(i -> second);
        }
    }

    for(int i = 0; i < N - 1; i++) if(M[s[i].second] == M[s[i + 1].second]){
        adj[s[i].second].push_back({s[i + 1].second, 0});
        adj[s[i + 1].second].push_back({s[i].second, 0});
    }

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    vector<bool> v(N, false);
    pq.push({0, 0});

    while(!pq.empty()){
        pair<long long, long long> n = pq.top();
        pq.pop();

        if(v[n.second]) continue;

        v[n.second] = true;
        T[n.second] = n.first;

        for(pair<long long, long long> i: adj[n.second]){
            if(v[i.first] or T[i.first] <= n.first + i.second) continue;
            pq.push({n.first + i.second, i.first});
        }
    }

    for(long long& i: T) if(i == LLONG_MAX) i = -1;

    return;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

	int n;
	cin >> n;
	
	vector<int> M(n), B(n);
	vector<long long> T(n, 0);
	
	for(int i = 0; i < n; i++) cin >> M[i] >> B[i];
	
	brucia(n, M, B, T);
	for(int i = 0; i < n; i++) cout << T[i] << " ";
	cout << endl;
}

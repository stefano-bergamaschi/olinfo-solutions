#include <bits/stdc++.h>
using namespace std;

bool check(int N, int M, vector<int>& T, vector<int>& P, long long ans, vector<long long>& cap){
	vector<long long> count(M, 0);
	for(int i = 0; i < M and ans > 0; i++){
		if(ans >= P[i]){
			count[i] = P[i];
			ans -= P[i];
		} else{
			count[i] = ans;
			ans = 0;
		}
	}

	long long weight = 0;
	for(int i = M - 1; i >= 0; i--){
		weight += (1LL << i) * count[i];
		if(weight > cap[i]) return false;
	}
	
	return true;
}


long long riciclo(int N, int M, vector<int> T, vector<int> P){
	vector<long long> cap(M);
	for(int i = 0; i < M; i++) for(int j: T) cap[i] += ((long long)j >> i) << i;
	
	
	
	long long l = 0;
	long long r = 0;
	for(int i: P) r += i;

	long long ans = 0;
	
	while(l <= r){
		long long m = (l + r) / 2;
		if(check(N, M, T, P, m, cap)){
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	
	return ans;
}

int main() {
	int N, M;

	cin >> N >> M;

  	vector<int> T(N), P(M);

	for (int i = 0; i < N; i++) {
    	cin >> T[i];
  	}
  	for (int i = 0; i < M; i++) {
    	cin >> P[i];
  	}

  	cout << riciclo(N, M, T, P) << endl;

  	return 0;
}

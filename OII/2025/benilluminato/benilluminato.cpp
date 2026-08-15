#include <bits/stdc++.h>
using namespace std;

int illumina(int N, int M, vector<int> H, vector<int> A, vector<int> B, vector<int> L) {
	int ris = 0;
	
	vector<vector<pair<int, int>>> adj(N);
	vector<bool> lampione_preso(N, false);
	vector<bool> strada_usata(M, false);	
	queue<int> q;

	for(int i = 0; i < M; i++){
		adj[A[i]].push_back({B[i], i});
		adj[B[i]].push_back({A[i], i});
		
		bool a = H[A[i]] <= L[i];
		bool b = H[B[i]] <= L[i];

		if(a and b and H[A[i]] + H[B[i]] <= L[i]){
			strada_usata[i] = true;
			lampione_preso[A[i]] = true;
			q.push(A[i]);
			lampione_preso[B[i]] = true;
			q.push(B[i]);
		} else if(a and !b){
			strada_usata[i] = true;
			lampione_preso[A[i]] = true;
			q.push(A[i]);
		} else if(!a and b){
			strada_usata[i] = true;
			lampione_preso[B[i]] = true;
			q.push(B[i]);
		} else if(!a and !b){
			strada_usata[i] = true;
		}
	
	}

	while(!q.empty()){
		int lampione = q.front();
		q.pop();

		for(pair<int, int> i: adj[lampione]){
			if(strada_usata[i.second]) continue;
			if(!lampione_preso[i.first]){
				lampione_preso[i.first] = true;	
				q.push(i.first);
			} 
			strada_usata[i.second] = true;
		}
	}

	for(bool i: lampione_preso) if(i) ris++;

	for(int i = 0; i < N; i++){
		if(lampione_preso[i]) continue;

		int strade_rimaste = 0;
		int lampioni_rimasti = 0;
		
		q.push(i);
		while(!q.empty()){
			int lampione = q.front();
			q.pop();
			
			if(lampione_preso[lampione]) continue;
			lampione_preso[lampione] = true;
			lampioni_rimasti++;

			for(pair<int, int> j: adj[lampione]){
				if(strada_usata[j.second]) continue;
				strada_usata[j.second] = true;
				strade_rimaste++;
				if(!lampione_preso[j.first]) q.push(j.first);
			}
		}

		ris += min(strade_rimaste, lampioni_rimasti);
	}

	return ris;
}


#ifndef EVAL

int main() {
	int N; cin >> N;
	int M; cin >> M;

	vector<int> H(N);
	for (int i = 0; i < N; ++i)
		cin >> H[i];

	vector<int> A(M), B(M), L(M);
	for (int i = 0; i < M; ++i)
		cin >> A[i] >> B[i] >> L[i];

	cout << illumina(N, M, H, A, B, L) << "\n";
}

#endif

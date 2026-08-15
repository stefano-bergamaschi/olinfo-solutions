#include <bits/stdc++.h>
using namespace std;

int pulisci(int N, int M, vector<string> S){
  	deque<int> h(N, 0);
  	deque<int> w(M, 0);
	
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(S[i][j] == '1'){ 
		h[i]++;
		w[j]++;
	}

	sort(h.begin(), h.end());
	sort(w.begin(), w.end());

	int hl = 0, hr = M;
	int wl = 0, wr = N;
	
	while(!h.empty() and !w.empty() and (h.front() <= hl or h.back() >= hr or w.front() <= wl or w.back() >= wr)){
		while(!h.empty() and h.front() <= hl){
			h.pop_front();
			wr--;
		}
		while(!h.empty() and h.back() >= hr){
			h.pop_back();
			wl++;
		}
		while(!w.empty() and w.front() <= wl){
			w.pop_front();
			hr--;
		}
		while(!w.empty() and w.back() >= wr){
			w.pop_back();
			hl++;
		}
	} 
	
	return h.size() * w.size();
}

int main() {
  	int N, M;

  	cin >> N >> M;

  	vector<string> S(N);

  	for(int i = 0; i < N; i++) {
    	cin >> S[i];
  	}

  	cout << pulisci(N, M, S) << endl;

  	return 0;
}

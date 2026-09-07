#include <bits/stdc++.h>
using namespace std;

void aggiungi(){
	cout << "A";
}
void copia(){
	cout << "C";
}
void incolla(){
	cout << "I";
}

unordered_map<long long, pair<long long, long long>> mem;
vector<long long> v = {2, 3, 4, 5, 7, 11, 13};
long long solve(long long N){
    if(N <= 7) return N;
    
    if(mem.find(N) != mem.end()) return mem[N].first;
    
    pair<long long, long long> ans = {LLONG_MAX, 0};
    for(long long k: v){
        if(k > N) break;
        long long v = solve(N / k) + N % k + k + 1LL;
        if(v < ans.first) ans = {v, k};
    } 
    mem[N] = ans;

    return ans.first;
}

void write(long long N){
    if(N <= 7){
        for(int i = 0; i < N; i++) aggiungi();
        return;
    }
    
    write(N / mem[N].second);

    copia();
    for(int i = 0; i < mem[N].second - 1; i++) incolla();
    for(int i = 0; i < N % mem[N].second; i++) aggiungi();

    return;
}

void auguri(long long N){
    solve(N);
    write(N);
}


int main(){
	int N;
    cin >> N;
    auguri(N);
}

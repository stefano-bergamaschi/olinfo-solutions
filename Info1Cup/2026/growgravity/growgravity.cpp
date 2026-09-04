#include <bits/stdc++.h>
using namespace std;

class segment_trea {
    private:
        long long n;
        vector<pair<long long, long long>> st;

        pair<long long, long long> merge(pair<long long, long long> a, pair<long long, long long> b){
            return {a.first + b.first, a.second + b.second};
        }

        long long formula(pair<long long, long long> v){
            return (2 * (v.first + v.second) + 1) * (2 * (v.first + v.second) + 1) - (v.second * v.second + 3 * v.second); 
        }
        
    public:
        segment_trea(string v){
            n = v.size();
            st.resize(n << 1);

            for(long long i = 0; i < n; i++){
                if(v[i] == '*') st[i + n] = {1, 0};
                else st[i + n] = {0, 1};
            }
            for(long long i = n - 1; i > 0; i--) st[i] = merge(st[i << 1], st[i << 1 | 1]);  
        }

        void update(long long i){
            if(st[i + n] == pair<long long, long long>{1, 0}) st[i + n] = {0 , 1};
            else st[i + n] = {1, 0};

            for(i += n; i > 1; i >>= 1) st[i >> 1] = merge(st[i], st[i ^ 1]);
        }

        long long query(long long l, long long r){
            pair<long long, long long> ans = {0, 0};
            for(l += n, r += n; l < r; l >>= 1, r >>= 1){
                if(l & 1) ans = merge(ans, st[l++]);
                if(r & 1) ans = merge(ans, st[--r]);
            }

            return formula(ans);
        }
};


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long N;
    cin >> N;

    string v;
    cin >> v;

    segment_trea st(v);

    long long Q;
    cin >> Q;

    for(long long q = 0;  q < Q; q++){
        long long t;
        cin >> t;

        if(t == 1){
            long long i;
            cin >> i;
            st.update(i - 1);
        } else {
            long long l, r;
            cin >> l >> r;
            cout << st.query(l - 1, r) << "\n";
        }
    }
}
#include <bits/stdc++.h>  
using namespace std;

const long long MOD = 998244353;

struct node {
    pair<long long, long long> first;
    pair<long long, long long> second; 
    bool check;
};

class segment_trea {
    private:
        long long n;
        vector<node> st;
        vector<long long> m;
        

        pair<long long, long long> unite(pair<long long, long long> a, pair<long long, long long> b){
            return {(a.first * b.first) % MOD, (a.second * b.first + b.second) % MOD};
        }
        
        node merge(node a, node b){
            if(a.check) return {unite(a.first, b.second), unite(a.second, b.second), true};
            else return {unite(a.first, b.first), unite(a.second, b.second), b.check};
        }

    public:
        segment_trea(vector<long long> v){
            n = v.size();
            m.assign(v.begin(), v.end());
            st.resize(n << 1);

            for(long long i = 0; i < n; i++){
                if(v[i] & 1){
                    st[i + n].first.first = 1;
                    st[i + n].first.second = v[i];
                    st[i + n].second.first = v[i];
                    st[i + n].second.second = 0;
                    st[i + n].check = true;
                } else {
                    st[i + n].first.first = v[i];
                    st[i + n].first.second = 0;
                    st[i + n].second.first = 1;
                    st[i + n].second.second =v[i];
                    st[i + n].check = false;
                }
            }

            for(long long i = n - 1; i > 0; i--) st[i] = merge(st[i << 1], st[i << 1 | 1]);
        }

        long long query(long long tl, long long tr){
            long long i = tl;
            
            node left = {{1, 0}, {1, 0}}, right = {{1, 0}, {1, 0}};
            for(tl += n + 1, tr += n + 1; tl < tr; tl >>= 1, tr >>= 1){
                if(tl & 1){
                    left = merge(left, st[tl++]);
                } 
                if(tr & 1){
                    right = merge(st[--tr], right);
                } 
            }
            
            node total = merge(left, right);
            if(m[i] & 1){
                return (m[i] * total.second.first + total.second.second) % MOD;
            } else {
                return (m[i] * total.first.first + total.first.second) % MOD;
            }
        }
};

int main(){
    ifstream cin("input.txt");
    
    long long N;
    cin >> N;

    vector<long long> v(N);
    for(long long& i: v) cin >> i;

    segment_trea st(v);

    long long Q;
    cin >> Q;

    for(long long q = 0; q < Q; q++){
        long long tl, tr;
        cin >> tl >> tr;
        cout << st.query(tl - 1, tr - 1) << endl;
    }
    
}
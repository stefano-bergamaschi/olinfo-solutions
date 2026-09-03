#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long a, long long n) {
    long long ans = 1;
    a %= MOD;
    
    while (n > 0) {
        if (n & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    
    return ans;
}

struct Node {
    long long suma = 0;
    long long sumd = 0;
    long long sump = 0;
    long long lazya = 0;
    long long lazyd = 0;
    long long len = 0;
};

class segment_trea {
    private:
        int n;
        vector<Node> st;

        void apply(int n, long long va, long long vd) {
            va %= MOD;
            vd %= MOD;
            
            st[n].sump = (st[n].sump +  va * st[n].sumd + vd * st[n].suma + (vd * va % MOD) * st[n].len) % MOD;
            st[n].suma = (st[n].suma + va * st[n].len) % MOD;
            st[n].sumd = (st[n].sumd + vd * st[n].len) % MOD;

            st[n].lazya = (st[n].lazya + va) % MOD;
            st[n].lazyd = (st[n].lazyd + vd) % MOD;
        }

        void push(int n) {
            if(st[n].lazya != 0 or st[n].lazyd != 0){
                apply(n << 1, st[n].lazya, st[n].lazyd);
                apply(n << 1 | 1, st[n].lazya, st[n].lazyd);
                st[n].lazya = 0;
                st[n].lazyd = 0;
            }
        }

        void pull(int n) {
            st[n].suma = (st[n << 1].suma + st[n << 1 | 1].suma) % MOD;
            st[n].sumd = (st[n << 1].sumd + st[n << 1 | 1].sumd) % MOD;
            st[n].sump = (st[n << 1].sump + st[n << 1 | 1].sump) % MOD;
        }

        void build(int n, int tl, int tr, vector<int>& a, vector<int>& d) {
            st[n].len = tr - tl + 1;
            if (tl == tr) {
                st[n].suma = a[tl];
                st[n].sumd = d[tl];
                st[n].sump = (1LL * a[tl] * d[tl]) % MOD;
                return;
            }
            int mid = (tl + tr) / 2;
            build(n << 1, tl, mid, a, d);
            build(n << 1 | 1, mid + 1, tr, a, d);
            pull(n);
        }

        void update(int n, int tl, int tr, int l, int r, long long va, long long vd) {
            if (r < tl || tr < l) return;
            if (l <= tl && tr <= r) {
                apply(n, va, vd);
                return;
            }
            push(n);
            int mid = (tl + tr) / 2;
            update(n << 1, tl, mid, l, r, va, vd);
            update(n << 1 | 1, mid + 1, tr, l, r, va, vd);
            pull(n);
        }

        Node query(int n, int tl, int tr, int l, int r) {
            if (r < tl || tr < l) return Node();
            if (l <= tl && tr <= r) return st[n];
            
            push(n);
            int mid = (tl + tr) / 2;
            Node left_res = query(n << 1, tl, mid, l, r);
            Node right_res = query(n << 1 | 1, mid + 1, tr, l, r);
            
            Node res;
            res.suma = (left_res.suma + right_res.suma) % MOD;
            res.sumd = (left_res.sumd + right_res.sumd) % MOD;
            res.sump = (left_res.sump + right_res.sump) % MOD;
            res.len = left_res.len + right_res.len;
            return res;
        }

    public:
        segment_trea(vector<int>& a, vector<int>& d) {
            n = a.size();
            st.resize(4 * n);
            build(1, 0, n - 1, a, d);
        }

        void update_a(int l, int r, long long v) {
            update(1, 0, n - 1, l, r, v, 0);
        }

        void update_d(int l, int r, long long v) {
            update(1, 0, n - 1, l, r, 0, v);
        }

        long long get(int l, int r, long long k) {
            Node ans = query(1, 0, n - 1, l, r);
            return (((ans.suma * ans.sumd) % MOD) * power(ans.sump, k - 1)) % MOD;
        }
};

int main() {
    int n;
    cin >> n;

    vector<int> d(n), a(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    for(int i = 0; i < n; i++) cin >> a[i];

    segment_trea st(a, d);

    int Q;
    cin >> Q;
    
    for(int q = 0; q < Q; q++){
        int n;
        cin >> n;

        if (n == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            st.update_d(l - 1, r - 1, val);
        } else if (n == 2) {
            int l, r, val;
            cin >> l >> r >> val;
            st.update_a(l - 1, r - 1, val);
        } else if (n == 3) {
            int l, r;
            long long k;
            cin >> l >> r >> k;
            cout << st.get(l - 1, r - 1, k) << "\n";
        }
    }
}
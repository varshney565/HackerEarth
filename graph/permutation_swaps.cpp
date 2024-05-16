/**
 * author : shivam varshney
 * UIET KURUKSHETRA UNIVERSITY
 * ∑.⌣
 * */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pbds tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#include<bits/stdc++.h>
#pragma GCC optimise("Ofast")
#pragma GCC target("avx","avx2","fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define pi pair<int,int>
#define ff first
#define ss second

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(bool t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
inline void read(int &n,vector<int> &v) {for(int i = 0 ; i < n ; i++) cin>>v[i];}
inline void print(int &n,vector<int> &v) {for(int i = 0 ; i < n ; i++) cout<<v[i]<<" ";cout<<"\n";}
inline void read(int &n,int &m,vector<vector<int>> &v) {for(int i = 0 ; i < n ; i++) {for(int j = 0 ; j < m ; j++){ cin>>v[i][j];}}}
inline void print(int &n,int &m,vector<vector<int>> &v) {for(int i = 0 ;i < n ; i++){for(int j = 0 ; j < m ; j++){cout<<v[i][j]<<" ";}cout<<"\n";}}
inline void consoleLog(bool ans) {cout<<(ans ? "YES\n" : "NO\n");}
inline int get(pbds &s,int ind) {return *s.find_by_order(ind);}
inline int lb(pbds &s,int val) {return s.order_of_key(val);}

class Dsu {
public:
    vector<int> p;
    Dsu(int n) {
        p.resize(n);
        iota(all(p),0);
    }

    int get(int n) {
        if(p[n] == n) {
            return n;
        }
        return p[n] = get(p[n]);
    }

    bool unite(int a,int b) {
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2) {
            return false;
        }
        p[p1] = p2;
        return true;
    }
};


void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> p(n);
    vector<int> q(n);
    for(int i = 0 ; i < n ; i++) {
        int t;cin>>t;
        t--;
        p[i] = t;
    }
    for(int i = 0 ; i < n ; i++) {
        int t;
        cin>>t;
        t--;
        q[i] = t;
    }
    debug(p);
    debug(q);
    Dsu d(n);
    for(int i = 0 ; i < m ; i++) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        int x = p[a];
        int y = p[b];
        d.unite(x,y);
    }
    int ans = true;
    for(int i = 0 ; i < n ; i++) {
        if(p[i] != q[i]) {
            int p1 = d.get(p[i]);
            int p2 = d.get(q[i]);
            if(p1 != p2) {
                ans = false;
                break;
            }
        }
    }
    if(ans) {
        cout<<"YES\n";
    }else {
        cout<<"NO\n";
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("./input.txt","r",stdin);
        freopen("./output.txt","w",stdout);
        freopen("./error.txt", "w", stderr);
    #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
} 

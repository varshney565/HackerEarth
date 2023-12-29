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

/**
 * 
 * Actual code starts here.
 * 
 * */

class P {
public:
    int a;
    int b;
    int index;
    P (int a,int b,int index) {
        this->a = a;
        this->b = b;
        this->index = index;
    }
};

void _print(P p) {cerr<<"a:"<<p.a<<" "<<"b:"<<p.b<<" "<<"index:"<<p.index<<"\n";}

const int mod = 1e9+7;

void solve() {
	int N;
    cin>>N;
    vector<int> a(N),b(N);
    read(N,a);read(N,b);
    vector<P> data;
    for(int i = 0 ; i < N ; i++) {
        data.push_back(P(a[i],b[i],i));
    }
    sort(all(data),[&](const P &a,const P &b) {
        if(a.a != b.a) {
            return a.a < b.a;
        }
        return a.b > b.b;
    });

    for(int i = 0 ; i < N ; i++) {
        b[i] = data[i].b;
    }
    vector<vector<int>> dp(N+1,vector<int>(1001,1));
    for(int n = 1 ; n <= N ; n++) {
        for(int sum = 0 ; sum <= 1000 ; sum++) {
            // first ignore
            int op1 = dp[n-1][sum];
            // second take
            int op2 = 0;
            if(sum-b[n-1] >= 0) {
                op2 = dp[n-1][sum-b[n-1]];
            }
            dp[n][sum] = (op1+op2)%mod;
        }
    }
    // dp[i][j] mean total number of subarrays from i to 0 such that their sum is equal to j
    int ans = 0;
    for(int i = N - 1 ; i >= 0 ; i--) {
        int sumToFind = data[i].a-data[i].b;
        if(sumToFind >= 0 && i) {
            ans = (ans + dp[i][sumToFind])%mod;
        }else if(i == 0) {
            if(sumToFind >= 0) ans = (ans+1)%mod;
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
   #ifndef ONLINE_JUDGE
        freopen("./../io/input.txt","r",stdin);
        freopen("./../io/output.txt","w",stdout);
        freopen("./../io/error.txt", "w", stderr);
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
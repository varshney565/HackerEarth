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
// #define int long long
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

const int mod = 1e9+7;

void solve() {  
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin>>v[i][j];
        }
    }
    
    const int mod = 1e9+7;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(3,-1)));
    int d[][2] = {{-1,0},{0,-1}};
    function<int(int,int,int)> go = [&](int x,int y,int dir) {
        if(dp[x][y][dir] != -1) return dp[x][y][dir];
        if(v[x][y] == '1') {
            if(dir == 2) {
                return dp[x][y][dir] = 0;
            }
            if(dir == 0) {
                // left
                if(x - 1 >= 0) {
                    return dp[x][y][dir] = go(x-1,y,dir);
                }
                return dp[x][y][dir] = 0;
            }
            if(dir == 1) {
                // up
                if(y - 1 >= 0) {
                    return dp[x][y][dir] = go(x,y-1,dir);
                }
                return dp[x][y][dir] = 0;
            }
            return dp[x][y][dir] = 0;
        }
        if(x == 0 && y == 0) {
            return dp[x][y][dir] = 1;
        }

        int ans = 0;
        for(int i = 0 ; i < 2 ; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(newx >= 0 && newx < n && newy >= 0 && newy < m) {
                ans = (ans + go(newx,newy,i))%mod;
            }
        }
        return dp[x][y][dir] = ans;
    };
    int ans = go(n-1,m-1,2);
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
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
} 
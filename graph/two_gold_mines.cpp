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

void solve() {
    int n;cin>>n;
    vector<string> v(n);
    for(int i = 0 ; i < n ; i++) {
        cin>>v[i];
    }
    int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    function<int(int,int)> bfs = [&](int p1,int p2) {
        vector<char> visited(n*n,false);
        queue<int> PendingNodes;
        PendingNodes.push(p1);
        visited[p1] = false;
        int level = 0;
        while(!PendingNodes.empty()) {
            int size = PendingNodes.size();
            while(size-->0) {
                int front = PendingNodes.front();
                PendingNodes.pop();
                if(front == p2) {
                    return level;
                }
                int x = front/n;
                int y = front%n;
                for(int i = 0 ; i < 4 ; i++) {
                    int newx = x + dir[i][0];
                    int newy = y + dir[i][1];
                    int ind = newx*n+newy;
                    if(newx >= 0 && newx < n && newy >= 0 && newy < n && !visited[ind] && v[newx][newy] != '#') {
                        visited[ind] = true;
                        PendingNodes.push(ind);
                    }
                }
            }
            level++;
        }
        return INT_MAX;
    };
    vector<int> miners;
    vector<int> targets;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(v[i][j] == '^') {
                miners.push_back(i*n+j);
            }else if(v[i][j] == '*') {
                targets.push_back(i*n+j);
            }
        }
    }
    int ans = INT_MAX;
    int t1 = bfs(miners[0],targets[0]);
    int t2 = bfs(miners[0],targets[1]);
    int t3 = bfs(miners[1],targets[0]);
    int t4 = bfs(miners[1],targets[1]);
    int t5 = bfs(targets[0],targets[1]);
    
    if(t1 != INT_MAX && t2 != INT_MAX) {
        ans = min(ans,max(t1,t4));
    }
    if(t3 < INT_MAX && t4 < INT_MAX) {
        ans = min(ans,max(t2,t3));
    }

    if(t1 < INT_MAX && t2 < INT_MAX) {
        ans = min(ans,min(t1,t2)+t5);
    }
    if(t3 < INT_MAX && t4 < INT_MAX) {
        ans = min(ans,min(t3,t4)+t5);
    }
    if(ans == INT_MAX) {
        cout<<"No\n";
    }else {
        cout<<"Yes\n";
        cout<<ans<<"\n";
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

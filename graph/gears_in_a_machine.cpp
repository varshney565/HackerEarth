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


void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> type(n);
    read(n,type);
    vector<vector<int>> adj(n);
    for(int i = 0 ; i < m ; i++) {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //some precomputation

    vector<int> visited(n,0);
    vector<int> component(n,0);
    vector<int> isBipartile(n,-1); //for component only
    int cnt = 0;
    function<bool(int,int)> bfs = [&](int u,int component_number) {
        queue<int> PendingNodes;
        PendingNodes.push(u);
        visited[u] = 1;
        component[u] = component_number;
        bool res = true;
        while(!PendingNodes.empty()) {
            int size = PendingNodes.size();
            while(size-->0) {
                int front = PendingNodes.front();
                PendingNodes.pop();
                for(auto child : adj[front]) {
                    if(!visited[child]) {
                        PendingNodes.push(child);
                        component[child] = component_number;
                        if(type[child] == -1) {
                            //internal node
                            visited[child] = visited[front];
                        }else {
                            if(type[front] == -1) {
                                visited[child] = visited[front];
                            }else {
                                //external node
                                visited[child] = ((visited[front] == 2) ? 1 : 2);
                            }
                        }
                    }else {
                        if(type[child] == 1) {
                            //external node
                            if(type[front] == -1) {
                                if(visited[child] != visited[front]) {
                                    res = false;
                                }
                            }
                            else if(visited[child] == visited[front]) {
                                res = false;
                            }
                        }else if(type[child] == -1) {
                            //internal node
                            if(visited[child] != visited[front]) {
                                res = false;
                            }
                        }
                    }
                }
            }
        }
        return res;
    };
    for(int i = 0 ; i < n ; i++) {
        if(!visited[i]) {
            isBipartile[cnt] = bfs(i,cnt);
            cnt++;
        }
    }
    for(int i = 0 ; i < q ; i++) {
        int u,v,d1,d2;
        cin>>u>>v>>d1>>d2;
        if(d1 == -1) {
            d1 = 2;
        }
        if(d2 == -1) {
            d2 = 2;
        }
        u--;v--;
        //time to do the query
        int c1 = component[u];
        int c2 = component[v];
        if(!isBipartile[c1] || !isBipartile[c2]) {
            cout<<"NO\n";
        }else if(c1 != c2) {
            cout<<"YES\n";
        }else {
            int s1 = visited[u]+visited[v];
            int s2 = d1+d2;
            if((s1 == s2) || (s2%s1 == 0) || (s1%s2 == 0)) {
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
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
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
} 
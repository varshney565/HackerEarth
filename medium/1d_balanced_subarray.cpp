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
#define int long long
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

void solve() {
	int n;cin>>n;
    vector<int> v(n);
    read(n,v);
    vector<pair<int,int>> pre(n,{0ll,0ll}),suf(n,{0ll,0ll});
    // first will be the total number of subarrays ending at index i such that their sum is odd
    // second will be same for even 
    for(int i = 0 ; i < n ; i++) {
        if(v[i]%2) pre[i].ff++;
        else pre[i].ss++;
        if(i) {
            if(v[i-1]%2) {
                if(v[i]%2 == 0) {
                    pre[i].ff += pre[i-1].ff;
                    pre[i].ss += pre[i-1].ss;
                }else {
                    pre[i].ff += pre[i-1].ss;
                    pre[i].ss += pre[i-1].ff;
                }
            }
        }
    }

    for(int j = n-1 ; j >= 0 ; j--) {
        if(v[j]%2) suf[j].ff++;
        else suf[j].ss++;
        if(j < n-1) {
            if(v[j]%2 == 0) {
                suf[j].ff += suf[j+1].ff;
                suf[j].ss += suf[j+1].ss;
            }else {
                suf[j].ff += suf[j+1].ss;
                suf[j].ss += suf[j+1].ff;
            }
        }
    }
    int ans = 0;
    int prev = -1;
    for(int i = 0 ; i < n ; i++) {
        if(v[i]%2 == 0) {
            int l = i-prev-1;
            int l1 = (l+1)/2;
            ans = ans + l1*l-l1*(l1-1); // l1(l-l1+1)
            int leven = 0,lodd = 0,reven = 0,rodd = 0;
            if(i) {
                leven = pre[i-1].ss;
                lodd = pre[i-1].ff;
                if(v[i-1]%2 == 0) {
                    leven = 0;
                    lodd = 0;
                }
            }
            if(i < n-1) {
                reven = suf[i+1].ss;
                rodd = suf[i+1].ff;
            }
            ans = ans + (leven+1ll)*(reven+1ll) + (lodd)*(rodd);
            prev = i;
        }
    }
    int l = n-prev-1;
    int l1 = (l+1)/2;
    ans = ans + l1*l-l1*(l1-1);
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
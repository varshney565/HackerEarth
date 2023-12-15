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

class dsu {
public:
    vector<int> p;
    vector<int> s;
    dsu(int n) {
        p.resize(n);
        iota(p.begin(),p.end(),0);
        s.resize(n,1);
    }

    int get(int n) {
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }

    bool unite(int a,int b) {
        int p1 = get(a),p2 = get(b);
        if(p1 == p2) return false;
        p[p1] = p2;
        s[p2] += s[p1];
        return true;
    }
};

class SegTree {
public:
    vector<int> p;
    vector<int> v;
    SegTree(vector<int> &v) {
        int n = v.size();
        p.resize(4*n,0);
        this->v.assign(v.begin(),v.end());
    }

    int query(int index,int l,int r,int low,int high) {
        if(r < low || high < l)
            return 2147483647;

        if(l <= low && r >= high)
            return p[index];
        int mid = low+(high-low)/2;
        int left = query(2*index+1,l,r,low,mid);
        int right = query(2*index+2,l,r,mid+1,high);
        return (left&right);        
    }

    void build(int index,int low,int high) {
        if(low == high){
            p[index] = v[low];
            return;
        }

        int mid = low+(high-low)/2;
        build(2*index+1,low,mid);
        build(2*index+2,mid+1,high);
        p[index] = (p[2*index+1]&p[2*index+2]);
    }
};

/**
 * 
 * Actual code starts here.
 * 
 * */

void solve() {
	int n;
	cin>>n;
	vector<int> sticks(3);
	for(int i = 0 ; i < 3 ; i++) {
		cin>>sticks[i];
	}

	vector<int> dp(n+1,-1);
	function<int(int)> go = [&](int n) {
		if(dp[n] != -1) {
			return dp[n];
		}
		int ans = -1;
		for(int i = 0 ; i < 3 ; i++) {
			if(n-sticks[i] > 0) {
				int temp = go(n-sticks[i]);
				if(temp >= 0) {
					ans = max(ans,1 + temp);
				}
			}else if(n-sticks[i] == 0) {
				ans = max(ans,1);
			}
		}
		return dp[n] = ans;
	};
	cout<<go(n)<<"\n";
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
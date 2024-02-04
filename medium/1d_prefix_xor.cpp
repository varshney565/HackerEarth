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

/**
 * 
 * Actual code starts here.
 * 
 * */

void solve() {
	int n,q;
	cin>>n>>q;
	vector<int> v(n);
	read(n,v);
	vector<vector<int>> cnt(n,vector<int>(60,0));
	vector<int> xr(n);
	for(int i = 0 ; i < n ; i++) {
		xr[i] = v[i];
		if(i) {
			xr[i] ^= xr[i-1];
		}
	}
	
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < 60 ; j++) {
			if((1ll<<j)&xr[i]) cnt[i][j] = 1;
			else cnt[i][j] = 0;
		}
	}
	
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < 60 ; j++) {
			if(i) {
				cnt[i][j] += cnt[i-1][j];
			}
		}
	}

	for(int i = 0 ; i < q ; i++) {
		int l,r;cin>>l>>r;
		l--;r--;

		// here calculate the answer
		vector<int> sumBits(60,0);
		for(int i = 0 ; i < 60 ; i++) {
            sumBits[i] = cnt[r][i];
        }
        if(l) {
            for(int i = 0 ; i < 60 ; i++) {
                sumBits[i] -= cnt[l-1][i];
            }
            int len = r-l+1;

            for(int j = 0 ; j < 60 ; j++) {
                if((1ll<<j)&xr[l-1]) {
                    sumBits[j] = len-sumBits[j];
                }
            }
        }
        int ans = 0;
        int carry = 0;
        for(int j = 0 ; j < 60 ; j++) {
            int val = (sumBits[j] + carry);
            int rem = val%2;
            carry = (val-rem)/2;
            sumBits[j] = rem;
        }
        for(int j = 60 ; j >= 0 ; j--) {
            ans = ((ans<<1ll)|sumBits[j]);
        }
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
    int t = 1;
    while(t--) {
        solve();
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
}
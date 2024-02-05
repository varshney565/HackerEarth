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
	// int n;
	// cin>>n;
	// map<int,map<int,int>> cnt;
	// for(int i = 0 ; i < n ; i++) {
	// 	string s;
	// 	cin>>s;
	// 	int ans = 0;
	// 	for(int j = 0 ; j < s.size() ; j++) {
	// 		if(s[j] == '1') {
	// 			ans = ((ans<<1ll)|1ll);
	// 		}else {
	// 			ans = (ans<<1ll);
	// 		}
	// 	}
	// 	cnt[ans][s.size()-1]++;
	// }

	// auto total = [&](int val,int k) {
	// 	int sum = 0;
	// 	for(int i = k ; i < 5 ; i++) {
	// 		sum += cnt[val][i];
	// 	}
	// 	return sum;
	// };

	// int ans = 0;
	// for(int i = 0 ; i < 32 ; i++) {
	// 	for(int j = i ; j < 32 ; j++) {
	// 		if(i == j) {
	// 			int t = 0;
	// 			t = total(i,0);
	// 			ans += t*(t-1)/2;
	// 			continue;
	// 		}
	// 		int k = 0;
	// 		for(k = 0 ; k < 5 ; k++) {
	// 			if(((1ll<<k)&i) == ((1ll<<k)&j)) {
	// 				break;
	// 			}
	// 		}
	// 		if(k != 5) {
	// 			int a1 = total(i,k);
	// 			int a2 = total(j,k);
	// 			ans = ans + a1*a2;
	// 		}
	// 	}
	// }
	// cout<<ans<<"\n";

	int n;
	cin>>n;
	int p=0,q=0,r=0;
	for(int i = 0 ; i < n ; i++) {
		string s;
		cin>>s;
		int a = count(all(s),'1');
		int b = count(all(s),'0');
		if(a) p++;
		if(b) q++;
		if(a && b) r++; 
	}
	int a = p*(p-1)/2;int b = q*(q-1)/2;int c = r*(r-1)/2;
	debug(a);debug(b);debug(c);
	cout<<a+b-c<<"\n";
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

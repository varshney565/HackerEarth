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
 * 
 * 
 * 
 * 
 * 
 * for(i=A;i<=B;i++) {
 *  for(j=C;j<=D;j++) {
 *      sum = sum + (i^j)
 *  }
 * }
 * 
 * 
 *                     
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * */

void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    auto countOnes = [&](int x,int y,int bit) {
        int s = x;
        int e = x+(1<<bit);
        int cnt = 0;
        if((1ull<<bit)&x) {
            // search for 1st occurance of 0
            while(s <= e) {
                int mid = s+(e-s)/2ull;
                if((1ull<<bit)&mid) {
                    s = mid+1;
                }else{
                    e = mid-1;
                }
            }

            // s is now pointing to first 0 from where it is starting
            // debug(s);debug(e);
            cnt += min(e,y)-x+1;
            if(s <= y) {
                int N = y-s+1;
                int times = (N/(1ll<<(bit+1)));
                int t1 = times*(1ll<<bit);
                int rem = N-(1ll<<(bit+1ull))*times;
                cnt += t1;
                cnt += max(0ll,rem-(1ll<<bit));
            }
        }else {
            // search for 1st occurance of 1
            while(s <= e) {
                int mid = s+(e-s)/2ll;
                if((1ull<<bit)&mid) {
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }

            // s is not pointing to first 1 from where it is starting
            if(s <= y) {
                int N = y-s+1;
                int times = N/(1ll<<(bit+1));
                int t1 = times*(1ll<<bit);
                int rem = min((1ll<<bit),N-(1ll<<(bit+1))*times);
                cnt += t1+rem;
            }
        }
        return cnt;
    };

    const int mod = 1000000007ll;
    int N = 32,M = 1001;
    vector<int> cnt(N,0);
    for(int i = 0 ; i < N ; i++) {
        cnt[i] = countOnes(a,b,i);
    }

    vector<int> bits(M,0);
    for(int i = 0 ; i < N ; i++) {
        int one1  = countOnes(c,d,i);
        int zero1 = d-c+1-one1;
        int one2  = cnt[i];
        int zero2 = b-a+1-one2;
        bits[i] = zero1*one2 + one1*zero2;
    }

    int carry = 0;
    for(int i = 0 ; i < M ; i++) {
        int sum = carry+bits[i];
        if(sum&1ull) {
            bits[i] = 1;
        }else {
            bits[i] = 0;
        }
        carry = (sum-(sum&1ll))/2ll;
    }
    int ans = 0;
    for(int i = M-1 ; i >= 0 ; i--) {
        ans = (ans<<1ll);
        if(bits[i] == 1ll) {
            ans = (ans | 1ll);
        }
        ans = ans%mod;
        if(i == 0) {
            break;
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
#include<bits/stdc++.h>
using namespace std;

void lps(string pattern,vector<int> &LPS) {
	int n = pattern.size();
	// pattern : a a a b a a a c a a a b a
	// LPS     : 0 1 2 0 1 2 3 0 1 2 3 4 5
	for(int i = 1 ; i < n ; i++) {
		int k = LPS[i-1];
		while(k && pattern[k] != pattern[i]) {
			k = LPS[k-1];
		}
		if(pattern[k] == pattern[i]) LPS[i] = k+1;
		else LPS[i] = 0;
	}
}

vector<int> solve(string s,string p) {
	int n = s.size();
	int m = p.size();
	if(n < m) {
		return {};
	}
	vector<int> LPS(m,0);
	lps(p,LPS);
	vector<int> ans; 
	int j = 0;
	for(int i = 0 ; i < n ; ) {
		while(j < m && i < n && s[i] == p[j]) {
			i++;
			j++;
		}
		if(j == m) {
			ans.push_back(i-m);
			j = LPS[j-1];
		}else if(j != 0) {
			j = LPS[j-1];
		}else {
			i++;
		}
	}
	return ans;
}

signed main()
{
	string s;
	cin>>s;
	string p;
	cin>>p;
	auto t = solve(s,p);
	for(auto x : t) {
		cout<<x<<" ";
	}
	cout<<"\n";
    return 0;
} 
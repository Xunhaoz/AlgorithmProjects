#include<bits/stdc++.h>
using namespace std;
vector<int> G[26];

void init(int n) {
	for(int i=0;i<n;i++) G[i].clear();
}

void add_edge(int a,int b) {
	G[a].push_back(b);
	G[b].push_back(a);
}

int main() {
	int t, n = 26, ans = 0, check = 0;
	string s;
	cin>>t;
	while(cin >> s){
		if(s.length() == 1 && check != 0){
			
			for(int i=0;i<26;i++){
				if(G[i].size() > ans)
					ans = G[i].size();
			}
			cout<<ans;	
			init(n);
			

			
			
		} else {
			check  = 1;
			add_edge(s[0] - 'A', s[1] - 'A');
		}
		
	}
} 

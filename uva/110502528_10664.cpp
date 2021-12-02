#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(false), cin.tie(NULL);
	int n, weight, totalweight;
	string input;
	bool DB[4001];
	cin >> n, getline(cin, input);
	while(n--){
		getline(cin,  input);		
		stringstream ss(input);
		memset(DB, 0, sizeof(DB));
		DB[0] = true, totalweight = 0;
		while(ss >> weight) {
			totalweight += weight;
			for(int i=totalweight;i >= weight;--i)
				DB[i] += DB[i-weight];
		}
		cout<< ((totalweight & 1) && DB[totalweight >> 1] ? "YES\n" : "NO\n");
		
	}
}

#include<bits/stdc++.h>
using namespace std;
int num_string[1000000];
int num_check[1000000];
int main(){
	string str;
	int group = 1;
	cin >> str;
	for(int i=0;i<str.length();i++){
		num_string[i] = (int)str[i] - 48;
		if(num_string[i] != num_string[i-1] && i >= 1){
			group++;
		}
		num_check[i] = group;
	}
	int x, y;
	cin>>x>>y;
	cout<< ((num_check[x] == num_check[y]) ? "YES" : "NO");
}

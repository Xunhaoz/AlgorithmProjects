#include<iostream>
#include <cstdio>
#include<vector>
using namespace std;
int main(){
	string s;
	while(cin>>s && s!="."){
		vector<int>  failure(s.length(), 0);
		
		for(int i=1,j = failure[0] = -1;i<s.length();i++){
			while(j>=0 && s[j+1]!= s[i]) j = failure[j];
			if(s[j+1] == s[i]) j++;
			failure[i] = j;
			cout<<j<<endl;
		}

		/*
		int repeatlength = s.length() - failure[s.length()-1]-1;
		
		if(s.length() % repeatlength == 0){
			cout<<s.length()/repeatlength<<endl;
		}
		else cout<<"1"<<endl;
		*/
		
	}
	return 0;
} 

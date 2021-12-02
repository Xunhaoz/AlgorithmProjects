#include<iostream>
#include<string>
using namespace std;

int main(){
	while(1){
		int a_E[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int b_E[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		string a, b;
		cin>>a>>b;
		for(int i=0;i<a.length();i++){
			a_E[(int)a[i] - 97] = 1;
		}
		for(int i=0;i<b.length();i++){
			b_E[(int)b[i] - 97] = 1;
		}
		
		for(int i=0;i<26;i++){
			if(a_E[i]==1 && b_E[i]==1){
				cout<<(char) (i+97);
			}
		}
		
		cout<<endl;
	}
	
} 

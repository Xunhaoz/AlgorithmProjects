#include<iostream>
#include<string>
using namespace std;
int main(){
	int times,n;
	cin>>times;
	string tem;
	while(times--){
		cin >> n;
		getline(cin, tem);
		string target[n],source[n];
		for(int i=0; i<n; i++){
			getline(cin, source[i]);
		}
		for(int i=0; i<n; i++){
			getline(cin, target[i]);
		}
		int flagS = n-1, flagT = n-1;
		while(flagS >= 0){
			if(source[flagS] == target[flagT]) flagT--;
			flagS--;
		}
		while(flagT >= 0){
			cout << target[flagT--] << "\n";
		}
		cout<<endl;
	
	} 
	return 0;
}

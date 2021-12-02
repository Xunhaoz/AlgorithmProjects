#include<bits/stdc++.h>
using namespace std;
int array[3000];
int main(){
	int n, is_jolly = 1, num;
	cin>>n;
	for(int i=0;i<n;++i){
		cin >> num;
		array[i] = num;
		
		if(i>0 && !(abs(array[i]-array[i-1])<n)){
			is_jolly = 0;
			break;
		}
		
	}
	cout<<(is_jolly ? "Jolly" : "Not Jolly");
}

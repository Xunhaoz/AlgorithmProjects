#include<iostream>
#include<cstring>
using namespace std;
int num_list[1001];

int main(){
	int a;
	cin>>a;
	while(a--){
		
		int num;
		cin>>num;
		memset(num_list, 0, sizeof(num_list));
		
		for(int i=0;i<num;i++){
			cin>>num_list[i];
		}
		
		int sum = num_list[0];
		int ans = 2;
		for(int i=1;i<num-1;i++){
			if(sum+num_list[i]<num_list[i+1]){
				sum += num_list[i];
				ans++;			
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
} 

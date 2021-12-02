#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int T, N, P, h;
	cin>>T;
	while(T--){
		cin >> N >> P;
		int day[N+1];
		memset(day, 0, sizeof(day));
		for(int i=0;i<P;i++){
			cin>>h;
			for(int j=h;j<=N;j+=h){
				day[j] = 1;
			}
		}
		for(int i=6;i<=N;i+=7){
			day[i] = 0;
		}
		
		for(int i=7;i<=N;i+=7){
			day[i] = 0;
		}
		int sum = 0;
		for(int i=0;i<=N;i++){
			sum+=day[i];
		}
		cout<<sum<<endl;
	}
	return 0;
} 
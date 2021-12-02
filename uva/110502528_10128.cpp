#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(false), cin.tie(NULL);
	
	int times, N, P, R;
	unsigned long long int DP[14][14][14];
	
	cin>>times;
	
	memset(DP, 0, sizeof(DP));
	DP[1][1][1] = 1;
	for(int i=2;i<14;i++){
		for(int j=1;j<=i;j++){
			for(int k=1;k<=i;k++){
				DP[i][j][k]	= DP[i-1][j][k]*(i-2) + DP[i-1][j-1][k] + DP[i-1][j][k-1];
			}
		}
	}
	
	while(times--){
		cin>>N;
		for(int i=0;i<13;i++){
			for(int j=0;j<13;j++)
				cout<<DP[N][i][j]<<' ';
			cout<<endl;	
		}
		
	}
	
	
} 

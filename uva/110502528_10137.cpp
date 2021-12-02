#include<bits/stdc++.h>
using namespace std;
int costs[1000];
int main(){
	int n, total;
	double cost;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>cost;
		cost *= 100;
		total += cost;
		costs[i] = cost;
	}
	
	total /= n;
	
	int bigger_sum=0, smaller_sum=0;
	for(int i=0;i<n;++i){
		if(costs[i]>total)
			bigger_sum += (costs[i]-total);
		else if(costs[i]<total)
			smaller_sum += (total-costs[i]);
	}
	printf("%.2f\n",min(((float)bigger_sum/100), ((float)smaller_sum/100)));
}

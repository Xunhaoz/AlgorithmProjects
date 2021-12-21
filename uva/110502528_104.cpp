#include<iostream>
using namespace std;
double value[30][30][30];
int front_[30][30][30];
int dp(int n);
void output(int,int,int);
int main(){
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i == j){
                    value[1][i][j] = 1.0;
                }
                else{
                    cin >> value[1][i][j];
                }
            }
        }

        if(!dp(n)){
            cout << "no arbitrage sequence exists\n";
        }
    }
    return 0;
}
int dp(int n){
    for(int i=2;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                value[i][j][k] = -1.0;
                for(int l=1;l<=n;++l){
                    if(value[i][j][k] < value[i-1][j][l]*value[1][l][k]){
                        value[i][j][k] = value[i-1][j][l]*value[1][l][k];
                        front_[i][j][k] = l;
                    }

                }
                if(value[i][j][j]>1.01){
                    output(i, j, j);
                    cout<<endl;
                    return 1;
                }

            }
        }
    }
    return 0;
}
void output(int t,int u,int v){
    if(t >= 1){
        output(t-1, u, front_[t][u][v]);
        cout << " " << v;
    }
    else{
        cout << u;
    }
}

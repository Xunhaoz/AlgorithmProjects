#include<bits/stdc++.h>
using namespace std;
int n;
string color[6] = {"front", "back", "left", "right", "top", "bottom"};

int dp[3003];
int bot[3003];
int top[3003];
int pre[3003];

void printP(int);

int main(){

    int c[6];
    int Case = 0;

    while(cin >> n && n){
        for(int i=0;i<n;++i){

            for(int j=0;j<6;++j){
                cin >> c[j];
            }

            for(int j=0;j<6;++j){
                int tmp = i*6+j;
                top[tmp] = c[j];
                bot[tmp] = ((j%2) ? c[j-1] : c[j+1]);
                dp[tmp] = 1;
                pre[tmp] = -1;
            }
        }

        n = n * 6;
        int tmp = 0;

        for(int i=0;i<n;i++){
            if(dp[tmp]<dp[i]) tmp = i;
            for(int j=((i/6)+1)*6;j<n;++j){
                if(top[j] == bot[i] && dp[j]<dp[i]+1){
                    dp[j] = dp[i]+1;
                    pre[j] = i;
                }
            }
        }
        if(Case>0) cout << endl;
        cout << "Case #" << ++Case << endl << dp[tmp] << endl;
        printP(tmp);
    }
    return 0;
}
void printP(int tmp){
    if(tmp != -1){
        printP(pre[tmp]);
        cout << tmp/6+1 << ' ' << color[tmp%6] << endl;
    }
}

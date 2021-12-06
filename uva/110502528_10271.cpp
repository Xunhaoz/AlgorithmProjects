
#include<iostream>
#define MAXNUM 999999999
using namespace std;
int each_length[5001];
int DB[1001][5001];
int main(){
    int test_case, N, K;


    for(int i=0;i<1001;++i){
        DB[i][0] = MAXNUM;
    }
    for(int i=0;i<5001;i++){
        DB[0][i] = 0;
    }

    cin >> test_case;

    while(test_case--){
        cin >> K >> N;
        K += 8;



        for(int i=N;i>0;--i)
            cin >> each_length[i];

        for(int i=1;i<K+1;i++){
            for(int j=1;j<N+1;j++){
                if(j<i*3){
                    DB[i][j] = MAXNUM;
                }
                else if(j>=i*3){
                    DB[i][j] = min(DB[i][j-1], DB[i-1][j-2] + (each_length[j]-each_length[j-1])*(each_length[j]-each_length[j-1]));
                }
            }
        }

        cout << DB[K][N] << endl;
    }
    return 0;

}

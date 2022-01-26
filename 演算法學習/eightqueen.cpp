#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int count = 0;
int queen[4];

void dfs(int);

int main(){
    dfs(0);

    return 0;
}

void dfs(int level){
    if(level == 4){
        count++;
        for(int i=3;i>=0;i--)
            cout << setw(2) << queen[i];
        cout << "count: " << count << endl;

        return;
    }

    for(int i=0;i<4;i++){
        int cancut = 0;
        for(int j=0;j<level;j++){
            if(i == queen[j]){
                cancut = 1;
                break;
            }
            if(abs(queen[j]-i) == abs(level-j)){
                cancut = 1;
                break;
            }

        }

        if(cancut == 1)
            continue;

        queen[level] = i;
        dfs(level+1);
    }
}

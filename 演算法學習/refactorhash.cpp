#include<iostream>
#include<iomanip>
#include<ctime>
#include<random>
#include<windows.h>
using namespace std;

const int MAXNUM = 7;
const int INDEXBOX = 10;
int index[INDEXBOX], data[MAXNUM];

bool rehash(int);

int main(){
    srand(time(NULL));
    cout << "Original Array: " << endl;

    for(int i=0;i<MAXNUM;i++){
        data[i] = rand()%20 + 1;
        cout << "[" << setw(2) << data[i] << "]" << endl;
    }

    for(int i=0;i<MAXNUM;i++){
        int pos;
        pos = data[i] % MAXNUM;
        int posmove = 1;
        //cout << pos << " ";

        while(!rehash(posmove)){
            posmove++;
        }

        //cout << pos << endl;
        index[pos] = data[i];
    }
    cout << endl << "Hash Table Complete!" << endl;
    for(int i=0;i<INDEXBOX;i++){
        if(!i%10) cout << endl;
        cout << i+1 << " => [" << setw(2) << index[i] << "]" << endl;
    }

    return 0;
}

bool rehash(int a){
    for(int i=0;i<INDEXBOX;i++)
        index[i] = -1;

    for(int i=0;i<MAXNUM;i++){
        Sleep(1000);
        int pos;
        pos = (data[i]+a)%INDEXBOX;
        cout << data[i] << " " << (data[i]+a)%INDEXBOX << " " << pos << endl;
        if(index[pos]!=-1) return false;

        index[pos] = data[i];
    }

    return true;
}

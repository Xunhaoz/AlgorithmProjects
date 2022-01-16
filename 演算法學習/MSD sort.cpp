#include<iostream>
#include<iomanip>
using namespace std;
int dataNum = 0;
int data[100];

void showData();
void MSD();

int main(){
    int inputData;

    while(cin>>inputData && inputData){
        data[dataNum++] = inputData;
    }

    MSD();

    showData();
    return 0;
}

void MSD(){
    for(int i=1;i<100;i*=10){

        int tmp[10][100];

        for(int j=0;j<10;j++){
            for(int k=0;k<100;k++){
                tmp[j][k] = 0;
            }
        }

        for(int j=0;j<dataNum;j++){
            int digit = (data[j]/i)%10;
            tmp[digit][j] = data[j];
        }

        int l=0;
        for(int j=0;j<10;j++){
            for(int k=0;k<100;k++){
                if(!tmp[j][k]) continue;
                data[l++] = tmp[j][k];
            }
        }
    }
}

void showData(){
    for(int i=0;i<dataNum;i++) cout << setw(3) << data[i];
    cout << endl;
}

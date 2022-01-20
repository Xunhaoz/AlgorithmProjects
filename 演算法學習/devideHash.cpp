#include<iostream>
using namespace std;
int primeTable[1000];
void makePrime();
int main(){
    makePrime();
    for(int i=0;i<1000;i++) cout << i << primeTable[i] << endl;
}
void makePrime(){

    for(int i=0;i<1000;i++){
        if(i == 0 or i == 1){
            primeTable[i] = 1;
            continue;
        }

        for(int j=i*2;j<1000;j+=i){
            primeTable[j] = 1;
        }

    }

}

#include<iostream>
#include<iomanip>
using namespace std;
int dataNum = 0;
int data[100];
void mergesort(int, int);
void showData();
int main(){
    int inputData;

    while(cin>>inputData && inputData){
        data[dataNum++] = inputData;
    }

    mergesort(0, dataNum);

    showData();
    return 0;
}
void mergesort(int a, int b){
    if(a<b-1){
        mergesort(a, (a+b)/2);
        mergesort((a+b)/2, b);
    }

    int tmp[100], flagS=a, flagB=(a+b)/2;
    for(int j=a, k=0;j<b;++j,++k){

        if(flagS<(a+b)/2 && flagB<b){

            if(data[flagS]>data[flagB]){
                tmp[k] = data[flagB];
                flagB++;
            }
            else{
                tmp[k] = data[flagS];
                flagS++;
            }

        }
        else if(flagS<(a+b)/2){
            tmp[k] = data[flagS];
            flagS++;
        }
        else{
           tmp[k] = data[flagB];
           flagB++;
        }

    }
/*
    for(int j=a,k=0;j<b;++j,++k){
        cout << tmp[k] << " ";
    }
    cout << "   ";
*/
    for(int j=a,k=0;j<b;++j,++k){
        data[j] = tmp[k];
    }
    cout << "a" << a << "b" << b << ": ";
    showData();

    if(a == 0 && b==dataNum) return;
}
void showData(){
    for(int i=0;i<dataNum;i++) cout << setw(3) << data[i];
    cout << endl;
}

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;
int data[100];
void showData();
int main(){
    srand(time(NULL));
    for(int i=0;i<100;i++){
        data[i] = rand()%150;
    }

    cout << "data searching ..." ;
    int findData;
    while(cin >> findData && findData != -1){
        for(int i=0;i<100;i++){
            if(data[i] == findData){
                cout << "position of " << setw(3) << findData << " is at " << setw(2) << i << endl;
                break;
            }
            if(i ==  99) cout << "No data is " << setw(3) << findData << endl;
        }
    }

    showData();
    return 0;
}
void showData(){

    cout << endl << "data: ";
    for(int i=0;i<100;i++){
        if(i%10 == 0) cout << endl;
        cout  << setw(2) << i << "[" << setw(3) << data[i] << "] ";

    }
    cout << endl;
}

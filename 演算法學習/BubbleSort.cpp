#include<iostream>
#include<iomanip>
using namespace std;
int data[] = {6, 5, 9, 7, 2, 8};
int main(){
    cout << "bubble sort:" << endl;
    cout << "original data: ";

    for(int j=0;j<6;j++) cout << setw(3) << data[j];
    cout << endl << endl;

    for(int i=1;i<6;i++){
        for(int j=0;j<5;j++){

            if(data[j] > data[j+1]){
                int tmp = 0;
                tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }

        }
        cout << "sort " << i << " times: ";
        for(int j=0;j<6;j++) cout << setw(3) << data[j];
        cout  << endl;
    }
    return 0;
}

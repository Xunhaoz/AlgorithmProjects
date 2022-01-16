#include<iostream>
#include<iomanip>
using namespace std;
void showData();
int data[] = {4, 6, 1, 8, 10, 32};
int completeData[6];
int main(){
    cout << "insert sort" << endl;
    cout << "original data: ";

    for(int i=0;i<6;i++) cout << data[i] << " ";
    cout << endl;

    for(int i=0;i<6;i++){
        cout << i+1 << " times: " << data[i] << endl;
        for(int j=0;j<6;j++){
            if(data[i]<completeData[j]){

                for(int k=5;k>j;k--){
                    completeData[k] = completeData[k-1];
                }

                completeData[j] = data[i];
                break;
            }

            if(i == j){
                completeData[j] = data[i];
                break;
            }
        }
        cout << "After Sort :";
        showData();
    }

    return 0;
}
void showData(){
    for(int i=0;i<6;i++){
        cout << setw(3) << completeData[i];
    }
    cout << endl;
}

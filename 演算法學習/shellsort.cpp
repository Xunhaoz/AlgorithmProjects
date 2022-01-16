#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int data[] = {5, 65, 1, 45, 32, 67, 89, 12};

void showData();

int main(){
    cout << "Shell Sort";
    cout << "Original Data: ";
    showData();

    int jump = 8/2;
    int k=0;
    while(jump != 0){
        for(int i=jump;i<8;i++){
            int tmp = data[i];
            int j=i-jump;
            while(tmp<data[j] && j>=0){
                data[j+jump] = data[j];
                j=j-jump;
            }
            data[jump+j]=tmp;
        }

        cout << "sort " << ++k << " times: ";
        showData();
        jump/=2;
    }

    return 0;
}

void showData(){
    for(int i=0;i<8;i++)
        cout << setw(3) << data[i];
    cout << endl;
}

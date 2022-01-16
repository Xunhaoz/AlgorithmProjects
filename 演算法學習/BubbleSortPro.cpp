#include<iostream>
#include<iomanip>
using namespace std;
void bubble();
void showData();
int data[] = {4, 6, 2, 7, 8, 9};
int main(){
    cout << "bubble sort pro" << endl;
    cout << "original data: ";

    showData();
    bubble();

    return 0;
}
void bubble(){
    for(int i=1;i<6;i++){
        int flag = 0;
        for(int j=0;j<6-i;j++){
            if(data[j] > data[j+1]){
                int tmp = 0;
                tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
                flag = 1;
            }
        }
        cout << "sort " << i << " times: ";
        showData();

        if(flag==0) break;
    }
}
void showData(){
    for(int i=0;i<6;i++){
        cout << setw(3) << data[i];
    }
    cout << endl;

}

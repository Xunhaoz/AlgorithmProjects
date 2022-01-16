#include<iostream>
#include<iomanip>
using namespace std;
int data[] = {9, 7, 5, 3, 4, 6};
void showData();
int main(){
    cout << "select sort" << endl;
    cout << "original data: ";
    showData();
    for(int i=1;i<6;i++){

        for(int j=i;j<6;j++){

            if(data[i-1] > data[j]){
                int tmp = data[j];
                data[j] = data[i-1];
                data[i-1] = tmp;
            }

        }

        cout << "sort " << i << " times: ";
        showData();

    }
    return 0;
}

void showData(){
    for(int i=0;i<6;i++){
        cout << setw(3) << data[i];
    }
    cout << endl;

}

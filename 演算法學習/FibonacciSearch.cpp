#include<iostream>
#include<iomanip>
using namespace std;
int data[] = {37, 55, 76, 93, 109, 127, 140, 155, 167, 180, 193, 201, 211, 219, 224, 230, 236, 240, 242, 243};
int fib[100] = {0, 1};

void fibsearch(int);
void showData();

int main(){
    for(int i=2;i<100;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    cout << "data searching ..." ;
    int findData;


    while(cin >> findData && findData != -1){
        fibsearch(findData);
    }

    showData();

    return 0;
}

void showData(){

    cout << endl << "data: ";
    for(int i=0;i<20;i++){
        if(i%10 == 0) cout << endl;
        cout  << setw(2) << i << "[" << setw(3) << data[i] << "] ";

    }
    cout << endl;
}

void fibsearch(int a){
    int index = 2;
    while(fib[index] <= 20) index++;

    index--;
    int root = fib[index];
    int diff1 = fib[index-1];
    int diff2 = root - diff1;
    root--;

    while(1){
        if(a == data[root]){
            cout << "position of " << setw(3) << a << " is at " << setw(2) << root << endl;
            return;
        }

        else{
            if(index == 2){

                cout << "No data is " << setw(3) << a << endl;
                return;
            }

            else if(a < data[root]){
                root = root - diff2;
                int tmp = diff1 - diff2;
                diff1 = diff2;
                diff2 = tmp;
                index--;
            }
            else{
                if(index == 3){
                    cout << "No data is " << setw(3) << a << endl;
                    return;
                }
                root = root + diff2;
                diff1 = diff1 - diff2;
                diff2 = diff2 - diff1;
                index -= 2;
            }

        }

    }
}

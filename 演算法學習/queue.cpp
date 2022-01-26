#include<iostream>
#include<iomanip>
using namespace std;

int queue[100];
int f=0, b=0;

int main(){
    int userin;

    cout << "1.add  2.pop  3.isEmpty\n";
    cout << "=======================\n";

    while(1){
        cout << "=======================\n";
        cout << "Please input function: ";
        cin >> userin;
        if(userin == 1){
            cout << "Please input data: ";
            cin >> queue[b++];
        }
        else if(userin == 2){
            if(f == b)
                cout << "It is empty" << endl;
            else
                cout << queue[f++] << endl;
        }
        else if(userin == 3){
            if(f == b)
                cout << "It is empty" << endl;
            else
                cout << "It is not empty" << endl;
        }
        else
            continue;

    }
}

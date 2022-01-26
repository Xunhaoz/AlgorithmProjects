#include<iostream>
using namespace std;

int stack[100];
int flag = 0;

bool isEmpty();
bool push(int);
bool pop();

int main(){
    string userInput;
    cout << "Program start." << endl;
    while(1){
        cout << "1.exit  2.push  3.pop  4.isEmpty" << endl;
        cout << "User input: ";
        cin >> userInput;
        if(userInput == "exit"){
            break;
        }
        else if(userInput == "push"){
            int data;
            cout << "Input data: ";
            cin >> data;
            if(push(data)){
                cout << "Push Successful" << endl;
            }
            else cout << "Faild" << endl;
            cout << endl;
        }
        else if(userInput == "pop"){
            pop();
            cout << endl;
        }
        else if(userInput == "isEmpty"){
            cout << (isEmpty() ? "There's some data in stack." : "Stack is empty") << endl;
            cout << endl;
        }
        else
            cout << "Please input again." << endl;
    }
    cout << "Program is closed." << endl;
    return 0;
}

bool push(int a){
    if(flag == 100) return 0;
    stack[flag++] = a;
    return 1;
}

bool pop(){
    if(flag == 0){
        cout << "There's no data in stack." << endl;
        return 0;
    }
    cout << "Data at top: " << stack[--flag] << endl;
    return 1;

}
bool isEmpty(){
    return !(flag == 0);
}

#include<iostream>
using namespace std;
struct linkedlist{
    int val;
    struct linkedlist *next;
    struct linkedlist *pre;
};

typedef struct linkedlist node;
typedef node *link;

link head = NULL, tmp = NULL, newnode = NULL;

void init(int);
void push(int);
int pop();
bool isEmpty();

int main(){
    string userInput;
    while(1){
        cout << "Please input function." << endl;
        cin >> userInput;

        if(userInput == "-1")
            break;

        else if(userInput == "1"){
            int data;
            cout << "Input push data: ";
            cin >> data;
            push(data);
        }

        else if(userInput == "2"){
            cout << pop() << endl;

        }

        else if(userInput == "3"){
            cout << (isEmpty() ? "It is empty." : "It is not empty." ) << endl;
        }

        else
            continue;


    }

    return 0;
}

void init(int a){
    head = new node;
    head->val = a;
    head->next = NULL;
    head->pre = NULL;
    tmp = head;
}

bool isEmpty(){
    return (head == NULL);
}

void push(int a){
    if(isEmpty()){
        init(a);
    }
    else{
        newnode = new node;
        newnode->val = a;
        newnode->next = NULL;
        newnode->pre = tmp;
        tmp->next = newnode;
        tmp = newnode;
        newnode = NULL;
    }
}

int pop(){

    if(tmp == NULL){
        return -1;
    }

    int data;
    data = tmp->val;

    if(tmp == head){
        head = NULL;
        tmp = NULL;
        newnode = NULL;
        return data;
    }

    newnode = tmp->pre;
    tmp->pre = NULL;
    tmp->val = NULL;
    tmp->next = NULL;
    tmp = newnode;
    newnode = NULL;
    tmp->next = NULL;

    return data;
}

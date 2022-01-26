#include<iostream>
using namespace std;

struct linkedlist{
    int num;
    struct linkedlist *next;
    struct linkedlist *pre;
};
typedef struct linkedlist node;
typedef node *link;

link head = NULL, tmp = NULL, newnode = NULL;

int main(){
    int userin;

    cout << "1.add  2.pop front  3.pop back  4.isEmpty\n";

    while(1){
        cout << "=========================================\n";
        cout << "Please input function: ";
        cin >> userin;
        if(userin == 1){
            cout << "Please input data: ";
            cin >> userin;

            if(head == NULL){
                head = new node;
                head->next = NULL;
                head->pre = NULL;
                head->num = userin;
                tmp = head;
            }
            else{
                newnode = new node;
                newnode->next = NULL;
                newnode->num = userin;
                newnode->pre = tmp;
                tmp->next = newnode;
                tmp = newnode;
                newnode = NULL;
            }
        }
        else if(userin == 2){
            if(head == NULL || tmp == NULL){
                cout << "It is empty" << endl;
                head = NULL, tmp = NULL;
            }
            else{
                cout << head->num << endl;
                head = head->next;
                head->pre = NULL;
            }
        }
        else if(userin == 3){
            if(head == NULL || tmp == NULL){
                cout << "It is empty" << endl;
                head = NULL, tmp = NULL;
            }
            else{
                cout << tmp->num << endl;
                tmp = tmp->pre;
                tmp->next = NULL;

            }
        }
        else if(userin == 4){
            if(head == NULL)
                cout << "It is empty" << endl;
            else
                cout << "It is not empty" << endl;
        }
        else
            continue;

    }
    return 0;
}


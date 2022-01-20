#include<iostream>
#include<ctime>
#include<random>
#include<iomanip>
using namespace std;

struct linkedlist{
    int val;
    struct linkedlist *next;ik
};

typedef linkedlist node;
typedef node *link;
node indexbox[7];
int data[20] = {0, 1, 2, 3, 4, 5, 6};
void addlink(int);

int main(){
    addlink(0);
    addlink(1);
    addlink(2);
    addlink(3);
    addlink(4);
    addlink(5);
    addlink(6);

    for(int i=0;i<6;i++){
        cout << i;
        link head = new node;
        *head = indexbox[i];
        head = head->next;
        cout << "[" << head->val << "]" << endl;

    }

    return 0;
}

void addlink(int i){
    int pos = data[i]%7;

    link head = new node;
    link newnode = new node;

    *head = indexbox[pos];

    newnode->next = NULL;
    newnode->val = data[i];

    while(head->next != NULL){
        head = head->next;
    }
    head->next = newnode;
    head = head->next;
    cout << head->val << " ";
}

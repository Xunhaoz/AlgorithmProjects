#include<iostream>
using namespace std;

struct linkedlist{
    int coef, exp;
    struct linkedlist *next;
};

typedef struct linkedlist node;
typedef node *link;
int dataA[4] = {3, 0, 4, 2};
int dataB[4] = {6, 8, 6, 9};
link headA, headB, head, newnode, ptr;

void addnode();
void list();

int main(){
    addnode();

    list();

    return 0;
}

void addnode(){
    headA = new node;
    headA->coef = dataA[0];
    headA->exp = 3;
    headA->next = NULL;
    ptr = headA;
    for(int i=1;i<4;i++){
        newnode = new node;
        newnode->coef = dataA[i];
        newnode->exp = 3-i;
        ptr->next = newnode;
        ptr = ptr->next;
    }

    headB = new node;
    headB->coef = dataB[0];
    headB->exp = 3;
    headB->next = NULL;
    ptr = headB;
    for(int i=1;i<4;i++){
        newnode = new node;
        newnode->coef = dataB[i];
        newnode->exp = 3-i;
        ptr->next = newnode;
        ptr = ptr->next;
    }

    head = new node;
    head->coef = dataB[0] + dataA[0];
    head->exp = 3;
    head->next = NULL;
    ptr = head;
    for(int i=1;i<4;i++){
        newnode = new node;
        newnode->coef = dataB[i] + dataA[i];
        newnode->exp = 3-i;
        ptr->next = newnode;
        ptr = ptr->next;
    }
}

void list(){
    ptr = headA;
    for(int i=0;i<4;i++){
        cout << ptr->coef << "^" << ptr->exp << " ";
        ptr = ptr->next;
    }
    cout << endl;
    ptr = headB;
    for(int i=0;i<4;i++){
        cout << ptr->coef << "^" << ptr->exp << " ";
        ptr = ptr->next;
    }
    cout << endl;
    ptr = head;
    for(int i=0;i<4;i++){
        cout << ptr->coef << "^" << ptr->exp << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

#include<iostream>
using namespace std;

struct linkedlist{
    int num;
    struct linkedlist *next;
};
typedef struct linkedlist data;
typedef data *link;

link head, tmp, newdata;

void reversedata();
void init();
void addlist(int);
void listlist();
void insert(int, int);
void deletedata(int);

int main(){

    init();
    while(1){
        cout << "\nCommom: \n";
        cout << "========================================\n";
        cout << "1.list  2.add  3.del  4.insert  5.exit  6.reverse\n";

        string userinput;
        cin >> userinput;
        if(userinput == "add"){
            int add;
            cout << "Input Data: \n";
            cin >> add;
            addlist(add);
            cout << "Add Successful!" << endl;
        }
        else if(userinput == "del"){
            int del;
            cout << "Del Data: \n";
            cin >> del;
            deletedata(del);
            cout << "Delete Successful!" << endl;
        }
        else if(userinput == "insert"){
            int add, where;
            cout << "Insert Data: \n";
            cin >> add;
            cout << "Insert Pos: \n";
            cin >> where;
            insert(add, where);
            cout << "insert Successful!" << endl;
        }
        else if(userinput == "exit"){
            break;
        }
        else if(userinput == "list"){
            listlist();
        }
        else if(userinput == "reverse"){
            reversedata();
            cout << "Reverse Success\n";
        }
        else{
            cout << "input again\n";
        }
    }
    return 0;
}

void init(){
    head = new data;
    head->next = NULL;
    head->num = -1;
}

void addlist(int a){
    newdata = new data;
    newdata->num = a;
    newdata->next = NULL;
    tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newdata;
}

void listlist(){
    tmp = head;
    while(tmp->next != NULL){
        cout << "{" << tmp->num << "} -- ";
        tmp = tmp->next;
    }

    cout << "{" << tmp->num << "}" << endl;
}

void insert(int a, int b){
    int i = 1;
    tmp = head;
    while(tmp->next != NULL){
        if(i>=b) break;
        i++;
        tmp = tmp->next;
    }

    newdata = new data;
    newdata->num = a;
    newdata->next = tmp->next;
    tmp->next = newdata;
}

void deletedata(int a){
    tmp = head;
    while(tmp->next != NULL){
        newdata = tmp->next;
        if(newdata->num == a){
            tmp->next = newdata->next;
        }
        tmp = tmp->next;
    }
}

void reversedata(){
    tmp = head;//begin
    head = head->next;//next
    tmp->next = NULL;//NULL
    while(head->next != NULL){
        newdata = head;//copy
        head = head->next;//next
        newdata->next = tmp;
        tmp = newdata;
    }
    head->next = tmp;

}

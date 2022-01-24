#include<iostream>
using namespace std;

class list{
    public:
    int number, grade;
    string name;
    class list *next;
};
typedef class list node;
typedef node *link;

int main(){
    link del, ptr, newnode;
    cout << "Please input five students data: " << endl;

    del = new node;
    if(!del) cout << "Error! memory distribute failed!"<<endl;

    cout << "Student number: ";
    cin >> del->number;
    cout << "Student name: ";
    cin >> del->name;
    cout << "Student score: ";
    cin >> del->grade;
    del->next = NULL;
    ptr = del;
    for(int i=0;i<4;i++){
        newnode = new node;
        if(!newnode) cout << "Error! memory distribute failed!"<<endl;

        cout << "Student number: ";
        cin >> newnode->number;
        cout << "Student name: ";
        cin >> newnode->name;
        cout << "Student score: ";
        cin >> newnode->grade;
        newnode->next = NULL;
        ptr->next = newnode;
        ptr = ptr->next;
    }

    cout << "Students grade:" << endl;
    ptr = del;
    cout << "\n    Student Score    \nnumber\tname\tscore\n";
    for(int i=0;i<5;i++){


        cout << ptr->number << "\t" << ptr->name << "\t" << ptr->grade << "\n";
        ptr = ptr->next;
    }
    return 0;
}

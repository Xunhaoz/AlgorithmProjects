#include<iostream>
#include<ctime>
#include<iomanip>
#include<random>
#define INDEXBOX 7
#define MAXNUM 13
using namespace std;

class list{
    public:
    int val;
    class list *next;
};
typedef class list node;
typedef node *link;
node indextable[MAXNUM];

void creat_table(int);
void print_data(int);
int find_num(int);

int main(){
    int i, num, data[MAXNUM];
    srand((unsigned)time(NULL));

    for(int i=0;i<INDEXBOX;i++){
        indextable[i].next = NULL;
        indextable[i].val = i;
    }
    cout << "Original data:\n\t";

    for(int i=0;i<MAXNUM;i++){
        data[i] = rand()%89 + 11;
        cout << "[" << setw(2) << data[i] << "]  ";
        if(i%8==7) cout << "\n\t";
    }
    cout << endl;

    for(int i=0;i<MAXNUM;++i) creat_table(data[i]);
    cout << "\nHash Table:\n";
    for(int i=0;i<INDEXBOX;++i) print_data(i);
    int search;
    while(1){
        cout << "Input data: ";

        if(!(cin >> search && search)) break;

        if(find_num(search) == 0)
            cout << setw(2) << search  << " can't find." << endl;
        else
            cout << setw(2) << search  << " level is " << find_num(search) << endl;
    }

    return 0;
}

void creat_table(int val){

    link newnode;
    int hash = val%7;

    newnode = (link)new node;
    if(!newnode) cout << "memory distribute error!" << endl;
    newnode->val = val;
    newnode->next = NULL;
    newnode->next = indextable[hash].next;
    indextable[hash].next = newnode;
}
void print_data(int val){
    link head;
    head = indextable[val].next;
    cout << setw(2) << val << ":\t";
    while(head!=NULL){
        cout << "[" << setw(2) << head->val << "]-";
        head = head->next;
    }
    cout << "\b " << endl;
}
int find_num(int val){
    link current;
    int i=0, hash = val%7;
    current = indextable[hash].next;
    while(current!=NULL){
        i++;

        if(current->val == val)
            return i;

        else
            current = current->next;

    }
    return 0;
}

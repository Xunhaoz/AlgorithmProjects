#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
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
node indextable[INDEXBOX];


void creat_table(int);
void print_table(int);

int main(){
    int i, data[MAXNUM];
    srand((unsigned)time(NULL));

    for(int i=0;i<INDEXBOX;i++){
        indextable[i].val = -1;
        indextable[i].next = NULL;
    }

    cout << "Original data:\n\t";
    for(int i=0;i<MAXNUM;++i){
        data[i] = rand()%30+1;
        cout << "[" << setw(2) << data[i] << "]";
        if(i%8 == 7) cout << "\n\t";
    }

    cout << "\nHash Table:\n";
    for(int i=0;i<MAXNUM;++i) creat_table(data[i]);

    for(int i=0;i<INDEXBOX;++i) print_table(i);

    cout << "\n";

    return 0;
}

void creat_table(int val){
    link newnode;
    link current;
    int hash;
    hash = val%7;
    newnode = (link)malloc(sizeof(node));
    current = (link)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    *current = indextable[hash];
    if(current->next == NULL)
        indextable[hash].next = newnode;
    else{
        while(current->next != NULL){
            current = current->next;
        }
    }
    current->next = newnode;
}
void print_table(int val){
    link head;
    int i = 0;
    head = indextable[val].next;
    cout << "   " << setw(2) << val << ":\t";
    while(head!=NULL){
        cout << "[" << setw(2) << head->val << "]-";
        head = head->next;
    }
    cout << "\b \n";
}

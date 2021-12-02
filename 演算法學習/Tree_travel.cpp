#include<iostream>
#include<iomanip>
using namespace std;
class tree
{
    public:
        int data;
        class tree *left, *right;
};
typedef class tree node;
typedef node *btree;
btree creat_btree(btree, int);
void pre(btree);
void in(btree);
void post(btree);
int main(){
    int arr[] = {7,8,1,5,16,8,11,12,15,9,2};
    btree ptr= NULL;
    cout<<"原序：";
    for(int i=0;i<11;i++){
        ptr = creat_btree(ptr, arr[i]);
        cout<<"["<<setw(2)<<arr[i]<<"] ";
    }
    cout<<endl;

    cout<<"前序：";
    pre(ptr);
    cout<<endl<<"中序：";
    in(ptr);
    cout<<endl<<"後序：";
    post(ptr);

    return 0;

}
btree creat_btree(btree root, int val){
    btree newnode, current, backup;
    newnode = new node;
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    if(root == NULL){
        root = newnode;
        return root;
    }
    else{
        for(current=root;current!=NULL;){
            backup = current;
            if(current->data > val){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        if(backup->data > val)
            backup->left = newnode;
        else
            backup->right = newnode;
    }
    return root;
}
void pre(btree ptr){
    if(ptr != NULL){
        cout<<"["<<setw(2)<<ptr->data<<"] ";
        pre(ptr->left);
        pre(ptr->right);
    }
}
void in(btree ptr){
    if(ptr != NULL){
        in(ptr->left);
        cout<<"["<<setw(2)<<ptr->data<<"] ";
        in(ptr->right);
    }
}
void post(btree ptr){
    if(ptr != NULL){
        post(ptr->left);
        post(ptr->right);
        cout<<"["<<setw(2)<<ptr->data<<"] ";
    }
}

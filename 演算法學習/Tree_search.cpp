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
btree bin_search(btree, int);
int main(){
    int data, arr[] = {7,4,1,5,13,8,11,12,15,9,2};
    btree ptr= NULL;
    cout<<"[Original Array Data]"<<endl;
    for(int i=0;i<11;i++){
        ptr = creat_btree(ptr, arr[i]);
        cout<<"["<<setw(2)<<arr[i]<<"] ";
    }
    cout<<endl;

    cout<<"Please enter the data which you want to search."<<endl;
    cin>>data;

    if(bin_search(ptr, data) != NULL)
        cout<<"Data "<<setw(2)<<data<<" is found!"<<endl;
    else
        cout<<"No Data"<<endl;


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
btree bin_search(btree ptr, int val){
    int i = 1;
    while(1){
        if(ptr == NULL)
            return NULL;
        if(ptr->data == val){
            cout<<"It takes"<<setw(3)<<i<<" times"<<endl;
            return ptr;
        }
        else if(ptr->data > val)
            ptr = ptr->left;
        else
            ptr = ptr->right;
        i++;
    }
}

#include<iostream>
#include<cstdlib>
#include<iomanip>
#define ArraySize 10
using namespace std;

class Node
{
public:
    int value;
    struct Node *left_Node;
    struct Node *right_Node;
};

typedef class Node TreeNode;// 二元樹節點資料型態
typedef TreeNode *BinaryTree;// 二元樹鏈結資料型態
BinaryTree rootNode;// 根指標
void Add_Node_To_Tree(int value);

int main(){
    int tempta;
    int content[ArraySize];
    cout<<"十筆資料排續"<<endl;
    for(int i=0;i<ArraySize;i++){
        cout<<"請輸入第"<<setw(2)<<(i+1)<<"筆資料";
        cin>>tempta;
        content[i] = tempta;
    }
    for(int i=0;i<ArraySize;i++)
        Add_Node_To_Tree(content[i]);
    cout<<"Success";
    return 0;
}
void Add_Node_To_Tree(int value){
    BinaryTree currentNode;
    BinaryTree newnode;
    int flag = 0; // is_insert?
    newnode = (BinaryTree) malloc(sizeof(TreeNode));

    newnode->value = value;
    newnode->left_Node = NULL;
    newnode->right_Node = NULL;

    // is_root?
    if(rootNode == NULL)
        rootNode = newnode;
    else{
        currentNode = rootNode;
        while(!flag){
            // left sub-tree
            if(value<currentNode->value){
                if(currentNode->left_Node == NULL){
                    currentNode->left_Node = newnode;
                    flag = 1;
                }
                else
                    currentNode = currentNode->left_Node;
            }
            // right sub-tree
            else{
                if(currentNode->right_Node == NULL){
                    currentNode->right_Node = newnode;
                    flag = 1;
                }
                else
                    currentNode = currentNode->right_Node;
            }

        }
    }

}


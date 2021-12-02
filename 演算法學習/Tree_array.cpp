#include<iostream>
using namespace std;
int main(){
    int level;
    // original data
    int data[] = {0,6, 3, 5, 9, 7, 8, 4, 2};
    // tree by array
    int btree[16] = {0};

    for(int i=1;i<9;i++)
        cout<<"["<<data[i]<<"]";
    cout<<endl;

    // traversal original data
    for(int i=0;i<9;i++){

        // compare to data which is already in tree
        for(level=1;btree[level]!=0;){
            // according to 陣列與索引值的關係
            if(data[i]>btree[level])
                level = level*2+1;
            else
                level = level*2;
        }
        btree[level] = data[i];

    }

    for(int i=1;i<16;i++)
        cout<<"["<<btree[i]<<"]";

    return 0;
}

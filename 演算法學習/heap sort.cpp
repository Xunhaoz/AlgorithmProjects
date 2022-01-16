#include<iostream>
#define IFN 1e9
using namespace std;

int heap[100], dataNum = 0, data[100];

void heapsort();
void showdata();
void change(int*, int*);

int main(){
    int input;
    while(cin>>input && input){
        heap[dataNum++] = input;
    }

    heapsort();
    showdata();


    return 0;
}

void heapsort(){
    int flag = 0;
    while(1){

        for(int i=0;i<dataNum;i++){
            if(!i) continue;

            int tmp = i;
            while(tmp){
                if(heap[tmp] < heap[(tmp-1)/2]){
                    change(&heap[tmp], &heap[(tmp-1)/2]);
                    tmp = (tmp-1)/2;
                }
                else break;
            }
        }
        data[flag++] = heap[0];
        if(heap[0] == IFN) break;
        heap[0] = IFN;
    }
}

void showdata(){
    for(int i=0;i<dataNum;++i){
        cout << data[i] << " ";
    }
    cout << endl;

}

void change(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

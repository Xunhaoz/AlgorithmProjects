#include<iostream>
#include<iomanip>
using namespace std;
int data[] = {32, 5, 24, 55, 40, 81, 17, 48, 25, 71};
int process=0;
void quick(int ,int);
void show(int);

int main(){

    quick(0, 9);
    show(++process);

    return 0;
}

void quick(int lf, int rg){
    int lf_index, rg_index;
    if(lf < rg){
        lf_index = lf+1;
        rg_index = rg;
    }
    else return;
    while(1){
        show(++process);
        for(int i=lf+1;i<=rg;i++){
            if(data[i]>=data[lf]){
                lf_index = i;
                break;
            }
            lf_index++;
        }
        for(int i=rg;i>=lf+1;i--){
            if(data[lf]>=data[i]){
                rg_index = i;
                break;
            }
            rg_index--;
        }
        if(lf_index < rg_index){
            int tmp;
            tmp = data[rg_index];
            data[rg_index] = data[lf_index];
            data[lf_index] = tmp;
        }
        else break;
    }

    if(lf_index >= rg_index){
        int tmp;
        tmp = data[lf];
        data[lf] = data[rg_index];
        data[rg_index] = tmp;

        quick(lf, rg_index-1);
        quick(rg_index+1, rg);
    }

}

void show(int a){
    cout << "sort " << a << " times: ";
    for(int i=0;i<10;i++)
        cout << setw(3) << data[i];
    cout << endl;

}

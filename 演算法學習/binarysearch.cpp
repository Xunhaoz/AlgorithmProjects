
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;
int data[100];
void showData();
bool bsearch(int, int, int);
int main(){
    srand(time(NULL));
    for(int i=0;i<100;i++){
        data[i] = i*7 + (rand()%7);
    }

    cout << "data searching ..." ;

    int findData;
    while(cin >> findData && findData != -1){
        if(!bsearch(0, 100, findData))
            cout << "No data is " << setw(3) << findData << endl;
    }


    showData();
    return 0;
}

void showData(){

    cout << endl << "data: ";
    for(int i=0;i<100;i++){
        if(i%10 == 0) cout << endl;
        cout  << setw(2) << i << "[" << setw(3) << data[i] << "] ";

    }
    cout << endl;
}

bool bsearch(int a, int b, int c){
    int mid = (a + b)/2;

    if(a == b) return false;

    if(data[mid] == c){
        cout << "position of " << setw(3) << c << " is at " << setw(2) << mid << endl;
        return true;
    }

    else if(data[mid] < c) return bsearch(mid+1, b, c);

    else if(data[mid] > c) return bsearch(a, mid, c);
}

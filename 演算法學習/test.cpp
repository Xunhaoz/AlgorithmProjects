#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int i=20;
    int tmp;
    while(i--){
        tmp += rand()%5 + i;
        cout << tmp << ", ";
    }
}

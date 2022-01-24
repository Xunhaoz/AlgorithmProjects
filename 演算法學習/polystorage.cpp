#include<iostream>
#include<iomanip>
using namespace std;
int polyA[500];
int polyB[500];

int main(){
    int deg, tmp;

    cout << "Please input poly A's degree: ";
    cin >> deg;
    polyA[0] = deg;
    for(int i=deg;i>=0;i--){
        cout << "Please input x^" << i << ":  ";
        cin >> tmp;
        polyA[deg-i+1] = tmp;
    }

    cout << "Please input poly B's degree: ";
    cin >> deg;
    polyB[0] = deg;
    for(int i=deg;i>=0;i--){
        cout << "Please input x^" << i << ":  ";
        cin >> tmp;
        polyB[deg-i+1] = tmp;
    }

    cout << "poly A: " <<  "{";
    for(int i=0;i<=deg+1;i++){
        cout << polyA[i] << ", " ;
    }
    cout << "\b\b}" << endl;

    cout << "poly B: " <<  "{";
    for(int i=0;i<=deg+1;i++){
        cout << polyB[i] << ", " ;
    }
    cout << "\b\b}" << endl;

    cout << "poly A+B: " <<  "{";
    for(int i=0;i<=deg+1;i++){
        if(i==0){
            cout << max(polyA[i], polyB[i]) << ", " ;
            continue;
        }
        cout << polyA[i]+polyB[i] << ", " ;
    }
    cout << "\b\b}" << endl;
    return 0;
}

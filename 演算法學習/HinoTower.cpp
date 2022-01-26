#include<iostream>
#include<iomanip>
using namespace std;

void HinoTower(int, string, string, string);

int main(){

    int userinput;
    string a, b, c;

    cout << "Please Input plates' number: ";
    cin >> userinput;

    cout << "First tower: ";
    cin >> a;

    cout << "Second tower: ";
    cin >> b;

    cout << "Third tower: ";
    cin >> c;

    HinoTower(userinput, a, b, c);

    return 0;
}

void HinoTower(int n, string from, string by, string to){
    if(n == 1){
        cout << "From " << setw(3) << from << " move to " << setw(3) << to << endl;
        return;
    }

    HinoTower(n-1, from, to, by);

    cout << "From " << setw(3) << from << " move to " << setw(3) << to << endl;

    HinoTower(n-1, by, from, to);
}

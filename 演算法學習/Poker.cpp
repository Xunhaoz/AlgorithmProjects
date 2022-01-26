#include<iostream>
#include<ctime>
#include<random>
#include<iomanip>
using namespace std;
struct poker{
    int number, color; // num 1~13, color~1~4
};

struct poker cards[52];

void poker_init();
void makeRand();

int main(){

    srand((unsigned)time(NULL));
    cout << "[Preparing cards...]" << endl;
    poker_init();
    cout << "[Making random...]" << endl;
    makeRand();
    cout << "[Distributing...]" << endl;
    cout << "East\tNorth\tWest\tSouth" << endl;
    cout << "========================" << endl;

    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){

            cout << "[" << char(cards[i*4 + j].color + 32) ;
            cout << setw(2) << cards[i*4 + j].number << "]";
            cout << "\t";
        }
        cout << endl;
    }

    return 0;
}
void poker_init(){
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            cards[i*13 + j].number = j+1;
            cards[i*13 + j].color = i+1;
        }
    }
}
void makeRand(){
    for(int i=0;i<52;i++){
        int change_pos = rand()%52;
        struct poker tmp;
        tmp = cards[i];
        cards[i] = cards[change_pos];
        cards[change_pos] = tmp;
    }
}

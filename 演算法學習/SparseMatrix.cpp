#include<iostream>
#include<iomanip>
#include<ctime>
#include<random>
using namespace std;

int matrix[10][10];
int compressionMatrix[3][10];

void prodeceMatrix(int);
void compression();

int main(){
    srand((unsigned)time(NULL));
    int a;
    cin >> a;
    prodeceMatrix(a);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << setw(3) << matrix[i][j];
        }
        cout << endl;
    }

    compression();

    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            cout << setw(3) << compressionMatrix[i][j];
        }
        cout << endl;
    }

    return 0;
}

void prodeceMatrix(int a){

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            matrix[i][j] = 0;
        }
    }

    for(int i=0;i<a;i++){
        int x, y, tmp;
        x = rand()%10;
        y = rand()%10;
        tmp = rand()%100;
        matrix[x][y] = tmp;
    }

}

void compression(){
    int countNum = 0;
    compressionMatrix[0][0] = 10;
    compressionMatrix[1][0] = 10;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(!matrix[i][j]) continue;
            compressionMatrix[0][++countNum] = i;
            compressionMatrix[1][countNum] = j;
            compressionMatrix[2][countNum] = matrix[i][j];
        }
    }
    compressionMatrix[3][0] = countNum;
}

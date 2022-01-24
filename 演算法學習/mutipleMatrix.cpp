
#include<iostream>
#include<vector>
#include<ctime>
#include<random>
#include<iomanip>
using namespace std;

vector<int> MatrixA;
vector<int> MatrixB;
vector<int> MatrixAns;

void produce_Matrix(int a, int b){

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            int randomA = rand()%10;
            int randomB = rand()%10;
            MatrixA.push_back(randomA);
            MatrixB.push_back(randomB);
        }
    }
}

void printMatrix(vector<int> Matrix, int a, int b){
    for(int i=0;i<a*b;i++){
        if(i%b==0 && i) cout << '\n';
        cout << setw(3) << Matrix[i];

    }
}

void mutipleMatrix(int a, int b){

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            int tmp = 0;
            for(int k=0;k<a;k++){
                tmp += MatrixA[i*a+k] * MatrixB[j+k*b];
            }
            MatrixAns.push_back(tmp);
        }
    }
}

int main(){
    srand((unsigned)time(NULL));

    cout << "Input volume of Matrix: ";

    int high, weight;

    cin >> high >> weight;

    produce_Matrix(high, weight);

    mutipleMatrix(high, weight);

    cout << "\nFirst Matrix: \n";
    printMatrix(MatrixA, high, weight);

    cout << "\nSecond Matrix: \n";
    printMatrix(MatrixB, high, weight);

    cout << "\nAnswer Matrix: \n";
    printMatrix(MatrixAns, high, weight);

    return 0;
}

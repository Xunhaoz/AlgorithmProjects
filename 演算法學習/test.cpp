#include <iostream>
using namespace std;

const int N = 8;
int arr[10], total_cnt;
// arr記錄每一行(X)皇后的Y座標

bool isPlaceOK(int *a, int n, int c) {
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] == c || a[i] - i == c - n || a[i] + i == c + n)
            return false;
        //檢查位置是否可以放
        //c是將要放置的位置
        //a[i] == c如果放在同一列，false
        //a[i] -+ i = c -+ n 如果在對角線上，false
    }
    return true;
}

void printSol(int *a) {
    for (int i = 1; i <= N; ++i) { //遍歷每一行
        for (int j = 1; j <= N; ++j) { //遍歷每一列
            cout << (a[i] == j ? "X" : "-") << " ";;
        } //如果標記數組中這一行的皇后放在j位置，則輸出X，否則輸出-，
        //用空格分隔
        cout << endl; //每一行輸出一個換行
    }
    cout << endl; //每一組數據一個換行分隔
}

void addQueen(int *a, int n) {
    if (n > N) { //n代表從第一行開始放置
        printSol(a);
        total_cnt++;
        return ;
    }
    for (int i = 1; i <= N; ++i) { //i從第1列到第N列遍歷
        if (isPlaceOK(a, n, i)) {
            a[n] = i; //如果可以放置，就把皇后放在第n行第i列
            addQueen(a, n + 1);
        }
    }

}

int main() {
    addQueen(arr, 1);
    cout << "total: " << total_cnt << " solutions.\n";
    return 0;
}

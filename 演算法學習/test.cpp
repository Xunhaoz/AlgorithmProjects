#include <iostream>
using namespace std;

const int N = 8;
int arr[10], total_cnt;
// arr�O���C�@��(X)�ӦZ��Y�y��

bool isPlaceOK(int *a, int n, int c) {
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] == c || a[i] - i == c - n || a[i] + i == c + n)
            return false;
        //�ˬd��m�O�_�i�H��
        //c�O�N�n��m����m
        //a[i] == c�p�G��b�P�@�C�Afalse
        //a[i] -+ i = c -+ n �p�G�b�﨤�u�W�Afalse
    }
    return true;
}

void printSol(int *a) {
    for (int i = 1; i <= N; ++i) { //�M���C�@��
        for (int j = 1; j <= N; ++j) { //�M���C�@�C
            cout << (a[i] == j ? "X" : "-") << " ";;
        } //�p�G�аO�Ʋդ��o�@�檺�ӦZ��bj��m�A�h��XX�A�_�h��X-�A
        //�ΪŮ���j
        cout << endl; //�C�@���X�@�Ӵ���
    }
    cout << endl; //�C�@�ռƾڤ@�Ӵ�����j
}

void addQueen(int *a, int n) {
    if (n > N) { //n�N��q�Ĥ@��}�l��m
        printSol(a);
        total_cnt++;
        return ;
    }
    for (int i = 1; i <= N; ++i) { //i�q��1�C���N�C�M��
        if (isPlaceOK(a, n, i)) {
            a[n] = i; //�p�G�i�H��m�A�N��ӦZ��b��n���i�C
            addQueen(a, n + 1);
        }
    }

}

int main() {
    addQueen(arr, 1);
    cout << "total: " << total_cnt << " solutions.\n";
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* ¦r¦ê¤ÏÂà
template <typename T>
void swap(T *x, T *y){
    T tmp = *x;
    *x = *y;
    *y = T tmp;
}
template <typename T>
void swap(T *first, T *last){
    --last;
    while(first < last){
        swap(first, last);
        ++first;
        --last;
    }
}
*/

int moving(string);
int folding(string);
string streamstring(int);
int streamint(string);

int main(){

    string a;
    cin >> a;
    cout << moving(a) << endl;
    cout << folding(a) << endl;
    return 0;
}
int moving(string a){
    string tmp;
    int output = 0;
    for(int i=0;i<a.size();i++)
        tmp += streamstring(int(a[i]));

    for(int i=0;i<tmp.size();i+=4){
        output += streamint(tmp.substr(i, 4));
    }
    return output%10000;
}

int folding(string a){

    string tmp;
    int output = 0;
    for(int i=0;i<a.size();i++)
        tmp += streamstring(int(a[i]));
    bool oddTimes = 0;
    for(int i=0;i<tmp.size();i+=4){
        string b = tmp.substr(i, 4);
        if(oddTimes){
            reverse(b.begin(), b.end());
        }
        oddTimes = !oddTimes;
        output += streamint(b);
    }
    return output%10000;
}

string streamstring(int a){
    int tmp;
    string output;
    while(a>0){
        tmp = a%10;
        a = a/10;
        output += char(tmp + 48);
    }
    reverse(output.begin(), output.end());
    return output;
}

int streamint(string a){
    int output = 0;
    for(int i=a.size()-1, j=1;i>=0;i--, j*=10){
        output += (int(a[i])-48) * j;
    }
    return output;
}
//98 99 100 101

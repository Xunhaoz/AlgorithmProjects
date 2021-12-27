#include<bits/stdc++.h>
using namespace std;
struct point{
    double x, y;
};
point points[201], cl, cr;

void make_circle(point, point, double);
double scale(point a, point b);

int main(){

    int testcase;
    cin >> testcase;
    string line;
    getline(cin, line);
    getline(cin, line);

    while(testcase--){
        int n = 0, count_max = 0, countl, countr;

        while(getline(cin, line) && line.length() > 0){
            istringstream sttrm(line);
            sttrm >> points[n].x >> points[n].y;
            n++;
        }
        if(n) count_max = 1;


        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(scale(points[i], points[j]) <= 5){
                    make_circle(points[i], points[j], scale(points[i], points[j]));

                    countl = countr = 0;
                    for(int k=0;k<n;k++){
                        if(scale(cl, points[k]) < 2.5 + 1e-7) countl++;
                        if(scale(cr, points[k]) < 2.5 + 1e-7) countr++;
                    }
                    if(count_max < countl) count_max = countl;
                    if(count_max < countr) count_max = countr;
                }
            }
        }


        cout << count_max << endl;
        if(testcase != 0) cout << endl;
    }




    return 0;
}
void make_circle(point a, point b, double c){

    if(c <= 5){
        point fa;
        fa.x = (a.y - b.y)/c * sqrt(2.5*2.5 - c*0.5*c*0.5);
        fa.y = (b.x - a.x)/c * sqrt(2.5*2.5 - c*0.5*c*0.5);
        cl.x = (a.x + b.x)*0.5 + fa.x;
        cl.y = (a.y + b.y)*0.5 + fa.y;
        cr.x = (a.x + b.x)*0.5 - fa.x;
        cr.y = (a.y + b.y)*0.5 - fa.y;
    }

}
double scale(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

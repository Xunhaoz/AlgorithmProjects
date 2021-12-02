#include<bits/stdc++.h>
using namespace std;

typedef struct p_node
{
    int x, y;
}pnode;

typedef struct d_node
{
    int point1;
    int point2;
    double weight;
}enode;

pnode p[755];
enode edge[565000];
int smap[755][755];
int sets[755];
int rank_[755];

double dist(int, int);
void set_initial(int, int);
int set_find(int);
void set_union_(int, int);
int cmp_e(enode, enode);
double kruskal(int, int);

int main(){
    // n = 點量
    int n, m, a, b;
    while(scanf("%d", &n) != EOF){
        memset(smap, 0, sizeof(smap));
        for(int i=1;i<=n;++i){
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        scanf("%d", &m);
        for(int i=1;i<=m;++i){
            scanf("%d%d", &a, &b);
            smap[a][b] = smap[b][a] = 1;
        }
        // r = 邊量
        int r = 0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<i;++j){
               edge[r].point1 = i;
               edge[r].point2 = j;
               edge[r].weight = (!smap[i][j]) * dist(i, j);
               ++r;
            }
        }
        printf("%.2f\n", kruskal(n, r));
    }
    return 0;
}

double dist(int a, int b){
    return sqrt(0.0 + pow((p[a].x - p[b].x), 2) + pow((p[a].y - p[b].y), 2));
}
void set_initial(int a, int b){
    for(int i = a;i<=b;++i){
        rank_[i] = 0;
        sets[i] = i;
    }
}
int cmp_e(enode a, enode b){
    return a.weight < b.weight;
}
int set_find(int a){
    if(a != sets[a])
        sets[a] = set_find(sets[a]);
    return sets[a];
}
void set_union_(int a, int b){
    if(rank_[a] < rank_[b])
        sets[a] = b;
    else{
        if(rank_[a] == rank_[b])
            rank_[a]++;
        sets[b] = a;
    }
}
double kruskal(int n, int r){
    set_initial(1, n);
    sort( edge, edge + r, cmp_e);
    double sum = 0;
    for(int i=0;i<r;++i){
        int A = set_find( edge[i].point1 );
        int B = set_find( edge[i].point2 );
        if(A != B){
            set_union_(A, B);
            sum += edge[i].weight;
        }
    }
    return sum;
}

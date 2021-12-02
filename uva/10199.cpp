#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

vector<int> edge[105];
int dfs_clock, dfn[105], low[105];
map<string, int> Map;
string numToStr[105];
set<string> ans;

void Initial(int);
void dfs(int, int);

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, R, Case = 1;
    while(cin >> N && N){
        Initial(N);
        string name1, name2;
        for(int i=1;i<=N;++i){
            cin >> name1;
            Map[name1] = i;
            numToStr[i] = name1;
        }

        cin >> R;
        for(int i=0;i<R;++i){
            cin >> name1 >> name2;
            edge[Map[name1]].push_back(Map[name2]);
            edge[Map[name2]].push_back(Map[name1]);
        }

        for(int i=0;i<=N;++i)
            if(!dfn[i]) dfs(i, -1);

        if(Case != 1) cout<<endl;
        cout<<"City map #"<< Case++ <<": "<< ans.size() << " camera(s) found" << endl;
        for(set<string>::iterator iter=ans.begin();iter!=ans.end();++iter)
            cout<< *iter << endl;
    }
    return 0;
}
void Initial(int N){
    for(int i =0; i<=N; ++i){
        edge[i].clear();
        dfn[i] = low[i] = 0;
    }
    dfs_clock = 0;
    Map.clear();
    ans.clear();

}
void dfs(int cur, int parent){
    int child = 0;
    dfn[cur] = low[cur] = ++dfs_clock;

    for(int nxt : edge[cur]){
        if(!dfn[nxt]){
            ++child;
            dfs(nxt, cur);


            if((parent==-1 && child>1))
                ans.insert(numToStr[cur]);
        }
    }
}

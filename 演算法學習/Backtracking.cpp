#include<windows.h>
#include<iostream>
#include<fstream>
#define EAST maze[x][y+1]
#define WEST maze[x][y-1]
#define NORTH maze[x-1][y]
#define SOUTH maze[x+1][y]
using namespace std;
const int ExitX = 8, ExitY = 10;

struct list{
    int x, y;
    struct list *next;

};

typedef struct list node;
typedef node *link;
int maze[10][12];

link push(link stack, int x, int y);
link pop(link stack, int* x, int* y);
void init();
int chkExit(int, int, int, int);


int main(){
    init();

    link path = NULL;
    int x = 1, y = 1;

    cout << "[MAZE]:" << endl;

    for(int i=0;i<10;i++){
        for(int j=0;j<12;j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    while(x <= ExitX && y <= ExitY){
    /*
        Sleep(1000);
        for(int i=0;i<10;i++){
            for(int j=0;j<12;j++){
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    */
        maze[x][y] = 2;
        if(NORTH == 0){
            x -= 1;
            path = push(path, x, y);
        }

        else if(SOUTH == 0){
            x += 1;
            path = push(path, x, y);
        }

        else if(WEST == 0){
            y -= 1;
            path = push(path, x, y);
        }

        else if(EAST == 0){
            y += 1;
            path = push(path, x, y);
        }

        else if(chkExit(x, y, ExitX, ExitY))
            break;

        else{
            maze[x][y] = 2;
            path=pop(path, &x, &y);
        }

    }
    cout << "[FINAL MAZE]:" << endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<12;j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

void init(){
    ifstream ifs("MAZE.txt");
    for(int i=0;i<10;i++){
        for(int j=0;j<12;j++){
            ifs >> maze[i][j];
        }
    }
}

link push(link stack, int x, int y){
    link newnode;
    newnode = new node;

    if(!newnode){
        cout << "Error! memory distrube failed!" << endl;
        return NULL;
    }
    newnode->x = x;
    newnode->y = y;
    newnode->next = stack;
    stack = newnode;
    return stack;
}

link pop(link stack, int* x, int* y){
    link top;
    if(stack != NULL){
        top = stack;
        stack = stack->next;
        *x = top->x;
        *y = top->y;
        delete top;
        return stack;
    }

    else *x = -1;

    return stack;

}

int chkExit(int x, int y, int ex, int ey){
    if(x == ex && y == ey){
        if(NORTH+WEST+EAST+SOUTH == 5) return 1;
    }
    return 0;
}

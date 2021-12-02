#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  const int N_MAX_LIMIT = 10000000;
  bool isComposite[N_MAX_LIMIT + 5] = {true, true, false};
  for(int i = 2 ; i <= N_MAX_LIMIT ; ++i){
    if(isComposite[i]) continue;

    for(int j = i+i ; j <= N_MAX_LIMIT ; j += i){
      isComposite[j] = true;
    }
  } 

  int N;
  while(scanf("%d", &N) != EOF){
    if(N < 8){
       printf("Impossible.\n");
       continue;
    }

    if(N % 2 == 0){
      printf("2 2 ");
      N -= 4;
    }
    else{
      printf("2 3 ");
      N -= 5;
    }

    for(int i = 2 ; i <= N ; ++i){
      if(!isComposite[i] && !isComposite[N-i]){
        printf("%d %d\n", i, N-i);
        break;
      }
    }
  }
  return 0;
}

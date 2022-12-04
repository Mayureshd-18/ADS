#include <stdio.h>

int fibonacci_gen(int n){
    if(n<1)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibonacci_gen(n-1) + fibonacci_gen(n-2);
}
int min(int a, int b){
    if(a>b)
        return b;
    return a;
}
int fibonacci_search(int * arr, int val){
    int m = 0;
    while(fibonacci_gen(m)<5){
        m++;
    }
    int offset = -1;

    while(fibonacci_gen(m)>1){
        int i = min(offset+ fibonacci_gen(m-2),(sizeof(*arr)/sizeof(int)));
    }
}


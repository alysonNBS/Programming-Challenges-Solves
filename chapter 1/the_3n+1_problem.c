/*
* Section: 1.6.1
* Problem: The 3n+1 Problem
* UVa ID: 100
*
* Solve by @alysonNBS
*/

#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define MAX  1000100

int f(long long);
void swap(int*, int*);

int memo[MAX];

int main() {
    int i, j, answer;
    
    while(scanf("%d%d", &i, &j) != EOF) {
        answer = 0;

        printf("%d %d ", i, j);
        for(i>j ? swap(&i, &j) : 0; i<=j; i++)
            answer = max(answer, f(i));
        printf("%d\n", answer);
    }

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int f(long long n) {
    if(n == 1)
        return 1;
    if(n < MAX)
        return memo[n] ? memo[n] : (memo[n] = f( n % 2 ? 3*n + 1 : n>>1 ) + 1);
    return f( n % 2 ? 3*n + 1 : n>>1 ) + 1;
}

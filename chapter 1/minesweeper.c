/*
* Section: 1.6.2
* Problem: Minesweeper
* UVa ID: 10189
*
* Solve by @alysonNBS
*/

#include <stdio.h>

#define MAX 110

void reset_field(void);
void fill_square_field(int, int, char);
void print_field(void);

int n, m, field[MAX][MAX];

int main() {
    int x = 1;

    scanf("%d%*c%d%*c", &n, &m);
    while(n && m) {
        char line[m+1];
        int i, j;

        reset_field();
        for(i=0; i<n; i++) {
            scanf("%s%*c", line);

            for(j=0; j<m; j++)
                fill_square_field(i, j, line[j]);
        }
        printf("Field #%d:\n", x++);
        print_field();

        scanf("%d%*c%d%*c", &n, &m);
        if(n && m)
            putchar('\n');
    }

    return 0;
}

void reset_field() {
    int i, j;
    for(i=0; i<n; i++) for(j=0; j<m; j++) field[i][j] = 0;
}

void fill_square_field(int x, int y, char c) {
    if(c == '.')
        return;
    int i, j, _x, _y;
    int directions[] = {1, 0, -1};
    field[x][y] = -1;

    for(i = 0, _x = x + directions[0]; i<3; ++i, _x = x + directions[i])
        for(j = 0, _y = y + directions[0]; j<3; ++j, _y = y + directions[j])
            if(0 <= _x && _x < n && 0 <= _y && _y < m && field[_x][_y] + 1)
                field[_x][_y]++;
}

void print_field() {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) 
            field[i][j] + 1 ? printf("%d", field[i][j]) : putchar('*');
        putchar('\n');
    }
}

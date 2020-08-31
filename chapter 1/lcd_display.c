/*
* Section: 1.6.4
* Problem: LCD Display
* UVa ID: 706
*
* Solve by @alysonNBS
*/

#include <stdio.h>
#include <string.h>

#define MAXN 10

void print_number(int, char*);
char* itoa(int, char*);

char lcd_digits[][5][3] =   {   {
                                    {' ', '-', ' '},
                                    {'|', ' ', '|'},
                                    {' ', ' ', ' '},
                                    {'|', ' ', '|'},
                                    {' ', '-', ' '},
                                },
                                {
                                    {' ', ' ', ' '},
                                    {' ', ' ', '|'},
                                    {' ', ' ', ' '},
                                    {' ', ' ', '|'},
                                    {' ', ' ', ' '},
                                },
                                {
                                    {' ', '-', ' '},
                                    {' ', ' ', '|'},
                                    {' ', '-', ' '},
                                    {'|', ' ', ' '},
                                    {' ', '-', ' '},
                                },
                                {
                                    {' ', '-', ' '},
                                    {' ', ' ', '|'},
                                    {' ', '-', ' '},
                                    {' ', ' ', '|'},
                                    {' ', '-', ' '},
                                },
                                {
                                    {' ', ' ', ' '},
                                    {'|', ' ', '|'},
                                    {' ', '-', ' '},
                                    {' ', ' ', '|'},
                                    {' ', ' ', ' '},
                                },
                                {
                                    {' ', '-', ' '},
                                    {'|', ' ', ' '},
                                    {' ', '-', ' '},
                                    {' ', ' ', '|'},
                                    {' ', '-', ' '},
                                },
                                {
                                    {' ', '-', ' '},
                                    {'|', ' ', ' '},
                                    {' ', '-', ' '},
                                    {'|', ' ', '|'},
                                    {' ', '-', ' '},
                                },
                                {
                                    {' ', '-', ' '},
                                    {' ', ' ', '|'},
                                    {' ', ' ', ' '},
                                    {' ', ' ', '|'},
                                    {' ', ' ', ' '},
                                },
                                {
                                    {' ', '-', ' '},
                                    {'|', ' ', '|'},
                                    {' ', '-', ' '},
                                    {'|', ' ', '|'},
                                    {' ', '-', ' '},
                                },
                                {
                                    {' ', '-', ' '},
                                    {'|', ' ', '|'},
                                    {' ', '-', ' '},
                                    {' ', ' ', '|'},
                                    {' ', '-', ' '},
                                },
                            };

int main() {
    int s;
    char n[MAXN];

    while(scanf("%d%*[^0-9]%[0-9]%*c", &s, n) && s) {
        print_number(s, n);
        putchar('\n');
    }

    return 0;
}

void print_number(int s, char *n) {
    int i, j, k;
    for(i=0; i<5; i++) {
        if(!(i & 1)) {
            // print size(n) * (s + 3) - 1 columns in one line
            for(j=0; n[j]; j++) {
                putchar(' ');
                for(k=0; k<s; k++)
                    printf("%c", lcd_digits[ n[j]-'0' ][i][1]);
                putchar(' ');

                if(n[j+1])
                    putchar(' ');
            }
            putchar('\n');
        }
        else
            // print size(n) * (s + 3) - 1 columns in s lines 
            for(k = 0; k<s; k++) {
                for(j=0; n[j]; j++) {
                    char center_formated[10] = "%";
                    char s_string[10];

                    itoa(s, s_string);
                    strcat(center_formated, s_string);
                    strcat(center_formated, "s");

                    printf("%c", lcd_digits[ n[j]-'0' ][i][0]);
                    printf(center_formated, "");
                    printf("%c", lcd_digits[ n[j]-'0' ][i][2]);

                    if(n[j+1])
                        putchar(' ');
                }
                putchar('\n');
            }
    }            
}

char* itoa(int value, char *str) {
    int i, length;
    for(i=0; value; i++, value /= 10)
        str[i] = (value % 10) + '0';
    str[i] = 0;
    length = i;

    char aux;
    for(i=0; i < length>>1; i++)
        aux = str[i], str[i] = str[length-1-i], str[length-1-i] = aux;
    return str;
}

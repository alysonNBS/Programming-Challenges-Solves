/*
* Section: 1.6.6
* Problem: Interpreter
* UVa ID: 10033
*
* Solve by @alysonNBS
*/

#include <stdio.h>

int registers[10];
char ram[1000][4];
int instructions_size;
int current_instruction;
void (*encodings[10])(int, int);

void setup_encodings(void);
void reset_computer(void);
int read_instructions(void);
int execute_instructions(void);

int main() {
    int n;
    scanf("%d%*c", &n);
    setup_encodings();

    while (n--) {
        reset_computer();
        read_instructions();
        printf("%d\n%s", execute_instructions(), n ? "\n" : "");
    }

    return 0;
}

void e1(int, int);
void e2(int, int);
void e3(int, int);
void e4(int, int);
void e5(int, int);
void e6(int, int);
void e7(int, int);
void e8(int, int);
void e9(int, int);
void e0(int, int);

void setup_encodings() {
    encodings[0] = e0;
    encodings[1] = e1;
    encodings[2] = e2;
    encodings[3] = e3;
    encodings[4] = e4;
    encodings[5] = e5;
    encodings[6] = e6;
    encodings[7] = e7;
    encodings[8] = e8;
    encodings[9] = e9;
}

void reset_computer() {
    int i;
    for(i=0; i<10; i++)
        registers[i] = 0;
    for(i=0; i<1000; i++)
        ram[i][0] = ram[i][1] = ram[i][2] = '0',
        ram[i][3] = 0;
}

int read_instructions() {
    instructions_size = 0;

    scanf("%*c");
    while(scanf("%[0-9]%*c", ram+instructions_size++) == 1);

    return instructions_size;
}

int execute_instructions() {
    int instructions_executeds = 0;
    current_instruction = 0;

    while(current_instruction < 1000)
        encodings[ram[current_instruction][0] - '0'](ram[current_instruction][1] - '0', ram[current_instruction][2] - '0'),
        instructions_executeds++;
    
    return instructions_executeds;
}

void e1(int a, int b) {
    current_instruction = 1000;
}

void e2(int d, int n) {
    registers[d] = n;
    current_instruction++;
}

void e3(int d, int n) {
    registers[d] = (registers[d] + n) % 1000;
    current_instruction++;
}

void e4(int d, int n) {
    registers[d] = (registers[d] * n) % 1000;
    current_instruction++;
}

void e5(int d, int s) {
    registers[d] = registers[s];
    current_instruction++;
}

void e6(int d, int s) {
    registers[d] = (registers[d] + registers[s]) % 1000;
    current_instruction++;
}

void e7(int d, int s) {
    registers[d] = (registers[d] * registers[s]) % 1000;
    current_instruction++;
}

void e8(int d, int a) {
    registers[d] = (ram[registers[a]][0]-'0')*100 + (ram[registers[a]][1]-'0')*10 + (ram[registers[a]][2]-'0');
    current_instruction++;
}

void e9(int s, int a) {
    ram[registers[a]][0] = registers[s] / 100 + '0';
    ram[registers[a]][1] = (registers[s] % 100) / 10 + '0';
    ram[registers[a]][2] = registers[s] % 10 + '0';
    current_instruction++;
}

void e0(int d, int s) {
    if(registers[s])
        current_instruction = registers[d];
    else
        current_instruction++;
}

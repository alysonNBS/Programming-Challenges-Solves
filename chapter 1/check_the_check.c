/*
* Section: 1.6.7
* Problem: Check the Check
* UVa ID: 10196
*
* Solve by @alysonNBS
*/

#include <stdio.h>

#define valid(a, b) (0 <= a && a < 8 && 0 <= b && b < 8)

char board[8][9];

void read_board(void);
int board_empty(void);
int check_the_check(void);

int main() {
    int d=1;
    
    read_board();
    while (!board_empty()) {
        int check = check_the_check();
        printf("Game #%d: %s king is in check.\n", d++, check == 1 ? "white" : (check == -1 ? "black" : "no") );

        read_board();
    }
    return 0;
}

void read_board() {
    int i;
    for(i=0; i<8; i++)
        scanf("%[.pPnNbBrRqQkK]%*c", board[i]);
    scanf("%*c");
}

int board_empty() {
    int i, j;
    for(i=0; i<8; i++) for(j=0; j<8; j++) if(board[i][j] - '.')
        return 0;
    return 1;
}

// return 1 if white king is in check
// return -1 if black king is in check
// return 0 if no king is in check
int check_the_check() {
    int i, j, k;
    int knight_move[][2] = { {-2, -1},
                             {-2, 1},
                             {-1, -2},
                             {-1, 2},
                             {1, -2},
                             {1, 2},
                             {2, -1},
                             {2, 1},
    };

    for(i=0; i<8; i++) for(j=0; j<8; j++) if(board[i][j] == 'k') {
        int pieces_blocks[] = {0, 0, 0, 0, 0, 0, 0, 0};
        if((valid(i+1, j+1) && board[i+1][j+1] == 'P') || (valid(i+1, j-1) && board[i+1][j-1] == 'P'))
            return -1;
        
        if(valid(i+knight_move[0][0], j+knight_move[0][1]) && board[i+knight_move[0][0]][j+knight_move[0][1]] == 'N')
            return -1;
        for(k=1; k<8; k++)
            if(
                (valid(i+knight_move[k][0], j+knight_move[k][1]) && board[i+knight_move[k][0]][j+knight_move[k][1]] == 'N') ||
                (valid(i+k, j) && !(k == 1 ? 0 : (pieces_blocks[0] = board[i+(k-1)][j] != '.' ? 1 : pieces_blocks[0])) && (board[i+k][j] == 'R' || board[i+k][j] == 'Q')) ||
                (valid(i-k, j) && !(k == 1 ? 0 : (pieces_blocks[1] = board[i-(k-1)][j] != '.' ? 1 : pieces_blocks[1])) && (board[i-k][j] == 'R' || board[i-k][j] == 'Q')) ||
                (valid(i, j+k) && !(k == 1 ? 0 : (pieces_blocks[2] = board[i][j+(k-1)] != '.' ? 1 : pieces_blocks[2])) && (board[i][j+k] == 'R' || board[i][j+k] == 'Q')) ||
                (valid(i, j-k) && !(k == 1 ? 0 : (pieces_blocks[3] = board[i][j-(k-1)] != '.' ? 1 : pieces_blocks[3])) && (board[i][j-k] == 'R' || board[i][j-k] == 'Q')) ||
                (valid(i+k, j+k) && !(k == 1 ? 0 : (pieces_blocks[4] = board[i+(k-1)][j+(k-1)] != '.' ? 1 : pieces_blocks[4])) && (board[i+k][j+k] == 'B' || board[i+k][j+k] == 'Q')) ||
                (valid(i-k, j+k) && !(k == 1 ? 0 : (pieces_blocks[5] = board[i-(k-1)][j+(k-1)] != '.' ? 1 : pieces_blocks[5])) && (board[i-k][j+k] == 'B' || board[i-k][j+k] == 'Q')) ||
                (valid(i+k, j-k) && !(k == 1 ? 0 : (pieces_blocks[6] = board[i+(k-1)][j-(k-1)] != '.' ? 1 : pieces_blocks[6])) && (board[i+k][j-k] == 'B' || board[i+k][j-k] == 'Q')) ||
                (valid(i-k, j-k) && !(k == 1 ? 0 : (pieces_blocks[7] = board[i-(k-1)][j-(k-1)] != '.' ? 1 : pieces_blocks[7])) && (board[i-k][j-k] == 'B' || board[i-k][j-k] == 'Q'))
            )
                return -1;
    }
    else if(board[i][j] == 'K') {
        int pieces_blocks[] = {0, 0, 0, 0, 0, 0, 0, 0};
        if((valid(i-1, j+1) && board[i-1][j+1] == 'p') || (valid(i-1, j-1) && board[i-1][j-1] == 'p'))
            return 1;
        
        if(valid(i+knight_move[0][0], j+knight_move[0][1]) && board[i+knight_move[0][0]][j+knight_move[0][1]] == 'n')
            return 1;
        for(k=1; k<8; k++)
            if(
                (valid(i+knight_move[k][0], j+knight_move[k][1]) && board[i+knight_move[k][0]][j+knight_move[k][1]] == 'n') ||
                (valid(i+k, j) && !(k == 1 ? 0 : (pieces_blocks[0] = board[i+(k-1)][j] != '.' ? 1 : pieces_blocks[0])) && (board[i+k][j] == 'r' || board[i+k][j] == 'q')) ||
                (valid(i-k, j) && !(k == 1 ? 0 : (pieces_blocks[1] = board[i-(k-1)][j] != '.' ? 1 : pieces_blocks[1])) && (board[i-k][j] == 'r' || board[i-k][j] == 'q')) ||
                (valid(i, j+k) && !(k == 1 ? 0 : (pieces_blocks[2] = board[i][j+(k-1)] != '.' ? 1 : pieces_blocks[2])) && (board[i][j+k] == 'r' || board[i][j+k] == 'q')) ||
                (valid(i, j-k) && !(k == 1 ? 0 : (pieces_blocks[3] = board[i][j-(k-1)] != '.' ? 1 : pieces_blocks[3])) && (board[i][j-k] == 'r' || board[i][j-k] == 'q')) ||
                (valid(i+k, j+k) && !(k == 1 ? 0 : (pieces_blocks[4] = board[i+(k-1)][j+(k-1)] != '.' ? 1 : pieces_blocks[4])) && (board[i+k][j+k] == 'b' || board[i+k][j+k] == 'q')) ||
                (valid(i-k, j+k) && !(k == 1 ? 0 : (pieces_blocks[5] = board[i-(k-1)][j+(k-1)] != '.' ? 1 : pieces_blocks[5])) && (board[i-k][j+k] == 'b' || board[i-k][j+k] == 'q')) ||
                (valid(i+k, j-k) && !(k == 1 ? 0 : (pieces_blocks[6] = board[i+(k-1)][j-(k-1)] != '.' ? 1 : pieces_blocks[6])) && (board[i+k][j-k] == 'b' || board[i+k][j-k] == 'q')) ||
                (valid(i-k, j-k) && !(k == 1 ? 0 : (pieces_blocks[7] = board[i-(k-1)][j-(k-1)] != '.' ? 1 : pieces_blocks[7])) && (board[i-k][j-k] == 'b' || board[i-k][j-k] == 'q'))
            )
                return 1;
    }
    return 0;
}

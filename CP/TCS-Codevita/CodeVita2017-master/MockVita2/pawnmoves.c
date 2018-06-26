#include <stdio.h>
#include <stdbool.h>

#define BLACK 0
#define WHITE 1

char board[8][8];
int current;

void readBoard();
void findPawnMoves();
void printMove(char, int, int, int, int);

int main()
{
    readBoard();
    findPawnMoves();

    return 0;
}

void readBoard()
{
    char c = '\0';

    int row = 0;
    int col = 0;

    int i;

    while (c != ' ')
    {
        scanf("%c", &c);

        if (c == '/')
        {
            row++;
            col = 0;
            continue;
        }

        if (c >= '0' && c <= '9')
        {
            for (i = 0; i < c - '0'; i++)
                board[row][col++] = ' ';

            continue;
        }

        board[row][col++] = c;
    }

    scanf("%c", &c);
    current = c == 'w' ? WHITE : BLACK;
}

void findPawnMoves()
{
    int i, j;
    int factor = current == BLACK ? 1 : -1;
    char pawn = current == BLACK ? 'p' : 'P';
    char other;

    printf("[");

    for (j = 0; j < 8; j++)
    {
        if (current == BLACK && j == 7)
            continue;

        if (current == WHITE && j == 0)
            continue;

        for (i = 7; i > -1; i--)
            if (board[i][j] == pawn)
            {
                if (j != 0)
                {
                    other = board[i + factor][j - 1];
                    if (other != ' ')
                        printMove(other, i, j, i - 1, j + factor);
                }

                other = board[i + factor][j];
                if (other == ' ')
                    printMove(other, i, j, i + factor, j);

                if (current == BLACK && i == 1)
                {
                    other = board[i + factor * 2][j];
                    if (other == ' ')
                        printMove(other, i, j, i + factor * 2, j);
                }

                if (current == WHITE && i == 6)
                {
                    other = board[i + factor * 2][j];
                    if (other == ' ')
                        printMove(other, i, j, i + factor * 2, j);
                }

                if (j != 7)
                {
                    other = board[i + factor][j + 1];
                    if (other != ' ')
                        printMove(other, i, j, i + 1, j + factor);
                }
            }
    }

    printf("]");
}

void printMove(char other, int i1, int j1, int i2, int j2)
{
    static bool firstMove = true;

    if ((current == BLACK && other >= 'A' && other <= 'Z') ||
        (current == WHITE && other >= 'a' && other <= 'z') ||
        other == ' ')
    {
        if (!firstMove)
            printf(", ");

        firstMove = false;
        printf("%c%d%c%d", 'a' + j1, 8 - i1, 'a' + j2, 8 - i2);
    }
}

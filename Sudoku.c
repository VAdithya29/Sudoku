#include <Graphics.h>
#include <stdio.h>
void print();
void play();
int check();
int checkRow(int row, int col, int no);
int checkCol(int row, int col, int no);
int checkBox(int row, int col, int no);
int prob[4][4];
int i, j, a, cur, occur = 0, b, term, count;
int main()
{
    //initializing the Sudoku Board

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            prob[i][j] = 0;
            
        }
    }
    prob[2][3] = 1;
    prob[3][1] = 4;
    prob[4][2] = 1;
    prob[4][4] = 3;

    print();
    while (term != 1)
    {
        play();
    }
    return 0;
}

//Printing the Sudoku Board
void print()
{   printf("------------------------------------------------------------------\n");
    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            printf("| %d ", prob[i][j]);
            if (prob[i][j] != 0)
                count++;
        }
        printf(" | \n");
        printf("------------------------------------------------------------------\n");
    }

    if (count == 16)
        {

            check();
        }
}

void play()
{
    int x, y, ip;
    printf("Enter row in which you want to enter the number:\t");
    scanf("%d", &x);
    printf("Enter column in which you want to enter the number:\t");
    scanf("%d", &y);
    printf("Enter number which you want to put in %d,%d :\t", x, y);
    scanf("%d", &ip);
    prob[x][y] = ip;
    cur = prob[x][y];
    print();
}

int check()
{
    printf("Checking");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cur = prob[i][j];
            b = checkRow(i, j, cur);
            if (b == 1)
            {
                printf("1");
                b = checkCol(i, j, cur);
                if (b == 1)
                {
                    printf("2");
                    b = checkBox(i, j, cur);
                    if (b == 1)
                        printf("3");
                    term = 1;
                }
            }
        }
    }
}

int checkRow(int row, int col, int no)
{
    for (col = 0; col < 4; col++)
    {
        if (no == prob[row][col])
            occur++;
    }
    return occur;
}

int checkCol(int row, int col, int no)
{
    for (row = 0; row < 4; row++)
    {
        if (no == prob[row][col])
            occur++;
    }
    return occur;
}

int checkBox(int row, int col, int no)
{
    for (col = 0; col < 2; col++)
    {
        for (row = 0; row < 2; row++)
        {
            if (no == prob[row][col])
                occur++;
        }
        return occur;
    }
}
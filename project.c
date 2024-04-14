//C program to Play TIC TAC TOE

#include<stdio.h>

char board[3][3];//Globally declared 2D array

/*
Functions used in Code
1.initializeBoard()
2.displayBoard()
3.updateBoard()
4.checkWinner()
5.playTicTacToe()*/


void initializeBoard()//instructor board
{
    for(int i=0;i<3;i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    int num= 1;
    printf("\n\n\t  ");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d", num++);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (i < 2)
        printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}

//Displays the game board
void displayBoard(int x, int y)
{
    printf("\n\n\t  ");
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%c", board[i][j]);
            if (j<2)
            {
                printf("  |  ");
            }
        }
        if (i<2)
        printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}

//This function Updates our game board
int updateBoard(int box, char playerSign)
{
    int row = (box - 1) / 3;
    int col = (box - 1) % 3;
    int isValid = 1;
    // accessing already played box number
    if (board[row][col] != ' ')
    {
        printf("\nInvalid: Box is already Filled!\n");
        isValid = 0;
    }
    // valid box position
    else
    {
        board[row][col] = playerSign;
    }
    displayBoard(row, col);
    return isValid;
}

//To check the Winner of the Game
int checkWinner(char ps)
{
    // checking all rows
    if (board[0][0] == ps && board[0][1] == ps && board[0][2] == ps ||
      board[1][0] == ps && board[1][1] == ps && board[1][2] == ps ||
      board[2][0] == ps && board[2][1] == ps && board[2][2] == ps)
    {
        return 1;
      }
      // checking all columns
    else if (board[0][0] == ps && board[1][0] == ps && board[2][0] == ps ||
           board[0][1] == ps && board[1][1] == ps && board[2][1] == ps||
           board[0][2] == ps && board[1][2] == ps && board[2][2] == ps)
    {
        return 1;
    }
    // checking both diagonals
    else if (board[0][0] == ps && board[1][1] == ps && board[2][2] == ps ||
           board[0][2] == ps && board[1][1] == ps && board[2][0] == ps)
    {
        return 1;
    }
 
    // There is no winner
    return 0;
}


//OUR GAME STARTS HERE!!

void playTicTacToe()
{
    int gameResult = 0;
    int box = 0;
    int playCount = 0;
    int updationResult = 1;
 
    char playerSign = ' ';
 
    // start playing the game
    while (!gameResult && playCount < 9)
    {
        if (playCount % 2 == 0)
        {
            // player 1 choosing the box number
            printf("\nChoice of Player 1 [ X ] : ");
            playerSign = 'X';
        }
        else
        {
            // player 2 choosing box number
            printf("\nChoice of Player 2 [ O ] : ");
            playerSign = 'O';
        }
        scanf("%d", &box);
        if (box > 0 && box < 10)
        {
            updationResult = updateBoard(box, playerSign);
            // if updation is possible
            if (updationResult)
            {
                gameResult = checkWinner(playerSign);
                // print the winner of the game
                if (gameResult)
                {
                    printf("\t *** CONGRATULATIONS Player %d Won!! ***\n", playerSign == 'X' ? 1 : 2);
                }
                playCount++;
            }
        }
        else if (box == -1)
        {
            printf("\n\tGame Terminated\n");
            return;
        }
        else
        {
            printf("\nPlease Enter a valid box value\n");
        }
    }
 
    // no one won the game
    if (!gameResult && playCount == 9)
    {
        printf("\n\t *** Draw...  ***\n");
    }
    printf("\n\t --- Game Over --- \n");
}
int main()
{
    printf("--------- Tic Tac Toe ----------\n\n");
    printf("\n* Instructions to the Game \n\n");
    printf("\tPlayer 1 sign---> X\n");
    printf("\tPlayer 2 sign---> O");
    printf("\n\tTo exit from game, Enter -1\n");
    printf("\n\n* Cell Numbers on Board\n");
    initializeBoard();
    char start = ' ';
    printf("\n> Press Enter to start...");
    scanf("%c", &start);
    if (start)
    {
        int userChoice = 1;
        // restart the game
        while (userChoice)
        {
            playTicTacToe();
            printf("\n* Menu\n");
            printf("\nPress 1 to Restart");
            printf("\nPress 0 for Exit");
            printf("\n\nYour Choice: ");
            scanf("%d", &userChoice);
            if (userChoice)
            {
                initializeBoard();
            }
            printf("\n");
        }
    }
    printf("\n :: Thanks for playing Tic Tac Toe game!! :: \n");
    return 0;
}

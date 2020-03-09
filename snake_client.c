#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define R 30
#define C 120
int field[R][C], r_hpos, c_hpos, s_len = 3, game;

void food_dist() //distributes food randomly
{

}

void snake_len() //keeps track of, and updates snake length
{

}

void snake_init() //initializes the display array and snake position
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            field[i][j] = 0;
    c_hpos = C/2; //places snake at the center
    r_hpos = R/2;
    game = 0; //0 signifies the game is running
    field[r_hpos][c_hpos] = 2; //snake head
    field[r_hpos][c_hpos - 1] = 1; //snake body
    field[r_hpos][c_hpos - 2] = 1;
}

void game_scr() //prints the game screen
{
    for (int i = 1; i <= C + 2; ++i)
    {
        if (i == 1)
            printf("%c", 201);
        else if (i == C + 2)
            printf("%c\n", 187);
        else
            printf("%c", 205);
    }
    for (int i = 1; i <= R; ++i)
    {
     printf("%c", 186);
        for (int j = 0; j <= C - 1; ++j)
        {
        if(field[i - 1][j] == 1)
            printf("%c", 176); //prints the snake body
        else if(field[i - 1][j] == 2)
            printf("%c", 178); //prints the snake head
        else
            printf(" ");
        }
    printf("%c\n", 186);
    }
    for (int i = 1; i <= C + 2; ++i)
    {
        if (i == 1)
            printf("%c", 200);
        else if (i == C + 2)
            printf("%c\n", 188);
        else
            printf("%c", 205);
    }

}

void reset_screen_position() //prints the game frame at the top of the screen and avoids scrolling
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void main()
{
    snake_init();
    while (game == 0)
    {
        game_scr();
        reset_screen_pos();
    }
}

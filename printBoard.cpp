/*
 * =====================================================================================
 *
 *       Filename:  printBoard.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/24/2016  9:08:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <ncurses.h>
#include <string>

using namespace std;

char numToChar(int num)
{
    if(num == 0)
    {
        return 32;
    }
    else if(num == 1)
    {
        return 88;
    }
    else
    {
        return 79;
    }
}
int printBoard(vector< vector<int> > board)
{
    int x = 0;
    int y = 0;
    int ch;
    while(true)
    {
        printw("%c|", numToChar(board.at(0).at(0)));
        printw("%c|", numToChar(board.at(0).at(1)));
        printw("%c\n", numToChar(board.at(0).at(2)));
        printw("-+-+-\n");
        printw("%c|", numToChar(board.at(1).at(0)));
        printw("%c|", numToChar(board.at(1).at(1)));
        printw("%c\n", numToChar(board.at(1).at(2)));
        printw("-+-+-\n");
        printw("%c|", numToChar(board.at(2).at(0)));
        printw("%c|", numToChar(board.at(2).at(1)));
        printw("%c\n", numToChar(board.at(2).at(2)));
        move(y,x);
        refresh();
        ch = getch();
        if(ch == 66)//down
        {
            if(y == 4)
            {
                y = 0;
            }
            else
            {
                y += 2;
            }
        }
        else if(ch == 65)//up
        {
            if(y == 0)
            {
                y = 4;
            }
            else
            {
                y -= 2;
            }
        }
        else if(ch == 67)//right
        {
            if(x == 4)
            {
                x = 0;
            }
            else
            {
                x += 2;
            }
        }
        else if(ch == 68)//left
        {
            if(x == 0)
            {
                x = 4;
            }
            else
            {
                x -= 2;
            }
        }
        else if(ch == 10 && board.at(x).at(y) == 0)
        {
            return(((y/2)*3)+(x/2));
        }
        clear();
    }
}

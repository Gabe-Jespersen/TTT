/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/24/2016  6:34:06 PM
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

#include "boardCheck.h"
#include "printBoard.h"

using namespace std;

int main(int argc, char **argv)
{
    vector< vector<int> > board = {{0,0,0},
                                   {0,0,0},
                                   {0,0,0}};
    int temp = state(board);
    int temp2;
    bool turnx = true;
    initscr();
    while(!temp)
    {
        move(0,0);
        temp2 = printBoard(board);
        if(turnx)
        {
            board.at((temp2-(temp2%3))/3).at(temp2%3) = 1;
        }
        else
        {
            board.at((temp2-(temp2%3))/3).at(temp2%3) = 2;
        }
        turnx = !turnx;
    }
    clear();
    refresh();
    endwin();
    return 1;
}

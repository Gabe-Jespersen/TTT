/*
 * =====================================================================================
 *
 *       Filename:  boardCheck.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/24/2016  6:38:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>

#include "boardCheck.h"

using namespace std;

int state(vector< vector<int> > board)
{
    //0: continue
    //1: x wins
    //2: o wins
    //3: tie

    //horizontal check
    for(int i = 0; i < 3; i++)
    {
        if(board.at(i).at(0) == board.at(i).at(1) && board.at(i).at(1) == board.at(i).at(2))
        {
            return(board.at(i).at(0));
        }
    }
    //vertical check
    for(int i = 0; i < 3; i++)
    {
        if(board.at(0).at(i) == board.at(1).at(i) && board.at(1).at(i) == board.at(2).at(i))
        {
            return(board.at(i).at(0));
        }
    }
    //diagnol top-left to bottom-right check
    if(board.at(0).at(0) == board.at(1).at(1) && board.at(1).at(1) == board.at(2).at(2))
    {
        return(board.at(0).at(0));
    }
    //diagnol top-right to bottom-left check
    if(board.at(0).at(2) == board.at(1).at(1) && board.at(1).at(1) == board.at(2).at(0))
    {
        return(board.at(0).at(2));
    }
    //tie check
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board.at(i).at(j) == 0)
            {
                return 0;
            }
        }
    }
    return 3;
}

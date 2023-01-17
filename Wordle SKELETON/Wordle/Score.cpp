//
//  Score.cpp
//  Bunco
//
//  Created by Howard Stahl on 2/21/22.
//  Copyright © 2022 Howard Stahl. All rights reserved.
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

// setup a default score - all WRONG ANSWER's
Score::Score()
{
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG;
    }
}

// TODO comparing the played move to the answer move,
//      build the ANSWER array of this Score
Score::Score( Move move, Move answer )
{
    std::string s_M = move.to_string();
    std::string s_A = answer.to_string();
    int index_of_processed[REQUIREDLENGTH]={10};
    int index_of_move_checked[REQUIREDLENGTH]={};
    // the score should construct an array of answers.
    //compare characters of the piece with the answer, using getPiece function.
    for(int i=0; i < REQUIREDLENGTH; i++)
    {
        //convert to string and compare each char.
        //find all right answers.
            char m = s_M.at(i);
            char a = s_A.at(i);
            if(m == a)
            {
                array[i] = RIGHT;
                index_of_processed[i]=i;
                index_of_move_checked[i]=1;//record the already processed characters so that they don't get checked for twice.
            }
    }
    //find maybe
    for(int i =0; i<REQUIREDLENGTH; i++)
    {
        int count = 0;
        char m = s_M.at(i);
        char a = s_A.at(i);
        if(m==a)
            count++;
        for(int j = 0; j<REQUIREDLENGTH; j++)
        {
            char a = s_A.at(j);
            if (m == a && index_of_processed[j] != j && count == 0)
            {
                index_of_processed[j]=j;
                index_of_move_checked[i]=1;
                array[i] = MAYBE;
                count++;
            }
        }
    }
    //find WRONG
    for(int i = 0; i<REQUIREDLENGTH; i++)
    {
        int move_result = index_of_move_checked[i];
        if(move_result != 1)
            array[i] = WRONG;
    }

    //Right: letter and position matches
    //Wrong: letter and position does not matches, extra letters are wrong.
    //Maybe: letter is right but the position is wrong.
    //for one or more same letters, if one of them is right, disregard the rest, if none is at the right position, count the first appeared letter only.
    //
}

// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

// TODO is the ANSWER array all RIGHT ANSWER's?
bool Score::isExactMatch() const
{
    bool result = true;
    for(int i = 0; i<REQUIREDLENGTH; i++)//check if all elements in the array are RIGHT
    {
     if(array[i]!=RIGHT)
         return false;
    }
    return result;
}


}

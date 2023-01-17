//
//  main.cpp
//  Wordle
//

#include <iostream>
#include "Wordle.h"
#include "Move.h"
#include "Score.h"
#include <cassert>

void clearScreen( );

// interactively play Wordle
int main()
{
    using namespace cs31;
    using namespace std;
    
    clearScreen();
 /*
    // by default, no cheating - pick a random word
   Wordle game("court");
    
    bool forceEnd = false;
    std::string action, turn, message = "(p)lay (q)uit: ";
    cout << game.display( message ) << endl;
    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                forceEnd = true;
                break;
            case 'p':
            case 'P':
                if (game.determineGameOutcome() == GAMENOTOVER)
                {
                    // acquire the entered word
                    getline( cin, turn );
                    // if the word is valid, build a move
                    // for this round of play
                    if (game.isValid(turn))
                    {
                        Move m = game.play( turn );
                        game.endRound(m);
                    }
                    else
                    {
                        // turn was not a valid word and does not count
                        cout << turn << " was not a Dictionary word!" << endl;
                    }
                }
                break;
        }
        if (!game.gameIsOver())
        {
            // repetitively display the board
            cout << game.display( message ) << endl;
        }
        else
        {
            // once the game is over, finally display the board and
            // show the game outcome and the winning word
            cout << game.display( game.gameOutcomeAsString() ) << endl;
            cout << "The winning word was: " << game.answer() << endl;
        }
    } while( !game.gameIsOver() && !forceEnd );
    
    // destroy the in-memory database of five letter words managed by
    // the Dictionary object
    Singleton::destroySingleton();
    
    */
    //move test
    Move m1, m2,m3,m4;
    m1.setPieces( "spell" );
    m2.setPieces( "czars" );
    Score s( m1, m2 );
    assert( s.isExactMatch() == false );
    assert( s.to_string() == "M____" );
    try {
        m4.setPieces("sample");
    } catch (logic_error) {
        assert(true);
    }
    
   /* //board test
    Board b;
    assert(b.getCurrentRound()==0);
    b.endRound(m1, s);
    assert(b.getCurrentRound()==1);
    assert(b.getScoreForRound(0).to_string()=="M____");
    assert(b.getMoveForRound(0).to_string()=="SPELL");

    //wordle test
    Wordle w("cloud");
    assert(w.determineGameOutcome()==GAMENOTOVER);
    Move m = w.play("court");
    s=w.endRound(m);
    assert(w.determineGameOutcome()==GAMENOTOVER);
    assert(s.to_string()=="RMM__");
    
    try
    {
        b.getScoreForRound(4);
    }
    catch(logic_error)
    {
        assert(true);
    }
    try
    {
        b.getMoveForRound(4);
    }
    catch(logic_error)
    {
        assert(true);
    }
    
    cout<<"success"<<endl; */
    
    
    return( 0 );
}



void clearScreen();



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif


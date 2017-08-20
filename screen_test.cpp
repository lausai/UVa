#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <windows.h>   // WinApi header

using std::vector;
using std::string;

void SetColor()
{
    HANDLE  hConsole;
    int k;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);

    // you can loop k higher to see more color choices
    for(k = 1; k < 255; k++)
    {
        SetConsoleTextAttribute(hConsole, k);
        printf("%3d  %s\n", k, "I want to be nice today!");
    }


    // Reset color
    SetConsoleTextAttribute(hConsole, 7);
}

void ClearScreen()
{
    system("cls");
}

void cls()
{
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD coordScreen = { 0, 0 };    // home for the cursor 
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi; 
   DWORD dwConSize;

// Get the number of character cells in the current buffer. 

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

   // Fill the entire screen with blanks.

   if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer 
                                    (TCHAR) ' ',     // Character to write to the buffer
                                    dwConSize,       // Number of cells to write 
                                    coordScreen,     // Coordinates of first cell 
                                    &cCharsWritten ))// Receive number of characters written
   {
      return;
   }

   // Get the current text attribute.

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   // Set the buffer's attributes accordingly.

//   if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer 
//                                    csbi.wAttributes, // Character attributes to use
//                                    dwConSize,        // Number of cells to set attribute 
//                                    coordScreen,      // Coordinates of first cell 
//                                    &cCharsWritten )) // Receive number of characters written
//   {
//      return;
//   }

   // Put the cursor at its home coordinates.

   SetConsoleCursorPosition( hConsole, coordScreen );
}

void FillScreenBuf(char screenBuf[][80], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
            screenBuf[i][j] = (rand() % 10) + 48;
    }
}

void PrintScreenBuf(char screenBuf[][80], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        printf("%.*s", y, screenBuf[i]);
        printf("\r");
    }
}

int main()
{
    srand(time(NULL));

    char screenBuf[24][80] = {};
    int x = 24;
    int y = 80;

    FillScreenBuf(screenBuf, x, y);

    for (int i = 0; i < 3; i++)
    {
        cls();
        PrintScreenBuf(screenBuf, x, y);
        FillScreenBuf(screenBuf, x, y);
        printf("wait...");
        Sleep(1000);
    }

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
using namespace std;

// global variables
const int MAX_ROW = 40;
const int MAX_COL = 80;

// function prototypes
void displayMenu(void);
void setZeroArray(char setZero[MAX_ROW][MAX_COL]);
void setInitialPatternArray(char setPattern[MAX_ROW][MAX_COL], char & ans);
void displayArray(char displayArray[MAX_ROW][MAX_COL]);
void copyArray(char sourceArray[MAX_ROW][MAX_COL], char copyArray[MAX_ROW][MAX_COL]);
void setNextGenArray(char sourceArray[MAX_ROW][MAX_COL], char currentArray[MAX_ROW][MAX_COL]);
//void displaySavedArray()

int main ()
{
    // variables
    char ans = 'c';
    bool breakLoop;
    ifstream displaySaved;
    bool userInput = false;

    // body
    do
    {
        //system ("cls");

        // arrays
        char tempArray[MAX_ROW][MAX_COL];
        char currentArray[MAX_ROW][MAX_COL];

        //Initialize random seed
        srand(time(NULL));

        // body
        if (ans != 's')
        {
            displayMenu();

            setZeroArray(tempArray);

            copyArray(tempArray, currentArray);

            displayArray(currentArray);

            setInitialPatternArray(tempArray, ans);

            copyArray(tempArray, currentArray);
        }
        // stop and display current array
        else
        {
            do
            {
                system ("cls");

                displayMenu();

                displayArray(currentArray);

                ans = getch();
                ans = static_cast<char>(tolower(ans));
                if (ans == 'q' || ans == 'p' || ans == 'c')
                {
                    userInput = false;
                }
            }
            while (userInput == true);
        }


        while (userInput == false)
        {
            if (ans != 'q' || ans != 'p' || ans != 'c')
            {
                ans = getch();
                static_cast<char>(tolower(ans));
                if (ans == 'q')
                {
                    userInput = true;
                }
                else if (ans == 'c')
                {
                    system("cls" );

                    displayMenu();

                    setZeroArray(tempArray);

                    copyArray(tempArray, currentArray);

                    displayArray(currentArray);

                }
                else if (ans == 'i')
                {
                    system("cls" );

                    displayMenu();

                    setZeroArray(tempArray);

                    setInitialPatternArray(tempArray, ans);

                    copyArray(tempArray, currentArray);

                    displayArray(currentArray);

                }
                else if (ans == 'p')
                {
                    userInput = true;
                }
                else if (ans == 's')
                {
                    copyArray(currentArray, currentArray);
                    displayArray(currentArray);
                    ans = getch();
                }
            }
            else
            {
                userInput = true;
            }
        }



        // Next Gen Loop
        while (ans != 'p')
        {
            if (ans == 'q')
            break;
        }
        if (ans == 'q')
        {
            break;
        }
        while (1)
        {

            if (breakLoop = kbhit() && ans != 'q')
            {
                system ("cls");
                break;
            }
            else if (ans == 's')
            {
                userInput = false;

                break;
            }
            else
            {
                system("cls");
                displayMenu();
                setNextGenArray(currentArray, tempArray);
                copyArray(currentArray, tempArray);
                displayArray(currentArray);
                Sleep(1000);
            }
        }
        ans = getch();
        ans = static_cast<char>(tolower(ans));
    }
    while (ans != 'q');

    return 0;
}

// functions
// display menu function
void displayMenu(void)
{
    cout << "Load" << '[' << "I" << ']' << " - Press 'I' to load the initial pattern." << setw(8);
    cout << '[' << "D" << ']' << "isplay - Press 'D' to display the saved Array." << endl;
    cout << "Load" << '[' << 1 << ']' << " - Press '1' to load the ........." << setw(45);
    cout << "Load" << '[' << 2 << ']' << " - Press '2' to load the ..." << endl;
    cout << "Load" << '[' << 3 << ']' << " - Press '3' to load the ..." << setw(45);
    cout << "Load" << '[' << "T" << ']' << " - Press 'T' to input a custom pattern." << endl;
    cout << '[' << "P" << ']' << "lay - Press 'P' to play." << setw(29);
    cout << '[' << "S" << ']' << "top - Press 'S' to stop the program." << endl;
    cout << '[' << "C" << ']' << "lear - Press 'C' reset the display." << setw(18);
    cout << '[' << "Q" << ']' << "uit - Press 'Q' to exit." << endl;
    cout << "s" << '[' << "A" << ']' << "ve - Press 'A' to save the current array." << endl;
    cout << endl;
}

// initialize and set array to 0
void setZeroArray(char setZero[MAX_ROW][MAX_COL])
{
    // body
    for (int row = 0; row < MAX_ROW; row++)
    {
        for (int col = 0; col < MAX_COL; col++)
        {
            setZero[row][col] = 'X';
        }
    }
}

// set array pattern
void setInitialPatternArray(char setPattern[MAX_ROW][MAX_COL], char & ans)
{
    // variables
    int rowRand = (rand() % (MAX_ROW - 5));
    int colRand = (rand() % (MAX_COL - 6));

    // body
//    do
//    {
//        for (int row = rowRand; row < 6 + rowRand; row++)
//        {
//            for (int col = colRand; col < 7 + colRand; col++)
//            {
//                setPattern[row][col] = 'X';
//            }
//        }
//        ans = getch()
//    }
//    while (ans == 'c');

    for (int row = rowRand; row < 6 + rowRand; row++)
    {
        for (int col = colRand; col < 7 + colRand; col++)
        {
            if (row < 5 + rowRand && col == colRand)
            {
                setPattern[row][col] = 0;
            }
            else if (row < 5 + rowRand && col == 6 + colRand)
            {
                setPattern[row][col] = 0;
            }
            else if (row == 5 + rowRand)
            {
                setPattern[row][col] = 0;
            }
            else
            {
                setPattern[row][col] = 'X';
            }
        }
    }
}

// print function
void displayArray(char displayArray[MAX_ROW][MAX_COL])
{
    // body
    for (int row = 0; row < MAX_ROW; row++)
    {
        for (int col = 0; col < MAX_COL; col++)
        {
            cout << displayArray[row][col];
            if ((col + 1) % MAX_COL == 0)
            {
                cout << endl;
            }
        }
    }
}

// copy array function
void copyArray(char sourceArray[MAX_ROW][MAX_COL], char copyArray[MAX_ROW][MAX_COL])
{
    for (int row = 0; row < MAX_ROW; row++)
    {
        for (int col = 0; col < MAX_COL; col++)
        {
            copyArray[row][col] = sourceArray[row][col];
        }
    }
}

// set next generation array function
void setNextGenArray(char sourceArray[MAX_ROW][MAX_COL], char currentArray[MAX_ROW][MAX_COL])
{
    for (int row = 0; row < MAX_ROW; row++)
    {
        for (int col = 0; col < MAX_COL; col++)
        {
            int sum = 0;
            // corners, rows, and columns
            if ((row == 0 || row == MAX_ROW - 1) || (col == 0 || col == MAX_COL - 1))
            {
                // top left corner live cell
                if (currentArray[row][col] == 0 && (row == 0 && col == 0))
                {
                    for (int nRow = row; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // top left corner dead cell
                else if (currentArray[row][col] == 'X' && (row == 0 && col == 0))
                {
                    for (int nRow = row; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // top right corner live cell
                else if (currentArray[row][col] == 0 && (row == 0 && col == MAX_COL - 1))
                {
                    for (int nRow = row; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // top right corner dead cell
                else if (currentArray[row][col] == 'X' && (row == 0 && col == MAX_COL - 1))
                {
                    for (int nRow = row; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // bottom right corner live cell
                else if (currentArray[row][col] == 0 && (row == MAX_ROW - 1 && col == MAX_COL - 1))
                {
                    for (int nRow = row - 1; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // bottom right corner dead cell
                else if (currentArray[row][col] == 'X' && (row == MAX_ROW - 1 && col == MAX_COL - 1))
                {
                    for (int nRow = row - 1; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // bottom left corner live cell
                else if (currentArray[row][col] == 0 && (row == MAX_ROW - 1 && col == 0))
                {
                    for (int nRow = row - 1; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // bottom left corner dead cell
                else if (currentArray[row][col] == 'X' && (row == MAX_ROW - 1 && col == 0))
                {
                    for (int nRow = row - 1; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // top row live cell
                else if ((currentArray[row][col] == 0 && row == 0) && (col != 0 && col != MAX_COL - 1))
                {
                    for (int nRow = row; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // top row dead cell
                else if ((currentArray[row][col] == 'X' && row == 0) && (col != 0 && col != MAX_COL - 1))
                {
                    for (int nRow = row; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // right column live cell
                else if ((currentArray[row][col] == 0 && col == MAX_COL - 1) && (row != 0 && row != MAX_ROW - 1))
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // right column dead cell
                else if ((currentArray[row][col] == 'X' && col == MAX_COL - 1) && (row != 0 && row != MAX_ROW - 1))
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // bottom row live cell
                else if ((currentArray[row][col] == 0 && row == MAX_ROW - 1) && (col != 0 && col != MAX_COL - 1))
                {
                    for (int nRow = row - 1; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // bottom row dead cell
                else if ((currentArray[row][col] == 'X' && row == MAX_ROW - 1) && (col != 0 && col != MAX_COL - 1))
                {
                    for (int nRow = row - 1; nRow < row + 1; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // left column live cell
                else if (currentArray[row][col] == 0 && col == 0)
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // left column dead cell
                else if (currentArray[row][col] == 'X' && col == 0)
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col; nCol < col + 1; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
            }
            // inner matrix cells
            else
            {
                // MAX row/col > live cell > 0
                if (currentArray[row][col] == 0)
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    sum--;
                    if (sum == 2 || sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
                // MAX row/col > dead cell > 0
                else if (currentArray[row][col] == 'X')
                {
                    for (int nRow = row - 1; nRow < row + 2; nRow++)
                    {
                        for (int nCol = col - 1; nCol < col + 2; nCol++)
                        {
                            if (currentArray[nRow][nCol] == 0)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 3)
                    {
                        sourceArray[row][col] = 0;
                    }
                    else
                    {
                        sourceArray[row][col] = 'X';
                    }
                }
            }
        }
    }
}

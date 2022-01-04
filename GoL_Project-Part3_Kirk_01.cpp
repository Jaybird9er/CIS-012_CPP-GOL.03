#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// global variables
const int MAX_ROW = 40;
const int MAX_COL = 80;

// function prototypes
void displayMenu(void);
void setZeroArray(char setZero[MAX_ROW][MAX_COL]);
void setInitialPatternArray(char setPattern[MAX_ROW][MAX_COL]);
void displayArray(char displayArray[MAX_ROW][MAX_COL]);
void copyArray(char sourceArray[MAX_ROW][MAX_COL], char copyArray[MAX_ROW][MAX_COL]);
void setNextGenArray(char sourceArray[MAX_ROW][MAX_COL], char currentArray[MAX_ROW][MAX_COL]);
void displaySavedArray(char tempArray[MAX_ROW][MAX_COL], int patternArray[]);

int main ()
{
    // variables
    char ans;
    bool breakLoop;
    ifstream loadArray;
    bool userInput = false;

    // arrays
    char tempArray[MAX_ROW][MAX_COL];
    char currentArray[MAX_ROW][MAX_COL];

    // body
    // quit
    do
    {
        //Initialize random seed
        srand(time(NULL));
        // set array to dead cells (clear)
        do
        {
            system("cls");

            displayMenu();

            setZeroArray(tempArray);

            copyArray(tempArray, currentArray);

            displayArray(currentArray);

            cout << endl;
            cout << "> ";

                        // await user input
                        do
                        {
                            // variables and arrays
                            int val = 0;
                            int index = 0;
                            int patternArray[MAX_ROW * MAX_COL] = {0};

                            ans = getch();
                            static_cast<char>(tolower(ans));
                            // output initial array
                            if (ans == 'i')
                            {
                                system("cls" );

                                displayMenu();

                                setZeroArray(tempArray);

                                setInitialPatternArray(tempArray);

                                copyArray(tempArray, currentArray);

                                displayArray(currentArray);

                                breakLoop = true;

                                cout << endl;
                                cout << "> ";
                            }
                            else if (ans == 'd')
                            {
                                system("cls" );

                                displayMenu();

                                setZeroArray(tempArray);

                                loadArray.open("savedPattern.txt");

                                while (! loadArray.eof())
                                {
                                    loadArray >> val;
                                    patternArray[index] = val;
                                    index++;
                                }

                                loadArray.close();

                                displaySavedArray(tempArray, patternArray);

                                copyArray(tempArray, currentArray);

                                displayArray(currentArray);

                                breakLoop = true;

                                cout << endl;
                                cout << "> ";
                            }
                            // load pattern 1
                            else if (ans == '1')
                            {
                                system("cls" );

                                displayMenu();

                                setZeroArray(tempArray);

                                loadArray.open("pattern1.txt");

                                while (! loadArray.eof())
                                {
                                    loadArray >> val;
                                    patternArray[index] = val;
                                    index++;
                                }

                                loadArray.close();

                                displaySavedArray(tempArray, patternArray);

                                copyArray(tempArray, currentArray);

                                displayArray(currentArray);

                                breakLoop = true;

                                cout << endl;
                                cout << "> ";
                            }
                            else if (ans == '2')
                            {
                                system("cls" );

                                displayMenu();

                                setZeroArray(tempArray);

                                loadArray.open("pattern2.txt");

                                while (! loadArray.eof())
                                {
                                    loadArray >> val;
                                    patternArray[index] = val;
                                    index++;
                                }

                                loadArray.close();

                                displaySavedArray(tempArray, patternArray);

                                copyArray(tempArray, currentArray);

                                displayArray(currentArray);

                                breakLoop = true;

                                cout << endl;
                                cout << "> ";
                            }
                            else if (ans == '3')
                            {
                                // open pattern 3 and output array
                            }
                            else if (ans == 't')
                            {
                                // allow user to input custom pattern
                            }
                            else if (ans == 'q')
                            {
                                breakLoop = true;
                            }
                            else
                            {
                                system ("cls");

                                cout << "User has to load pattern." << endl;
                                cout << "Please try again." << endl;

                                displayMenu();

                                displayArray(currentArray);

                                cout << endl;
                                cout << "> ";
                            }
                        }
                        while (breakLoop == false);     // pattern has been loaded
                        cout << 1 << endl;
                        do
                        {
                            if ((ans == 'q' || ans == 'p') || (ans == 'c' || ans == 's'))
                            {
                                breakLoop = true;
                            }
                            else
                            {
                                ans = getch();
                                static_cast<char>(tolower(ans));
                                if ((ans == 'q' || ans == 'p') || (ans == 'c' || ans == 's'))
                                {
                                    breakLoop = true;
                                }
                                else
                                {
                                    system("cls");

                                    cout << "Invalid input." << endl;

                                    displayMenu();

                                    displayArray(currentArray);

                                    cout << endl;
                                    cout << "> ";

                                    breakLoop = false;
                                }
                            }
                        }
                        while (breakLoop == false);     // user inputs command (p, s, a, c, q)
                        cout << 2 << endl;
                        breakLoop = false;
            // stop and save array
            do
            {
                    // stop and play
                    do
                    {

                            // play
                            do
                            {
                                if (ans == 'q' || (ans == 'c' || ans == 's') || ans == 'a')
                                {
                                    breakLoop = true;
                                }
                                else if (userInput = kbhit())
                                {
                                    system("cls");
                                    cout << "Invalid input. AAAAA" << endl;
                                    displayMenu();
                                    displayArray(currentArray);
                                    cout << endl;
                                    cout << "> ";
                                    ans = getch();
                                }
                                else if (ans == 'p')
                                {
                                    system("cls");
                                    displayMenu();
                                    setNextGenArray(currentArray, tempArray);
                                    copyArray(currentArray, tempArray);
                                    displayArray(currentArray);
                                    Sleep(1000);
                                }
                            }
                            while (breakLoop == false);     // play (p)
                        // stop
                        do
                        {
                            cout << 3 << endl;
                            breakLoop = false;
                            if (ans == 'q' || (ans == 'c' || ans == 'p'))
                            {
                                breakLoop = true;
                            }
                            else
                            {
                                system("cls");
                                if (ans != 's')
                                {
                                    cout << "Invalid input. BBBB" << endl;
                                }
                                displayMenu();
                                displayArray(currentArray);
                                cout << endl;
                                cout << "> ";
                                ans = getch();
                            }
                        }
                        while (breakLoop == false);     // stop (s)
                        if (ans == 'p')
                        {
                            breakLoop = false;
                        }
                }
                while (breakLoop == false);             // return to play after stop and invalid input @ stop
                cout << 4 << endl;
                breakLoop = false;
                if (ans == 'c' || ans == 'q')
                {
                    breakLoop = true;
                }
                ans = getch();
            }
            while (breakLoop == false);                 // save (a)
            // save current array to txt file
            cout << 5 << endl;
            breakLoop = false;
            if (ans == 'q')
            {
                breakLoop = true;
            }
        }
        while (breakLoop == false);                     // copy (c)
    }
    while (breakLoop == false);                         // quit (q)



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
void setInitialPatternArray(char setPattern[MAX_ROW][MAX_COL])
{
    // variables
    int rowRand = (rand() % (MAX_ROW - 5));
    int colRand = (rand() % (MAX_COL - 6));

    // body
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

void displaySavedArray(char tempArray[MAX_ROW][MAX_COL], int patternArray[])
{
    int patternRow = 0;
    int patternCol = 0;
    int counter = 0;

    int newRow[MAX_ROW];
    int newCol[MAX_COL];
    int val = 0;

    for (int index = 0; index < MAX_ROW; index++)
    {
        if (index % 2 == 0)
        {
            newRow[val] = patternArray[index];
            val++;
        }
    }

    for (int index = 0; index < MAX_COL; index++)
    {
        if (index % 2 == 1)
        {
            newCol[val] = patternArray[index];
            val++;
        }
    }


    int maxRow = newRow[0];
    int maxCol = newCol[0];

    for (int loc = maxRow + 1; loc < MAX_ROW; loc++)
    {
        if (newRow[loc] == '\0')
        {
            break;
        }
        else if (newRow[loc] > newRow[maxRow])
        {
            maxRow = loc;
        }
    }

    for (int loc = maxCol + 1; loc < MAX_COL; loc++)
    {
        if (newCol[loc] == '\0')
        {
            break;
        }
        else if (newCol[loc] > newCol[maxCol])
        {
            maxCol = loc;
        }
    }

    int rowRand = (rand() % (MAX_ROW - maxRow + 1));
    int colRand = (rand() % (MAX_COL - maxCol + 1));

    for (int row = 0; row < MAX_ROW; row++)
    {
        patternRow = rowRand;
        patternRow += patternArray[counter];
        counter++;
        for (int col = 0; col < 1; col++)
        {
            patternCol = colRand;
            patternCol += patternArray[counter];
            counter++;
        }
        tempArray[patternRow][patternCol] = 0;
        if (patternArray[counter] == '\0')
        {
            break;
        }
    }
}

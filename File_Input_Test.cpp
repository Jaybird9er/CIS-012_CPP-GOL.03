#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
    int singleArray[] = {1, 2, 3, 4, 5, 8, 5, 4};
    int doubleArray[100][100];
    int index = 0;
    int counter = 0;
    int nRow = 0;
    int nCol = 0;
    int newRow[100];
    int newCol[100];
    int userArray[100];
    int userNums = 0;

    for (int num = 0; num < 100; num++)
    {
        cin >> userNums;
        userArray[num] = userNums;
        if (num % 2 == 0)
        {
            cout << "Enter more numbers" << endl;
        }
        else if (userNums == 'r')
        {
            break;
        }
    }

    cout << userArray[0] << endl;
    cout << userArray[1] << endl;
    cout << userArray[2] << endl;
    cout << userArray[3] << endl;


//    for (int row = 0; row < 3; row++)
//    {
//        nRow = 0;
//        nRow = singleArray[counter];
//        counter++;
//        for (int col = 0; col < 1; col++)
//        {
//            nCol = 0;
//            nCol = singleArray[counter];
//            counter++;
//
//        }
//        doubleArray[nRow][nCol] = counter;
//
//    }
//    cout << doubleArray[1][2] << endl;
//    cout << doubleArray[3][4] << endl;
//    cout << doubleArray[5][6] << endl;
//
//    int bigNum = 0;
//    bigNum = index;
//
//    for (int loc = index + 1; loc < 100; loc++)
//    {
//        if ((singleArray[loc] > singleArray[bigNum]) && singleArray[loc] < 5)
//        {
//            bigNum = loc;
//        }
//        if (singleArray[loc] == '\0')
//        {
//            break;
//        }
//    }
//    cout << singleArray[bigNum] << endl;
//    int test = 0;
//    for (int index = 0; index < 100; index++)
//    {
//        if (index % 2 == 0)
//        {
//            newRow[test] = singleArray[index];
//            test++;
//        }
//    }
//
//    cout << endl;
//    cout << newRow[0] << endl;
//    cout << newRow[1] << endl;
//    cout << newRow[2] << endl;
//    cout << newRow[3] << endl;



    return 0;
}

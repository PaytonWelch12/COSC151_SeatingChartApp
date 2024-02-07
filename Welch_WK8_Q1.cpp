// File Name: Welch_Week8
// Class COSC 151
// Author: Payton welch
// Descriptopm: This is a simple program that allows the user to edit a seating chart for students

#include <iostream>
#include <cstdlib>

using namespace std;

// Type definition
typedef int *IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes
void createArrays(IntPtr labs[], int labsizes[]);
void freeArrays(IntPtr labs[]);
void showLabs(IntPtr labs[], int labsizes[]);
void login(IntPtr labs[], int labsizes[]);
void logOff(IntPtr labs[], int labsizes[]);
void search(IntPtr labs[], int labsizes[]);
bool searchInLogin(IntPtr labs[], int labsizes[], int code);
void mainMenu(IntPtr labs[], int labsizes[]);
void setSeat(IntPtr labs[], int code, int labRow, int seatColumn);

void createArrays(IntPtr labs[], int labsizes[])
{

    for (int i = 0; i < 4; i++)
    {
        labs[i] = new int[labsizes[i]];

        for (int j = 0; j < labsizes[i]; j++)
        {
            labs[i][j] = 0;
        }
    }
}

void freeArrays(IntPtr labs[])
{
    for (int i = 0; i < 4; i++)
    {
        delete labs[i];
    }
}

void showLabs(IntPtr labs[], int labsizes[])
{

    cout << "                       Column                    " << endl;
    cout << " ------------------------------------------------" << endl;
    cout << "    Row  |   1   |   2   |   3   |   4   |   5   " << endl;
    cout << " ------------------------------------------------" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "     " << i + 1 << "  ";
        for (int j = 0; j < labsizes[i]; j++)
        {

            if (labs[i][j] != 0)
            {
                cout << " | " << labs[i][j];
            }
            if (labs[i][j] == 0)
            {
                cout << " | Empty";
            }
        }
        cout << "\n";
    }
}

void login(IntPtr labs[], int labsizes[])
{
    int row, column, code;
    cout << "   What row are you in? ";
    cin >> row;
    cout << "   Which column are you in? ";
    cin >> column;
    cout << "   Please enter your 5 digit student ID. ";
    cin >> code;

    if (searchInLogin(labs, labsizes, code) == false)
    {
        labs[row - 1][column - 1] = code;
        system("cls");
    }
    else
    {
        system("cls");
        cout << endl
             << endl
             << "The ID " << code << " is already Used. Delete before reassigning." << endl;
    }
}

void setSeat(IntPtr labs[], int code, int labRow, int seatColumn)
{
    labs[labRow - 1][seatColumn - 1] = code;
}

void logOff(IntPtr labs[], int labsizes[])
{
    int code;
    cout << endl
         << "   What Student ID do you want to log off?";
    cin >> code;

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < labsizes[i]; j++)
        {
            if (code == labs[i][j])
            {
                labs[i][j] = 0;
                system("cls");
            }
        }
    }
}

void search(IntPtr labs[], int labsizes[])
{
    int id = -1;
    cout << "   Enter 5 digit key to search for lab and computer number. ";
    cout << "   ";
    cin >> id;
    while ((id < 0) || (id > 99999))
    {
        cout << "   Enter the 5 digit ID number of the user to find:" << endl;
        cout << "   ";
        cin >> id;
    }

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < labsizes[i]; j++)
        {
            if (id == labs[i][j])
            {
                system("cls");
                cout << endl
                     << "   ID " << id << " is logged into Lab " << i + 1 << " computer " << j + 1 << endl;
                return;
            }
        }
    }
    system("cls");
    cout << endl
         << endl
         << "   That user is not logged in." << endl;
}

bool searchInLogin(IntPtr labs[], int labsizes[], int code)
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < labsizes[i]; j++)
        {
            if (code == labs[i][j])
            {
                return true;
            }
        }
    }

    return false;
}

void mainMenu(IntPtr labs[], int labsizes[])
{
    int choice = -1;
    while (choice != 0)
    {
        cout << endl;
        showLabs(labs, labsizes);
        cout << "\n\n   MAIN MENU" << endl;
        cout << "   0) Quit" << endl;
        cout << "   1) Update Seat" << endl;
        cout << "   2) Empty Seat" << endl;
        cout << "   3) Search" << endl;
        cout << "   ";
        cin >> choice;
        if (choice == 1)
        {
            login(labs, labsizes);
        }
        else if (choice == 2)
        {
            logOff(labs, labsizes);
        }
        else if (choice == 3)
        {
            search(labs, labsizes);
        }
    }
}

int main()
{
    IntPtr labs[NUMLABS];  // Array to reference each lab
    int labsizes[NUMLABS]; // Number of computers in each lab

    // Initialize labsizes to those given in the problem
    labsizes[0] = 5;
    labsizes[1] = 5;
    labsizes[2] = 5;
    labsizes[3] = 5;

    // Create the arrays
    createArrays(labs, labsizes);

    // Assign a few seats
    setSeat(labs, 11111, 1, 1);
    setSeat(labs, 22222, 1, 2);
    setSeat(labs, 33333, 1, 3);

    mainMenu(labs, labsizes);

    // Exit
    freeArrays(labs);
    return 0;
}
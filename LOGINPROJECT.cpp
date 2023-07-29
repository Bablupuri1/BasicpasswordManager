
#include <iostream> //this header file is used for cout and cin object
#include <conio.h>  //this header file is used for getch meand clear screen
#include <fstream>  //this header file is used for ifstream class and ofstream class

void rejister();
void login();

using namespace std;

void rejister()
{

    system("cls");
    fstream file;
    string username;
    string pasword;

    cout << "Enter username:  ";
    cin >> username;
    cout << "Enter pasword  :";
    cin >> pasword;

    // Open file in append or
    // output mode
    file.open("rejister.txt", ios::out | ios::app); // this file is open write mode //
    file << " " << username << " " << pasword << " ";
    file.close();
    cout << "REJISTER SUCESSFULLY........\n";
}
void login()
{
    system("cls");
    int f = 0;
    string username1;
    string username;
    string pasword;
    string pasword1;

    ifstream fout;
    // the file open in read mode using ifstream class //
    fout.open("rejister.txt", ios::in);
start:

    cout << "Enter username1:";
    cin >> username1;
    cout << "Enter pasword:";
    cin >> pasword1;
    if (!fout)
    {
        cout << "file cant not find\n";
    }
    else
    {
        while (!fout.eof())
        {
            fout >> username >> pasword;

            if (username == username1 && pasword == pasword1)
            {
                cout << "LOGIN SUCESSFULLY..................\n";
                cout << "\n";
                f++;
            }
        }
        system("COLOR 14");
        if (f == 0)
        {
            system("COLOR 14");
            cout << "Unautrized user for access my program\n";
            cout << "please first of all rejister my application\n";
            cout << "\n";

            goto start;
        }
    }

    fout.close();
}

int main()
{
    system("cls");
    system("COLOR 12");
    int choice;
    do
    {
        cout << "1. REJISTER USER\n";
        cout << "2. LOGIN USER\n";
        cout << "Enter choice\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            system("COLOR 42");
            rejister();
            break;

        case 2:
            system("cls");
            system("COLOR 60");
            login();
            break;
        }

        /* code */
    } while (choice != 4);
    return 0;
}
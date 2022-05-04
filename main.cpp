#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <conio.h>

using namespace std;


#include "consoleFunctions.h"
#include "person.h"
#include "quicksort.h"
#include "department.h"


void printHomeChoice(){

    SET_CONSOLE_COLOR(YELLOW);
    cout << "--- MAIN MENU ---\n\n" ;
    cout << "1. Add new employee" << endl;
    cout << "2. Delete employee information" << endl;
    cout << "3. Update employee information" << endl;
    cout << "4. Make reports based on specific field" << endl;
    cout << "5. Search Employee" << endl;
    cout << "6. Quit" << endl;
    cout << "7. Show All Employees" << endl;
    SET_CONSOLE_COLOR(WHITE);
    cout << "Please enter the related number of your requested command? ";

}

int main(){

    CLEAR_CONSOLE();

    Department hrmdep;

    int choice;
    
    cout << "Welcome to Human Resourse Management (HRM) Software of Company XYZ.\n\nTo do Specific task please choose one of the following commands.\n\n";
    
    do{
        printHomeChoice();
        cin >> choice;
        switch(choice){
            case 1:
                hrmdep.AddPerson();
                break;
            case 2:
                hrmdep.DeletePerson();
                break;
            case 3:
                hrmdep.UpdatePerson();
                break;
            case 4:
                hrmdep.ReportList();
                break;
            case 5:
                hrmdep.SearchPerson();
                break;
            case 6:{
                cout << "\n\nExiting system...\n";
                exit(1);
                break;
            }
            case 7:
                hrmdep.ShowAllEmployees();
                break;
            default:
                cout << "Invalid Option!!!";
                break;
        }
        WaitForKeyPress();
        CLEAR_CONSOLE();
    }while(1);
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <conio.h>

#include "person.h"

#define CYAN 3
#define RED 4
#define GREEN 10
#define WHITE 15
#define YELLOW 14

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 
inline void SET_CONSOLE_COLOR(int color) {
    SetConsoleTextAttribute(hConsole, color);
} 
inline void CLEAR_CONSOLE() {
    system("CLS");
}  

void WaitForKeyPress() {
    cout << "\nPress Enter to continue...";
    getch();
}

/* ---------------------------PERSON CLASS------------------------------------------ */

// CLASS PERSON
class Person {
    private:
        int personalID;
        string firstName;
        string lastName;
        double salary;
        double workingHours;
        double costPerHour;

    public:
        Person() {} 
        
        void Set_FirstName(string firstName) {
            this->firstName = firstName;
        }

        void Set_LastName(string lastName) {
            this->lastName = lastName;
        } 

        void Set_WorkingHours(double workingHours) {
            this->workingHours = workingHours;
        }

        void Set_CostPerHour(double workingHours) {
            this->workingHours = workingHours;
        }

        int Get_PersonalID() {
            return this->personalID;
        }

        string Get_FirstName() {
            return this->firstName;
        }

        string Get_LastName() {
            return this->lastName;
        }

        double Get_SalaryPerYear(){
            return this->workingHours * this->costPerHour * 52;
        }

        double Get_WorkingHour() {
            return this->workingHours;
        }

        double Get_CostPerHour() {
            return this->costPerHour;
        }
        
        void CreatePerson(int id){
            this->personalID = id;
            double _workingHours, _costPerHour;
            cout << "Please enter the first name of the employee? ";
            cin >>  this->firstName;
            cout << "Please enter the last name of the employee? ";
            cin >> this->lastName;
            
            while (1) {
                cout << "How many hours a week is his/her work? ";
                cin >> _workingHours;
                if(_workingHours > 0) {
                    this->workingHours = _workingHours;
                    break;
                }
                else {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\nInvalid Working Hour for a Person!!!\nPlease Retry\n\n";
                    SetConsoleTextAttribute(hConsole, 15);

                }
            }

            while (1) {
                cout << "How much per hour is his/her salary? ";
                cin >> _costPerHour;
                if(_costPerHour > 0) {
                    this->costPerHour = _costPerHour;
                    break;
                }
                else{
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\nInvalid Cost Per Hour for a Person!!!\nPlease Retry\n\n";
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
            SET_CONSOLE_COLOR(GREEN);
            cout << "\n\nThe empolyee with the following information is added to the system.\n\n";
            SetConsoleTextAttribute(hConsole, 15);
        }

        void DisplayPerson(){
            cout << "FirstName\tLastName\tPersonalID\tSalaryPerYear(Euros)\n";
            cout << "--------------------------------------------------------------------\n";
            cout << this->firstName << "\t\t" << this->lastName << "\t\t" << this->personalID << "\t\t" << this->Get_SalaryPerYear() << "\n";
            cout << "--------------------------------------------------------------------\n";
        }

};

void swap(Person* a, Person* b) {
    Person t = *a;
    *a = *b;
    *b = t;
}

int partition (Person arr[], int low, int high, int choice) {
    
    double pivot = arr[high].Get_SalaryPerYear();
    int pivotID = arr[high].Get_PersonalID();
    string pivotStr = arr[high].Get_LastName();
    int i = (low - 1);
                            
    for (int j = low; j <= high - 1; j++) {

        switch (choice){
            case 1:{
                if ((arr[j].Get_LastName().compare(pivotStr)) < 0 ) {
                    i++; // increment index of smaller element
                    swap(&arr[i], &arr[j]);
                    
                }
                break;
            }
            case 2:{
                if (arr[j].Get_SalaryPerYear()  < pivot) {
                    i++; // increment index of smaller element
                    swap(&arr[i], &arr[j]);
                    
                }
                break;
            }
            case 3:{
                if (arr[j].Get_PersonalID()  < pivotID) {
                    i++; // increment index of smaller element
                    swap(&arr[i], &arr[j]);
                }
                break;
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
    
}

void quickSort(Person arr[], int low, int high, int choice) {
    if (low < high) {
        int pi = partition(arr, low, high, choice);
        quickSort(arr, low, pi - 1, choice);
        quickSort(arr, pi + 1, high, choice);
    }
}


// CLASS DEPARTMENT 

class Department {
    private:

        Person employees[100];
        int noOfEmployees = 0;

        int binarySearch(Person arr[], int l, int r, double id){
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (arr[m].Get_PersonalID() == id) return m;
                if (arr[m].Get_PersonalID() < id) l = m + 1;
                else r = m - 1;
            }
            return -1;
        }
    
    public:
        void AddPerson(){
            CLEAR_CONSOLE();
            SET_CONSOLE_COLOR(CYAN);
            cout << "--- ADDING EMPLOYEE ---\n";
            SET_CONSOLE_COLOR(WHITE);
            int id;
            if(noOfEmployees == 0){
                id = 8921001;
            }   
            else{
                id = employees[noOfEmployees - 1].Get_PersonalID() + 1;
            }

            Person newPerson;
            newPerson.CreatePerson(id);
            newPerson.DisplayPerson();

            cout << "\n\n";
            this->employees[noOfEmployees] = newPerson;
            noOfEmployees++;

        }

        void DeletePerson(){
            CLEAR_CONSOLE();
            SET_CONSOLE_COLOR(RED);
            cout << "--- DELETING EMPLOYEE ---\n";
            SET_CONSOLE_COLOR(WHITE);
            int employeeToDelete;

            getPersonalIDtoDelete:
            cout << "Please enter the personal number of an employee: ";
            cin >> employeeToDelete;

            int position = binarySearch(employees, 0, noOfEmployees - 1, employeeToDelete);
            if(position !=  -1 ){
                for(int i = position; i < noOfEmployees - 1; i++){
                    employees[i] = employees[i + 1];
                }
                noOfEmployees--;

                SET_CONSOLE_COLOR(RED);
                cout << "\nTHE EMPLOYEE INFO IS DELETED!!!\n";
                SET_CONSOLE_COLOR(WHITE);
            }
            else {
                char choice;
                SET_CONSOLE_COLOR(RED);
                cout << "Sorry, there is not any employee with the requested personal ID.\nDo you want to repeat delete by entering the new personal number (y/n)? ";
                SET_CONSOLE_COLOR(WHITE);
                cin >> choice;
                CLEAR_CONSOLE();
                if(choice == 'y') 
                    goto getPersonalIDtoDelete;
            }

        }

        void UpdatePerson(){

            getPersonalIDtoSearch:
            CLEAR_CONSOLE();
            SET_CONSOLE_COLOR(CYAN);
            cout << "--- UPDATING EMPLOYEE INFO ---\n";
            SET_CONSOLE_COLOR(WHITE);

            int employeeToSearch;

            
            cout << "Please enter the personal number of an employee? ";
            cin >> employeeToSearch;

            int position = binarySearch(employees, 0, noOfEmployees - 1, employeeToSearch);

            if(position != -1 ){
               //  update
                employees[position].DisplayPerson();
                char cont;
                do {
                    int choice;
                    cout << "\nPlease enter the related number of field which you would like to update\n";
                    cout << "1. First name\n2. Family name\n3.Working hours per week\n4.Payement for one hour\nEnter choice? ";
                    cin >> choice;
                    switch (choice) {
                        case 1:{
                            string firstName;
                            cout << "Please enter new First name for " << employees[position].Get_LastName() << " ? ";
                            cin >> firstName;
                            employees[position].Set_FirstName(firstName);
                            break;}
                        case 2:{
                            string lastName;
                            cout << "Please enter new Family name for " << employees[position].Get_LastName() << " ? ";
                            cin >> lastName;
                            employees[position].Set_LastName(lastName);
                            break;}
                        case 3:{
                            double workingHours;
                            cout << "Please enter new Working hours per week for " << employees[position].Get_LastName() << " ? ";
                            cin >> workingHours;
                            employees[position].Set_WorkingHours(workingHours);
                            break;}
                        case 4:{
                            double costPerHour;
                            cout << "Please enter new Cost per hour for " << employees[position].Get_LastName() << " ? ";
                            cin >> costPerHour;
                            employees[position].Set_CostPerHour(costPerHour);
                            break;}
                    }  
                    
                    cout << "Do you like to update any other field (y/n)? ";
                    cin >> cont;
                }while( cont == 'y');
                CLEAR_CONSOLE();
                char ch;
                SET_CONSOLE_COLOR(GREEN);
                employees[position].DisplayPerson();
                cout << "\nThe information for " << employees[position].Get_LastName() << " has been updated. Do you want to repeat update by entering the new personal number (y/n)? ";
                SET_CONSOLE_COLOR(WHITE);
                cin >> ch;
                if(ch == 'y') 
                    goto getPersonalIDtoSearch;
            }
            else {
                char choice;
                SET_CONSOLE_COLOR(RED);
                cout << "Sorry, there is not any employee with the requested personal ID. Do you want to repeat update by entering the new personal number (y/n)? ";
                SET_CONSOLE_COLOR(WHITE);
                cin >> choice;
                if(choice == 'y') 
                    goto getPersonalIDtoSearch;
            }

        }

        void ReportList(){
            
            char newReport;
            do{
                CLEAR_CONSOLE();
                SET_CONSOLE_COLOR(CYAN);
                cout << "--- DEPARTMENT REPORT ---\n";
                SET_CONSOLE_COLOR(WHITE);
                int choice;
                cout << "Please enter the related number of field which you would like to sort the list based on it.\n1. Family Name\n2. Salary\nPlease Enter you choice? ";
                cin >> choice;

                quickSort(employees, 0 , noOfEmployees - 1, choice);
                ShowAllEmployees();
                quickSort(employees, 0 , noOfEmployees - 1, 3);
                
                cout << "Do you want to generate a new report (y/n)? ";
                cin >> newReport;      

            }while(newReport == 'y');

            
        }

        void SearchPerson(){
                
                char newSearch;
                do{
                    CLEAR_CONSOLE();
                    SET_CONSOLE_COLOR(CYAN);
                    cout << "--- SEARCHING EMPLOYEE ---\n";
                    SET_CONSOLE_COLOR(WHITE);
                    int choice;
                    cout << "Search is based on two Fields\n1. Family Name\n2. Salary\nPlease Enter you choice? ";
                    cin >> choice;
                    switch (choice) {
                        case 2: { 
                            double S_min, S_max;
                            cout << "Please define your search range for the salary of the employees (S_min, S_max).\n";
                            cout << "What is the minimum salary for search (S_min)? ";
                            cin >> S_min;
                            cout << "What is the maximum salary for search (S_max)? ";
                            cin >> S_max;
                            int res = 0;

                            for(int i = 0 ; i < noOfEmployees; i++){

                                if(employees[i].Get_SalaryPerYear() >= S_min && employees[i].Get_SalaryPerYear() <= S_max){
                                    if(res == 0){
                                        cout << "FirstName\tLastName\tPersonalID\tSalaryPerYear (Euros)\n";
                                        cout << "--------------------------------------------------------------------\n";
                                        cout << employees[i].Get_FirstName() << "\t\t" << employees[i].Get_LastName() << "\t\t" << employees[i].Get_PersonalID() << "\t\t" << employees[i].Get_SalaryPerYear() << "\n";
                                        res++;
                                    }
                                    else{
                                        cout << employees[i].Get_FirstName() << "\t\t" << employees[i].Get_LastName() << "\t\t" << employees[i].Get_PersonalID() << "\t\t" << employees[i].Get_SalaryPerYear() << "\n";
                                    }
                                }
                            }

                            if(res == 0){
                                SET_CONSOLE_COLOR(RED);
                                cout << "\nNO RESULTS FOUND!!!\n\n";
                                SET_CONSOLE_COLOR(WHITE);
                            }

                            break;
                        }
                        case 1: {
                            string lastNameToFind;
                            cout << "Please enter the family name of the employee? ";
                            cin >> lastNameToFind;

                            int res = 0;

                            for(int i = 0 ; i < noOfEmployees; i++){
                                string lastName = employees[i].Get_LastName();
                                transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
                                transform(lastNameToFind.begin(), lastNameToFind.end(), lastNameToFind.begin(), ::tolower);
                                if(lastName == lastNameToFind){
                                    if(res == 0){
                                        cout << "FirstName\tLastName\tPersonalID\tSalaryPerYear (Euros)\n";
                                        cout << "--------------------------------------------------------------------\n";
                                        cout << employees[i].Get_FirstName() << "\t\t" << employees[i].Get_LastName() << "\t\t" << employees[i].Get_PersonalID() << "\t\t" << employees[i].Get_SalaryPerYear() << "\n";
                                        res++;
                                    }
                                    else{
                                        cout << employees[i].Get_FirstName() << "\t\t" << employees[i].Get_LastName() << "\t\t" << employees[i].Get_PersonalID() << "\t\t" << employees[i].Get_SalaryPerYear() << "\n";
                                    }
                                }
                            }

                            if(res == 0){
                                SET_CONSOLE_COLOR(RED);
                                cout << "\nNO RESULTS FOUND!!!\n\n";
                                SET_CONSOLE_COLOR(WHITE);
                            }
                        }
                            

                        
                    }
                    cout << "Do you want to do new search (y/n)? ";
                    cin >> newSearch;


                } while(newSearch == 'y');

        }

        void ShowAllEmployees(){
            CLEAR_CONSOLE();
            SET_CONSOLE_COLOR(CYAN);
            cout << "--- EMPLOYEE ---\n";
            SET_CONSOLE_COLOR(WHITE);

            if(noOfEmployees == 0){
                SET_CONSOLE_COLOR(RED);
                cout << "\n\nNo Employees added yet!!\n\n";
                SET_CONSOLE_COLOR(WHITE);
                return;
            }
            
            cout << "FirstName\tLastName\tPersonalID\tSalaryPerYear (Euros)\n";
            cout << "--------------------------------------------------------------------\n";
            for(int i = 0; i < noOfEmployees; i++){
                cout << employees[i].Get_FirstName() << "\t\t" << employees[i].Get_LastName() << "\t\t" << employees[i].Get_PersonalID() << "\t\t" << employees[i].Get_SalaryPerYear() << "\n";
            }
        }
};

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
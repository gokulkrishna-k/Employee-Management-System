class Department
{
private:
    map<int, Person> employees;
    int noOfEmployees = 0;
    static int idCounter;

    void displayPerson(Person p)
    {
        cout << "FirstName\tLastName\tPersonalID\tSalaryPerYear(Euros)\n";
        cout << "--------------------------------------------------------------------\n";
        cout << p.Get_FirstName() << "\t\t" << p.Get_LastName() << "\t\t" << p.Get_PersonalID() << "\t\t" << p.Get_SalaryPerYear() << "\n";
        cout << "--------------------------------------------------------------------\n";
    }

public:
    Department() {}

    map<int, Person> Get_employees()
    {
        return employees;
    }

    void AddPerson()
    {
        CLEAR_CONSOLE();
        ShowMessage("--- ADDING EMPLOYEE ---\n", CYAN);

        string fName, lName;
        double wHours, cpHour;
        cout << "Please enter the first name of the employee? ";
        cin >> fName;
        cout << "Please enter the last name of the employee? ";
        cin >> lName;

        while (1)
        {
            cout << "How many hours a week is his/her work? ";
            cin >> wHours;
            if (wHours > 0)
            {
                break;
            }
            else
            {
                ShowMessage("\nInvalid Working Hour for a Person!!!\nPlease Retry\n\n", RED);
            }
        }

        while (1)
        {
            cout << "How much per hour is his/her salary? ";
            cin >> cpHour;
            if (cpHour > 0)
                break;
            else
            {
                ShowMessage("\nInvalid Cost Per Hour for a Person!!!\nPlease Retry\n\n", RED);
            }
        }

        ShowMessage("\n\nThe empolyee with the following information is added to the system.\n\n", GREEN);

        Person newPerson(idCounter, fName, lName, wHours, cpHour);
        cout << "\n\n";
        employees.insert(pair<int, Person>(idCounter, newPerson));

        displayPerson(newPerson);

        delete &newPerson;

        idCounter++;
        noOfEmployees++;
    }

    void addData(string fName, string lName, double wHours, double cpHour)
    {
        Person newPerson(idCounter, fName, lName, wHours, cpHour);
        cout << "\n\n";
        employees.insert(pair<int, Person>(idCounter, newPerson));
        displayPerson(newPerson);
        delete &newPerson;
        idCounter++;
        noOfEmployees++;
    }

    void DeletePerson()
    {
        CLEAR_CONSOLE();
        ShowMessage("--- DELETING EMPLOYEE ---\n", RED);

        int employeeToDelete;

    getPersonalIDtoDelete:
        cout << "Please enter the personal number of an employee: ";
        cin >> employeeToDelete;

        map<int, Person>::iterator itr;
        itr = employees.find(employeeToDelete);
        if (itr != employees.end())
        {
            employees.erase(employeeToDelete);
            noOfEmployees--;
            ShowMessage("\nTHE EMPLOYEE INFO IS DELETED!!!\n", RED);
        }
        else
        {
            char choice;
            ShowMessage("Sorry, there is not any employee with the requested personal ID.\nDo you want to repeat delete by entering the new personal number (y/n)? ", RED);

            cin >> choice;
            CLEAR_CONSOLE();
            if (choice == 'y')
                goto getPersonalIDtoDelete;
        }
    }

    void UpdatePerson()
    {

    getPersonalIDtoSearch:
        CLEAR_CONSOLE();

        ShowMessage("--- UPDATING EMPLOYEE INFO ---\n", CYAN);

        int employeeToSearch;

        cout << "Please enter the personal number of an employee? ";
        cin >> employeeToSearch;

        map<int, Person>::iterator itr;
        itr = employees.find(employeeToSearch);

        if (itr != employees.end())
        {
            displayPerson(itr->second);
            char cont;
            do
            {
                int choice;
                cout << "\nPlease enter the related number of field which you would like to update\n";
                cout << "1. First name\n2. Family name\n3.Working hours per week\n4.Payement for one hour\nEnter choice? ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    string firstName;
                    cout << "Please enter new First name for " << itr->second.Get_LastName() << " ? ";
                    cin >> firstName;
                    itr->second.Set_FirstName(firstName);
                    break;
                }
                case 2:
                {
                    string lastName;
                    cout << "Please enter new Family name for " << itr->second.Get_LastName() << " ? ";
                    cin >> lastName;
                    itr->second.Set_LastName(lastName);
                    break;
                }
                case 3:
                {
                    double workingHours;
                    cout << "Please enter new Working hours per week for " << itr->second.Get_LastName() << " ? ";
                    cin >> workingHours;
                    itr->second.Set_WorkingHours(workingHours);
                    break;
                }
                case 4:
                {
                    double costPerHour;
                    cout << "Please enter new Cost per hour for " << itr->second.Get_LastName() << " ? ";
                    cin >> costPerHour;
                    itr->second.Set_CostPerHour(costPerHour);
                    break;
                }
                }

                cout << "Do you like to update any other field (y/n)? ";
                cin >> cont;
            } while (cont == 'y');

            CLEAR_CONSOLE();
            SET_CONSOLE_COLOR(GREEN);
            displayPerson(itr->second);
            cout << "\nThe information for " << itr->second.Get_LastName() << " has been updated. Do you want to repeat update by entering the new personal number (y/n)? ";
            SET_CONSOLE_COLOR(WHITE);

            char ch;
            cin >> ch;
            if (ch == 'y')
                goto getPersonalIDtoSearch;
        }
        else
        {
            char choice;
            ShowMessage("Sorry, there is not any employee with the requested personal ID. Do you want to repeat update by entering the new personal number (y/n)? ", RED);
            cin >> choice;
            if (choice == 'y')
                goto getPersonalIDtoSearch;
        }
    }

    void ReportList()
    {

        char newReport;
        do
        {
            CLEAR_CONSOLE();
            ShowMessage("--- DEPARTMENT REPORT ---\n", CYAN);
            int choice;
            cout << "Please enter the related number of field which you would like to sort the list based on it.\n1. Family Name\n2. Salary\nPlease Enter you choice? ";
            cin >> choice;

            vector<Person> tempEmployeeVector;
            for (const auto &entry : employees)
            {
                tempEmployeeVector.push_back(entry.second);
            }
            quickSort(tempEmployeeVector, 0, noOfEmployees - 1, choice);

            cout << "FirstName\tLastName\tPersonalID\tSalaryPerYear (Euros)\n";
            cout << "--------------------------------------------------------------------\n";

            for (int i = 0; i < tempEmployeeVector.size(); i++)
            {
                cout << tempEmployeeVector[i].Get_FirstName() << "\t\t" << tempEmployeeVector[i].Get_LastName() << "\t\t" << tempEmployeeVector[i].Get_PersonalID() << "\t\t" << tempEmployeeVector[i].Get_SalaryPerYear() << "\n";
            }

            delete &tempEmployeeVector;

            cout << "Do you want to generate a new report (y/n)? ";
            cin >> newReport;

        } while (newReport == 'y');
    }

    // void SearchPerson(){

    //         char newSearch;
    //         do{
    //             CLEAR_CONSOLE();
    //             SET_CONSOLE_COLOR(CYAN);
    //             cout << "--- SEARCHING EMPLOYEE ---\n";
    //             SET_CONSOLE_COLOR(WHITE);
    //             int choice;
    //             cout << "Search is based on two Fields\n1. Family Name\n2. Salary\nPlease Enter you choice? ";
    //             cin >> choice;
    //             switch (choice) {
    //                 case 2: {
    //                     double S_min, S_max;
    //                     cout << "Please define your search range for the salary of the employees (S_min, S_max).\n";
    //                     cout << "What is the minimum salary for search (S_min)? ";
    //                     cin >> S_min;
    //                     cout << "What is the maximum salary for search (S_max)? ";
    //                     cin >> S_max;
    //                     int res = 0;

    //                     for(int i = 0 ; i < noOfEmployees; i++){

    //                         if(employees[i].Get_SalaryPerYear() >= S_min && employees[i].Get_SalaryPerYear() <= S_max){
    //                             if(res == 0){
    //                                 cout << "FirstName\tLastName\tPersonalID\tSalaryPerYear (Euros)\n";
    //                                 cout << "--------------------------------------------------------------------\n";
    //                                 cout << employees[i].Get_FirstName() << "\t\t" << employees[i].Get_LastName() << "\t\t" << employees[i].Get_PersonalID() << "\t\t" << employees[i].Get_SalaryPerYear() << "\n";
    //                                 res++;
    //                             }
    //                             else{
    //                                 cout << employees[i].Get_FirstName() << "\t\t" << employees[i].Get_LastName() << "\t\t" << employees[i].Get_PersonalID() << "\t\t" << employees[i].Get_SalaryPerYear() << "\n";
    //                             }
    //                         }
    //                     }

    //                     if(res == 0){
    //                         SET_CONSOLE_COLOR(RED);
    //                         cout << "\nNO RESULTS FOUND!!!\n\n";
    //                         SET_CONSOLE_COLOR(WHITE);
    //                     }

    //                     break;
    //                 }
    //                 case 1: {
    //                     string lastNameToFind;
    //                     cout << "Please enter the family name of the employee? ";
    //                     cin >> lastNameToFind;

    //                     int res = 0;

    //                     for(int i = 0 ; i < noOfEmployees; i++){
    //                         string lastName = employees[i].Get_LastName();
    //                         transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
    //                         transform(lastNameToFind.begin(), lastNameToFind.end(), lastNameToFind.begin(), ::tolower);
    //                         if(lastName == lastNameToFind){
    //                             if(res == 0){
    //                                 cout << "FirstName\tLastName\tPersonalID\tSalaryPerYear (Euros)\n";
    //                                 cout << "--------------------------------------------------------------------\n";
    //                                 cout << employees[i].Get_FirstName() << "\t\t" << employees[i].Get_LastName() << "\t\t" << employees[i].Get_PersonalID() << "\t\t" << employees[i].Get_SalaryPerYear() << "\n";
    //                                 res++;
    //                             }
    //                             else{
    //                                 cout << employees[i].Get_FirstName() << "\t\t" << employees[i].Get_LastName() << "\t\t" << employees[i].Get_PersonalID() << "\t\t" << employees[i].Get_SalaryPerYear() << "\n";
    //                             }
    //                         }
    //                     }

    //                     if(res == 0){
    //                         SET_CONSOLE_COLOR(RED);
    //                         cout << "\nNO RESULTS FOUND!!!\n\n";
    //                         SET_CONSOLE_COLOR(WHITE);
    //                     }
    //                 }
    //             }
    //             cout << "Do you want to do new search (y/n)? ";
    //             cin >> newSearch;
    //         } while(newSearch == 'y');
    // }

    void ShowAllEmployees()
    {
        // CLEAR_CONSOLE();
        ShowMessage("--- EMPLOYEE ---\n", CYAN);

        if (noOfEmployees == 0)
        {
            ShowMessage("\n\nNo Employees added yet!!\n\n", RED);
            return;
        }
        map<int, Person>::iterator itr;
        cout << "FirstName\tLastName\tPersonalID\tSalaryPerYear (Euros)\n";
        cout << "--------------------------------------------------------------------\n";

        for (itr = employees.begin(); itr != employees.end(); itr++)
        {
            cout << itr->second.Get_FirstName() << "\t\t" << itr->second.Get_LastName() << "\t\t" << itr->second.Get_PersonalID() << "\t\t" << itr->second.Get_SalaryPerYear() << "\n";
        }
    }
};

int Department::idCounter = 8921001;
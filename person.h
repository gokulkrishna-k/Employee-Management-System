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

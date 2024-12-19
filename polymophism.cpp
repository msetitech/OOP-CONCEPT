#include<iostream>
#include<string>
using namespace std;
class Employee{
    private:
        string name;
        int id;
        
    public:
    Employee(string empName, int empID):name(empName),id(empID){}

    void displayInformation(){
        cout << "--- Employee System ---\n";
        cout << "Employee Name: " << name << "\nEmployee ID: " << id << endl;
    }
};

class Manager : public Employee {
    private:
        string bonus;
    public:
        Manager(string empName, int empID, string empBonus) : Employee(empName,empID),bonus(empBonus){}
    
        void displayInformation()  {
                cout << "Manager Information\n";
                Employee::displayInformation();
                cout << "Bonus: " << bonus << endl;
            }
};

int main(){
    Employee *emp1 = new Manager("Ibrahim Mseti", 1234, "Manager");
    emp1->displayInformation();
    cout << endl;
    return 0;
}
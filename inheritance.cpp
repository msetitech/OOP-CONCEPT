#include <iostream>>
#include<string>

using namespace std;


//Parent class Of employee
class Employee{
private:
    string name;
    int pfnumber;
    int id;
    double salary;

public:
    Employee(string name, int pf, int id, double salary):name(name), pfnumber(pf), id(id), salary(salary){}

    void displayInfo(){
        cout << "Employee Name : " << name << "\nEmployee ID: " << id << "\nEmployee PF No: " << pfnumber << "\nEmployee Salary: " << salary << endl;
    }
};


//inherited class That inherit from parent class

class Manager:public Employee{
    private:
        string promotion;

    public:
    Manager(string name, int pf, int id, double salary, string position):Employee(name, pf, id, salary), promotion(position){} 

    void displayManagerInfo(){
        displayInfo();
        cout << "\nPosition: " << promotion << endl;
    }
}
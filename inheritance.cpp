#include <iostream>
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
};

//drived class for developer

class Developer : public Employee{

    private:
        string programmingLanguage;
    public:
    Developer(string name, int empPF, int empID, double salary,string planguage):Employee(name, empPF, empID, salary),programmingLanguage(planguage){}
    
    void displayDeveloperInfo(){
        displayInfo();
        cout << "\nLanguage: " << programmingLanguage << endl;
    }
};


int main(){
    Manager mng("Ibrahim Mseti", 347, 987654321, 467000.97, "manager");
    Developer dev("Ibrahim Mseti", 347, 987654321, 467000.97, "C++, Js,React, C, Kotlin");

    mng.displayManagerInfo();
    cout << "\n----------------------------------------------" << endl;
    dev.displayDeveloperInfo();
    cout << "\n----------------------------------------------" << endl;
    return 0;
}
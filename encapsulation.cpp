#include<iostream>
#include<string>
using namespace std;


//Key concept in Encapsulation is that all data is private and is accessible using Public MEthod Ony
class Employee{
    private:
        string name;
        int id;
        double salary;

    public:
    Employee(string empName, int empID, double empSalary):name(empName),id(empID),salary(empSalary){}

//Key feature to get data by setter and get Methods

//Setter and Get for name
void setName(string empName){
    name = empName;
}
string getName(){
    return name;
}


//Setter and Get for name
void setId(int empID){
    id = empID;
}
int getId(){
    return id;
}


//Setter and Get for name
void setSalary(double empSalary){
    salary = empSalary;
}
double getSalary(){
    return salary;
}


};


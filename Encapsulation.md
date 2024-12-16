### **Encapsulation in Depth Reviw**

---

Encapsulation is a fundamental concept in Object-Oriented Programming (OOP) that emphasizes **data hiding** and **modular design**. It ensures that the internal workings of a class are hidden from the outside world, and interaction with the class occurs through well-defined interfaces.

#### **Key Principles of Encapsulation**

1. **Access Modifiers**: Control access to the data members and member functions of a class.

   - `private`: Accessible only within the same class.
   - `protected`: Accessible within the class and derived classes.
   - `public`: Accessible from anywhere.

2. **Data Hiding**: Keeps data safe from unintended interference and misuse by making it private and exposing only necessary details through getter and setter methods.

3. **Encapsulation in C++**: Achieved by combining data (fields) and methods (functions) into a class, while restricting direct access to the fields.

---

#### **Advantages of Encapsulation**

1. **Improves Code Maintainability**:
   - Changes to the implementation details of a class do not affect code using the class, as long as the interface remains consistent.
2. **Enhances Security**:

   - Sensitive or critical data is hidden and can only be accessed or modified through controlled methods.

3. **Promotes Modularity**:

   - Classes act as self-contained modules, making it easier to debug, test, and reuse code.

4. **Allows Validation**:
   - By using setters, you can validate data before assigning it to class members.

---

### **Encapsulation Example in Employee Management System**

#### **Basic Example**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name; // Private data member
    int id;      // Private data member
    double salary; // Private data member

public:
    // Constructor to initialize employee
    Employee(string empName, int empId, double empSalary) {
        name = empName;
        id = empId;
        salary = empSalary;
    }

    // Setter for name
    void setName(string empName) {
        name = empName;
    }

    // Getter for name
    string getName() {
        return name;
    }

    // Setter for ID
    void setId(int empId) {
        if (empId > 0) { // Validating the input
            id = empId;
        } else {
            cout << "Invalid ID. It must be greater than 0." << endl;
        }
    }

    // Getter for ID
    int getId() {
        return id;
    }

    // Setter for Salary
    void setSalary(double empSalary) {
        if (empSalary >= 0) { // Validating the input
            salary = empSalary;
        } else {
            cout << "Invalid Salary. It cannot be negative." << endl;
        }
    }

    // Getter for Salary
    double getSalary() {
        return salary;
    }

    // Method to display employee details
    void displayDetails() {
        cout << "Employee ID: " << id << "\nName: " << name << "\nSalary: $" << salary << endl;
    }
};

int main() {
    // Creating an employee object
    Employee emp("Alice", 101, 5000.0);

    // Accessing and modifying data through getters and setters
    cout << "Before updates:" << endl;
    emp.displayDetails();

    emp.setName("Alicia");
    emp.setId(102);
    emp.setSalary(5500.0);

    cout << "\nAfter updates:" << endl;
    emp.displayDetails();

    // Invalid data updates
    emp.setId(-5); // Will display validation error
    emp.setSalary(-1000.0); // Will display validation error

    return 0;
}
```

---

### **Features Illustrated**

1. **Private Members**: The data members (`name`, `id`, `salary`) are private, preventing direct access from outside the class.
2. **Getter and Setter Methods**: Used to provide controlled access to private members.
3. **Validation**: The setter methods include logic to validate inputs, ensuring the data remains consistent and correct.

---

#### **Encapsulation and Real-World Analogy**

Think of an ATM:

- You interact with the ATM via a **public interface** (the screen and buttons), but you don’t know or need to know how it processes your request internally.
- The ATM **hides internal details** such as the database operations or how money is dispensed.
- It ensures security by validating inputs (e.g., correct PIN) and restricting access to your account.

Similarly, in encapsulation:

- **Data members (internal details)** are hidden.
- **Methods (interface)** handle interaction and ensure controlled access.

---

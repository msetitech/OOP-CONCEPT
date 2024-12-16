### **Inheritance in Depth**

Inheritance is one of the pillars of Object-Oriented Programming (OOP) that allows a class (known as the **child** or **derived** class) to acquire properties and behaviors (data members and methods) from another class (known as the **parent** or **base** class). It promotes **reusability**, **extensibility**, and **polymorphism**.

---

### **Key Concepts in Inheritance**

1. **Base and Derived Classes**:

   - The **Base Class** is the class whose members (fields and methods) are inherited.
   - The **Derived Class** is the class that inherits from the base class.

2. **Access Specifiers and Inheritance**:

   - Inheritance depends on the access specifier (`public`, `protected`, `private`) in the base class.
   - The way members are inherited depends on the type of inheritance.

3. **Types of Inheritance in C++**:

   - **Single Inheritance**: A class inherits from one base class.
   - **Multiple Inheritance**: A class inherits from more than one base class.
   - **Multilevel Inheritance**: A class is derived from another derived class.
   - **Hierarchical Inheritance**: Multiple classes inherit from a single base class.
   - **Hybrid Inheritance**: A combination of two or more types of inheritance.

4. **Constructors and Destructors in Inheritance**:
   - Constructors of the base class are called first, followed by the derived class.
   - Destructors are called in reverse order (derived class destructor first).

---

### **Access Control in Inheritance**

The accessibility of base class members in the derived class depends on:

1. The **access specifier** in the base class (`public`, `protected`, `private`).
2. The **mode of inheritance** in the derived class (`public`, `protected`, `private`).

| Base Class Member Access | Public Inheritance | Protected Inheritance | Private Inheritance |
| ------------------------ | ------------------ | --------------------- | ------------------- |
| **Public Members**       | Public             | Protected             | Private             |
| **Protected Members**    | Protected          | Protected             | Private             |
| **Private Members**      | Not Inherited      | Not Inherited         | Not Inherited       |

---

### **Inheritance Examples**

#### 1. **Single Inheritance**

A derived class inherits from a single base class.

```cpp
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string empName, int empId) : name(empName), id(empId) {}

    void displayBasicInfo() {
        cout << "Name: " << name << "\nID: " << id << endl;
    }
};

// Derived Class
class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string empName, int empId, double empBonus) : Employee(empName, empId), bonus(empBonus) {}

    void displayManagerInfo() {
        displayBasicInfo();
        cout << "Bonus: $" << bonus << endl;
    }
};

int main() {
    Manager mgr("Alice", 101, 5000.0);
    mgr.displayManagerInfo();
    return 0;
}
```

---

#### 2. **Multilevel Inheritance**

A derived class is further inherited by another class.

```cpp
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
protected:
    string name;

public:
    Person(string personName) : name(personName) {}

    void displayPerson() {
        cout << "Name: " << name << endl;
    }
};

// Derived Class
class Employee : public Person {
protected:
    int id;

public:
    Employee(string empName, int empId) : Person(empName), id(empId) {}

    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << id << endl;
    }
};

// Further Derived Class
class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string mgrName, int mgrId, double mgrBonus) : Employee(mgrName, mgrId), bonus(mgrBonus) {}

    void displayManager() {
        displayEmployee();
        cout << "Bonus: $" << bonus << endl;
    }
};

int main() {
    Manager mgr("Bob", 202, 10000.0);
    mgr.displayManager();
    return 0;
}
```

---

#### 3. **Hierarchical Inheritance**

Multiple derived classes inherit from a single base class.

```cpp
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string empName, int empId) : name(empName), id(empId) {}

    void displayBasicInfo() {
        cout << "Name: " << name << "\nID: " << id << endl;
    }
};

// Derived Class 1
class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string empName, int empId, double empBonus) : Employee(empName, empId), bonus(empBonus) {}

    void displayManagerInfo() {
        displayBasicInfo();
        cout << "Bonus: $" << bonus << endl;
    }
};

// Derived Class 2
class Developer : public Employee {
private:
    string language;

public:
    Developer(string empName, int empId, string devLanguage) : Employee(empName, empId), language(devLanguage) {}

    void displayDeveloperInfo() {
        displayBasicInfo();
        cout << "Programming Language: " << language << endl;
    }
};

int main() {
    Manager mgr("Alice", 101, 7000.0);
    Developer dev("Charlie", 102, "C++");

    mgr.displayManagerInfo();
    cout << endl;
    dev.displayDeveloperInfo();

    return 0;
}
```

---

#### 4. **Multiple Inheritance**

A class inherits from multiple base classes.

```cpp
#include <iostream>
using namespace std;

// Base Class 1
class Person {
protected:
    string name;

public:
    Person(string personName) : name(personName) {}
};

// Base Class 2
class Organization {
protected:
    string orgName;

public:
    Organization(string organizationName) : orgName(organizationName) {}
};

// Derived Class
class Employee : public Person, public Organization {
private:
    int id;

public:
    Employee(string empName, string organizationName, int empId)
        : Person(empName), Organization(organizationName), id(empId) {}

    void displayInfo() {
        cout << "Name: " << name << "\nOrganization: " << orgName << "\nEmployee ID: " << id << endl;
    }
};

int main() {
    Employee emp("Diana", "Tech Corp", 201);
    emp.displayInfo();
    return 0;
}
```

---

### **Key Challenges and Features in Inheritance**

1. **Constructor Call Order**:

   - Base class constructors are called before derived class constructors.
   - In multilevel inheritance, constructors are called in the hierarchy order (from top-most base to derived).

2. **Virtual Base Classes (Ambiguity Resolution)**:
   - In multiple inheritance, if two base classes share a common base class, the derived class gets two copies of the common base class, leading to ambiguity.
   - Use **virtual base classes** to solve this.

#### Example:

```cpp
class A {
    // Common base class
};

class B : virtual public A {
    // Derived from A
};

class C : virtual public A {
    // Derived from A
};

class D : public B, public C {
    // Derived from both B and C
};
```

---

### **Benefits of Inheritance**

1. **Reusability**: Base class functionality can be reused in derived classes.
2. **Extensibility**: New functionality can be added without modifying existing code.
3. **Polymorphism**: Base class pointers or references can point to derived class objects.

---

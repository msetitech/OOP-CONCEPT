### **Polymorphism in Depth**

Polymorphism, one of the key principles of Object-Oriented Programming (OOP), allows objects to take on many forms. It enables a single interface to control access to a variety of related types.

Polymorphism enhances code flexibility and maintainability by allowing behavior to vary depending on the object type at runtime or compile time.

---

### **Types of Polymorphism**

Polymorphism in C++ is broadly classified into two categories:

1. **Compile-Time Polymorphism (Static Binding)**:

   - Behavior is determined at compile time.
   - Achieved using:
     - **Function Overloading**
     - **Operator Overloading**

2. **Run-Time Polymorphism (Dynamic Binding)**:
   - Behavior is determined at runtime.
   - Achieved using:
     - **Virtual Functions**
     - **Function Overriding**

---

### **1. Compile-Time Polymorphism**

#### **Function Overloading**

- Functions with the same name but different parameter lists (type or number of arguments).
- Resolved during compilation.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    // Function to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Function to add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Function to add two doubles
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    cout << "Sum of 2 integers: " << calc.add(10, 20) << endl;
    cout << "Sum of 3 integers: " << calc.add(10, 20, 30) << endl;
    cout << "Sum of 2 doubles: " << calc.add(10.5, 20.3) << endl;
    return 0;
}
```

---

#### **Operator Overloading**

- Redefines the behavior of operators for user-defined types.
- Improves readability and maintainability.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2.3, 4.5), c2(1.1, 3.3);
    Complex c3 = c1 + c2; // Uses overloaded + operator
    c3.display();
    return 0;
}
```

---

### **2. Run-Time Polymorphism**

#### **Function Overriding**

- A derived class provides its own version of a base class function.
- Requires the function in the base class to be marked as `virtual`.
- Function resolution occurs at runtime.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Employee {
public:
    virtual void work() {
        cout << "Employee is working on general tasks." << endl;
    }
};

class Manager : public Employee {
public:
    void work() override {
        cout << "Manager is managing the team." << endl;
    }
};

class Developer : public Employee {
public:
    void work() override {
        cout << "Developer is writing code." << endl;
    }
};

int main() {
    Employee* emp1 = new Manager();
    Employee* emp2 = new Developer();

    emp1->work(); // Manager's work() is called
    emp2->work(); // Developer's work() is called

    delete emp1;
    delete emp2;
    return 0;
}
```

---

#### **Virtual Functions**

- Declared in the base class using the `virtual` keyword.
- Enables overriding in derived classes.
- Ensures correct function is invoked for the object type.

**Key Points**:

1. Virtual functions rely on the **vtable** (virtual table) mechanism.
2. Only pointers or references to base class objects can invoke overridden behavior.

---

#### **Pure Virtual Functions and Abstract Classes**

- A **pure virtual function** has no implementation in the base class and forces derived classes to override it.
- A class containing at least one pure virtual function is called an **abstract class**.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle." << endl;
    }
};

int main() {
    Shape* s1 = new Circle();
    Shape* s2 = new Rectangle();

    s1->draw();
    s2->draw();

    delete s1;
    delete s2;
    return 0;
}
```

---

### **Polymorphism in Real-World Systems**

#### **Example: Employee Management System**

- Use polymorphism to implement role-based tasks.

```cpp
#include <iostream>
using namespace std;

// Abstract Base Class
class Employee {
public:
    virtual void performTask() = 0; // Pure virtual function
    virtual ~Employee() {}
};

// Derived Classes
class Manager : public Employee {
public:
    void performTask() override {
        cout << "Manager is conducting a meeting." << endl;
    }
};

class Developer : public Employee {
public:
    void performTask() override {
        cout << "Developer is fixing bugs." << endl;
    }
};

class Intern : public Employee {
public:
    void performTask() override {
        cout << "Intern is preparing a report." << endl;
    }
};

int main() {
    Employee* employees[3];

    employees[0] = new Manager();
    employees[1] = new Developer();
    employees[2] = new Intern();

    for (int i = 0; i < 3; ++i) {
        employees[i]->performTask();
        delete employees[i];
    }

    return 0;
}
```

---

### **Advantages of Polymorphism**

1. **Flexibility**:
   - Code can work with objects of different types through a common interface.
2. **Extensibility**:
   - New functionality can be added with minimal changes to existing code.
3. **Maintainability**:
   - Code is easier to read and modify.

---

### **Comparison Between Compile-Time and Run-Time Polymorphism**

| **Aspect**         | **Compile-Time Polymorphism** | **Run-Time Polymorphism**     |
| ------------------ | ----------------------------- | ----------------------------- |
| **Binding Time**   | Compile time                  | Runtime                       |
| **Implementation** | Function/Operator Overloading | Virtual Functions, Overriding |
| **Performance**    | Faster, no runtime overhead   | Slightly slower due to vtable |
| **Flexibility**    | Less flexible                 | Highly flexible               |

---

Would you like to explore **advanced virtual functions**, **polymorphism and memory management**, or **real-world design patterns** using polymorphism?

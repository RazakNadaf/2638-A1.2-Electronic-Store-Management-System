/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Employee.h

Description:
Represents an employee working in the electronics store.
Inherits from Person class and can update product stock
in the inventory. Demonstrates inheritance, encapsulation,
and polymorphism in C++.
=========================================================
*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Inventory.h"

class Employee : public Person {
private:
    std::string role;

public:
    // Constructor to initialize employee attributes
    Employee(int employeeId, const std::string& name, const std::string& role, const std::string& contactNo)
        : Person(employeeId, name, contactNo), role(role) {}

    // Getters and Setters
    int getEmployeeId() const {
        return id;
    }

    std::string getRole() const {
        return role;
    }

    void setRole(const std::string& r) {
        this->role = r;
    }

    // Method allowing employee to update product stock
    void manageStock(Inventory& inventory, int productId, int newQuantity) {
        std::cout << "Employee " << name << " (" << role << ") is updating inventory stock...\n";
        inventory.updateStock(productId, newQuantity);
    }

    // Display employee details (Method Overriding)
    void displayDetails() const override {
        std::cout << "Employee ID: " << id
                  << " | Name: " << name
                  << " | Role: " << role
                  << " | Contact: " << contactNo << "\n";
    }
};

#endif // EMPLOYEE_H

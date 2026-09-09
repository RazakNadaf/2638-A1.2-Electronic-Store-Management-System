/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Person.h

Description:
Abstract parent class for common personal details like
ID, name, and contact number. Inherited by Owner,
Employee, and Customer classes. Demonstrates abstraction
and runtime polymorphism in C++.
=========================================================
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
protected:
    // Common attributes for all persons
    int id;
    std::string name;
    std::string contactNo;

public:
    // Constructor to initialize common details
    Person(int id, const std::string& name, const std::string& contactNo)
        : id(id), name(name), contactNo(contactNo) {}

    // Virtual destructor for proper polymorphic cleanup
    virtual ~Person() = default;

    // Getters and Setters
    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    std::string getContactNo() const {
        return contactNo;
    }

    void setContactNo(const std::string& contactNo) {
        this->contactNo = contactNo;
    }

    // Pure virtual method to be implemented by child classes
    virtual void displayDetails() const = 0;
};

#endif // PERSON_H

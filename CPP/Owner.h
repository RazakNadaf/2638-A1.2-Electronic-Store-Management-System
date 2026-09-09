/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Owner.h

Description:
Represents the store owner. Extends the Person class to
inherit basic details and display owner information.
Demonstrates single inheritance and method overriding.
=========================================================
*/

#ifndef OWNER_H
#define OWNER_H

#include "Person.h"

class Owner : public Person {
public:
    // Constructor passing details to Person superclass
    Owner(int ownerId, const std::string& name, const std::string& contactNo)
        : Person(ownerId, name, contactNo) {}

    // Getter for owner id
    int getOwnerId() const {
        return id;
    }

    // Display owner details (Method Overriding)
    void displayDetails() const override {
        std::cout << "Owner ID: " << id << "\n";
        std::cout << "Owner Name: " << name << "\n";
        std::cout << "Contact Number: " << contactNo << "\n";
    }
};

#endif // OWNER_H

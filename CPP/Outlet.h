/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Outlet.h

Description:
Represents a physical branch/outlet of the electronic store.
Each outlet maintains its own Inventory object to manage stock.
Demonstrates composition and encapsulation in C++.
=========================================================
*/

#ifndef OUTLET_H
#define OUTLET_H

#include <string>
#include <iostream>
#include "Inventory.h"

class Outlet {
private:
    int outletId;
    std::string name;
    std::string address;
    std::string contactNo;
    Inventory inventory;

public:
    // Constructor creates a dedicated Inventory instance for this outlet (Composition)
    Outlet(int outletId = 0, const std::string& name = "",
           const std::string& address = "", const std::string& contactNo = "")
        : outletId(outletId), name(name), address(address), contactNo(contactNo),
          inventory(outletId * 10, outletId) {}

    // Getters and Setters
    int getOutletId() const {
        return outletId;
    }

    void setOutletId(int id) {
        this->outletId = id;
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& n) {
        this->name = n;
    }

    std::string getAddress() const {
        return address;
    }

    void setAddress(const std::string& addr) {
        this->address = addr;
    }

    std::string getContactNo() const {
        return contactNo;
    }

    void setContactNo(const std::string& cNo) {
        this->contactNo = cNo;
    }

    Inventory& getInventory() {
        return inventory;
    }

    const Inventory& getInventory() const {
        return inventory;
    }

    void setInventory(const Inventory& inv) {
        this->inventory = inv;
    }

    // Display outlet information
    void displayOutletDetails() const {
        std::cout << "Outlet ID: " << outletId << "\n";
        std::cout << "Outlet Name: " << name << "\n";
        std::cout << "Address: " << address << "\n";
        std::cout << "Contact Number: " << contactNo << "\n";
        std::cout << "Total Products in Stock: " << inventory.getProducts().size() << "\n";
    }
};

#endif // OUTLET_H

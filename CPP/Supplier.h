/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Supplier.h

Description:
Represents an external supplier who provides electronic
products to the store catalog. Demonstrates encapsulation
in C++.
=========================================================
*/

#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <iostream>

class Supplier {
private:
    int supplierId;
    std::string supplierName;
    std::string contactNo;

public:
    // Constructor
    Supplier(int supplierId, const std::string& supplierName, const std::string& contactNo)
        : supplierId(supplierId), supplierName(supplierName), contactNo(contactNo) {}

    // Getters and Setters
    int getSupplierId() const {
        return supplierId;
    }

    void setSupplierId(int sId) {
        this->supplierId = sId;
    }

    std::string getSupplierName() const {
        return supplierName;
    }

    void setSupplierName(const std::string& sName) {
        this->supplierName = sName;
    }

    std::string getContactNo() const {
        return contactNo;
    }

    void setContactNo(const std::string& cNo) {
        this->contactNo = cNo;
    }

    // Display supplier details
    void displaySupplier() const {
        std::cout << "Supplier ID: " << supplierId
                  << " | Name: " << supplierName
                  << " | Contact: " << contactNo << "\n";
    }
};

#endif // SUPPLIER_H

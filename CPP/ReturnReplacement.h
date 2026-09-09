/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : ReturnReplacement.h

Description:
Manages customer requests for product returns or replacements
including the reason, type (Return/Replacement), and status.
Demonstrates encapsulation and association in C++.
=========================================================
*/

#ifndef RETURN_REPLACEMENT_H
#define RETURN_REPLACEMENT_H

#include <string>
#include <iostream>
#include "Customer.h"

class ReturnReplacement {
private:
    int returnId;
    int productId;
    std::string reason;
    std::string type; // "Return" or "Replacement"
    std::string status;
    Customer* customer;

public:
    // Constructor to initialize return/replacement request
    ReturnReplacement(int returnId, int productId, const std::string& reason,
                      const std::string& type, const std::string& status,
                      Customer* customer = nullptr)
        : returnId(returnId), productId(productId), reason(reason),
          type(type), status(status), customer(customer) {}

    // Getters and Setters
    int getReturnId() const {
        return returnId;
    }

    void setReturnId(int id) {
        this->returnId = id;
    }

    int getProductId() const {
        return productId;
    }

    void setProductId(int pId) {
        this->productId = pId;
    }

    std::string getReason() const {
        return reason;
    }

    void setReason(const std::string& r) {
        this->reason = r;
    }

    std::string getType() const {
        return type;
    }

    void setType(const std::string& t) {
        this->type = t;
    }

    std::string getStatus() const {
        return status;
    }

    void setStatus(const std::string& s) {
        this->status = s;
    }

    Customer* getCustomer() const {
        return customer;
    }

    void setCustomer(Customer* cust) {
        this->customer = cust;
    }

    // Process and approve the request
    void processRequest() {
        this->status = "Approved";
        std::cout << "----------------------------------------\n";
        std::cout << "    RETURN / REPLACEMENT PROCESSING     \n";
        std::cout << "----------------------------------------\n";
        std::cout << "Request ID: " << returnId << "\n";
        std::cout << "Customer: " << (customer != nullptr ? customer->getName() : "Customer") << "\n";
        std::cout << "Product ID: " << productId << "\n";
        std::cout << "Type: " << type << "\n";
        std::cout << "Reason: " << reason << "\n";
        std::cout << "Status: " << status << "\n";
        std::cout << ">> " << type << " request processed and approved!\n";
        std::cout << "----------------------------------------\n";
    }

    // Display request summary
    void displayDetails() const {
        std::cout << "Request ID: " << returnId
                  << " | Customer: " << (customer != nullptr ? customer->getName() : "N/A")
                  << " | Product ID: " << productId
                  << " | Type: " << type
                  << " | Reason: " << reason
                  << " | Status: " << status << "\n";
    }
};

#endif // RETURN_REPLACEMENT_H

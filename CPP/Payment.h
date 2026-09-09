/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Payment.h

Description:
Represents a payment transaction made by a customer.
Handles payment processing, receipt generation, and payment
mode selection (Cash, Card, UPI). Demonstrates encapsulation
and association in C++.
=========================================================
*/

#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <iostream>
#include "Customer.h"

class Payment {
private:
    int paymentId;
    double amount;
    std::string paymentMode; // Cash, Card, UPI
    std::string paymentStatus;
    Customer* customer;

public:
    // Constructor to record payment details
    Payment(int paymentId, double amount, const std::string& paymentMode,
            const std::string& paymentStatus, Customer* customer = nullptr)
        : paymentId(paymentId), amount(amount), paymentMode(paymentMode),
          paymentStatus(paymentStatus), customer(customer) {}

    // Getters and Setters
    int getPaymentId() const {
        return paymentId;
    }

    void setPaymentId(int id) {
        this->paymentId = id;
    }

    double getAmount() const {
        return amount;
    }

    void setAmount(double amt) {
        this->amount = amt;
    }

    std::string getPaymentMode() const {
        return paymentMode;
    }

    void setPaymentMode(const std::string& mode) {
        this->paymentMode = mode;
    }

    std::string getPaymentStatus() const {
        return paymentStatus;
    }

    void setPaymentStatus(const std::string& status) {
        this->paymentStatus = status;
    }

    Customer* getCustomer() const {
        return customer;
    }

    void setCustomer(Customer* cust) {
        this->customer = cust;
    }

    // Process and print payment receipt
    void processPayment() {
        this->paymentStatus = "Paid";
        std::cout << "----------------------------------------\n";
        std::cout << "           PAYMENT RECEIPT              \n";
        std::cout << "----------------------------------------\n";
        std::cout << "Payment ID: " << paymentId << "\n";
        std::cout << "Customer: " << (customer != nullptr ? customer->getName() : "Walk-in Customer") << "\n";
        std::cout << "Amount Paid: Rs. " << amount << "\n";
        std::cout << "Payment Mode: " << paymentMode << "\n";
        std::cout << "Status: " << paymentStatus << "\n";
        std::cout << ">> Payment completed successfully!\n";
        std::cout << "----------------------------------------\n";
    }

    // Display basic payment summary
    void displayPayment() const {
        std::cout << "Payment ID: " << paymentId
                  << " | Customer: " << (customer != nullptr ? customer->getName() : "N/A")
                  << " | Amount: Rs. " << amount
                  << " | Mode: " << paymentMode
                  << " | Status: " << paymentStatus << "\n";
    }
};

#endif // PAYMENT_H

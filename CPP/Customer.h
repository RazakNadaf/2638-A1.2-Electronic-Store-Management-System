/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Customer.h

Description:
Represents a customer in the store. Extends Person class
and includes methods to purchase products and submit
ratings/reviews. Demonstrates inheritance, runtime
polymorphism (method overriding), and compile-time
polymorphism (method overloading) in C++.
=========================================================
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Product.h"

class Customer : public Person {
private:
    int age;
    std::string address;
    std::string review;
    int rating;

public:
    // Constructor to initialize customer details
    Customer(int customerId, const std::string& name, int age,
             const std::string& contactNo, const std::string& address)
        : Person(customerId, name, contactNo),
          age(age), address(address),
          review("No review yet"), rating(0) {}

    // Getters and Setters
    int getCustomerId() const {
        return id;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    std::string getAddress() const {
        return address;
    }

    void setAddress(const std::string& address) {
        this->address = address;
    }

    std::string getReview() const {
        return review;
    }

    int getRating() const {
        return rating;
    }

    // Purchase product and reduce quantity from stock
    bool purchaseProduct(Product& product, int quantity) {
        if (product.getStockQuantity() >= quantity) {
            product.setStockQuantity(product.getStockQuantity() - quantity);
            std::cout << ">> " << name << " successfully purchased " << quantity
                      << " unit(s) of " << product.getName() << ".\n";
            return true;
        } else {
            std::cout << ">> Error: Insufficient stock for " << product.getName()
                      << ". Available: " << product.getStockQuantity() << "\n";
            return false;
        }
    }

    // Overloaded method to give review with default 5-star rating (Method Overloading)
    void giveReview(const std::string& reviewText) {
        this->review = reviewText;
        this->rating = 5;
        std::cout << ">> Review recorded from " << name << ": \"" << reviewText << "\" (Rating: 5/5)\n";
    }

    // Overloaded method to give review with custom rating (Method Overloading)
    void giveReview(const std::string& reviewText, int stars) {
        this->review = reviewText;
        this->rating = stars;
        std::cout << ">> Review recorded from " << name << ": \"" << reviewText << "\" (" << stars << "/5 stars)\n";
    }

    // Display customer information (Method Overriding)
    void displayDetails() const override {
        std::cout << "Customer ID: " << id << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Contact: " << contactNo << "\n";
        std::cout << "Address: " << address << "\n";
        if (rating > 0) {
            std::cout << "Feedback: " << review << " (" << rating << " Stars)\n";
        }
        std::cout << "----------------------------------------\n";
    }

    void displayCustomer() const {
        displayDetails();
    }
};

#endif // CUSTOMER_H

/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Product.h

Description:
Represents an electronic product in the store with
details like brand, price, discount percentage, warranty,
and current stock quantity. Demonstrates encapsulation
and aggregation with Supplier in C++.
=========================================================
*/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Supplier.h"

class Product {
private:
    int productId;
    std::string name;
    std::string brand;
    double price;
    double discount; // Discount percentage
    std::string warranty;
    int stockQuantity;
    Supplier* supplier;

public:
    // Constructor to initialize product details
    Product(int productId, const std::string& name, const std::string& brand,
            double price, double discount, const std::string& warranty,
            int stockQuantity, Supplier* supplier = nullptr)
        : productId(productId), name(name), brand(brand),
          price(price), discount(discount), warranty(warranty),
          stockQuantity(stockQuantity), supplier(supplier) {}

    // Getters and Setters
    int getProductId() const {
        return productId;
    }

    void setProductId(int pId) {
        this->productId = pId;
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& n) {
        this->name = n;
    }

    std::string getBrand() const {
        return brand;
    }

    void setBrand(const std::string& b) {
        this->brand = b;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double p) {
        this->price = p;
    }

    double getDiscount() const {
        return discount;
    }

    void setDiscount(double d) {
        this->discount = d;
    }

    std::string getWarranty() const {
        return warranty;
    }

    void setWarranty(const std::string& w) {
        this->warranty = w;
    }

    int getStockQuantity() const {
        return stockQuantity;
    }

    void setStockQuantity(int sq) {
        this->stockQuantity = sq;
    }

    Supplier* getSupplier() const {
        return supplier;
    }

    void setSupplier(Supplier* s) {
        this->supplier = s;
    }

    // Calculate discounted final price
    double getFinalPrice() const {
        return price - (price * (discount / 100.0));
    }

    // Display product specifications
    void displayProduct() const {
        std::cout << "Product ID: " << productId << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Brand: " << brand << "\n";
        std::cout << "Price: Rs. " << price << "\n";
        std::cout << "Discount: " << discount << "%\n";
        std::cout << "Final Price: Rs. " << getFinalPrice() << "\n";
        std::cout << "Warranty: " << warranty << "\n";
        std::cout << "Stock Quantity: " << stockQuantity << "\n";
        if (supplier != nullptr) {
            std::cout << "Supplier: " << supplier->getSupplierName() << "\n";
        }
        std::cout << "----------------------------------------\n";
    }
};

#endif // PRODUCT_H

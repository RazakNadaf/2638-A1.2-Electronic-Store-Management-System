/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Inventory.h

Description:
Manages the list of products and stock levels for a store
outlet. Allows adding, removing, searching, and updating
product stock. Demonstrates aggregation and encapsulation in C++.
=========================================================
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <iostream>
#include "Product.h"

class Inventory {
private:
    int inventoryId;
    int outletId;
    std::vector<Product> products;

public:
    // Constructor initializing an empty product list
    Inventory(int inventoryId = 0, int outletId = 0)
        : inventoryId(inventoryId), outletId(outletId) {}

    // Getters and Setters
    int getInventoryId() const {
        return inventoryId;
    }

    void setInventoryId(int iId) {
        this->inventoryId = iId;
    }

    int getOutletId() const {
        return outletId;
    }

    void setOutletId(int oId) {
        this->outletId = oId;
    }

    std::vector<Product>& getProducts() {
        return products;
    }

    const std::vector<Product>& getProducts() const {
        return products;
    }

    // Add new product to the list
    void addProduct(const Product& product) {
        products.push_back(product);
        std::cout << ">> Product \"" << product.getName() << "\" added to inventory successfully.\n";
    }

    // Remove product by its ID
    bool removeProduct(int productId) {
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i].getProductId() == productId) {
                std::string removedName = products[i].getName();
                products.erase(products.begin() + i);
                std::cout << ">> Product \"" << removedName << "\" (ID: " << productId << ") removed from inventory.\n";
                return true;
            }
        }
        std::cout << ">> Error: Product with ID " << productId << " not found.\n";
        return false;
    }

    // Update stock quantity for a product
    bool updateStock(int productId, int quantity) {
        for (auto& p : products) {
            if (p.getProductId() == productId) {
                p.setStockQuantity(quantity);
                std::cout << ">> Stock for \"" << p.getName() << "\" updated to " << quantity << " units.\n";
                return true;
            }
        }
        std::cout << ">> Error: Product with ID " << productId << " not found.\n";
        return false;
    }

    // Search for a product by ID
    Product* findProduct(int productId) {
        for (auto& p : products) {
            if (p.getProductId() == productId) {
                return &p;
            }
        }
        return nullptr;
    }

    // Calculate total stock count across all items
    int getTotalStockQuantity() const {
        int total = 0;
        for (const auto& p : products) {
            total += p.getStockQuantity();
        }
        return total;
    }

    // Display all products in this inventory
    void displayInventory() const {
        std::cout << "========================================\n";
        std::cout << "         OUTLET INVENTORY LIST          \n";
        std::cout << "Inventory ID: " << inventoryId << " | Outlet ID: " << outletId << "\n";
        std::cout << "========================================\n";
        if (products.empty()) {
            std::cout << "No products available in inventory.\n";
        } else {
            for (const auto& p : products) {
                p.displayProduct();
            }
        }
    }
};

#endif // INVENTORY_H

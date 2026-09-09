/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Main.cpp

Description:
Main driver program providing a console-based interactive
menu to perform operations in the Electronic Store System.
Demonstrates object creation, method invocation, and
console I/O handling in C++.
=========================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Person.h"
#include "Owner.h"
#include "Employee.h"
#include "Customer.h"
#include "Supplier.h"
#include "Product.h"
#include "Inventory.h"
#include "Outlet.h"
#include "Payment.h"
#include "ReturnReplacement.h"
#include "ElectronicStore.h"

// Helper function to trim whitespace from both ends of a string
static inline std::string trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    auto end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

int main() {
    int paymentIdCounter = 1001;
    int returnIdCounter = 501;

    // Setting up store, owner, branch outlet, and manager
    Owner owner(1, "Razak", "9876543210");
    Outlet mainOutlet(101, "Downtown Branch", "123 Main Street", "9876500001");
    ElectronicStore store(1, "TechZone Electronics Store", "9876500000", &owner, &mainOutlet);

    // Employee working in store
    Employee manager(1, "Aakash", "Store Manager", "9876512345");
    store.addEmployee(manager);

    // Lists to track payments and returns during the session
    std::vector<Payment> paymentHistory;
    std::vector<ReturnReplacement> returnHistory;

    std::cout << "=================================================\n";
    std::cout << "       ELECTRONICS STORE MANAGEMENT SYSTEM       \n";
    std::cout << "=================================================\n";

    bool running = true;
    std::string line;

    while (running) {
        std::cout << "\n----------------- MAIN MENU -----------------\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. View Products\n";
        std::cout << "3. Search Product\n";
        std::cout << "4. Update Product\n";
        std::cout << "5. Delete Product\n";
        std::cout << "6. Add Supplier\n";
        std::cout << "7. View Suppliers\n";
        std::cout << "8. Add Customer\n";
        std::cout << "9. View Customers\n";
        std::cout << "10. Make Payment\n";
        std::cout << "11. Return/Replacement\n";
        std::cout << "12. Exit\n";
        std::cout << "---------------------------------------------\n";
        std::cout << "Enter your choice (1-12): ";

        if (!std::getline(std::cin, line)) {
            break;
        }

        std::string choice = trim(line);

        if (choice == "1") {
            // Add Product
            std::cout << "\n--- ADD NEW PRODUCT ---\n";
            try {
                std::cout << "Enter Product ID: ";
                if (!std::getline(std::cin, line)) break;
                int prodId = std::stoi(trim(line));

                if (store.findProduct(prodId) != nullptr) {
                    std::cout << ">> Error: Product ID already exists.\n";
                    continue;
                }

                std::cout << "Enter Product Name: ";
                if (!std::getline(std::cin, line)) break;
                std::string name = trim(line);

                std::cout << "Enter Brand: ";
                if (!std::getline(std::cin, line)) break;
                std::string brand = trim(line);

                std::cout << "Enter Price (Rs.): ";
                if (!std::getline(std::cin, line)) break;
                double price = std::stod(trim(line));

                std::cout << "Enter Discount (%): ";
                if (!std::getline(std::cin, line)) break;
                double discount = std::stod(trim(line));

                std::cout << "Enter Warranty (e.g. 1 Year): ";
                if (!std::getline(std::cin, line)) break;
                std::string warranty = trim(line);

                std::cout << "Enter Stock Quantity: ";
                if (!std::getline(std::cin, line)) break;
                int stock = std::stoi(trim(line));

                Supplier* supplier = nullptr;
                if (!store.getSuppliers().empty()) {
                    std::cout << "Available Suppliers:\n";
                    for (const auto& s : store.getSuppliers()) {
                        s.displaySupplier();
                    }
                    std::cout << "Enter Supplier ID (or 0 for none): ";
                    if (!std::getline(std::cin, line)) break;
                    int supId = std::stoi(trim(line));
                    supplier = store.findSupplier(supId);
                }

                Product newProduct(prodId, name, brand, price, discount, warranty, stock, supplier);
                store.addProduct(newProduct);

            } catch (const std::exception&) {
                std::cout << ">> Error: Invalid numeric input.\n";
            }
        } else if (choice == "2") {
            // View Products
            std::cout << "\n--- PRODUCT LIST ---\n";
            if (store.getProducts().empty()) {
                std::cout << "No products available. Use Option 1 to add products.\n";
            } else {
                for (const auto& p : store.getProducts()) {
                    p.displayProduct();
                }
            }
        } else if (choice == "3") {
            // Search Product
            std::cout << "\n--- SEARCH PRODUCT ---\n";
            try {
                std::cout << "Enter Product ID to search: ";
                if (!std::getline(std::cin, line)) break;
                int searchId = std::stoi(trim(line));
                Product* found = store.findProduct(searchId);
                if (found != nullptr) {
                    std::cout << "\n>> Product Found:\n";
                    found->displayProduct();
                } else {
                    std::cout << ">> Product with ID " << searchId << " not found.\n";
                }
            } catch (const std::exception&) {
                std::cout << ">> Error: Invalid Product ID.\n";
            }
        } else if (choice == "4") {
            // Update Product
            std::cout << "\n--- UPDATE PRODUCT ---\n";
            try {
                std::cout << "Enter Product ID to update: ";
                if (!std::getline(std::cin, line)) break;
                int updateId = std::stoi(trim(line));
                Product* toUpdate = store.findProduct(updateId);
                if (toUpdate == nullptr) {
                    std::cout << ">> Product not found.\n";
                    continue;
                }

                std::cout << "Current details:\n";
                toUpdate->displayProduct();

                std::cout << "Enter New Price (or press Enter to skip): ";
                if (!std::getline(std::cin, line)) break;
                std::string priceInput = trim(line);
                if (!priceInput.empty()) {
                    toUpdate->setPrice(std::stod(priceInput));
                }

                std::cout << "Enter New Discount % (or press Enter to skip): ";
                if (!std::getline(std::cin, line)) break;
                std::string discInput = trim(line);
                if (!discInput.empty()) {
                    toUpdate->setDiscount(std::stod(discInput));
                }

                std::cout << "Enter New Stock Quantity (or press Enter to skip): ";
                if (!std::getline(std::cin, line)) break;
                std::string stockInput = trim(line);
                if (!stockInput.empty()) {
                    int newStock = std::stoi(stockInput);
                    // Demonstrating Employee managing stock
                    if (store.getInventory() != nullptr) {
                        manager.manageStock(*(store.getInventory()), updateId, newStock);
                    }
                }

                std::cout << ">> Product updated successfully!\n";
            } catch (const std::exception&) {
                std::cout << ">> Error: Invalid numeric input.\n";
            }
        } else if (choice == "5") {
            // Delete Product
            std::cout << "\n--- DELETE PRODUCT ---\n";
            try {
                std::cout << "Enter Product ID to delete: ";
                if (!std::getline(std::cin, line)) break;
                int deleteId = std::stoi(trim(line));
                store.removeProduct(deleteId);
            } catch (const std::exception&) {
                std::cout << ">> Error: Invalid Product ID.\n";
            }
        } else if (choice == "6") {
            // Add Supplier
            std::cout << "\n--- ADD SUPPLIER ---\n";
            try {
                std::cout << "Enter Supplier ID: ";
                if (!std::getline(std::cin, line)) break;
                int supId = std::stoi(trim(line));

                if (store.findSupplier(supId) != nullptr) {
                    std::cout << ">> Error: Supplier ID already exists.\n";
                    continue;
                }

                std::cout << "Enter Supplier Name: ";
                if (!std::getline(std::cin, line)) break;
                std::string supName = trim(line);

                std::cout << "Enter Contact Number: ";
                if (!std::getline(std::cin, line)) break;
                std::string contact = trim(line);

                Supplier newSupplier(supId, supName, contact);
                store.addSupplier(newSupplier);
            } catch (const std::exception&) {
                std::cout << ">> Error: Invalid Supplier ID.\n";
            }
        } else if (choice == "7") {
            // View Suppliers
            std::cout << "\n--- SUPPLIERS LIST ---\n";
            if (store.getSuppliers().empty()) {
                std::cout << "No suppliers registered yet. Use Option 6 to add suppliers.\n";
            } else {
                for (const auto& s : store.getSuppliers()) {
                    s.displaySupplier();
                }
            }
        } else if (choice == "8") {
            // Add Customer
            std::cout << "\n--- ADD CUSTOMER ---\n";
            try {
                std::cout << "Enter Customer ID: ";
                if (!std::getline(std::cin, line)) break;
                int custId = std::stoi(trim(line));

                if (store.findCustomer(custId) != nullptr) {
                    std::cout << ">> Error: Customer ID already exists.\n";
                    continue;
                }

                std::cout << "Enter Customer Name: ";
                if (!std::getline(std::cin, line)) break;
                std::string custName = trim(line);

                std::cout << "Enter Age: ";
                if (!std::getline(std::cin, line)) break;
                int age = std::stoi(trim(line));

                std::cout << "Enter Contact Number: ";
                if (!std::getline(std::cin, line)) break;
                std::string contact = trim(line);

                std::cout << "Enter Address: ";
                if (!std::getline(std::cin, line)) break;
                std::string address = trim(line);

                Customer newCustomer(custId, custName, age, contact, address);
                store.addCustomer(newCustomer);
            } catch (const std::exception&) {
                std::cout << ">> Error: Invalid numeric input.\n";
            }
        } else if (choice == "9") {
            // View Customers
            std::cout << "\n--- CUSTOMERS LIST ---\n";
            if (store.getCustomers().empty()) {
                std::cout << "No customers registered yet. Use Option 8 to add customers.\n";
            } else {
                for (const auto& c : store.getCustomers()) {
                    c.displayCustomer();
                }
            }
        } else if (choice == "10") {
            // Make Payment / Purchase
            std::cout << "\n--- MAKE PAYMENT / PURCHASE PRODUCT ---\n";
            if (store.getProducts().empty()) {
                std::cout << ">> No products in store to purchase. Add products first.\n";
                continue;
            }

            try {
                Customer* currentCustomer = nullptr;
                if (!store.getCustomers().empty()) {
                    std::cout << "Registered Customers:\n";
                    for (const auto& c : store.getCustomers()) {
                        std::cout << "ID: " << c.getCustomerId() << " | Name: " << c.getName() << "\n";
                    }
                    std::cout << "Enter Customer ID (or 0 for new walk-in customer): ";
                    if (!std::getline(std::cin, line)) break;
                    int custId = std::stoi(trim(line));
                    currentCustomer = store.findCustomer(custId);
                }

                if (currentCustomer == nullptr) {
                    std::cout << "Enter Customer Name: ";
                    if (!std::getline(std::cin, line)) break;
                    std::string name = trim(line);

                    std::cout << "Enter Contact: ";
                    if (!std::getline(std::cin, line)) break;
                    std::string contact = trim(line);

                    int walkInId = static_cast<int>(store.getCustomers().size()) + 100;
                    Customer walkInCustomer(walkInId, name, 25, contact, "Walk-in");
                    store.addCustomer(walkInCustomer);
                    currentCustomer = store.findCustomer(walkInId);
                }

                std::cout << "\nAvailable Products:\n";
                for (const auto& p : store.getProducts()) {
                    std::cout << "ID: " << p.getProductId() << " | " << p.getName()
                              << " | Price: Rs. " << p.getPrice()
                              << " | Final Price (after " << p.getDiscount() << "% disc): Rs. " << p.getFinalPrice()
                              << " | Stock: " << p.getStockQuantity() << "\n";
                }

                std::cout << "Enter Product ID to buy: ";
                if (!std::getline(std::cin, line)) break;
                int buyId = std::stoi(trim(line));
                Product* toBuy = store.findProduct(buyId);
                if (toBuy == nullptr) {
                    std::cout << ">> Product not found.\n";
                    continue;
                }

                std::cout << "Enter Quantity: ";
                if (!std::getline(std::cin, line)) break;
                int qty = std::stoi(trim(line));

                // Customer attempts to purchase
                bool success = currentCustomer->purchaseProduct(*toBuy, qty);
                if (!success) {
                    continue;
                }

                double totalAmount = toBuy->getFinalPrice() * qty;
                std::cout << "Total Amount to Pay: Rs. " << totalAmount << "\n";

                std::cout << "Select Payment Mode:\n";
                std::cout << "1. Cash\n";
                std::cout << "2. Card\n";
                std::cout << "3. UPI\n";
                std::cout << "Enter choice (1-3): ";
                if (!std::getline(std::cin, line)) break;
                std::string modeChoice = trim(line);
                std::string mode = "Cash";
                if (modeChoice == "2") mode = "Card";
                else if (modeChoice == "3") mode = "UPI";

                // Create and process payment
                Payment payment(paymentIdCounter++, totalAmount, mode, "Pending", currentCustomer);
                payment.processPayment();
                paymentHistory.push_back(payment);

                // Option to leave a review
                std::cout << "Would customer like to give a review? (y/n): ";
                if (!std::getline(std::cin, line)) break;
                std::string revAns = trim(line);
                if (revAns == "y" || revAns == "Y") {
                    std::cout << "Enter review comment: ";
                    if (!std::getline(std::cin, line)) break;
                    std::string reviewText = trim(line);

                    std::cout << "Enter rating (1 to 5 stars): ";
                    if (!std::getline(std::cin, line)) break;
                    int stars = std::stoi(trim(line));
                    currentCustomer->giveReview(reviewText, stars);
                }

            } catch (const std::exception&) {
                std::cout << ">> Error: Invalid numeric input.\n";
            }
        } else if (choice == "11") {
            // Return / Replacement
            std::cout << "\n--- REQUEST RETURN / REPLACEMENT ---\n";
            try {
                Customer* retCustomer = nullptr;
                if (!store.getCustomers().empty()) {
                    std::cout << "Enter Customer ID: ";
                    if (!std::getline(std::cin, line)) break;
                    int cId = std::stoi(trim(line));
                    retCustomer = store.findCustomer(cId);
                }

                std::cout << "Enter Product ID: ";
                if (!std::getline(std::cin, line)) break;
                int rProdId = std::stoi(trim(line));

                std::cout << "Enter Reason for request: ";
                if (!std::getline(std::cin, line)) break;
                std::string reason = trim(line);

                std::cout << "Select Request Type:\n";
                std::cout << "1. Return\n";
                std::cout << "2. Replacement\n";
                std::cout << "Enter choice (1 or 2): ";
                if (!std::getline(std::cin, line)) break;
                std::string typeChoice = trim(line);
                std::string type = (typeChoice == "1") ? "Return" : "Replacement";

                ReturnReplacement rr(returnIdCounter++, rProdId, reason, type, "Pending", retCustomer);
                rr.processRequest();
                returnHistory.push_back(rr);

            } catch (const std::exception&) {
                std::cout << ">> Error: Invalid numeric input.\n";
            }
        } else if (choice == "12") {
            // Exit
            std::cout << "\n=================================================\n";
            std::cout << "  Thank you for using TechZone Electronics Store!\n";
            std::cout << "=================================================\n";
            running = false;
        } else {
            std::cout << ">> Invalid choice! Please select an option between 1 and 12.\n";
        }
    }

    return 0;
}

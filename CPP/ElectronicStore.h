/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : ElectronicStore.h

Description:
Main electronic store class managing relations between Owner,
Outlet, Employees, Products, Suppliers, Customers, and
Inventory stock. Demonstrates composition and aggregation in C++.
=========================================================
*/

#ifndef ELECTRONIC_STORE_H
#define ELECTRONIC_STORE_H

#include <string>
#include <vector>
#include <iostream>
#include "Owner.h"
#include "Outlet.h"
#include "Employee.h"
#include "Supplier.h"
#include "Customer.h"

class ElectronicStore {
private:
    int storeId;
    std::string name;
    std::string contactNo;
    Owner* owner;
    Outlet* outlet;
    std::vector<Employee> employees;
    std::vector<Supplier> suppliers;
    std::vector<Customer> customers;

public:
    // Constructor connecting all main store components
    ElectronicStore(int storeId, const std::string& name, const std::string& contactNo,
                    Owner* owner = nullptr, Outlet* outlet = nullptr)
        : storeId(storeId), name(name), contactNo(contactNo),
          owner(owner), outlet(outlet) {}

    // Getters and Setters
    int getStoreId() const {
        return storeId;
    }

    void setStoreId(int id) {
        this->storeId = id;
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& n) {
        this->name = n;
    }

    std::string getContactNo() const {
        return contactNo;
    }

    void setContactNo(const std::string& cNo) {
        this->contactNo = cNo;
    }

    Owner* getOwner() const {
        return owner;
    }

    void setOwner(Owner* own) {
        this->owner = own;
    }

    Outlet* getOutlet() const {
        return outlet;
    }

    void setOutlet(Outlet* out) {
        this->outlet = out;
    }

    Inventory* getInventory() {
        return (outlet != nullptr) ? &(outlet->getInventory()) : nullptr;
    }

    // --- Product Management (handled via Outlet Inventory) ---
    void addProduct(const Product& product) {
        if (outlet != nullptr) {
            outlet->getInventory().addProduct(product);
        }
    }

    bool removeProduct(int productId) {
        if (outlet != nullptr) {
            return outlet->getInventory().removeProduct(productId);
        }
        return false;
    }

    Product* findProduct(int productId) {
        if (outlet != nullptr) {
            return outlet->getInventory().findProduct(productId);
        }
        return nullptr;
    }

    std::vector<Product>& getProducts() {
        static std::vector<Product> emptyList;
        if (outlet != nullptr) {
            return outlet->getInventory().getProducts();
        }
        return emptyList;
    }

    // --- Employee Management ---
    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    std::vector<Employee>& getEmployees() {
        return employees;
    }

    // --- Supplier Management ---
    void addSupplier(const Supplier& supplier) {
        suppliers.push_back(supplier);
        std::cout << ">> Supplier \"" << supplier.getSupplierName() << "\" added successfully.\n";
    }

    std::vector<Supplier>& getSuppliers() {
        return suppliers;
    }

    Supplier* findSupplier(int supplierId) {
        for (auto& s : suppliers) {
            if (s.getSupplierId() == supplierId) {
                return &s;
            }
        }
        return nullptr;
    }

    // --- Customer Management ---
    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
        std::cout << ">> Customer \"" << customer.getName() << "\" registered successfully.\n";
    }

    std::vector<Customer>& getCustomers() {
        return customers;
    }

    Customer* findCustomer(int customerId) {
        for (auto& c : customers) {
            if (c.getCustomerId() == customerId) {
                return &c;
            }
        }
        return nullptr;
    }

    // Display summary of store
    void displayStoreInfo() const {
        std::cout << "========================================\n";
        std::cout << "       ELECTRONICS STORE OVERVIEW       \n";
        std::cout << "========================================\n";
        std::cout << "Store ID: " << storeId << "\n";
        std::cout << "Store Name: " << name << "\n";
        std::cout << "Store Contact: " << contactNo << "\n";
        if (owner != nullptr) {
            std::cout << "Owner: " << owner->getName() << " (Contact: " << owner->getContactNo() << ")\n";
        }
        if (outlet != nullptr) {
            std::cout << "Main Outlet: " << outlet->getName() << " (" << outlet->getAddress() << ")\n";
        }
        size_t prodCount = (outlet != nullptr) ? outlet->getInventory().getProducts().size() : 0;
        std::cout << "Total Products: " << prodCount << "\n";
        std::cout << "Total Employees: " << employees.size() << "\n";
        std::cout << "Total Suppliers: " << suppliers.size() << "\n";
        std::cout << "Total Customers: " << customers.size() << "\n";
        std::cout << "========================================\n";
    }
};

#endif // ELECTRONIC_STORE_H

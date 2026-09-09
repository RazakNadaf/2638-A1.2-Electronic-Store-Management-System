/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : ElectronicStore.java

Description:
Main electronic store class managing relations between Owner,
Outlet, Employees, Products, Suppliers, Customers, and
Inventory stock.
=========================================================
*/

import java.util.ArrayList;

public class ElectronicStore {
    private int storeId;
    private String name;
    private String contactNo;
    private Owner owner;
    private Outlet outlet;
    private ArrayList<Employee> employees;
    private ArrayList<Supplier> suppliers;
    private ArrayList<Customer> customers;

    // Constructor connecting all main store components
    public ElectronicStore(int storeId, String name, String contactNo, Owner owner, Outlet outlet) {
        this.storeId = storeId;
        this.name = name;
        this.contactNo = contactNo;
        this.owner = owner;
        this.outlet = outlet;
        this.employees = new ArrayList<Employee>();
        this.suppliers = new ArrayList<Supplier>();
        this.customers = new ArrayList<Customer>();
    }

    // Getters and Setters
    public int getStoreId() {
        return storeId;
    }

    public void setStoreId(int storeId) {
        this.storeId = storeId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getContactNo() {
        return contactNo;
    }

    public void setContactNo(String contactNo) {
        this.contactNo = contactNo;
    }

    public Owner getOwner() {
        return owner;
    }

    public void setOwner(Owner owner) {
        this.owner = owner;
    }

    public Outlet getOutlet() {
        return outlet;
    }

    public void setOutlet(Outlet outlet) {
        this.outlet = outlet;
    }

    public Inventory getInventory() {
        return outlet != null ? outlet.getInventory() : null;
    }

    // --- Product Management (handled via Outlet Inventory) ---
    public void addProduct(Product product) {
        if (outlet != null && outlet.getInventory() != null) {
            outlet.getInventory().addProduct(product);
        }
    }

    public boolean removeProduct(int productId) {
        if (outlet != null && outlet.getInventory() != null) {
            return outlet.getInventory().removeProduct(productId);
        }
        return false;
    }

    public Product findProduct(int productId) {
        if (outlet != null && outlet.getInventory() != null) {
            return outlet.getInventory().findProduct(productId);
        }
        return null;
    }

    public ArrayList<Product> getProducts() {
        if (outlet != null && outlet.getInventory() != null) {
            return outlet.getInventory().getProducts();
        }
        return new ArrayList<Product>();
    }

    // --- Employee Management ---
    public void addEmployee(Employee employee) {
        employees.add(employee);
    }

    public ArrayList<Employee> getEmployees() {
        return employees;
    }

    // --- Supplier Management ---
    public void addSupplier(Supplier supplier) {
        suppliers.add(supplier);
        System.out.println(">> Supplier \"" + supplier.getSupplierName() + "\" added successfully.");
    }

    public ArrayList<Supplier> getSuppliers() {
        return suppliers;
    }

    public Supplier findSupplier(int supplierId) {
        for (Supplier s : suppliers) {
            if (s.getSupplierId() == supplierId) {
                return s;
            }
        }
        return null;
    }

    // --- Customer Management ---
    public void addCustomer(Customer customer) {
        customers.add(customer);
        System.out.println(">> Customer \"" + customer.getName() + "\" registered successfully.");
    }

    public ArrayList<Customer> getCustomers() {
        return customers;
    }

    public Customer findCustomer(int customerId) {
        for (Customer c : customers) {
            if (c.getCustomerId() == customerId) {
                return c;
            }
        }
        return null;
    }

    // Display summary of store
    public void displayStoreInfo() {
        System.out.println("========================================");
        System.out.println("       ELECTRONICS STORE OVERVIEW       ");
        System.out.println("========================================");
        System.out.println("Store ID: " + storeId);
        System.out.println("Store Name: " + name);
        System.out.println("Store Contact: " + contactNo);
        if (owner != null) {
            System.out.println("Owner: " + owner.getName() + " (Contact: " + owner.getContactNo() + ")");
        }
        if (outlet != null) {
            System.out.println("Main Outlet: " + outlet.getName() + " (" + outlet.getAddress() + ")");
        }
        System.out.println("Total Products: " + getProducts().size());
        System.out.println("Total Employees: " + employees.size());
        System.out.println("Total Suppliers: " + suppliers.size());
        System.out.println("Total Customers: " + customers.size());
        System.out.println("========================================");
    }
}

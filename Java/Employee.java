/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Employee.java

Description:
Represents an employee working in the electronics store.
Inherits from Person class and can update product stock
in the inventory.
=========================================================
*/

public class Employee extends Person {
    private String role;

    // Constructor to initialize employee attributes
    public Employee(int employeeId, String name, String role, String contactNo) {
        super(employeeId, name, contactNo);
        this.role = role;
    }

    // Getters and Setters
    public int getEmployeeId() {
        return id;
    }

    public String getRole() {
        return role;
    }

    public void setRole(String role) {
        this.role = role;
    }

    // Method allowing employee to update product stock
    public void manageStock(Inventory inventory, int productId, int newQuantity) {
        System.out.println("Employee " + name + " (" + role + ") is updating inventory stock...");
        inventory.updateStock(productId, newQuantity);
    }

    // Display employee details
    @Override
    public void displayDetails() {
        System.out.println("Employee ID: " + id + " | Name: " + name + " | Role: " + role + " | Contact: " + contactNo);
    }
}

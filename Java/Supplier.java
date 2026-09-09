/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Supplier.java

Description:
Represents an external supplier who provides electronic
products to the store catalog.
=========================================================
*/

public class Supplier {
    private int supplierId;
    private String supplierName;
    private String contactNo;

    // Constructor
    public Supplier(int supplierId, String supplierName, String contactNo) {
        this.supplierId = supplierId;
        this.supplierName = supplierName;
        this.contactNo = contactNo;
    }

    // Getters and Setters
    public int getSupplierId() {
        return supplierId;
    }

    public void setSupplierId(int supplierId) {
        this.supplierId = supplierId;
    }

    public String getSupplierName() {
        return supplierName;
    }

    public void setSupplierName(String supplierName) {
        this.supplierName = supplierName;
    }

    public String getContactNo() {
        return contactNo;
    }

    public void setContactNo(String contactNo) {
        this.contactNo = contactNo;
    }

    // Display supplier details
    public void displaySupplier() {
        System.out.println("Supplier ID: " + supplierId + " | Name: " + supplierName + " | Contact: " + contactNo);
    }
}

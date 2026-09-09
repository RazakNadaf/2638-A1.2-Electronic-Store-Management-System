/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Person.java

Description:
Abstract parent class for common personal details like
ID, name, and contact number. Inherited by Owner,
Employee, and Customer classes.
=========================================================
*/

public abstract class Person {
    // Common attributes for all persons
    protected int id;
    protected String name;
    protected String contactNo;

    // Constructor to initialize common details
    public Person(int id, String name, String contactNo) {
        this.id = id;
        this.name = name;
        this.contactNo = contactNo;
    }

    // Getters and Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
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

    // Abstract method to be implemented by child classes
    public abstract void displayDetails();
}

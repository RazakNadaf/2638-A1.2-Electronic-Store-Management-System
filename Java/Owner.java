/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Owner.java

Description:
Represents the store owner. Extends the Person class to
inherit basic details and display owner information.
=========================================================
*/

public class Owner extends Person {

    // Constructor passing details to Person superclass
    public Owner(int ownerId, String name, String contactNo) {
        super(ownerId, name, contactNo);
    }

    // Getter for owner id
    public int getOwnerId() {
        return id;
    }

    // Display owner details
    @Override
    public void displayDetails() {
        System.out.println("Owner ID: " + id);
        System.out.println("Owner Name: " + name);
        System.out.println("Contact Number: " + contactNo);
    }
}

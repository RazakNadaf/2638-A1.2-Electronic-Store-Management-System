/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Customer.java

Description:
Represents a customer in the store. Extends Person class
and includes methods to purchase products and submit
ratings/reviews.
=========================================================
*/

public class Customer extends Person {
    private int age;
    private String address;
    private String review;
    private int rating;

    // Constructor to initialize customer details
    public Customer(int customerId, String name, int age, String contactNo, String address) {
        super(customerId, name, contactNo);
        this.age = age;
        this.address = address;
        this.review = "No review yet";
        this.rating = 0;
    }

    // Getters and Setters
    public int getCustomerId() {
        return id;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getReview() {
        return review;
    }

    public int getRating() {
        return rating;
    }

    // Purchase product and reduce quantity from stock
    public boolean purchaseProduct(Product product, int quantity) {
        if (product == null) {
            System.out.println(">> Error: Product does not exist.");
            return false;
        }

        if (product.getStockQuantity() >= quantity) {
            product.setStockQuantity(product.getStockQuantity() - quantity);
            System.out.println(">> " + name + " successfully purchased " + quantity + " unit(s) of " + product.getName() + ".");
            return true;
        } else {
            System.out.println(">> Error: Insufficient stock for " + product.getName() + ". Available: " + product.getStockQuantity());
            return false;
        }
    }

    // Overloaded method to give review with default 5-star rating
    public void giveReview(String reviewText) {
        this.review = reviewText;
        this.rating = 5;
        System.out.println(">> Review recorded from " + name + ": \"" + reviewText + "\" (Rating: 5/5)");
    }

    // Overloaded method to give review with custom rating
    public void giveReview(String reviewText, int stars) {
        this.review = reviewText;
        this.rating = stars;
        System.out.println(">> Review recorded from " + name + ": \"" + reviewText + "\" (" + stars + "/5 stars)");
    }

    // Display customer information
    @Override
    public void displayDetails() {
        System.out.println("Customer ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Contact: " + contactNo);
        System.out.println("Address: " + address);
        if (rating > 0) {
            System.out.println("Feedback: " + review + " (" + rating + " Stars)");
        }
        System.out.println("----------------------------------------");
    }

    public void displayCustomer() {
        displayDetails();
    }
}

/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Payment.java

Description:
Represents a payment transaction made by a customer.
Handles payment processing, receipt generation, and payment
mode selection (Cash, Card, UPI).
=========================================================
*/

public class Payment {
    private int paymentId;
    private double amount;
    private String paymentMode; // Cash, Card, UPI
    private String paymentStatus;
    private Customer customer;

    // Constructor to record payment details
    public Payment(int paymentId, double amount, String paymentMode, String paymentStatus, Customer customer) {
        this.paymentId = paymentId;
        this.amount = amount;
        this.paymentMode = paymentMode;
        this.paymentStatus = paymentStatus;
        this.customer = customer;
    }

    // Getters and Setters
    public int getPaymentId() {
        return paymentId;
    }

    public void setPaymentId(int paymentId) {
        this.paymentId = paymentId;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public String getPaymentMode() {
        return paymentMode;
    }

    public void setPaymentMode(String paymentMode) {
        this.paymentMode = paymentMode;
    }

    public String getPaymentStatus() {
        return paymentStatus;
    }

    public void setPaymentStatus(String paymentStatus) {
        this.paymentStatus = paymentStatus;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }

    // Process and print payment receipt
    public void processPayment() {
        this.paymentStatus = "Paid";
        System.out.println("----------------------------------------");
        System.out.println("           PAYMENT RECEIPT              ");
        System.out.println("----------------------------------------");
        System.out.println("Payment ID: " + paymentId);
        System.out.println("Customer: " + (customer != null ? customer.getName() : "Walk-in Customer"));
        System.out.println("Amount Paid: Rs. " + amount);
        System.out.println("Payment Mode: " + paymentMode);
        System.out.println("Status: " + paymentStatus);
        System.out.println(">> Payment completed successfully!");
        System.out.println("----------------------------------------");
    }

    // Display basic payment summary
    public void displayPayment() {
        System.out.println("Payment ID: " + paymentId + " | Customer: " + (customer != null ? customer.getName() : "N/A") +
                " | Amount: Rs. " + amount + " | Mode: " + paymentMode + " | Status: " + paymentStatus);
    }
}

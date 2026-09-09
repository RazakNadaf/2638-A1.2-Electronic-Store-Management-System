/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : ReturnReplacement.java

Description:
Manages customer requests for product returns or replacements
including the reason, type (Return/Replacement), and status.
=========================================================
*/

public class ReturnReplacement {
    private int returnId;
    private int productId;
    private String reason;
    private String type; // "Return" or "Replacement"
    private String status;
    private Customer customer;

    // Constructor to initialize return/replacement request
    public ReturnReplacement(int returnId, int productId, String reason, String type, String status, Customer customer) {
        this.returnId = returnId;
        this.productId = productId;
        this.reason = reason;
        this.type = type;
        this.status = status;
        this.customer = customer;
    }

    // Getters and Setters
    public int getReturnId() {
        return returnId;
    }

    public void setReturnId(int returnId) {
        this.returnId = returnId;
    }

    public int getProductId() {
        return productId;
    }

    public void setProductId(int productId) {
        this.productId = productId;
    }

    public String getReason() {
        return reason;
    }

    public void setReason(String reason) {
        this.reason = reason;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }

    // Process and approve the request
    public void processRequest() {
        this.status = "Approved";
        System.out.println("----------------------------------------");
        System.out.println("    RETURN / REPLACEMENT PROCESSING     ");
        System.out.println("----------------------------------------");
        System.out.println("Request ID: " + returnId);
        System.out.println("Customer: " + (customer != null ? customer.getName() : "Customer"));
        System.out.println("Product ID: " + productId);
        System.out.println("Type: " + type);
        System.out.println("Reason: " + reason);
        System.out.println("Status: " + status);
        System.out.println(">> " + type + " request processed and approved!");
        System.out.println("----------------------------------------");
    }

    // Display request summary
    public void displayDetails() {
        System.out.println("Request ID: " + returnId + " | Customer: " + (customer != null ? customer.getName() : "N/A") +
                " | Product ID: " + productId + " | Type: " + type + " | Reason: " + reason + " | Status: " + status);
    }
}

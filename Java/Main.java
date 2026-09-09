/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Main.java

Description:
Main driver class providing a simple console-based menu
for the user to interact with the electronics store system.
=========================================================
*/

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Static counters for unique IDs
    private static int paymentIdCounter = 1001;
    private static int returnIdCounter = 501;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Setting up store, owner, branch outlet, and manager
        Owner owner = new Owner(1, "Razak", "9876543210");
        Outlet mainOutlet = new Outlet(101, "Downtown Branch", "123 Main Street", "9876500001");
        ElectronicStore store = new ElectronicStore(1, "TechZone Electronics Store", "9876500000", owner, mainOutlet);

        // Employee working in store
        Employee manager = new Employee(1, "Aakash", "Store Manager", "9876512345");
        store.addEmployee(manager);

        // Lists to track payments and returns during the session
        ArrayList<Payment> paymentHistory = new ArrayList<Payment>();
        ArrayList<ReturnReplacement> returnHistory = new ArrayList<ReturnReplacement>();

        System.out.println("=================================================");
        System.out.println("       ELECTRONICS STORE MANAGEMENT SYSTEM       ");
        System.out.println("=================================================");

        boolean running = true;
        while (running) {
            System.out.println("\n----------------- MAIN MENU -----------------");
            System.out.println("1. Add Product");
            System.out.println("2. View Products");
            System.out.println("3. Search Product");
            System.out.println("4. Update Product");
            System.out.println("5. Delete Product");
            System.out.println("6. Add Supplier");
            System.out.println("7. View Suppliers");
            System.out.println("8. Add Customer");
            System.out.println("9. View Customers");
            System.out.println("10. Make Payment");
            System.out.println("11. Return/Replacement");
            System.out.println("12. Exit");
            System.out.println("---------------------------------------------");
            System.out.print("Enter your choice (1-12): ");

            if (!scanner.hasNextLine()) {
                break;
            }

            String choice = scanner.nextLine().trim();

            switch (choice) {
                case "1":
                    // Add Product
                    System.out.println("\n--- ADD NEW PRODUCT ---");
                    try {
                        System.out.print("Enter Product ID: ");
                        int prodId = Integer.parseInt(scanner.nextLine().trim());

                        if (store.findProduct(prodId) != null) {
                            System.out.println(">> Error: Product ID already exists.");
                            break;
                        }

                        System.out.print("Enter Product Name: ");
                        String name = scanner.nextLine().trim();

                        System.out.print("Enter Brand: ");
                        String brand = scanner.nextLine().trim();

                        System.out.print("Enter Price (Rs.): ");
                        double price = Double.parseDouble(scanner.nextLine().trim());

                        System.out.print("Enter Discount (%): ");
                        double discount = Double.parseDouble(scanner.nextLine().trim());

                        System.out.print("Enter Warranty (e.g. 1 Year): ");
                        String warranty = scanner.nextLine().trim();

                        System.out.print("Enter Stock Quantity: ");
                        int stock = Integer.parseInt(scanner.nextLine().trim());

                        Supplier supplier = null;
                        if (!store.getSuppliers().isEmpty()) {
                            System.out.println("Available Suppliers:");
                            for (Supplier s : store.getSuppliers()) {
                                s.displaySupplier();
                            }
                            System.out.print("Enter Supplier ID (or 0 for none): ");
                            int supId = Integer.parseInt(scanner.nextLine().trim());
                            supplier = store.findSupplier(supId);
                        }

                        Product newProduct = new Product(prodId, name, brand, price, discount, warranty, stock, supplier);
                        store.addProduct(newProduct);

                    } catch (NumberFormatException e) {
                        System.out.println(">> Error: Invalid numeric input.");
                    }
                    break;

                case "2":
                    // View Products
                    System.out.println("\n--- PRODUCT LIST ---");
                    if (store.getProducts().isEmpty()) {
                        System.out.println("No products available. Use Option 1 to add products.");
                    } else {
                        for (Product p : store.getProducts()) {
                            p.displayProduct();
                        }
                    }
                    break;

                case "3":
                    // Search Product
                    System.out.println("\n--- SEARCH PRODUCT ---");
                    try {
                        System.out.print("Enter Product ID to search: ");
                        int searchId = Integer.parseInt(scanner.nextLine().trim());
                        Product found = store.findProduct(searchId);
                        if (found != null) {
                            System.out.println("\n>> Product Found:");
                            found.displayProduct();
                        } else {
                            System.out.println(">> Product with ID " + searchId + " not found.");
                        }
                    } catch (NumberFormatException e) {
                        System.out.println(">> Error: Invalid Product ID.");
                    }
                    break;

                case "4":
                    // Update Product
                    System.out.println("\n--- UPDATE PRODUCT ---");
                    try {
                        System.out.print("Enter Product ID to update: ");
                        int updateId = Integer.parseInt(scanner.nextLine().trim());
                        Product toUpdate = store.findProduct(updateId);
                        if (toUpdate == null) {
                            System.out.println(">> Product not found.");
                            break;
                        }

                        System.out.println("Current details:");
                        toUpdate.displayProduct();

                        System.out.print("Enter New Price (or press Enter to skip): ");
                        String priceInput = scanner.nextLine().trim();
                        if (!priceInput.isEmpty()) {
                            toUpdate.setPrice(Double.parseDouble(priceInput));
                        }

                        System.out.print("Enter New Discount % (or press Enter to skip): ");
                        String discInput = scanner.nextLine().trim();
                        if (!discInput.isEmpty()) {
                            toUpdate.setDiscount(Double.parseDouble(discInput));
                        }

                        System.out.print("Enter New Stock Quantity (or press Enter to skip): ");
                        String stockInput = scanner.nextLine().trim();
                        if (!stockInput.isEmpty()) {
                            int newStock = Integer.parseInt(stockInput);
                            // Demonstrating Employee managing stock
                            manager.manageStock(store.getInventory(), updateId, newStock);
                        }

                        System.out.println(">> Product updated successfully!");
                    } catch (NumberFormatException e) {
                        System.out.println(">> Error: Invalid numeric input.");
                    }
                    break;

                case "5":
                    // Delete Product
                    System.out.println("\n--- DELETE PRODUCT ---");
                    try {
                        System.out.print("Enter Product ID to delete: ");
                        int deleteId = Integer.parseInt(scanner.nextLine().trim());
                        store.removeProduct(deleteId);
                    } catch (NumberFormatException e) {
                        System.out.println(">> Error: Invalid Product ID.");
                    }
                    break;

                case "6":
                    // Add Supplier
                    System.out.println("\n--- ADD SUPPLIER ---");
                    try {
                        System.out.print("Enter Supplier ID: ");
                        int supId = Integer.parseInt(scanner.nextLine().trim());

                        if (store.findSupplier(supId) != null) {
                            System.out.println(">> Error: Supplier ID already exists.");
                            break;
                        }

                        System.out.print("Enter Supplier Name: ");
                        String supName = scanner.nextLine().trim();

                        System.out.print("Enter Contact Number: ");
                        String contact = scanner.nextLine().trim();

                        Supplier newSupplier = new Supplier(supId, supName, contact);
                        store.addSupplier(newSupplier);
                    } catch (NumberFormatException e) {
                        System.out.println(">> Error: Invalid Supplier ID.");
                    }
                    break;

                case "7":
                    // View Suppliers
                    System.out.println("\n--- SUPPLIERS LIST ---");
                    if (store.getSuppliers().isEmpty()) {
                        System.out.println("No suppliers registered yet. Use Option 6 to add suppliers.");
                    } else {
                        for (Supplier s : store.getSuppliers()) {
                            s.displaySupplier();
                        }
                    }
                    break;

                case "8":
                    // Add Customer
                    System.out.println("\n--- ADD CUSTOMER ---");
                    try {
                        System.out.print("Enter Customer ID: ");
                        int custId = Integer.parseInt(scanner.nextLine().trim());

                        if (store.findCustomer(custId) != null) {
                            System.out.println(">> Error: Customer ID already exists.");
                            break;
                        }

                        System.out.print("Enter Customer Name: ");
                        String custName = scanner.nextLine().trim();

                        System.out.print("Enter Age: ");
                        int age = Integer.parseInt(scanner.nextLine().trim());

                        System.out.print("Enter Contact Number: ");
                        String contact = scanner.nextLine().trim();

                        System.out.print("Enter Address: ");
                        String address = scanner.nextLine().trim();

                        Customer newCustomer = new Customer(custId, custName, age, contact, address);
                        store.addCustomer(newCustomer);
                    } catch (NumberFormatException e) {
                        System.out.println(">> Error: Invalid numeric input.");
                    }
                    break;

                case "9":
                    // View Customers
                    System.out.println("\n--- CUSTOMERS LIST ---");
                    if (store.getCustomers().isEmpty()) {
                        System.out.println("No customers registered yet. Use Option 8 to add customers.");
                    } else {
                        for (Customer c : store.getCustomers()) {
                            c.displayCustomer();
                        }
                    }
                    break;

                case "10":
                    // Make Payment / Purchase
                    System.out.println("\n--- MAKE PAYMENT / PURCHASE PRODUCT ---");
                    if (store.getProducts().isEmpty()) {
                        System.out.println(">> No products in store to purchase. Add products first.");
                        break;
                    }

                    try {
                        Customer currentCustomer = null;
                        if (!store.getCustomers().isEmpty()) {
                            System.out.println("Registered Customers:");
                            for (Customer c : store.getCustomers()) {
                                System.out.println("ID: " + c.getCustomerId() + " | Name: " + c.getName());
                            }
                            System.out.print("Enter Customer ID (or 0 for new walk-in customer): ");
                            int custId = Integer.parseInt(scanner.nextLine().trim());
                            currentCustomer = store.findCustomer(custId);
                        }

                        if (currentCustomer == null) {
                            System.out.print("Enter Customer Name: ");
                            String name = scanner.nextLine().trim();
                            System.out.print("Enter Contact: ");
                            String contact = scanner.nextLine().trim();
                            currentCustomer = new Customer(store.getCustomers().size() + 100, name, 25, contact, "Walk-in");
                            store.addCustomer(currentCustomer);
                        }

                        System.out.println("\nAvailable Products:");
                        for (Product p : store.getProducts()) {
                            System.out.println("ID: " + p.getProductId() + " | " + p.getName() + " | Price: Rs. " + p.getPrice() +
                                    " | Final Price (after " + p.getDiscount() + "% disc): Rs. " + p.getFinalPrice() +
                                    " | Stock: " + p.getStockQuantity());
                        }

                        System.out.print("Enter Product ID to buy: ");
                        int buyId = Integer.parseInt(scanner.nextLine().trim());
                        Product toBuy = store.findProduct(buyId);
                        if (toBuy == null) {
                            System.out.println(">> Product not found.");
                            break;
                        }

                        System.out.print("Enter Quantity: ");
                        int qty = Integer.parseInt(scanner.nextLine().trim());

                        // Customer attempts to purchase
                        boolean success = currentCustomer.purchaseProduct(toBuy, qty);
                        if (!success) {
                            break;
                        }

                        double totalAmount = toBuy.getFinalPrice() * qty;
                        System.out.println("Total Amount to Pay: Rs. " + totalAmount);

                        System.out.println("Select Payment Mode:");
                        System.out.println("1. Cash");
                        System.out.println("2. Card");
                        System.out.println("3. UPI");
                        System.out.print("Enter choice (1-3): ");
                        String modeChoice = scanner.nextLine().trim();
                        String mode = "Cash";
                        if ("2".equals(modeChoice)) mode = "Card";
                        else if ("3".equals(modeChoice)) mode = "UPI";

                        // Create and process payment
                        Payment payment = new Payment(paymentIdCounter++, totalAmount, mode, "Pending", currentCustomer);
                        payment.processPayment();
                        paymentHistory.add(payment);

                        // Option to leave a review
                        System.out.print("Would customer like to give a review? (y/n): ");
                        String revAns = scanner.nextLine().trim();
                        if (revAns.equalsIgnoreCase("y")) {
                            System.out.print("Enter review comment: ");
                            String reviewText = scanner.nextLine().trim();
                            System.out.print("Enter rating (1 to 5 stars): ");
                            int stars = Integer.parseInt(scanner.nextLine().trim());
                            currentCustomer.giveReview(reviewText, stars);
                        }

                    } catch (NumberFormatException e) {
                        System.out.println(">> Error: Invalid numeric input.");
                    }
                    break;

                case "11":
                    // Return / Replacement
                    System.out.println("\n--- REQUEST RETURN / REPLACEMENT ---");
                    try {
                        Customer retCustomer = null;
                        if (!store.getCustomers().isEmpty()) {
                            System.out.print("Enter Customer ID: ");
                            int cId = Integer.parseInt(scanner.nextLine().trim());
                            retCustomer = store.findCustomer(cId);
                        }

                        System.out.print("Enter Product ID: ");
                        int rProdId = Integer.parseInt(scanner.nextLine().trim());

                        System.out.print("Enter Reason for request: ");
                        String reason = scanner.nextLine().trim();

                        System.out.println("Select Request Type:");
                        System.out.println("1. Return");
                        System.out.println("2. Replacement");
                        System.out.print("Enter choice (1 or 2): ");
                        String typeChoice = scanner.nextLine().trim();
                        String type = "1".equals(typeChoice) ? "Return" : "Replacement";

                        ReturnReplacement rr = new ReturnReplacement(returnIdCounter++, rProdId, reason, type, "Pending", retCustomer);
                        rr.processRequest();
                        returnHistory.add(rr);

                    } catch (NumberFormatException e) {
                        System.out.println(">> Error: Invalid numeric input.");
                    }
                    break;

                case "12":
                    // Exit
                    System.out.println("\n=================================================");
                    System.out.println("  Thank you for using TechZone Electronics Store!");
                    System.out.println("=================================================");
                    running = false;
                    break;

                default:
                    System.out.println(">> Invalid choice! Please select an option between 1 and 12.");
                    break;
            }
        }

        scanner.close();
    }
}

/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Inventory.java

Description:
Manages the list of products and stock levels for a store
outlet. Allows adding, removing, and updating product stock.
=========================================================
*/

import java.util.ArrayList;

public class Inventory {
    private int inventoryId;
    private int outletId;
    private ArrayList<Product> products;

    // Constructor initializing an empty product list
    public Inventory(int inventoryId, int outletId) {
        this.inventoryId = inventoryId;
        this.outletId = outletId;
        this.products = new ArrayList<Product>();
    }

    // Getters and Setters
    public int getInventoryId() {
        return inventoryId;
    }

    public void setInventoryId(int inventoryId) {
        this.inventoryId = inventoryId;
    }

    public int getOutletId() {
        return outletId;
    }

    public void setOutletId(int outletId) {
        this.outletId = outletId;
    }

    public ArrayList<Product> getProducts() {
        return products;
    }

    // Add new product to the list
    public void addProduct(Product product) {
        products.add(product);
        System.out.println(">> Product \"" + product.getName() + "\" added to inventory successfully.");
    }

    // Remove product by its ID
    public boolean removeProduct(int productId) {
        for (int i = 0; i < products.size(); i++) {
            if (products.get(i).getProductId() == productId) {
                String removedName = products.get(i).getName();
                products.remove(i);
                System.out.println(">> Product \"" + removedName + "\" (ID: " + productId + ") removed from inventory.");
                return true;
            }
        }
        System.out.println(">> Error: Product with ID " + productId + " not found.");
        return false;
    }

    // Update stock quantity for a product
    public boolean updateStock(int productId, int quantity) {
        for (Product p : products) {
            if (p.getProductId() == productId) {
                p.setStockQuantity(quantity);
                System.out.println(">> Stock for \"" + p.getName() + "\" updated to " + quantity + " units.");
                return true;
            }
        }
        System.out.println(">> Error: Product with ID " + productId + " not found.");
        return false;
    }

    // Search for a product by ID
    public Product findProduct(int productId) {
        for (Product p : products) {
            if (p.getProductId() == productId) {
                return p;
            }
        }
        return null;
    }

    // Calculate total stock count across all items
    public int getTotalStockQuantity() {
        int total = 0;
        for (Product p : products) {
            total += p.getStockQuantity();
        }
        return total;
    }

    // Display all products in this inventory
    public void displayInventory() {
        System.out.println("========================================");
        System.out.println("         OUTLET INVENTORY LIST          ");
        System.out.println("Inventory ID: " + inventoryId + " | Outlet ID: " + outletId);
        System.out.println("========================================");
        if (products.isEmpty()) {
            System.out.println("No products available in inventory.");
        } else {
            for (Product p : products) {
                p.displayProduct();
            }
        }
    }
}

/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Product.java

Description:
Represents an electronic product in the store with
details like brand, price, discount percentage, warranty,
and current stock quantity.
=========================================================
*/

public class Product {
    private int productId;
    private String name;
    private String brand;
    private double price;
    private double discount; // Discount percentage
    private String warranty;
    private int stockQuantity;
    private Supplier supplier;

    // Constructor to initialize product details
    public Product(int productId, String name, String brand, double price, double discount, String warranty, int stockQuantity, Supplier supplier) {
        this.productId = productId;
        this.name = name;
        this.brand = brand;
        this.price = price;
        this.discount = discount;
        this.warranty = warranty;
        this.stockQuantity = stockQuantity;
        this.supplier = supplier;
    }

    // Getters and Setters
    public int getProductId() {
        return productId;
    }

    public void setProductId(int productId) {
        this.productId = productId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getDiscount() {
        return discount;
    }

    public void setDiscount(double discount) {
        this.discount = discount;
    }

    public String getWarranty() {
        return warranty;
    }

    public void setWarranty(String warranty) {
        this.warranty = warranty;
    }

    public int getStockQuantity() {
        return stockQuantity;
    }

    public void setStockQuantity(int stockQuantity) {
        this.stockQuantity = stockQuantity;
    }

    public Supplier getSupplier() {
        return supplier;
    }

    public void setSupplier(Supplier supplier) {
        this.supplier = supplier;
    }

    // Calculate discounted final price
    public double getFinalPrice() {
        return price - (price * (discount / 100.0));
    }

    // Display product specifications
    public void displayProduct() {
        System.out.println("Product ID: " + productId);
        System.out.println("Name: " + name);
        System.out.println("Brand: " + brand);
        System.out.println("Price: Rs. " + price);
        System.out.println("Discount: " + discount + "%");
        System.out.println("Final Price: Rs. " + getFinalPrice());
        System.out.println("Warranty: " + warranty);
        System.out.println("Stock Quantity: " + stockQuantity);
        if (supplier != null) {
            System.out.println("Supplier: " + supplier.getSupplierName());
        }
        System.out.println("----------------------------------------");
    }
}

/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Outlet.java

Description:
Represents a physical branch/outlet of the electronic store.
Each outlet maintains its own Inventory object to manage stock.
=========================================================
*/

public class Outlet {
    private int outletId;
    private String name;
    private String address;
    private String contactNo;
    private Inventory inventory;

    // Constructor creates a dedicated Inventory instance for this outlet
    public Outlet(int outletId, String name, String address, String contactNo) {
        this.outletId = outletId;
        this.name = name;
        this.address = address;
        this.contactNo = contactNo;
        this.inventory = new Inventory(outletId * 10, outletId);
    }

    // Getters and Setters
    public int getOutletId() {
        return outletId;
    }

    public void setOutletId(int outletId) {
        this.outletId = outletId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getContactNo() {
        return contactNo;
    }

    public void setContactNo(String contactNo) {
        this.contactNo = contactNo;
    }

    public Inventory getInventory() {
        return inventory;
    }

    public void setInventory(Inventory inventory) {
        this.inventory = inventory;
    }

    // Display outlet information
    public void displayOutletDetails() {
        System.out.println("Outlet ID: " + outletId);
        System.out.println("Outlet Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Contact Number: " + contactNo);
        System.out.println("Total Products in Stock: " + inventory.getProducts().size());
    }
}

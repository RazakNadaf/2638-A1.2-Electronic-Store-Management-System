/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Program.cs

Description:
Main driver class providing a console-based interactive
menu for the user to interact with the Electronic Store System.
Demonstrates object creation, method calls, and user input/output in C#.
=========================================================
*/

using System;
using System.Collections.Generic;

namespace ElectronicsStore
{
    public class Program
    {
        // Static counters for unique IDs
        private static int paymentIdCounter = 1001;
        private static int returnIdCounter = 501;

        public static void Main(string[] args)
        {
            // Setting up store, owner, branch outlet, and manager
            Owner owner = new Owner(1, "Razak", "9876543210");
            Outlet mainOutlet = new Outlet(101, "Downtown Branch", "123 Main Street", "9876500001");
            ElectronicStore store = new ElectronicStore(1, "TechZone Electronics Store", "9876500000", owner, mainOutlet);

            // Employee working in store
            Employee manager = new Employee(1, "Aakash", "Store Manager", "9876512345");
            store.AddEmployee(manager);

            // Lists to track payments and returns during the session
            List<Payment> paymentHistory = new List<Payment>();
            List<ReturnReplacement> returnHistory = new List<ReturnReplacement>();

            Console.WriteLine("=================================================");
            Console.WriteLine("       ELECTRONICS STORE MANAGEMENT SYSTEM       ");
            Console.WriteLine("=================================================");

            bool running = true;
            while (running)
            {
                Console.WriteLine("\n----------------- MAIN MENU -----------------");
                Console.WriteLine("1. Add Product");
                Console.WriteLine("2. View Products");
                Console.WriteLine("3. Search Product");
                Console.WriteLine("4. Update Product");
                Console.WriteLine("5. Delete Product");
                Console.WriteLine("6. Add Supplier");
                Console.WriteLine("7. View Suppliers");
                Console.WriteLine("8. Add Customer");
                Console.WriteLine("9. View Customers");
                Console.WriteLine("10. Make Payment");
                Console.WriteLine("11. Return/Replacement");
                Console.WriteLine("12. Exit");
                Console.WriteLine("---------------------------------------------");
                Console.Write("Enter your choice (1-12): ");

                string choice = Console.ReadLine();
                if (choice == null)
                {
                    break;
                }
                choice = choice.Trim();

                switch (choice)
                {
                    case "1":
                        // Add Product
                        Console.WriteLine("\n--- ADD NEW PRODUCT ---");
                        try
                        {
                            Console.Write("Enter Product ID: ");
                            int prodId = int.Parse(Console.ReadLine().Trim());

                            if (store.FindProduct(prodId) != null)
                            {
                                Console.WriteLine(">> Error: Product ID already exists.");
                                break;
                            }

                            Console.Write("Enter Product Name: ");
                            string name = Console.ReadLine().Trim();

                            Console.Write("Enter Brand: ");
                            string brand = Console.ReadLine().Trim();

                            Console.Write("Enter Price (Rs.): ");
                            double price = double.Parse(Console.ReadLine().Trim());

                            Console.Write("Enter Discount (%): ");
                            double discount = double.Parse(Console.ReadLine().Trim());

                            Console.Write("Enter Warranty (e.g. 1 Year): ");
                            string warranty = Console.ReadLine().Trim();

                            Console.Write("Enter Stock Quantity: ");
                            int stock = int.Parse(Console.ReadLine().Trim());

                            Supplier supplier = null;
                            if (store.GetSuppliers().Count > 0)
                            {
                                Console.WriteLine("Available Suppliers:");
                                foreach (Supplier s in store.GetSuppliers())
                                {
                                    s.DisplaySupplier();
                                }
                                Console.Write("Enter Supplier ID (or 0 for none): ");
                                int supId = int.Parse(Console.ReadLine().Trim());
                                supplier = store.FindSupplier(supId);
                            }

                            Product newProduct = new Product(prodId, name, brand, price, discount, warranty, stock, supplier);
                            store.AddProduct(newProduct);
                        }
                        catch (FormatException)
                        {
                            Console.WriteLine(">> Error: Invalid numeric input.");
                        }
                        break;

                    case "2":
                        // View Products
                        Console.WriteLine("\n--- PRODUCT LIST ---");
                        if (store.GetProducts().Count == 0)
                        {
                            Console.WriteLine("No products available. Use Option 1 to add products.");
                        }
                        else
                        {
                            foreach (Product p in store.GetProducts())
                            {
                                p.DisplayProduct();
                            }
                        }
                        break;

                    case "3":
                        // Search Product
                        Console.WriteLine("\n--- SEARCH PRODUCT ---");
                        try
                        {
                            Console.Write("Enter Product ID to search: ");
                            int searchId = int.Parse(Console.ReadLine().Trim());
                            Product found = store.FindProduct(searchId);
                            if (found != null)
                            {
                                Console.WriteLine("\n>> Product Found:");
                                found.DisplayProduct();
                            }
                            else
                            {
                                Console.WriteLine(">> Product with ID " + searchId + " not found.");
                            }
                        }
                        catch (FormatException)
                        {
                            Console.WriteLine(">> Error: Invalid Product ID.");
                        }
                        break;

                    case "4":
                        // Update Product
                        Console.WriteLine("\n--- UPDATE PRODUCT ---");
                        try
                        {
                            Console.Write("Enter Product ID to update: ");
                            int updateId = int.Parse(Console.ReadLine().Trim());
                            Product toUpdate = store.FindProduct(updateId);
                            if (toUpdate == null)
                            {
                                Console.WriteLine(">> Product not found.");
                                break;
                            }

                            Console.WriteLine("Current details:");
                            toUpdate.DisplayProduct();

                            Console.Write("Enter New Price (or press Enter to skip): ");
                            string priceInput = Console.ReadLine().Trim();
                            if (!string.IsNullOrEmpty(priceInput))
                            {
                                toUpdate.SetPrice(double.Parse(priceInput));
                            }

                            Console.Write("Enter New Discount % (or press Enter to skip): ");
                            string discInput = Console.ReadLine().Trim();
                            if (!string.IsNullOrEmpty(discInput))
                            {
                                toUpdate.SetDiscount(double.Parse(discInput));
                            }

                            Console.Write("Enter New Stock Quantity (or press Enter to skip): ");
                            string stockInput = Console.ReadLine().Trim();
                            if (!string.IsNullOrEmpty(stockInput))
                            {
                                int newStock = int.Parse(stockInput);
                                // Demonstrating Employee managing stock
                                manager.ManageStock(store.GetInventory(), updateId, newStock);
                            }

                            Console.WriteLine(">> Product updated successfully!");
                        }
                        catch (FormatException)
                        {
                            Console.WriteLine(">> Error: Invalid numeric input.");
                        }
                        break;

                    case "5":
                        // Delete Product
                        Console.WriteLine("\n--- DELETE PRODUCT ---");
                        try
                        {
                            Console.Write("Enter Product ID to delete: ");
                            int deleteId = int.Parse(Console.ReadLine().Trim());
                            store.RemoveProduct(deleteId);
                        }
                        catch (FormatException)
                        {
                            Console.WriteLine(">> Error: Invalid Product ID.");
                        }
                        break;

                    case "6":
                        // Add Supplier
                        Console.WriteLine("\n--- ADD SUPPLIER ---");
                        try
                        {
                            Console.Write("Enter Supplier ID: ");
                            int supId = int.Parse(Console.ReadLine().Trim());

                            if (store.FindSupplier(supId) != null)
                            {
                                Console.WriteLine(">> Error: Supplier ID already exists.");
                                break;
                            }

                            Console.Write("Enter Supplier Name: ");
                            string supName = Console.ReadLine().Trim();

                            Console.Write("Enter Contact Number: ");
                            string contact = Console.ReadLine().Trim();

                            Supplier newSupplier = new Supplier(supId, supName, contact);
                            store.AddSupplier(newSupplier);
                        }
                        catch (FormatException)
                        {
                            Console.WriteLine(">> Error: Invalid Supplier ID.");
                        }
                        break;

                    case "7":
                        // View Suppliers
                        Console.WriteLine("\n--- SUPPLIERS LIST ---");
                        if (store.GetSuppliers().Count == 0)
                        {
                            Console.WriteLine("No suppliers registered yet. Use Option 6 to add suppliers.");
                        }
                        else
                        {
                            foreach (Supplier s in store.GetSuppliers())
                            {
                                s.DisplaySupplier();
                            }
                        }
                        break;

                    case "8":
                        // Add Customer
                        Console.WriteLine("\n--- ADD CUSTOMER ---");
                        try
                        {
                            Console.Write("Enter Customer ID: ");
                            int custId = int.Parse(Console.ReadLine().Trim());

                            if (store.FindCustomer(custId) != null)
                            {
                                Console.WriteLine(">> Error: Customer ID already exists.");
                                break;
                            }

                            Console.Write("Enter Customer Name: ");
                            string custName = Console.ReadLine().Trim();

                            Console.Write("Enter Age: ");
                            int age = int.Parse(Console.ReadLine().Trim());

                            Console.Write("Enter Contact Number: ");
                            string contact = Console.ReadLine().Trim();

                            Console.Write("Enter Address: ");
                            string address = Console.ReadLine().Trim();

                            Customer newCustomer = new Customer(custId, custName, age, contact, address);
                            store.AddCustomer(newCustomer);
                        }
                        catch (FormatException)
                        {
                            Console.WriteLine(">> Error: Invalid numeric input.");
                        }
                        break;

                    case "9":
                        // View Customers
                        Console.WriteLine("\n--- CUSTOMERS LIST ---");
                        if (store.GetCustomers().Count == 0)
                        {
                            Console.WriteLine("No customers registered yet. Use Option 8 to add customers.");
                        }
                        else
                        {
                            foreach (Customer c in store.GetCustomers())
                            {
                                c.DisplayCustomer();
                            }
                        }
                        break;

                    case "10":
                        // Make Payment / Purchase
                        Console.WriteLine("\n--- MAKE PAYMENT / PURCHASE PRODUCT ---");
                        if (store.GetProducts().Count == 0)
                        {
                            Console.WriteLine(">> No products in store to purchase. Add products first.");
                            break;
                        }

                        try
                        {
                            Customer currentCustomer = null;
                            if (store.GetCustomers().Count > 0)
                            {
                                Console.WriteLine("Registered Customers:");
                                foreach (Customer c in store.GetCustomers())
                                {
                                    Console.WriteLine("ID: " + c.GetCustomerId() + " | Name: " + c.Name);
                                }
                                Console.Write("Enter Customer ID (or 0 for new walk-in customer): ");
                                int custId = int.Parse(Console.ReadLine().Trim());
                                currentCustomer = store.FindCustomer(custId);
                            }

                            if (currentCustomer == null)
                            {
                                Console.Write("Enter Customer Name: ");
                                string name = Console.ReadLine().Trim();
                                Console.Write("Enter Contact: ");
                                string contact = Console.ReadLine().Trim();
                                currentCustomer = new Customer(store.GetCustomers().Count + 100, name, 25, contact, "Walk-in");
                                store.AddCustomer(currentCustomer);
                            }

                            Console.WriteLine("\nAvailable Products:");
                            foreach (Product p in store.GetProducts())
                            {
                                Console.WriteLine("ID: " + p.GetProductId() + " | " + p.GetName() + " | Price: Rs. " + p.GetPrice() +
                                        " | Final Price (after " + p.GetDiscount() + "% disc): Rs. " + p.GetFinalPrice() +
                                        " | Stock: " + p.GetStockQuantity());
                            }

                            Console.Write("Enter Product ID to buy: ");
                            int buyId = int.Parse(Console.ReadLine().Trim());
                            Product toBuy = store.FindProduct(buyId);
                            if (toBuy == null)
                            {
                                Console.WriteLine(">> Product not found.");
                                break;
                            }

                            Console.Write("Enter Quantity: ");
                            int qty = int.Parse(Console.ReadLine().Trim());

                            // Customer attempts to purchase
                            bool success = currentCustomer.PurchaseProduct(toBuy, qty);
                            if (!success)
                            {
                                break;
                            }

                            double totalAmount = toBuy.GetFinalPrice() * qty;
                            Console.WriteLine("Total Amount to Pay: Rs. " + totalAmount);

                            Console.WriteLine("Select Payment Mode:");
                            Console.WriteLine("1. Cash");
                            Console.WriteLine("2. Card");
                            Console.WriteLine("3. UPI");
                            Console.Write("Enter choice (1-3): ");
                            string modeChoice = Console.ReadLine().Trim();
                            string mode = "Cash";
                            if ("2".Equals(modeChoice)) mode = "Card";
                            else if ("3".Equals(modeChoice)) mode = "UPI";

                            // Create and process payment
                            Payment payment = new Payment(paymentIdCounter++, totalAmount, mode, "Pending", currentCustomer);
                            payment.ProcessPayment();
                            paymentHistory.Add(payment);

                            // Option to leave a review
                            Console.Write("Would customer like to give a review? (y/n): ");
                            string revAns = Console.ReadLine().Trim();
                            if (revAns.Equals("y", StringComparison.OrdinalIgnoreCase))
                            {
                                Console.Write("Enter review comment: ");
                                string reviewText = Console.ReadLine().Trim();
                                Console.Write("Enter rating (1 to 5 stars): ");
                                int stars = int.Parse(Console.ReadLine().Trim());
                                currentCustomer.GiveReview(reviewText, stars);
                            }
                        }
                        catch (FormatException)
                        {
                            Console.WriteLine(">> Error: Invalid numeric input.");
                        }
                        break;

                    case "11":
                        // Return / Replacement
                        Console.WriteLine("\n--- REQUEST RETURN / REPLACEMENT ---");
                        try
                        {
                            Customer retCustomer = null;
                            if (store.GetCustomers().Count > 0)
                            {
                                Console.Write("Enter Customer ID: ");
                                int cId = int.Parse(Console.ReadLine().Trim());
                                retCustomer = store.FindCustomer(cId);
                            }

                            Console.Write("Enter Product ID: ");
                            int rProdId = int.Parse(Console.ReadLine().Trim());

                            Console.Write("Enter Reason for request: ");
                            string reason = Console.ReadLine().Trim();

                            Console.WriteLine("Select Request Type:");
                            Console.WriteLine("1. Return");
                            Console.WriteLine("2. Replacement");
                            Console.Write("Enter choice (1 or 2): ");
                            string typeChoice = Console.ReadLine().Trim();
                            string type = "1".Equals(typeChoice) ? "Return" : "Replacement";

                            ReturnReplacement rr = new ReturnReplacement(returnIdCounter++, rProdId, reason, type, "Pending", retCustomer);
                            rr.ProcessRequest();
                            returnHistory.Add(rr);
                        }
                        catch (FormatException)
                        {
                            Console.WriteLine(">> Error: Invalid numeric input.");
                        }
                        break;

                    case "12":
                        // Exit
                        Console.WriteLine("\n=================================================");
                        Console.WriteLine("  Thank you for using TechZone Electronics Store!");
                        Console.WriteLine("=================================================");
                        running = false;
                        break;

                    default:
                        Console.WriteLine(">> Invalid choice! Please select an option between 1 and 12.");
                        break;
                }
            }
        }
    }
}

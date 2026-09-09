/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Inventory.cs

Description:
Manages the list of products and stock levels for a store
outlet. Allows adding, removing, searching, and updating
product stock. Demonstrates encapsulation and collection handling.
=========================================================
*/

using System;
using System.Collections.Generic;

namespace ElectronicsStore
{
    public class Inventory
    {
        private int inventoryId;
        private int outletId;
        private List<Product> products;

        // Constructor initializing an empty product list
        public Inventory(int inventoryId, int outletId)
        {
            this.inventoryId = inventoryId;
            this.outletId = outletId;
            this.products = new List<Product>();
        }

        // Getters and Setters
        public int GetInventoryId()
        {
            return inventoryId;
        }

        public void SetInventoryId(int inventoryId)
        {
            this.inventoryId = inventoryId;
        }

        public int GetOutletId()
        {
            return outletId;
        }

        public void SetOutletId(int outletId)
        {
            this.outletId = outletId;
        }

        public List<Product> GetProducts()
        {
            return products;
        }

        // Add new product to the list
        public void AddProduct(Product product)
        {
            products.Add(product);
            Console.WriteLine(">> Product \"" + product.GetName() + "\" added to inventory successfully.");
        }

        // Remove product by its ID
        public bool RemoveProduct(int productId)
        {
            for (int i = 0; i < products.Count; i++)
            {
                if (products[i].GetProductId() == productId)
                {
                    string removedName = products[i].GetName();
                    products.RemoveAt(i);
                    Console.WriteLine(">> Product \"" + removedName + "\" (ID: " + productId + ") removed from inventory.");
                    return true;
                }
            }
            Console.WriteLine(">> Error: Product with ID " + productId + " not found.");
            return false;
        }

        // Update stock quantity for a product
        public bool UpdateStock(int productId, int quantity)
        {
            foreach (Product p in products)
            {
                if (p.GetProductId() == productId)
                {
                    p.SetStockQuantity(quantity);
                    Console.WriteLine(">> Stock for \"" + p.GetName() + "\" updated to " + quantity + " units.");
                    return true;
                }
            }
            Console.WriteLine(">> Error: Product with ID " + productId + " not found.");
            return false;
        }

        // Search for a product by ID
        public Product FindProduct(int productId)
        {
            foreach (Product p in products)
            {
                if (p.GetProductId() == productId)
                {
                    return p;
                }
            }
            return null;
        }

        // Calculate total stock count across all items
        public int GetTotalStockQuantity()
        {
            int total = 0;
            foreach (Product p in products)
            {
                total += p.GetStockQuantity();
            }
            return total;
        }

        // Display all products in this inventory
        public void DisplayInventory()
        {
            Console.WriteLine("========================================");
            Console.WriteLine("         OUTLET INVENTORY LIST          ");
            Console.WriteLine("Inventory ID: " + inventoryId + " | Outlet ID: " + outletId);
            Console.WriteLine("========================================");
            if (products.Count == 0)
            {
                Console.WriteLine("No products available in inventory.");
            }
            else
            {
                foreach (Product p in products)
                {
                    p.DisplayProduct();
                }
            }
        }
    }
}

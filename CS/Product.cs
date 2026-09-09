/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Product.cs

Description:
Represents an electronic product in the store with
details like brand, price, discount percentage, warranty,
and current stock quantity. Demonstrates encapsulation
and aggregation.
=========================================================
*/

using System;

namespace ElectronicsStore
{
    public class Product
    {
        private int productId;
        private string name;
        private string brand;
        private double price;
        private double discount; // Discount percentage
        private string warranty;
        private int stockQuantity;
        private Supplier supplier;

        // Constructor to initialize product details
        public Product(int productId, string name, string brand, double price, double discount, string warranty, int stockQuantity, Supplier supplier)
        {
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
        public int GetProductId()
        {
            return productId;
        }

        public void SetProductId(int productId)
        {
            this.productId = productId;
        }

        public string GetName()
        {
            return name;
        }

        public void SetName(string name)
        {
            this.name = name;
        }

        public string GetBrand()
        {
            return brand;
        }

        public void SetBrand(string brand)
        {
            this.brand = brand;
        }

        public double GetPrice()
        {
            return price;
        }

        public void SetPrice(double price)
        {
            this.price = price;
        }

        public double GetDiscount()
        {
            return discount;
        }

        public void SetDiscount(double discount)
        {
            this.discount = discount;
        }

        public string GetWarranty()
        {
            return warranty;
        }

        public void SetWarranty(string warranty)
        {
            this.warranty = warranty;
        }

        public int GetStockQuantity()
        {
            return stockQuantity;
        }

        public void SetStockQuantity(int stockQuantity)
        {
            this.stockQuantity = stockQuantity;
        }

        public Supplier GetSupplier()
        {
            return supplier;
        }

        public void SetSupplier(Supplier supplier)
        {
            this.supplier = supplier;
        }

        // Calculate discounted final price
        public double GetFinalPrice()
        {
            return price - (price * (discount / 100.0));
        }

        // Display product specifications
        public void DisplayProduct()
        {
            Console.WriteLine("Product ID: " + productId);
            Console.WriteLine("Name: " + name);
            Console.WriteLine("Brand: " + brand);
            Console.WriteLine("Price: Rs. " + price);
            Console.WriteLine("Discount: " + discount + "%");
            Console.WriteLine("Final Price: Rs. " + GetFinalPrice());
            Console.WriteLine("Warranty: " + warranty);
            Console.WriteLine("Stock Quantity: " + stockQuantity);
            if (supplier != null)
            {
                Console.WriteLine("Supplier: " + supplier.GetSupplierName());
            }
            Console.WriteLine("----------------------------------------");
        }
    }
}

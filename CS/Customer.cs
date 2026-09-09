/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Customer.cs

Description:
Represents a customer in the store. Extends Person class
and includes methods to purchase products and submit
ratings/reviews. Demonstrates inheritance, method overriding,
and method overloading in C#.
=========================================================
*/

using System;

namespace ElectronicsStore
{
    public class Customer : Person
    {
        private int age;
        private string address;
        private string review;
        private int rating;

        // Constructor to initialize customer details
        public Customer(int customerId, string name, int age, string contactNo, string address)
            : base(customerId, name, contactNo)
        {
            this.age = age;
            this.address = address;
            this.review = "No review yet";
            this.rating = 0;
        }

        // Getters and Setters
        public int GetCustomerId()
        {
            return id;
        }

        public int Age
        {
            get { return age; }
            set { age = value; }
        }

        public int GetAge()
        {
            return age;
        }

        public void SetAge(int age)
        {
            this.age = age;
        }

        public string Address
        {
            get { return address; }
            set { address = value; }
        }

        public string GetAddress()
        {
            return address;
        }

        public void SetAddress(string address)
        {
            this.address = address;
        }

        public string Review
        {
            get { return review; }
            set { review = value; }
        }

        public string GetReview()
        {
            return review;
        }

        public int Rating
        {
            get { return rating; }
            set { rating = value; }
        }

        public int GetRating()
        {
            return rating;
        }

        // Purchase product and reduce quantity from stock
        public bool PurchaseProduct(Product product, int quantity)
        {
            if (product == null)
            {
                Console.WriteLine(">> Error: Product does not exist.");
                return false;
            }

            if (product.GetStockQuantity() >= quantity)
            {
                product.SetStockQuantity(product.GetStockQuantity() - quantity);
                Console.WriteLine(">> " + name + " successfully purchased " + quantity + " unit(s) of " + product.GetName() + ".");
                return true;
            }
            else
            {
                Console.WriteLine(">> Error: Insufficient stock for " + product.GetName() + ". Available: " + product.GetStockQuantity());
                return false;
            }
        }

        // Overloaded method to give review with default 5-star rating (Method Overloading)
        public void GiveReview(string reviewText)
        {
            this.review = reviewText;
            this.rating = 5;
            Console.WriteLine(">> Review recorded from " + name + ": \"" + reviewText + "\" (Rating: 5/5)");
        }

        // Overloaded method to give review with custom rating (Method Overloading)
        public void GiveReview(string reviewText, int stars)
        {
            this.review = reviewText;
            this.rating = stars;
            Console.WriteLine(">> Review recorded from " + name + ": \"" + reviewText + "\" (" + stars + "/5 stars)");
        }

        // Display customer information (Method Overriding)
        public override void DisplayDetails()
        {
            Console.WriteLine("Customer ID: " + id);
            Console.WriteLine("Name: " + name);
            Console.WriteLine("Age: " + age);
            Console.WriteLine("Contact: " + contactNo);
            Console.WriteLine("Address: " + address);
            if (rating > 0)
            {
                Console.WriteLine("Feedback: " + review + " (" + rating + " Stars)");
            }
            Console.WriteLine("----------------------------------------");
        }

        public void DisplayCustomer()
        {
            DisplayDetails();
        }
    }
}

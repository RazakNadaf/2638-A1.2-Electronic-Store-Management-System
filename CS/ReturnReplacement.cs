/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : ReturnReplacement.cs

Description:
Manages customer requests for product returns or replacements
including the reason, type (Return/Replacement), and status.
Demonstrates encapsulation and association in C#.
=========================================================
*/

using System;

namespace ElectronicsStore
{
    public class ReturnReplacement
    {
        private int returnId;
        private int productId;
        private string reason;
        private string type; // "Return" or "Replacement"
        private string status;
        private Customer customer;

        // Constructor to initialize return/replacement request
        public ReturnReplacement(int returnId, int productId, string reason, string type, string status, Customer customer)
        {
            this.returnId = returnId;
            this.productId = productId;
            this.reason = reason;
            this.type = type;
            this.status = status;
            this.customer = customer;
        }

        // Getters and Setters
        public int GetReturnId()
        {
            return returnId;
        }

        public void SetReturnId(int returnId)
        {
            this.returnId = returnId;
        }

        public int GetProductId()
        {
            return productId;
        }

        public void SetProductId(int productId)
        {
            this.productId = productId;
        }

        public string GetReason()
        {
            return reason;
        }

        public void SetReason(string reason)
        {
            this.reason = reason;
        }

        public new string GetType()
        {
            return type;
        }

        public void SetType(string type)
        {
            this.type = type;
        }

        public string GetStatus()
        {
            return status;
        }

        public void SetStatus(string status)
        {
            this.status = status;
        }

        public Customer GetCustomer()
        {
            return customer;
        }

        public void SetCustomer(Customer customer)
        {
            this.customer = customer;
        }

        // Process and approve the request
        public void ProcessRequest()
        {
            this.status = "Approved";
            Console.WriteLine("----------------------------------------");
            Console.WriteLine("    RETURN / REPLACEMENT PROCESSING     ");
            Console.WriteLine("----------------------------------------");
            Console.WriteLine("Request ID: " + returnId);
            Console.WriteLine("Customer: " + (customer != null ? customer.Name : "Customer"));
            Console.WriteLine("Product ID: " + productId);
            Console.WriteLine("Type: " + type);
            Console.WriteLine("Reason: " + reason);
            Console.WriteLine("Status: " + status);
            Console.WriteLine(">> " + type + " request processed and approved!");
            Console.WriteLine("----------------------------------------");
        }

        // Display request summary
        public void DisplayDetails()
        {
            Console.WriteLine("Request ID: " + returnId + " | Customer: " + (customer != null ? customer.Name : "N/A") +
                    " | Product ID: " + productId + " | Type: " + type + " | Reason: " + reason + " | Status: " + status);
        }
    }
}

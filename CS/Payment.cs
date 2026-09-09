/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Payment.cs

Description:
Represents a payment transaction made by a customer.
Handles payment processing, receipt generation, and payment
mode selection (Cash, Card, UPI). Demonstrates encapsulation
and association.
=========================================================
*/

using System;

namespace ElectronicsStore
{
    public class Payment
    {
        private int paymentId;
        private double amount;
        private string paymentMode; // Cash, Card, UPI
        private string paymentStatus;
        private Customer customer;

        // Constructor to record payment details
        public Payment(int paymentId, double amount, string paymentMode, string paymentStatus, Customer customer)
        {
            this.paymentId = paymentId;
            this.amount = amount;
            this.paymentMode = paymentMode;
            this.paymentStatus = paymentStatus;
            this.customer = customer;
        }

        // Getters and Setters
        public int GetPaymentId()
        {
            return paymentId;
        }

        public void SetPaymentId(int paymentId)
        {
            this.paymentId = paymentId;
        }

        public double GetAmount()
        {
            return amount;
        }

        public void SetAmount(double amount)
        {
            this.amount = amount;
        }

        public string GetPaymentMode()
        {
            return paymentMode;
        }

        public void SetPaymentMode(string paymentMode)
        {
            this.paymentMode = paymentMode;
        }

        public string GetPaymentStatus()
        {
            return paymentStatus;
        }

        public void SetPaymentStatus(string paymentStatus)
        {
            this.paymentStatus = paymentStatus;
        }

        public Customer GetCustomer()
        {
            return customer;
        }

        public void SetCustomer(Customer customer)
        {
            this.customer = customer;
        }

        // Process and print payment receipt
        public void ProcessPayment()
        {
            this.paymentStatus = "Paid";
            Console.WriteLine("----------------------------------------");
            Console.WriteLine("           PAYMENT RECEIPT              ");
            Console.WriteLine("----------------------------------------");
            Console.WriteLine("Payment ID: " + paymentId);
            Console.WriteLine("Customer: " + (customer != null ? customer.Name : "Walk-in Customer"));
            Console.WriteLine("Amount Paid: Rs. " + amount);
            Console.WriteLine("Payment Mode: " + paymentMode);
            Console.WriteLine("Status: " + paymentStatus);
            Console.WriteLine(">> Payment completed successfully!");
            Console.WriteLine("----------------------------------------");
        }

        // Display basic payment summary
        public void DisplayPayment()
        {
            Console.WriteLine("Payment ID: " + paymentId + " | Customer: " + (customer != null ? customer.Name : "N/A") +
                    " | Amount: Rs. " + amount + " | Mode: " + paymentMode + " | Status: " + paymentStatus);
        }
    }
}

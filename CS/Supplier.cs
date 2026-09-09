/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Supplier.cs

Description:
Represents an external supplier who provides electronic
products to the store catalog. Demonstrates encapsulation.
=========================================================
*/

using System;

namespace ElectronicsStore
{
    public class Supplier
    {
        private int supplierId;
        private string supplierName;
        private string contactNo;

        // Constructor
        public Supplier(int supplierId, string supplierName, string contactNo)
        {
            this.supplierId = supplierId;
            this.supplierName = supplierName;
            this.contactNo = contactNo;
        }

        // Getters and Setters
        public int GetSupplierId()
        {
            return supplierId;
        }

        public void SetSupplierId(int supplierId)
        {
            this.supplierId = supplierId;
        }

        public string GetSupplierName()
        {
            return supplierName;
        }

        public void SetSupplierName(string supplierName)
        {
            this.supplierName = supplierName;
        }

        public string GetContactNo()
        {
            return contactNo;
        }

        public void SetContactNo(string contactNo)
        {
            this.contactNo = contactNo;
        }

        // Display supplier details
        public void DisplaySupplier()
        {
            Console.WriteLine("Supplier ID: " + supplierId + " | Name: " + supplierName + " | Contact: " + contactNo);
        }
    }
}

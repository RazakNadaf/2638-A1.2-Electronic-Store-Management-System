/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Employee.cs

Description:
Represents an employee working in the electronics store.
Inherits from Person class and can update product stock
in the inventory. Demonstrates inheritance, encapsulation,
and polymorphism.
=========================================================
*/

using System;

namespace ElectronicsStore
{
    public class Employee : Person
    {
        private string role;

        // Constructor to initialize employee attributes
        public Employee(int employeeId, string name, string role, string contactNo)
            : base(employeeId, name, contactNo)
        {
            this.role = role;
        }

        // Getters and Setters
        public int GetEmployeeId()
        {
            return id;
        }

        public string Role
        {
            get { return role; }
            set { role = value; }
        }

        public string GetRole()
        {
            return role;
        }

        public void SetRole(string role)
        {
            this.role = role;
        }

        // Method allowing employee to update product stock
        public void ManageStock(Inventory inventory, int productId, int newQuantity)
        {
            Console.WriteLine("Employee " + name + " (" + role + ") is updating inventory stock...");
            inventory.UpdateStock(productId, newQuantity);
        }

        // Display employee details (Method Overriding)
        public override void DisplayDetails()
        {
            Console.WriteLine("Employee ID: " + id + " | Name: " + name + " | Role: " + role + " | Contact: " + contactNo);
        }
    }
}

/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Person.cs

Description:
Abstract parent class for common personal details like
ID, name, and contact number. Inherited by Owner,
Employee, and Customer classes. Demonstrates abstraction,
encapsulation, and polymorphism in C#.
=========================================================
*/

using System;

namespace ElectronicsStore
{
    public abstract class Person
    {
        // Common protected attributes
        protected int id;
        protected string name;
        protected string contactNo;

        // Constructor to initialize common details
        public Person(int id, string name, string contactNo)
        {
            this.id = id;
            this.name = name;
            this.contactNo = contactNo;
        }

        // Getters and Setters (Properties)
        public int Id
        {
            get { return id; }
            set { id = value; }
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public string ContactNo
        {
            get { return contactNo; }
            set { contactNo = value; }
        }

        // Abstract method to be implemented by derived classes
        public abstract void DisplayDetails();
    }
}

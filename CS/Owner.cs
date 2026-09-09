/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Owner.cs

Description:
Represents the store owner. Extends the Person class to
inherit basic details and display owner information.
Demonstrates single inheritance and method overriding in C#.
=========================================================
*/

using System;

namespace ElectronicsStore
{
    public class Owner : Person
    {
        // Constructor passing details to Person base class
        public Owner(int ownerId, string name, string contactNo)
            : base(ownerId, name, contactNo)
        {
        }

        // Getter for owner id
        public int GetOwnerId()
        {
            return id;
        }

        // Display owner details (Method Overriding)
        public override void DisplayDetails()
        {
            Console.WriteLine("Owner ID: " + id);
            Console.WriteLine("Owner Name: " + name);
            Console.WriteLine("Contact Number: " + contactNo);
        }
    }
}

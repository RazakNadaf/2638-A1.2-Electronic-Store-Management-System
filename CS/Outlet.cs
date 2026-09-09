/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : Outlet.cs

Description:
Represents a physical branch/outlet of the electronic store.
Each outlet maintains its own Inventory object to manage stock.
Demonstrates composition and encapsulation in C#.
=========================================================
*/

using System;

namespace ElectronicsStore
{
    public class Outlet
    {
        private int outletId;
        private string name;
        private string address;
        private string contactNo;
        private Inventory inventory;

        // Constructor creates a dedicated Inventory instance for this outlet (Composition)
        public Outlet(int outletId, string name, string address, string contactNo)
        {
            this.outletId = outletId;
            this.name = name;
            this.address = address;
            this.contactNo = contactNo;
            this.inventory = new Inventory(outletId * 10, outletId);
        }

        // Getters and Setters
        public int GetOutletId()
        {
            return outletId;
        }

        public void SetOutletId(int outletId)
        {
            this.outletId = outletId;
        }

        public string GetName()
        {
            return name;
        }

        public void SetName(string name)
        {
            this.name = name;
        }

        public string GetAddress()
        {
            return address;
        }

        public void SetAddress(string address)
        {
            this.address = address;
        }

        public string GetContactNo()
        {
            return contactNo;
        }

        public void SetContactNo(string contactNo)
        {
            this.contactNo = contactNo;
        }

        public Inventory GetInventory()
        {
            return inventory;
        }

        public void SetInventory(Inventory inventory)
        {
            this.inventory = inventory;
        }

        // Display outlet information
        public void DisplayOutletDetails()
        {
            Console.WriteLine("Outlet ID: " + outletId);
            Console.WriteLine("Outlet Name: " + name);
            Console.WriteLine("Address: " + address);
            Console.WriteLine("Contact Number: " + contactNo);
            Console.WriteLine("Total Products in Stock: " + inventory.GetProducts().Count);
        }
    }
}

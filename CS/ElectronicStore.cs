/*
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : ElectronicStore.cs

Description:
Main electronic store class managing relations between Owner,
Outlet, Employees, Products, Suppliers, Customers, and
Inventory stock. Demonstrates aggregation, composition, and
encapsulation in C#.
=========================================================
*/

using System;
using System.Collections.Generic;

namespace ElectronicsStore
{
    public class ElectronicStore
    {
        private int storeId;
        private string name;
        private string contactNo;
        private Owner owner;
        private Outlet outlet;
        private List<Employee> employees;
        private List<Supplier> suppliers;
        private List<Customer> customers;

        // Constructor connecting all main store components
        public ElectronicStore(int storeId, string name, string contactNo, Owner owner, Outlet outlet)
        {
            this.storeId = storeId;
            this.name = name;
            this.contactNo = contactNo;
            this.owner = owner;
            this.outlet = outlet;
            this.employees = new List<Employee>();
            this.suppliers = new List<Supplier>();
            this.customers = new List<Customer>();
        }

        // Getters and Setters
        public int GetStoreId()
        {
            return storeId;
        }

        public void SetStoreId(int storeId)
        {
            this.storeId = storeId;
        }

        public string GetName()
        {
            return name;
        }

        public void SetName(string name)
        {
            this.name = name;
        }

        public string GetContactNo()
        {
            return contactNo;
        }

        public void SetContactNo(string contactNo)
        {
            this.contactNo = contactNo;
        }

        public Owner GetOwner()
        {
            return owner;
        }

        public void SetOwner(Owner owner)
        {
            this.owner = owner;
        }

        public Outlet GetOutlet()
        {
            return outlet;
        }

        public void SetOutlet(Outlet outlet)
        {
            this.outlet = outlet;
        }

        public Inventory GetInventory()
        {
            return outlet != null ? outlet.GetInventory() : null;
        }

        // --- Product Management (handled via Outlet Inventory) ---
        public void AddProduct(Product product)
        {
            if (outlet != null && outlet.GetInventory() != null)
            {
                outlet.GetInventory().AddProduct(product);
            }
        }

        public bool RemoveProduct(int productId)
        {
            if (outlet != null && outlet.GetInventory() != null)
            {
                return outlet.GetInventory().RemoveProduct(productId);
            }
            return false;
        }

        public Product FindProduct(int productId)
        {
            if (outlet != null && outlet.GetInventory() != null)
            {
                return outlet.GetInventory().FindProduct(productId);
            }
            return null;
        }

        public List<Product> GetProducts()
        {
            if (outlet != null && outlet.GetInventory() != null)
            {
                return outlet.GetInventory().GetProducts();
            }
            return new List<Product>();
        }

        // --- Employee Management ---
        public void AddEmployee(Employee employee)
        {
            employees.Add(employee);
        }

        public List<Employee> GetEmployees()
        {
            return employees;
        }

        // --- Supplier Management ---
        public void AddSupplier(Supplier supplier)
        {
            suppliers.Add(supplier);
            Console.WriteLine(">> Supplier \"" + supplier.GetSupplierName() + "\" added successfully.");
        }

        public List<Supplier> GetSuppliers()
        {
            return suppliers;
        }

        public Supplier FindSupplier(int supplierId)
        {
            foreach (Supplier s in suppliers)
            {
                if (s.GetSupplierId() == supplierId)
                {
                    return s;
                }
            }
            return null;
        }

        // --- Customer Management ---
        public void AddCustomer(Customer customer)
        {
            customers.Add(customer);
            Console.WriteLine(">> Customer \"" + customer.Name + "\" registered successfully.");
        }

        public List<Customer> GetCustomers()
        {
            return customers;
        }

        public Customer FindCustomer(int customerId)
        {
            foreach (Customer c in customers)
            {
                if (c.GetCustomerId() == customerId)
                {
                    return c;
                }
            }
            return null;
        }

        // Display summary of store
        public void DisplayStoreInfo()
        {
            Console.WriteLine("========================================");
            Console.WriteLine("       ELECTRONICS STORE OVERVIEW       ");
            Console.WriteLine("========================================");
            Console.WriteLine("Store ID: " + storeId);
            Console.WriteLine("Store Name: " + name);
            Console.WriteLine("Store Contact: " + contactNo);
            if (owner != null)
            {
                Console.WriteLine("Owner: " + owner.Name + " (Contact: " + owner.ContactNo + ")");
            }
            if (outlet != null)
            {
                Console.WriteLine("Main Outlet: " + outlet.GetName() + " (" + outlet.GetAddress() + ")");
            }
            Console.WriteLine("Total Products: " + GetProducts().Count);
            Console.WriteLine("Total Employees: " + employees.Count);
            Console.WriteLine("Total Suppliers: " + suppliers.Count);
            Console.WriteLine("Total Customers: " + customers.Count);
            Console.WriteLine("========================================");
        }
    }
}

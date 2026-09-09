"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : electronic_store.py

Description:
Main electronic store class managing relations between Owner,
Outlet, Employees, Products, Suppliers, Customers, and
Inventory stock. Demonstrates aggregation, composition, and
encapsulation in Python.
=========================================================
"""

from typing import List, Optional
from owner import Owner
from outlet import Outlet
from inventory import Inventory
from product import Product
from employee import Employee
from supplier import Supplier
from customer import Customer


class ElectronicStore:
    """Central store management class aggregating all store operations."""

    def __init__(self, store_id: int, name: str, contact_no: str,
                 owner: Optional[Owner] = None, outlet: Optional[Outlet] = None):
        self._store_id = store_id
        self._name = name
        self._contact_no = contact_no
        self._owner = owner
        self._outlet = outlet
        self._employees: List[Employee] = []
        self._suppliers: List[Supplier] = []
        self._customers: List[Customer] = []

    # Getters and Setters
    def get_store_id(self) -> int:
        return self._store_id

    def set_store_id(self, store_id: int) -> None:
        self._store_id = store_id

    def get_name(self) -> str:
        return self._name

    def set_name(self, name: str) -> None:
        self._name = name

    def get_contact_no(self) -> str:
        return self._contact_no

    def set_contact_no(self, contact_no: str) -> None:
        self._contact_no = contact_no

    def get_owner(self) -> Optional[Owner]:
        return self._owner

    def set_owner(self, owner: Optional[Owner]) -> None:
        self._owner = owner

    def get_outlet(self) -> Optional[Outlet]:
        return self._outlet

    def set_outlet(self, outlet: Optional[Outlet]) -> None:
        self._outlet = outlet

    def get_inventory(self) -> Optional[Inventory]:
        return self._outlet.get_inventory() if self._outlet else None

    # --- Product Management (handled via Outlet Inventory) ---
    def add_product(self, product: Product) -> None:
        if self._outlet and self._outlet.get_inventory():
            self._outlet.get_inventory().add_product(product)

    def remove_product(self, product_id: int) -> bool:
        if self._outlet and self._outlet.get_inventory():
            return self._outlet.get_inventory().remove_product(product_id)
        return False

    def find_product(self, product_id: int) -> Optional[Product]:
        if self._outlet and self._outlet.get_inventory():
            return self._outlet.get_inventory().find_product(product_id)
        return None

    def get_products(self) -> List[Product]:
        if self._outlet and self._outlet.get_inventory():
            return self._outlet.get_inventory().get_products()
        return []

    # --- Employee Management ---
    def add_employee(self, employee: Employee) -> None:
        self._employees.append(employee)

    def get_employees(self) -> List[Employee]:
        return self._employees

    # --- Supplier Management ---
    def add_supplier(self, supplier: Supplier) -> None:
        self._suppliers.append(supplier)
        print(f">> Supplier \"{supplier.get_supplier_name()}\" added successfully.")

    def get_suppliers(self) -> List[Supplier]:
        return self._suppliers

    def find_supplier(self, supplier_id: int) -> Optional[Supplier]:
        for s in self._suppliers:
            if s.get_supplier_id() == supplier_id:
                return s
        return None

    # --- Customer Management ---
    def add_customer(self, customer: Customer) -> None:
        self._customers.append(customer)
        print(f">> Customer \"{customer.get_name()}\" registered successfully.")

    def get_customers(self) -> List[Customer]:
        return self._customers

    def find_customer(self, customer_id: int) -> Optional[Customer]:
        for c in self._customers:
            if c.get_customer_id() == customer_id:
                return c
        return None

    # Display summary of store
    def display_store_info(self) -> None:
        print("========================================")
        print("       ELECTRONICS STORE OVERVIEW       ")
        print("========================================")
        print(f"Store ID: {self._store_id}")
        print(f"Store Name: {self._name}")
        print(f"Store Contact: {self._contact_no}")
        if self._owner is not None:
            print(f"Owner: {self._owner.get_name()} (Contact: {self._owner.get_contact_no()})")
        if self._outlet is not None:
            print(f"Main Outlet: {self._outlet.get_name()} ({self._outlet.get_address()})")
        print(f"Total Products: {len(self.get_products())}")
        print(f"Total Employees: {len(self._employees)}")
        print(f"Total Suppliers: {len(self._suppliers)}")
        print(f"Total Customers: {len(self._customers)}")
        print("========================================")

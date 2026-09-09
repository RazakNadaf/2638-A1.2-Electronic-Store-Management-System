"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : inventory.py

Description:
Manages the list of products and stock levels for a store
outlet. Allows adding, removing, searching, and updating
product stock. Demonstrates encapsulation and list manipulation.
=========================================================
"""

from typing import List, Optional
from product import Product


class Inventory:
    """Manages the product catalog and stock for an outlet."""

    def __init__(self, inventory_id: int, outlet_id: int):
        self._inventory_id = inventory_id
        self._outlet_id = outlet_id
        self._products: List[Product] = []

    # Getters and Setters
    def get_inventory_id(self) -> int:
        return self._inventory_id

    def set_inventory_id(self, inventory_id: int) -> None:
        self._inventory_id = inventory_id

    def get_outlet_id(self) -> int:
        return self._outlet_id

    def set_outlet_id(self, outlet_id: int) -> None:
        self._outlet_id = outlet_id

    def get_products(self) -> List[Product]:
        return self._products

    # Add new product to the list
    def add_product(self, product: Product) -> None:
        self._products.append(product)
        print(f">> Product \"{product.get_name()}\" added to inventory successfully.")

    # Remove product by its ID
    def remove_product(self, product_id: int) -> bool:
        for i, p in enumerate(self._products):
            if p.get_product_id() == product_id:
                removed_name = p.get_name()
                del self._products[i]
                print(f">> Product \"{removed_name}\" (ID: {product_id}) removed from inventory.")
                return True
        print(f">> Error: Product with ID {product_id} not found.")
        return False

    # Update stock quantity for a product
    def update_stock(self, product_id: int, quantity: int) -> bool:
        for p in self._products:
            if p.get_product_id() == product_id:
                p.set_stock_quantity(quantity)
                print(f">> Stock for \"{p.get_name()}\" updated to {quantity} units.")
                return True
        print(f">> Error: Product with ID {product_id} not found.")
        return False

    # Search for a product by ID
    def find_product(self, product_id: int) -> Optional[Product]:
        for p in self._products:
            if p.get_product_id() == product_id:
                return p
        return None

    # Calculate total stock count across all items
    def get_total_stock_quantity(self) -> int:
        return sum(p.get_stock_quantity() for p in self._products)

    # Display all products in this inventory
    def display_inventory(self) -> None:
        print("========================================")
        print("         OUTLET INVENTORY LIST          ")
        print(f"Inventory ID: {self._inventory_id} | Outlet ID: {self._outlet_id}")
        print("========================================")
        if not self._products:
            print("No products available in inventory.")
        else:
            for p in self._products:
                p.display_product()

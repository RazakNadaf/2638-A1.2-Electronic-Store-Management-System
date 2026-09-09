"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : outlet.py

Description:
Represents a physical branch/outlet of the electronic store.
Each outlet maintains its own Inventory object to manage stock.
Demonstrates composition and encapsulation in Python.
=========================================================
"""

from inventory import Inventory


class Outlet:
    """Represents a store outlet branch with its dedicated inventory."""

    def __init__(self, outlet_id: int, name: str, address: str, contact_no: str):
        self._outlet_id = outlet_id
        self._name = name
        self._address = address
        self._contact_no = contact_no
        self._inventory = Inventory(outlet_id * 10, outlet_id)

    # Getters and Setters
    def get_outlet_id(self) -> int:
        return self._outlet_id

    def set_outlet_id(self, outlet_id: int) -> None:
        self._outlet_id = outlet_id

    def get_name(self) -> str:
        return self._name

    def set_name(self, name: str) -> None:
        self._name = name

    def get_address(self) -> str:
        return self._address

    def set_address(self, address: str) -> None:
        self._address = address

    def get_contact_no(self) -> str:
        return self._contact_no

    def set_contact_no(self, contact_no: str) -> None:
        self._contact_no = contact_no

    def get_inventory(self) -> Inventory:
        return self._inventory

    def set_inventory(self, inventory: Inventory) -> None:
        self._inventory = inventory

    # Display outlet information
    def display_outlet_details(self) -> None:
        print(f"Outlet ID: {self._outlet_id}")
        print(f"Outlet Name: {self._name}")
        print(f"Address: {self._address}")
        print(f"Contact Number: {self._contact_no}")
        print(f"Total Products in Stock: {len(self._inventory.get_products())}")

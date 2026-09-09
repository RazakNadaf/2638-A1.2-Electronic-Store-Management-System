"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : supplier.py

Description:
Represents an external supplier who provides electronic
products to the store catalog. Demonstrates encapsulation
in Python.
=========================================================
"""


class Supplier:
    """Represents a product supplier for the electronic store."""

    def __init__(self, supplier_id: int, supplier_name: str, contact_no: str):
        self._supplier_id = supplier_id
        self._supplier_name = supplier_name
        self._contact_no = contact_no

    # Getters and Setters
    def get_supplier_id(self) -> int:
        return self._supplier_id

    def set_supplier_id(self, supplier_id: int) -> None:
        self._supplier_id = supplier_id

    def get_supplier_name(self) -> str:
        return self._supplier_name

    def set_supplier_name(self, supplier_name: str) -> None:
        self._supplier_name = supplier_name

    def get_contact_no(self) -> str:
        return self._contact_no

    def set_contact_no(self, contact_no: str) -> None:
        self._contact_no = contact_no

    @property
    def supplier_id(self) -> int:
        return self._supplier_id

    @property
    def supplier_name(self) -> str:
        return self._supplier_name

    @property
    def contact_no(self) -> str:
        return self._contact_no

    # Display supplier details
    def display_supplier(self) -> None:
        print(f"Supplier ID: {self._supplier_id} | Name: {self._supplier_name} | Contact: {self._contact_no}")

"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : owner.py

Description:
Represents the store owner. Extends the Person class to
inherit basic details and display owner information.
Demonstrates single inheritance and method overriding in Python.
=========================================================
"""

from person import Person


class Owner(Person):
    """Represents the store owner inheriting from Person."""

    def __init__(self, owner_id: int, name: str, contact_no: str):
        super().__init__(owner_id, name, contact_no)

    def get_owner_id(self) -> int:
        return self._id

    # Display owner details (Method Overriding)
    def display_details(self) -> None:
        print(f"Owner ID: {self._id}")
        print(f"Owner Name: {self._name}")
        print(f"Contact Number: {self._contact_no}")

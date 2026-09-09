"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : employee.py

Description:
Represents an employee working in the electronics store.
Inherits from Person class and can update product stock
in the inventory. Demonstrates inheritance, encapsulation,
and polymorphism.
=========================================================
"""

from person import Person


class Employee(Person):
    """Represents an employee in the electronic store."""

    def __init__(self, employee_id: int, name: str, role: str, contact_no: str):
        super().__init__(employee_id, name, contact_no)
        self._role = role

    # Getters and Setters
    def get_employee_id(self) -> int:
        return self._id

    def get_role(self) -> str:
        return self._role

    def set_role(self, role: str) -> None:
        self._role = role

    @property
    def role(self) -> str:
        return self._role

    @role.setter
    def role(self, role: str) -> None:
        self._role = role

    # Method allowing employee to update product stock
    def manage_stock(self, inventory, product_id: int, new_quantity: int) -> None:
        print(f"Employee {self._name} ({self._role}) is updating inventory stock...")
        inventory.update_stock(product_id, new_quantity)

    # Display employee details (Method Overriding)
    def display_details(self) -> None:
        print(f"Employee ID: {self._id} | Name: {self._name} | Role: {self._role} | Contact: {self._contact_no}")

"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : return_replacement.py

Description:
Manages customer requests for product returns or replacements
including the reason, type (Return/Replacement), and status.
Demonstrates encapsulation and association in Python.
=========================================================
"""

from typing import Optional
from customer import Customer


class ReturnReplacement:
    """Manages return and replacement requests from customers."""

    def __init__(self, return_id: int, product_id: int, reason: str,
                 request_type: str, status: str,
                 customer: Optional[Customer] = None):
        self._return_id = return_id
        self._product_id = product_id
        self._reason = reason
        self._type = request_type  # "Return" or "Replacement"
        self._status = status
        self._customer = customer

    # Getters and Setters
    def get_return_id(self) -> int:
        return self._return_id

    def set_return_id(self, return_id: int) -> None:
        self._return_id = return_id

    def get_product_id(self) -> int:
        return self._product_id

    def set_product_id(self, product_id: int) -> None:
        self._product_id = product_id

    def get_reason(self) -> str:
        return self._reason

    def set_reason(self, reason: str) -> None:
        self._reason = reason

    def get_type(self) -> str:
        return self._type

    def set_type(self, request_type: str) -> None:
        self._type = request_type

    def get_status(self) -> str:
        return self._status

    def set_status(self, status: str) -> None:
        self._status = status

    def get_customer(self) -> Optional[Customer]:
        return self._customer

    def set_customer(self, customer: Optional[Customer]) -> None:
        self._customer = customer

    # Process and approve the request
    def process_request(self) -> None:
        self._status = "Approved"
        print("----------------------------------------")
        print("    RETURN / REPLACEMENT PROCESSING     ")
        print("----------------------------------------")
        print(f"Request ID: {self._return_id}")
        cust_name = self._customer.get_name() if self._customer else "Customer"
        print(f"Customer: {cust_name}")
        print(f"Product ID: {self._product_id}")
        print(f"Type: {self._type}")
        print(f"Reason: {self._reason}")
        print(f"Status: {self._status}")
        print(f">> {self._type} request processed and approved!")
        print("----------------------------------------")

    # Display request summary
    def display_details(self) -> None:
        cust_name = self._customer.get_name() if self._customer else "N/A"
        print(f"Request ID: {self._return_id} | Customer: {cust_name} | "
              f"Product ID: {self._product_id} | Type: {self._type} | "
              f"Reason: {self._reason} | Status: {self._status}")

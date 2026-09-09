"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : payment.py

Description:
Represents a payment transaction made by a customer.
Handles payment processing, receipt generation, and payment
mode selection (Cash, Card, UPI). Demonstrates encapsulation
and association in Python.
=========================================================
"""

from typing import Optional
from customer import Customer


class Payment:
    """Handles payment transactions for store purchases."""

    def __init__(self, payment_id: int, amount: float, payment_mode: str,
                 payment_status: str, customer: Optional[Customer] = None):
        self._payment_id = payment_id
        self._amount = float(amount)
        self._payment_mode = payment_mode
        self._payment_status = payment_status
        self._customer = customer

    # Getters and Setters
    def get_payment_id(self) -> int:
        return self._payment_id

    def set_payment_id(self, payment_id: int) -> None:
        self._payment_id = payment_id

    def get_amount(self) -> float:
        return self._amount

    def set_amount(self, amount: float) -> None:
        self._amount = float(amount)

    def get_payment_mode(self) -> str:
        return self._payment_mode

    def set_payment_mode(self, payment_mode: str) -> None:
        self._payment_mode = payment_mode

    def get_payment_status(self) -> str:
        return self._payment_status

    def set_payment_status(self, payment_status: str) -> None:
        self._payment_status = payment_status

    def get_customer(self) -> Optional[Customer]:
        return self._customer

    def set_customer(self, customer: Optional[Customer]) -> None:
        self._customer = customer

    # Process and print payment receipt
    def process_payment(self) -> None:
        self._payment_status = "Paid"
        print("----------------------------------------")
        print("           PAYMENT RECEIPT              ")
        print("----------------------------------------")
        print(f"Payment ID: {self._payment_id}")
        cust_name = self._customer.get_name() if self._customer else "Walk-in Customer"
        print(f"Customer: {cust_name}")
        print(f"Amount Paid: Rs. {self._amount}")
        print(f"Payment Mode: {self._payment_mode}")
        print(f"Status: {self._payment_status}")
        print(">> Payment completed successfully!")
        print("----------------------------------------")

    # Display basic payment summary
    def display_payment(self) -> None:
        cust_name = self._customer.get_name() if self._customer else "N/A"
        print(f"Payment ID: {self._payment_id} | Customer: {cust_name} | "
              f"Amount: Rs. {self._amount} | Mode: {self._payment_mode} | Status: {self._payment_status}")

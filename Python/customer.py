"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : customer.py

Description:
Represents a customer in the store. Extends Person class
and includes methods to purchase products and submit
ratings/reviews. Demonstrates inheritance, method overriding,
and simulated method overloading in Python.
=========================================================
"""

from person import Person


class Customer(Person):
    """Represents a customer in the electronic store."""

    def __init__(self, customer_id: int, name: str, age: int, contact_no: str, address: str):
        super().__init__(customer_id, name, contact_no)
        self._age = age
        self._address = address
        self._review = "No review yet"
        self._rating = 0

    # Getters and Setters
    def get_customer_id(self) -> int:
        return self._id

    def get_age(self) -> int:
        return self._age

    def set_age(self, age: int) -> None:
        self._age = age

    def get_address(self) -> str:
        return self._address

    def set_address(self, address: str) -> None:
        self._address = address

    def get_review(self) -> str:
        return self._review

    def get_rating(self) -> int:
        return self._rating

    @property
    def age(self) -> int:
        return self._age

    @property
    def address(self) -> str:
        return self._address

    @property
    def review(self) -> str:
        return self._review

    @property
    def rating(self) -> int:
        return self._rating

    # Purchase product and reduce quantity from stock
    def purchase_product(self, product, quantity: int) -> bool:
        if product is None:
            print(">> Error: Product does not exist.")
            return False

        if product.get_stock_quantity() >= quantity:
            product.set_stock_quantity(product.get_stock_quantity() - quantity)
            print(f">> {self._name} successfully purchased {quantity} unit(s) of {product.get_name()}.")
            return True
        else:
            print(f">> Error: Insufficient stock for {product.get_name()}. Available: {product.get_stock_quantity()}")
            return False

    # Overloaded review method using default arguments (Method Overloading emulation)
    def give_review(self, review_text: str, stars: int = 5) -> None:
        self._review = review_text
        self._rating = stars
        if stars == 5:
            print(f">> Review recorded from {self._name}: \"{review_text}\" (Rating: 5/5)")
        else:
            print(f">> Review recorded from {self._name}: \"{review_text}\" ({stars}/5 stars)")

    # Display customer information (Method Overriding)
    def display_details(self) -> None:
        print(f"Customer ID: {self._id}")
        print(f"Name: {self._name}")
        print(f"Age: {self._age}")
        print(f"Contact: {self._contact_no}")
        print(f"Address: {self._address}")
        if self._rating > 0:
            print(f"Feedback: {self._review} ({self._rating} Stars)")
        print("----------------------------------------")

    def display_customer(self) -> None:
        self.display_details()

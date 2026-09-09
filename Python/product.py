"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : product.py

Description:
Represents an electronic product in the store with
details like brand, price, discount percentage, warranty,
and current stock quantity. Demonstrates encapsulation
and aggregation in Python.
=========================================================
"""

from typing import Optional
from supplier import Supplier


class Product:
    """Represents an electronic product with pricing, discount, and stock info."""

    def __init__(self, product_id: int, name: str, brand: str, price: float,
                 discount: float, warranty: str, stock_quantity: int,
                 supplier: Optional[Supplier] = None):
        self._product_id = product_id
        self._name = name
        self._brand = brand
        self._price = float(price)
        self._discount = float(discount)
        self._warranty = warranty
        self._stock_quantity = int(stock_quantity)
        self._supplier = supplier

    # Getters and Setters
    def get_product_id(self) -> int:
        return self._product_id

    def set_product_id(self, product_id: int) -> None:
        self._product_id = product_id

    def get_name(self) -> str:
        return self._name

    def set_name(self, name: str) -> None:
        self._name = name

    def get_brand(self) -> str:
        return self._brand

    def set_brand(self, brand: str) -> None:
        self._brand = brand

    def get_price(self) -> float:
        return self._price

    def set_price(self, price: float) -> None:
        self._price = float(price)

    def get_discount(self) -> float:
        return self._discount

    def set_discount(self, discount: float) -> None:
        self._discount = float(discount)

    def get_warranty(self) -> str:
        return self._warranty

    def set_warranty(self, warranty: str) -> None:
        self._warranty = warranty

    def get_stock_quantity(self) -> int:
        return self._stock_quantity

    def set_stock_quantity(self, stock_quantity: int) -> None:
        self._stock_quantity = int(stock_quantity)

    def get_supplier(self) -> Optional[Supplier]:
        return self._supplier

    def set_supplier(self, supplier: Optional[Supplier]) -> None:
        self._supplier = supplier

    # Calculate discounted final price
    def get_final_price(self) -> float:
        return self._price - (self._price * (self._discount / 100.0))

    # Display product specifications
    def display_product(self) -> None:
        print(f"Product ID: {self._product_id}")
        print(f"Name: {self._name}")
        print(f"Brand: {self._brand}")
        print(f"Price: Rs. {self._price}")
        print(f"Discount: {self._discount}%")
        print(f"Final Price: Rs. {self.get_final_price()}")
        print(f"Warranty: {self._warranty}")
        print(f"Stock Quantity: {self._stock_quantity}")
        if self._supplier is not None:
            print(f"Supplier: {self._supplier.get_supplier_name()}")
        print("----------------------------------------")

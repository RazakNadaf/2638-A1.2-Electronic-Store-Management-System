"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : person.py

Description:
Abstract parent class for common personal details like
ID, name, and contact number. Inherited by Owner,
Employee, and Customer classes. Demonstrates abstraction,
encapsulation, and polymorphism in Python.
=========================================================
"""

from abc import ABC, abstractmethod


class Person(ABC):
    """Abstract base class representing a general person."""

    def __init__(self, person_id: int, name: str, contact_no: str):
        # Protected attributes
        self._id = person_id
        self._name = name
        self._contact_no = contact_no

    # Getters and Setters
    def get_id(self) -> int:
        return self._id

    def set_id(self, person_id: int) -> None:
        self._id = person_id

    def get_name(self) -> str:
        return self._name

    def set_name(self, name: str) -> None:
        self._name = name

    def get_contact_no(self) -> str:
        return self._contact_no

    def set_contact_no(self, contact_no: str) -> None:
        self._contact_no = contact_no

    @property
    def id(self) -> int:
        return self._id

    @property
    def name(self) -> str:
        return self._name

    @property
    def contact_no(self) -> str:
        return self._contact_no

    # Abstract method to be overridden by subclasses (Abstraction & Polymorphism)
    @abstractmethod
    def display_details(self) -> None:
        pass

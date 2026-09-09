"""
=========================================================
Author      : Razak Nadaf
Roll No.    : 2638
Assignment  : A1.2
Project     : Electronic Store Management System
File Name   : main.py

Description:
Main driver script providing an interactive console menu
for the user to interact with the Electronic Store System.
Demonstrates object creation, method calls, and user input/output.
=========================================================
"""

import sys
from owner import Owner
from outlet import Outlet
from employee import Employee
from customer import Customer
from supplier import Supplier
from product import Product
from payment import Payment
from return_replacement import ReturnReplacement
from electronic_store import ElectronicStore


def main():
    payment_id_counter = 1001
    return_id_counter = 501

    # Setting up store, owner, branch outlet, and manager
    owner = Owner(1, "Razak", "9876543210")
    main_outlet = Outlet(101, "Downtown Branch", "123 Main Street", "9876500001")
    store = ElectronicStore(1, "TechZone Electronics Store", "9876500000", owner, main_outlet)

    # Employee working in store
    manager = Employee(1, "Aakash", "Store Manager", "9876512345")
    store.add_employee(manager)

    # Lists to track payments and returns during the session
    payment_history = []
    return_history = []

    print("=================================================")
    print("       ELECTRONICS STORE MANAGEMENT SYSTEM       ")
    print("=================================================")

    running = True
    while running:
        print("\n----------------- MAIN MENU -----------------")
        print("1. Add Product")
        print("2. View Products")
        print("3. Search Product")
        print("4. Update Product")
        print("5. Delete Product")
        print("6. Add Supplier")
        print("7. View Suppliers")
        print("8. Add Customer")
        print("9. View Customers")
        print("10. Make Payment")
        print("11. Return/Replacement")
        print("12. Exit")
        print("---------------------------------------------")

        try:
            choice = input("Enter your choice (1-12): ").strip()
        except (EOFError, KeyboardInterrupt):
            break

        if choice == "1":
            # Add Product
            print("\n--- ADD NEW PRODUCT ---")
            try:
                prod_id = int(input("Enter Product ID: ").strip())

                if store.find_product(prod_id) is not None:
                    print(">> Error: Product ID already exists.")
                    continue

                name = input("Enter Product Name: ").strip()
                brand = input("Enter Brand: ").strip()
                price = float(input("Enter Price (Rs.): ").strip())
                discount = float(input("Enter Discount (%): ").strip())
                warranty = input("Enter Warranty (e.g. 1 Year): ").strip()
                stock = int(input("Enter Stock Quantity: ").strip())

                supplier = None
                if store.get_suppliers():
                    print("Available Suppliers:")
                    for s in store.get_suppliers():
                        s.display_supplier()
                    sup_id = int(input("Enter Supplier ID (or 0 for none): ").strip())
                    supplier = store.find_supplier(sup_id)

                new_product = Product(prod_id, name, brand, price, discount, warranty, stock, supplier)
                store.add_product(new_product)

            except ValueError:
                print(">> Error: Invalid numeric input.")

        elif choice == "2":
            # View Products
            print("\n--- PRODUCT LIST ---")
            products = store.get_products()
            if not products:
                print("No products available. Use Option 1 to add products.")
            else:
                for p in products:
                    p.display_product()

        elif choice == "3":
            # Search Product
            print("\n--- SEARCH PRODUCT ---")
            try:
                search_id = int(input("Enter Product ID to search: ").strip())
                found = store.find_product(search_id)
                if found is not None:
                    print("\n>> Product Found:")
                    found.display_product()
                else:
                    print(f">> Product with ID {search_id} not found.")
            except ValueError:
                print(">> Error: Invalid Product ID.")

        elif choice == "4":
            # Update Product
            print("\n--- UPDATE PRODUCT ---")
            try:
                update_id = int(input("Enter Product ID to update: ").strip())
                to_update = store.find_product(update_id)
                if to_update is None:
                    print(">> Product not found.")
                    continue

                print("Current details:")
                to_update.display_product()

                price_input = input("Enter New Price (or press Enter to skip): ").strip()
                if price_input:
                    to_update.set_price(float(price_input))

                disc_input = input("Enter New Discount % (or press Enter to skip): ").strip()
                if disc_input:
                    to_update.set_discount(float(disc_input))

                stock_input = input("Enter New Stock Quantity (or press Enter to skip): ").strip()
                if stock_input:
                    new_stock = int(stock_input)
                    # Demonstrating Employee managing stock
                    if store.get_inventory() is not None:
                        manager.manage_stock(store.get_inventory(), update_id, new_stock)

                print(">> Product updated successfully!")
            except ValueError:
                print(">> Error: Invalid numeric input.")

        elif choice == "5":
            # Delete Product
            print("\n--- DELETE PRODUCT ---")
            try:
                delete_id = int(input("Enter Product ID to delete: ").strip())
                store.remove_product(delete_id)
            except ValueError:
                print(">> Error: Invalid Product ID.")

        elif choice == "6":
            # Add Supplier
            print("\n--- ADD SUPPLIER ---")
            try:
                sup_id = int(input("Enter Supplier ID: ").strip())

                if store.find_supplier(sup_id) is not None:
                    print(">> Error: Supplier ID already exists.")
                    continue

                sup_name = input("Enter Supplier Name: ").strip()
                contact = input("Enter Contact Number: ").strip()

                new_supplier = Supplier(sup_id, sup_name, contact)
                store.add_supplier(new_supplier)
            except ValueError:
                print(">> Error: Invalid Supplier ID.")

        elif choice == "7":
            # View Suppliers
            print("\n--- SUPPLIERS LIST ---")
            suppliers = store.get_suppliers()
            if not suppliers:
                print("No suppliers registered yet. Use Option 6 to add suppliers.")
            else:
                for s in suppliers:
                    s.display_supplier()

        elif choice == "8":
            # Add Customer
            print("\n--- ADD CUSTOMER ---")
            try:
                cust_id = int(input("Enter Customer ID: ").strip())

                if store.find_customer(cust_id) is not None:
                    print(">> Error: Customer ID already exists.")
                    continue

                cust_name = input("Enter Customer Name: ").strip()
                age = int(input("Enter Age: ").strip())
                contact = input("Enter Contact Number: ").strip()
                address = input("Enter Address: ").strip()

                new_customer = Customer(cust_id, cust_name, age, contact, address)
                store.add_customer(new_customer)
            except ValueError:
                print(">> Error: Invalid numeric input.")

        elif choice == "9":
            # View Customers
            print("\n--- CUSTOMERS LIST ---")
            customers = store.get_customers()
            if not customers:
                print("No customers registered yet. Use Option 8 to add customers.")
            else:
                for c in customers:
                    c.display_customer()

        elif choice == "10":
            # Make Payment / Purchase
            print("\n--- MAKE PAYMENT / PURCHASE PRODUCT ---")
            if not store.get_products():
                print(">> No products in store to purchase. Add products first.")
                continue

            try:
                current_customer = None
                if store.get_customers():
                    print("Registered Customers:")
                    for c in store.get_customers():
                        print(f"ID: {c.get_customer_id()} | Name: {c.get_name()}")
                    cust_id = int(input("Enter Customer ID (or 0 for new walk-in customer): ").strip())
                    current_customer = store.find_customer(cust_id)

                if current_customer is None:
                    name = input("Enter Customer Name: ").strip()
                    contact = input("Enter Contact: ").strip()
                    walk_in_id = len(store.get_customers()) + 100
                    current_customer = Customer(walk_in_id, name, 25, contact, "Walk-in")
                    store.add_customer(current_customer)

                print("\nAvailable Products:")
                for p in store.get_products():
                    print(f"ID: {p.get_product_id()} | {p.get_name()} | Price: Rs. {p.get_price()} | "
                          f"Final Price (after {p.get_discount()}% disc): Rs. {p.get_final_price()} | "
                          f"Stock: {p.get_stock_quantity()}")

                buy_id = int(input("Enter Product ID to buy: ").strip())
                to_buy = store.find_product(buy_id)
                if to_buy is None:
                    print(">> Product not found.")
                    continue

                qty = int(input("Enter Quantity: ").strip())

                # Customer attempts to purchase
                success = current_customer.purchase_product(to_buy, qty)
                if not success:
                    continue

                total_amount = to_buy.get_final_price() * qty
                print(f"Total Amount to Pay: Rs. {total_amount}")

                print("Select Payment Mode:")
                print("1. Cash")
                print("2. Card")
                print("3. UPI")
                mode_choice = input("Enter choice (1-3): ").strip()
                mode = "Cash"
                if mode_choice == "2":
                    mode = "Card"
                elif mode_choice == "3":
                    mode = "UPI"

                # Create and process payment
                payment = Payment(payment_id_counter, total_amount, mode, "Pending", current_customer)
                payment_id_counter += 1
                payment.process_payment()
                payment_history.append(payment)

                # Option to leave a review
                rev_ans = input("Would customer like to give a review? (y/n): ").strip()
                if rev_ans.lower() == "y":
                    review_text = input("Enter review comment: ").strip()
                    stars = int(input("Enter rating (1 to 5 stars): ").strip())
                    current_customer.give_review(review_text, stars)

            except ValueError:
                print(">> Error: Invalid numeric input.")

        elif choice == "11":
            # Return / Replacement
            print("\n--- REQUEST RETURN / REPLACEMENT ---")
            try:
                ret_customer = None
                if store.get_customers():
                    c_id = int(input("Enter Customer ID: ").strip())
                    ret_customer = store.find_customer(c_id)

                r_prod_id = int(input("Enter Product ID: ").strip())
                reason = input("Enter Reason for request: ").strip()

                print("Select Request Type:")
                print("1. Return")
                print("2. Replacement")
                type_choice = input("Enter choice (1 or 2): ").strip()
                req_type = "Return" if type_choice == "1" else "Replacement"

                rr = ReturnReplacement(return_id_counter, r_prod_id, reason, req_type, "Pending", ret_customer)
                return_id_counter += 1
                rr.process_request()
                return_history.append(rr)

            except ValueError:
                print(">> Error: Invalid numeric input.")

        elif choice == "12":
            # Exit
            print("\n=================================================")
            print("  Thank you for using TechZone Electronics Store!")
            print("=================================================")
            running = False

        else:
            print(">> Invalid choice! Please select an option between 1 and 12.")


if __name__ == "__main__":
    main()

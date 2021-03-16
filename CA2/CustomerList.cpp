#include <iostream>
#include <fstream>
#include <algorithm>

#include "CustomerList.h"

// Returns a pointer to a customer if in the vector (as identified by their ID), and nullptr if not.
Customer* CustomerList::find_customer(const std::string& id) {
    std::vector<Customer>::iterator i = std::find_if(this->list.begin(), this->list.end(), [&id](const Customer& c) {
        return c.customerId == id;
    });

    if (i == this->list.end()) {
        return nullptr;
    }
    return &(*i);
}

// Pushes customer to vector
void CustomerList::add_customer(Customer& c) {
    this->list.push_back(c);
    std::cout << "OP: " << c << " added" << std::endl;
}

// Handles for end-of-day command. Iterates through vector and ships collective quantities if needed.
void CustomerList::end_of_day(const std::string& date) {
    std::cout << "OP: end of day " << date << std::endl;
    for (Customer& c : this->list) {
        if (c.currentOrderTotal > 0) {
            this->ship_to(date, c);
        }
    }
}

// Loops through file line-by-line to complete each command.
bool CustomerList::read_file(std::ifstream& input_file) {

	std::string line;
	while (std::getline(input_file, line)) {

		switch (line[0]) {
		case 'C': { 
            // Add customer
			std::string customer_id = line.substr(1, 4);

            // If customer already exists, return.
			if (find_customer(customer_id)) {
				std::cerr << "A customer with a duplicate ID was found." << std::endl;
				return false;
			}

            // Else, append customer to vector.
			Customer c(customer_id, line.substr(5));
			add_customer(c);

			break;
		}

		case 'S': {
            // Add shipment order

            // Lines must be exactly 17 long if correct
			if (line.length() != 17) {
				std::cerr << "Line was not correctly formed." << std::endl;
				return false;
			}

            // The end of the line should be numeric. If stoi() breaks, then it wasn't
			unsigned short quantity = 0;
			try {
				quantity = std::stoi(line.substr(14));
			}
			catch (...) {
				std::cerr << "Quantity in the line was non-numeric." << std::endl;
				return false;
			}

            // If the quantity is zero then there's no point continuing
			if (quantity <= 0) {
				break;
			}

            // Check the customer exists in the vector, and that the order can be made
			if (Customer* orderer = find_customer(line.substr(10, 4))) {
				if (!order(*orderer, line.substr(9, 1), line.substr(1, 8), quantity)) {
					std::cerr << "Order could not be placed." << std::endl;
					return false;
				}
			}
			else {
				std::cerr << "A customer with this id could not be found." << std::endl;
				return false;
			}
			break;
		}

		case 'E': {
            // End of day

            // Lines must be exactly 9 long if correct
			if (line.length() != 9) {
				std::cerr << "Line was not correctly formed." << std::endl;
				return false;
			}

            // Pass date to other function
			end_of_day(line.substr(1, 8));
			break;
		}

		default:
            // Command is invalid
			std::cerr << "Line does not start with 'new (C)ustomer', '(S)hip', or '(E)nd of day.'" << std::endl;
			return false;
		}
	}

	return true;
}

// Handles orders (sends invoice if express). True if order can be made, false if not
bool CustomerList::order(Customer& c, const std::string& order_type, const std::string& date, unsigned short quantity) {
	if (order_type != "X" && order_type != "N") {
		std::cerr << "Order not marked as either (N)ormal or e(X)press." << std::endl;
		return false;
	}

    std::cout << "OP: " << c << ": " << (order_type == "X" ? "EXPRESS" : "normal") << " order: quantity " << quantity << std::endl;
    c.currentOrderTotal += quantity;

    // if express, send invoice right away
    if (order_type == "X") {
        ship_to(date, c);
    }

    return true;
}

// sends invoice according to a customer's recorded order quantity at that time
void CustomerList::ship_to(const std::string& date, Customer& c) {
    std::cout << "OP: " << c << ": shipped " << c.currentOrderTotal << std::endl;
    Invoice invoice(c.customerId, c.name, date, c.currentOrderTotal);
    c.receiveInvoice(invoice);
}
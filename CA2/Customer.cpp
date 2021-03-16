#include "Customer.h"
#include "Invoice.h"
#include <iostream>

// Customer Constructor- empty as members are assigned in the signature
Customer::Customer(const std::string& id, const std::string& name) : customerId(id), name(name), currentOrderTotal(0) {}

// Acknowldgement of invoice from Customer object, sets ordered quantity to 0
void Customer::receiveInvoice(Invoice& i) {
	std::cout << "SC: " << *this << ": invoice " << i.invoiceNumber << ": date: " << i.shipmentDate << ", quantity: " << i.shipmentQuantity << std::endl;
    this->currentOrderTotal = 0;
}

// Stream insertion operator overloaded for easier formatting for console output
std::ostream& operator<<(std::ostream& lhs, const Customer& rhs) {
    lhs << "customer " << rhs.customerId << " (" << rhs.name << ")";
    return lhs;
}

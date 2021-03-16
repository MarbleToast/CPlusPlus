#pragma once

#include <string>
#include "Invoice.h"

class Customer
{
public:
	std::string customerId;
	std::string name;
	unsigned int currentOrderTotal;

	friend std::ostream& operator<< (std::ostream& lhs, const Customer& rhs);
	Customer(const std::string& id, const std::string& name);
	void receiveInvoice(Invoice& i);
};


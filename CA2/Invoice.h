#pragma once

#include <string>

class Invoice
{
public:
	static unsigned int nextInvoiceNumber;
	unsigned int invoiceNumber;
	const std::string customerNumber;
	const std::string customerName;
	const std::string shipmentDate;
	unsigned int shipmentQuantity;

	Invoice(const std::string& customerNumber, const std::string& customerName, const std::string& date, unsigned int quantity);
};

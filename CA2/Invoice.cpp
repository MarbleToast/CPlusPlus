#include "Invoice.h"
#include "Customer.h"

// Initialise static member to track invoice number
unsigned int Invoice::nextInvoiceNumber = 1000;

// Invoice constructor
Invoice::Invoice(const std::string& customerNumber, const std::string& customerName, const std::string& date, unsigned int quantity) :
	customerNumber(customerNumber),
	customerName(customerName),
	shipmentQuantity(quantity),
	shipmentDate(date) 
{
    // Post-Increment to tick up invoice number
	this->invoiceNumber = nextInvoiceNumber++;
}

#pragma once
#include <vector>
#include "Customer.h"

class CustomerList
{
private:
	std::vector<Customer> list;
public:
	Customer* find_customer(const std::string&);
	void add_customer(Customer&);

	bool read_file(std::ifstream&);
	bool order(Customer&, const std::string&, const std::string&, unsigned short);
	void end_of_day(const std::string&);
	void ship_to(const std::string&, Customer&);
};


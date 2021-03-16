#include <iostream>

int main() {
	char input[128];
	scanf_s("%s", input, (unsigned)_countof(input));
	printf("%s", input);

	return true;
}
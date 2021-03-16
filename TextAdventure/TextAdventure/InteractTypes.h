#pragma once
#include <string>
#include <algorithm>
#include <cctype>

typedef enum {
	VISUAL,
	TACTILE,
	VOCAL
} InteractionType;

InteractionType getVerbIntent(std::string verb) {
	std::transform(verb.begin(), verb.end(), verb.begin(), [](unsigned char c) {
		return std::tolower(c); 
	});
	if (verb == "") {

	}
}
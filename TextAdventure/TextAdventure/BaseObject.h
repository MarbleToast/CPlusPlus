#pragma once
#include <vector>
#include <string>

class BaseObject {
	std::string m_name;
	std::vector<std::string> m_verbs = {"inspect"};
public:
	BaseObject(std::string name);
	~BaseObject();

	std::vector<std::string> getVerbs();
	void interact(std::string verb);

	void onUse();
	void onInspect();
};


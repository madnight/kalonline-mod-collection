#include <string>
#include <vector>
#include <sstream>

class MadString
{
public:
	std::string madstring;
	MadString(std::string mad) {this->madstring = mad; }

	bool beginWith(std::string begin);
	void reverseStr();
	unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch);
};


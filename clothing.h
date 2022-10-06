#include <vector>
#include "util.h"
#include "product.h"

class Clothing : public Product{
public:
	Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);

	~Clothing(); //destructor

	std::set<std::string> keywords() const; //set of keywords

	std::string displayString() const; //display matches

	void dump(std::ostream& os) const;

private:
	std::string size_;
	std::string brand_;
};
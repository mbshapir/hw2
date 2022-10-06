#include <vector>
#include "util.h"
#include "product.h"

class Book : public Product{
public:
	Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);

	~Book(); //destructor

	std::set<std::string> keywords() const; //set of keywords

	std::string displayString() const; //display matches

	void dump(std::ostream& os) const;

private:
	std::string isbn_;
	std::string author_;
};
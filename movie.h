#include <vector>
#include "util.h"
#include "product.h"

class Movie : public Product{
public:
	Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);

	~Movie(); //destructor

	std::set<std::string> keywords() const; //set of keywords

	std::string displayString() const; //display matches

	void dump(std::ostream& os) const;

private:
	std::string genre_;
	std::string rating_;
};
#include <vector>
#include <iostream>
#include "util.h"
#include "clothing.h"
#include "product.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, string size, string brand) : Product(category, name, price, qty){
		size_ = size;
		brand_ = brand;
}

Clothing::~Clothing(){
}

set<string> Clothing::keywords() const{
	set<string> keywordBank;
	set<string> clothingnamekeywords = parseStringToWords(name_);//break name of clothing into keywords
	set<string> brandnamekeywords = parseStringToWords(brand_); //break brand name into keywords
	keywordBank.insert(clothingnamekeywords.begin(), clothingnamekeywords.end()); //add both to set of keywords
	keywordBank.insert(brandnamekeywords.begin(), brandnamekeywords.end());
	return keywordBank;

}

string Clothing::displayString() const{
	string output = "";
	output += "Name of Clothing: ";
	output += name_;
	output += "\n";
	output += "Name of Brand: ";
	output += brand_;
	output += "\n";
	output += "Size: "; 
	output += size_;
	output += "\n";
	output += "Price: ";
	output += price_;
	output += "\n";
	output += "Quantity: ";
	output += qty_;
	output += "\n";
	return output;
	/*string output = "";
	output = output + "Name of Clothing: " + name_ + "\n" + "Name of Brand: " + brand_ + "\n" + "Size: " + size_ + "\n" + "Price: " + price_ + "\n" + "Quantity: " + qty_ + "\n";
	return output;
	*/
}

void Clothing::dump(std::ostream& os) const{
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << brand_ << "\n" << size_ << endl;
	//taken from product.cpp but added size and brand
}
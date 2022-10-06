#include <vector>
#include <iostream>
#include "util.h"
#include "book.h"
#include "product.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, string isbn, string author) : Product(category, name, price, qty){
		isbn_ = isbn;
		author_ = author;
}

Book::~Book(){
}

set<string> Book::keywords() const{
	set<string> keywordBank;
	set<string> booknamekeywords = parseStringToWords(name_);//break name of book into keywords
	set<string> authornamekeywords = parseStringToWords(author_); //break author name into keywords
	keywordBank.insert(booknamekeywords.begin(), booknamekeywords.end()); //add both to set of keywords
	keywordBank.insert(authornamekeywords.begin(), authornamekeywords.end());
	keywordBank.insert(isbn_);
	return keywordBank;

}

string Book::displayString() const{
	string output = "";
	output += name_;
	output += "\n";
	output += "Author: ";
	output += author_;
	output += " ISBN: "; 
	output += isbn_;
	output += "\n";
	output += price_;
	output += " ";
	output += qty_;
	output += " left.";
	return output;
}

void Book::dump(std::ostream& os) const{
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << author_ << "\n" << isbn_ << endl;
	//taken from product.cpp but added isbn and author
}
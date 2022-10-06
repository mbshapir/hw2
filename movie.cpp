#include <vector>
#include <iostream>
#include "util.h"
#include "movie.h"
#include "product.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, string genre, string rating) : Product(category, name, price, qty){
		genre_ = genre;
		rating_ = rating;
}

Movie::~Movie(){
}

set<string> Movie::keywords() const{
	set<string> keywordBank;
	set<string> movienamekeywords = parseStringToWords(name_);//break name of movie into keywords
	set<string> genrenamekeywords = parseStringToWords(genre_); //break genre name into keywords
	keywordBank.insert(movienamekeywords.begin(), movienamekeywords.end()); //add both to set of keywords
	keywordBank.insert(genrenamekeywords.begin(), genrenamekeywords.end());
	return keywordBank;

}

string Movie::displayString() const{
	string output = "";
	output += name_;
	output += "\n";
	output += "Genre: ";
	output += genre_;
	output += " Rating: "; 
	output += rating_;
	output += "\n";
	output += price_;
	output += " ";
	output += qty_;
	output += " left.";
	return output;
	/*string output = "";
	output = output + "Name of Movie: " + name_ + "\n" + "Name of Genre: " + genre_ + "\n" + "Rating: " + rating_ + "\n" + "Price: " + price_ + "\n" + "Quantity: " + qty_ + "\n";
	return output;
	*/
}

void Movie::dump(std::ostream& os) const{
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
	//taken from product.cpp but added genre and rating
}
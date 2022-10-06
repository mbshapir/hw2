#include <search>
#include "datastore.h"
#include "product.h"
#include "util.h"


class MyDataStore : public DataStore{
public: 
	MyDataStore();
	~MyDataStore();

	void addProduct(Product* p); //add product

	void addUser(User* u); //add user

	std::vector<Product*> search(std::vector<std::string>& terms, int type);

	void dump(std::ostream& ofile);

	void addCart(int searchItemIndex, std::string currentUser));

	void viewCart(std::string currentUser);

	void checkoutCart(std::string currentUser)); 

private:

	std::map<std::string, User*> userlist; //store list of users found via username

	std::set<Product*> productlist; //store set of products

	std::map<std::string, Product*> nameToProduct; //maps key: product name to pointer to product
	
	std::map<std::string, std::set<Product*>> keywordToSet; //maps key: keywords to sets of products related to keywords

	std::map<std::string, std::vector<Product*>> nameToProduct; //key:username, value:cart contents stores as vector

	std::map<int, Product*> productSearched; //product displayed corresponding to search number

};
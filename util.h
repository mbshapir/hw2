#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
	typename std::set<T>::iterator set1iteratorB = s1.begin();
	typename std::set<T>::iterator set2iteratorB = s2.begin();
	typename std::set<T>::iterator set1iteratorE = s1.end();
	typename std::set<T>::iterator set2iteratorE = s2.end();
	typename std::set<T> intersectingSet;

	while(set1iteratorB != set1iteratorE && set2iteratorB != set2iteratorE){
		if(*set1iteratorB == *set2iteratorB){ //check if elements match
			intersectingSet.insert(*set1iteratorB); //insert if so
			set1iteratorB++; //increment
			set2iteratorB++;
		}else if(*set1iteratorB > *set2iteratorB){ //catch up lacking set if elements do not match
			set2iteratorB++;
		}else{ // if set1iteratorB < set2iteratorB
			set1iteratorB++;
		}
	}
	
	return intersectingSet;
	//should run in O(nlog(n)) considering this methid will go through all the elements of 1 set and only some of the other

}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{

	typename std::set<T> newSet; //new set to hold both old sets
	newSet.insert(s1.begin(), s1.end()); //include all of set 1
	newSet.insert(s2.begin(), s2.end()); //include all of set 2

	return newSet;

}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif

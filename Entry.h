/**----------------------------------------------------------------------------
FileName:
Author: Stephen Deguchi
Student ID#: 1672539
2/4/17
Holds data for each entry into the hash table
*/

#ifndef HASHTABLE_ENTRY_H
#define HASHTABLE_ENTRY_H

#include<string>
#include <iostream>

using namespace std;

//multiplier to scale letter binary values to the hash table entry positions
const double scale=160.654;

class Entry {

public:
//-----------------------------------------------------------------------------
// Constructor
/**
 * Default constructor for an Entry
 * @parameter string : entire line of entry in phonebook.txt
 */
	Entry(const string);
//-----------------------------------------------------------------------------
// HashFunction
/**
 * Hash function used to determine the position the entry will be inserted in
 * the hash table
 * @return position : int
 */
	int HashFunction() const;
//-----------------------------------------------------------------------------
// GetNum
/**
 * Gets the unique parts of each phone number
 * @return number
 */
	int GetNum() const;

private:
	//entries first name
	string last;
	//entries last name
	string first;
	//areacode
	int areaCode;
	//phone number
	int number;

};

#endif //HASHTABLE_ENTRY_H

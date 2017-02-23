/**----------------------------------------------------------------------------
FileName:
Author: Stephen Deguchi
Student ID#: 1672539
2/4/17
Holds the entries for each item in the phonebook text file
*/

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include "Entry.h"
#include <list>

const int size = 4177;  //size of hash table
const int histogramSize = 40; //histogram data set size


class HashTable {

public:
//-----------------------------------------------------------------------------
// Destructor
/**
 * Hash Table destructor
 */
	~HashTable();
//-----------------------------------------------------------------------------
// Insert
/**
 * Hash function used to determine the position the entry will be inserted in
 * the hash table
 * @param position : int : position to insert entry into table
 * @param entry : Entry& : Entry to insert into table
 */
	void Insert(int, Entry *&);
//-----------------------------------------------------------------------------
// Print
/**
 * Prints out the chain length for each hash table entry
 */
	void Print();

private:
	//hash table with list of Entry pointers
	list<Entry *> table[size];

	//histogram of entries and chain lengths
	int histogram[histogramSize];


//-----------------------------------------------------------------------------
// RetrieveCount
/**
 * Finds the number of items in a hash table entry
 * @param list<Entry*>& : Entry in the table
 * @return int : Chain length of entry
 */
	int RetrieveCount(list<Entry *> &) const;
//-----------------------------------------------------------------------------
// RetrieveStdDev
/**
 * Finds the standard deviation from chain length of 11 for each entry
 * @param int[] : histogram data
 * @return int : standard deviation
 */
int RetrieveStdDev(int&);
//-----------------------------------------------------------------------------
// CreateHistogram
/**
 * Initialize values and create the histogram for the hash table
 */
	void CreateHistogram();
};

#endif //HASHTABLE_HASHTABLE_H

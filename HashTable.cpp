/**----------------------------------------------------------------------------
FileName: HashTable.cpp
Author: Stephen Deguchi
Student ID#: 1672539
2/4/17
Holds the entries for each item in the phonebook text file
*/
#include "HashTable.h"

const int optChainlength = 11; //ideal chain length of listings
//-----------------------------------------------------------------------------
// Destructor
/**
 * Hash Table destructor
 */
HashTable::~HashTable() {

	//visit every entry in the hash table
	for (int i = 0; i < size; i++) {
		list<Entry *>::iterator it;

		//start at the beginning of the chain and delete every entry
		for (it = table[i].begin(); it != table[i].end(); it++) {
			delete *it;
		}
	}

}
//-----------------------------------------------------------------------------
// Insert
/**
 * Hash function used to determine the position the entry will be inserted in
 * the hash table
 * @param position : int : position to insert entry into table
 * @param entry : Entry*& : Entry* to insert into table
 */
void HashTable::Insert(int pos, Entry *&entry) {
	//iterator to insert the entry
	list<Entry *>::iterator it;
	it = table[pos].begin();

//insert the entry at the beginning of the list at given position
	table[pos].insert(it, entry);
}
//-----------------------------------------------------------------------------
// Print
/**
 * Prints out the histogram data for the listings in the hash table.
 * outputs a chain length and the number of entries in the hash table with
 * given chain length.
 */
void HashTable::Print() {

	//standard deviation for hash function
	int std=0;

	//number of total listings
	int entries=0;

	//create histogram
	CreateHistogram();

	//calculate standard deviation and number of listings
	std=RetrieveStdDev(entries);

	//output the histogram
	cout << "chain length" << "\t" << "# entries" << endl;
	for (int i = 0; i < histogramSize; i++) {
		cout << i << "\t\t" << histogram[i] << endl;
	}

	//output standard deviation hash functions standard deviation from
	//perfect hash function
	cout<<"Standard deviation from 11= "<<(double)std/size<<endl;

	//output total number of listings in table
	cout<<"# entries= "<<entries<<endl;

}
//-----------------------------------------------------------------------------
// RetrieveCount
/**
 * Finds the number of listings in a hash table entry
 * @param chain : list <Entry*>& : chain list
 * @return int : length of chain
 */
int HashTable::RetrieveCount(std::list<Entry *> &chain) const {

	//length of chain
	int count = 0;

	//iterator to walk through list
	list<Entry *>::iterator it;

	//increase the chain length until at the end of the list
	for (it = chain.begin(); it != chain.end(); it++) {
		count++;
	}
	return count;
}
//-----------------------------------------------------------------------------
// RetrieveStdDev
/**
 * Finds the standard deviation from chain length of 11 for each entry
 * @param int[] : histogram data
 * @return int : standard deviation
 */
int HashTable::RetrieveStdDev(int& entries){
	//int for standard deviation
	int std=0;

	//calculate standard deviation and count entries
	for(int i=0;i<histogramSize;i++){

		//11 is ideal chain size, subtract it from actual chain size and
		//multiply it by the number of occurrences
		std+=abs((optChainlength-i)*histogram[i]);

		//increase the count of listings
		entries+=i*histogram[i];
	}
	return std;
}
//-----------------------------------------------------------------------------
// CreateHistogram
/**
 * Initialize values and create the histogram for the hash table
 */
void HashTable::CreateHistogram(){

	//initialize the values to 0
	for (int i = 0; i < histogramSize; i++) {
		histogram[i] = 0;
	}
	//Get the chain length of each entry and increment the count of the
	// chain length in histogram
	for (int i = 0; i < size; i++) {

		//get the chain length of entry
		int count = RetrieveCount(table[i]);

		//increase the count of the entries with given chain length
		histogram[count]++;
	}
}
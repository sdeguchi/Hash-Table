/**----------------------------------------------------------------------------
FileName: main.cpp
Author: Stephen Deguchi
Student ID#: 1672539
2/4/17
Main for Hash Table function project

 *Input:Our input will be coming from a text file with entries in it consisting
 	of a last name, first name, and phone number. Here is an example of the
 	format of the text file: Arnold, Adam	(206) 429-2245

 *Output:The program needs to output data to construct a distribution of the
 	data in the form of a histogram for each hash table entry. It will count
 	the chain length at each entry and display the results, so that a hypothesis
 	can be made on how to improve the function.

 *Usage: Takes "phonebook.txt" as an argument

 *Assumptions: One assumption we will make is that each line will be consisting
 	of a unique entry, so that we won't have to account for same data in the
 	hash function.

 *Description of algorithms and variables:
 	Hash function:
	The data in the phone book was analyzed and found to contain equal
 	occurrences of first letters in the first name. The data set could then be
 	divided by 26(number of letters in the alphabet) and entries could be given
 	a value (1-26) and scaled to the 4177 entries. Since 4177/26=164.654, the
 	letter value was multiplied by this constant. Then to randomize the data
 	between the scaling of letter values, the number was added to the phone
 	number with the first digit after the area code removed and increased by a
 	constant value based on the area code.
 	The data contains nine unique first letters of last names and to further
 	distinguish each listing from another, the last names were then broken up
 	into different sets based on first letters and incremented by various values
 	from 0-2. Finally, to ensure the number fit in the hash table, a mod 4177
 	(table size)operation was applied to the number and returned.
*/
#include "HashTable.h"
#include <fstream>

int main(int argc, char *argv[]) {

	//check for valid arguments
	if (argc != 2) {
		cout << "usage: " << argv[0] << " <filename>\n";
		exit(1);
	}
	//create a infile stream from file name argument

	ifstream file(argv[1]);

	//check for valid txt file
	if (!file.is_open()) {
		cout << "invalid filename" << endl;
		exit(1);
	}
	//hash table to hold entries
	HashTable ht;

	//get lines from the text file while not at the end
	while (!file.eof()) {

		//string for entire entry line
		string line;
		getline(file, line);


		if (!file.eof()) {

			//create a new entry
			Entry *entry = new Entry(line);

			//insert the new entry
			ht.Insert(entry->HashFunction(), entry);

		}

	}
//close infile
	file.close();

//print out histogram values
	ht.Print();

	return 0;
}
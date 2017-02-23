/**----------------------------------------------------------------------------
FileName: Entry.cpp
Author: Stephen Deguchi
Student ID#: 1672539
2/4/17
Holds data for each entry into the hash table
*/
#include "Entry.h"

//-----------------------------------------------------------------------------
// Constructor
/**
 * Default constructor for an Entry
 * Parses line from file passed in and initializes all of the members
 */
Entry::Entry(const string line) {
	//position in the string
	int pos = 0;

	//get the characters for the last name
	while (line.at(pos) != ',') {
		last.push_back(line[pos]);
		pos++;
	}
	//skip space and comma
	pos += 2;
	//get the characters for the first name
	while (line.at(pos) != '\t') {
		first.push_back(line[pos]);
		pos++;
	}
	//skip space and parenthesis
	pos += 2;
	//string for areacode
	string code;
	//get the area code
	for (int i = 0; i < 3; i++) {
		code.push_back(line[pos]);
		pos++;
	}
	//convert the string with area code to an int
	areaCode = atoi(code.c_str());
	pos += 2;
	//string for phone number
	string num;
	//get the phone number
	for (int i = 0; i < 3; i++) {
		num.push_back(line[pos]);
		pos++;
	}
	//skip hyphen
	pos++;
	//get rest of phone number
	for (int i = 0; i < 4; i++) {
		num.push_back(line[pos]);
		pos++;
	}
	//convert string to int
	number = atoi(num.c_str());

}
//-----------------------------------------------------------------------------
// HashFunction (Analyzed data derivation)
/**
 * Hash function used to determine the position the entry will be inserted in
 * the hash table
 * Detailed description in main.cpp
 * @return position : int
 */
int Entry::HashFunction() const {

	//hash code to return
	int hash = 0;

	//assign values from 0-25 for A-Z
	hash=first.at(0)-'A';

	hash *= (first.at(0)-'A')%first.length();

	//use the unique digits in the phone number to add to hash number
	//hash = hash + (GetNum()<<((first.at(0)-'A'))%first.length());

	//double the hashcode to distinguish between areacodes
	if (areaCode == 425) {
		hash = hash * 2;
	}
	//Increment the hashcode to distinguish between starting letter of last name
	if (last.at(0) == 'A' || last.at(0) == 'B' || last.at(0) == 'E') {
		hash++;
	}
	if (last.at(0) == 'S' || last.at(0) == 'T' || last.at(0) == 'Z') {
		hash += 2;
	}

	//hash += GetNum() << 4;
	//Use mod table size to allow hash code to fit in the hash table
	return hash % 4177;
}
//-----------------------------------------------------------------------------
// HashFunction (ASCII value sums)
/**
 * Hash function used to determine the position the entry will be inserted in
 * the hash table
 * @return position : int
 */
//int Entry::HashFunction()const{
//int hash=0;
//	for(int i=0; i<first.length();i++){
//		hash+=first[i];
//	}
//	for(int i=0; i<last.length();i++){
//		hash+=last[i];
//	}
//	return (hash+GetNum())%4177;
//}
//-----------------------------------------------------------------------------
// HashFunction (5 bit binary number concatenation)
/**
 * Hash function used to determine the position the entry will be inserted in
 * the hash table
 * @return position : int
 */
//int Entry::HashFunction()const{
//ulong hash=0;
//	for(int i=0; i<first.length();i++){
//		hash+=first[i]*pow(32,first.length()-i-1);
//	}
//
//	for(int i=0; i<last.length();i++){
//		hash+=last[i]*pow(32,last.length()-i-1);
//	}
//	hash+=GetNum();
//
//	return abs((int)(hash%4177));
//}
//-----------------------------------------------------------------------------
// GetNum
/**
 * @return number
 */
int Entry::GetNum() const {
	//only leave the unique numbers in the 425 areacode number and
	// increment by 3
	if (areaCode == 425) {
		return number % 1000000 + 4000003;
	}
		//only leave the unique numbers in a 206 areacode and
		// increment by 5
	else {
		return number % 1000000 + 2000005;
	}
}

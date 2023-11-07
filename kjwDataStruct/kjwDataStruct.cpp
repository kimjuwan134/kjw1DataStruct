#include <iostream>
#include "HashTable.h"

using namespace std;


int main()
{
	HashTable<string, int> hash;

	hash.Insert("ANX", 1000);
	hash.Insert("DSA", 2000);
	hash.Insert("HFH", 3000);
	hash.Insert("ERU", 4000);
	hash.Insert("EQW", 5000);

	hash.Display();






	

	return 0;
}
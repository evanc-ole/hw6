#include "ht.h"
#include "hash.h"
#include <unordered_map>
#include <iostream>
#include <utility>
#include <set>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
int main()
{
    DoubleHashProber<std::string, MyStringHash > dh;
    HashTable<
        std::string, 
        int, 
        DoubleHashProber<std::string, MyStringHash >, 
        std::hash<std::string>, 
        std::equal_to<std::string> > ht(0.7, dh);

    // This is just arbitrary code. Change it to test whatever you like about your 
    // hash table implementation.
		pair<string, int> pair1("one", 1);
    pair<string, int> pair2("two", 2);
    pair<string, int> pair3("three", 3);
    HashTable<string, int, DoubleHashProber<string, std::hash<string>>, hash<string>, equal_to<string> > ht1;
    set<pair<string, int>> items;
    //Insert Items
    ht1.insert(pair1);
    ht1.insert(pair2);
    ht1.insert(pair3);

    //Remove Items
		ht1.remove("bruh");
    ht1.remove(pair1.first);

    ht1.remove(pair3.first);

    ht1.remove(pair2.first);

    return 0;
}

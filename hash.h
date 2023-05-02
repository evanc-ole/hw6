#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <iostream>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
			HASH_INDEX_T a[5]= {};

			// Add your code here
			for(int i = k.length() - 1, z = 4; i >= 0; i-=6, z--){
				HASH_INDEX_T base = 1;
				unsigned long long w[6] = {};
				for(int j = 0; j <= 5; j++){
					if(i - j >= 0){
						HASH_INDEX_T val = letterDigitToNumber(tolower(k[i - j]));
						w[j] += val*base;
						base *= 36;
					}
				}
				a[z] = w[0] + w[1] + w[2] + w[3] + w[4] + w[5];
			}
			for(int i = 0; i < 5; i++){
				std::cout << a[i] << std::endl;
			}
			return rValues[0] * a[0] + rValues[1] * a[1] + rValues[2] * a[2] + rValues[3] * a[3] + rValues[4] * a[4];
    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
			if('0' <= letter && letter <= '9'){
				return letter - '0' + 26;
			}
			else if('a' <= letter && letter <= 'z'){
				return letter - 'a';
			}
			return 0;
    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif

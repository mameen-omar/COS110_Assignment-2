#ifndef SUBSTITUTIONCIPHER_H
#define SUBSTITUTIONCIPHER_H
//add header guard



#include "Cipher.h"
#include <string>
#include <iostream>

using namespace std;

class SubstitutionCipher : public Cipher
{
	public:
		virtual char encodeChar(char) = 0;
		virtual char decodeChar(char) = 0;
		virtual string encode(string);
		virtual string decode(string);
};

#endif
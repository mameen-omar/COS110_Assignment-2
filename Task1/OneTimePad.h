#ifndef ONETIMEPAD_H
#define ONETIMEPAD_H

#include "Caesar.h"
#include "SubstitutionCipher.h"
#include "Cipher.h"

using namespace std;


class OneTimePad : public Caesar
{
	protected:
		long int seed;
	public:
		OneTimePad(long int);
		void setSeed(long int);
		virtual char encodeChar(char);
		virtual char decodeChar(char);
		virtual string encode(string);
		virtual string decode(string);
};


#endif
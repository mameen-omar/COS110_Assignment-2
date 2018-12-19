#ifndef ZIGZAG_H
#define ZIGZAG_H

#include "TranspositionCipher.h"
#include <string>

using namespace std;

class ZigZag : public TranspositionCipher
{
	public:
		string encode(string);
		string decode(string);
};

#endif
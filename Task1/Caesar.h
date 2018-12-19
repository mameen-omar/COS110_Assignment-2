#ifndef CAESAR_H
#define CAESAR_H

#include "SubstitutionCipher.h"
#include "Cipher.h"

using namespace std;


class Caesar : public SubstitutionCipher
{
	protected:
		int shift;

	public:
		Caesar();
		void setShift(int);
		virtual char encodeChar(char);
		virtual char decodeChar(char);
};



#endif
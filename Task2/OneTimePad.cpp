#include "Caesar.h"
#include "SubstitutionCipher.h"
#include "Cipher.h"
#include "OneTimePad.h"
#include <cstdlib>
#include <string>

using namespace std;

OneTimePad::OneTimePad(long int x)
{
	seed = x;
	srand(seed);
}


void OneTimePad::setSeed(long int x)
{
	seed = x;
	srand(seed);
}


char OneTimePad::encodeChar(char a)
{

	int random = ((rand() % (94 - 1 +1 )) + 1 );
	setShift(random);
	Caesar::encodeChar(a);
}

char OneTimePad::decodeChar(char a)
{
	int random = ((rand() % (94 - 1 +1 )) + 1 );
	setShift(random);
	Caesar::decodeChar(a);
}

string OneTimePad::encode(string s)
{
	srand(seed);

	int stringLength = s.length();

	for(int index = 0; index < stringLength; index++)
	{
		s[index] = encodeChar(s[index]);
	}

	return s;
}


string OneTimePad::decode(string s)
{
	srand(seed);

	int stringLength = s.length();

	for(int index = 0; index < stringLength; index++)
	{
		s[index] = decodeChar(s[index]);
	}

	return s;
}


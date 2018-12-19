#include "Cipher.h"
#include "SubstitutionCipher.h"
#include <string>
#include <iostream>

using namespace std;

string SubstitutionCipher::encode(string s)
{
	int stringLength = s.length();

	for(int index = 0; index < stringLength; index++)
	{
		s[index] = encodeChar(s[index]);
	}

	return s;
}

string SubstitutionCipher::decode(string s)
{
	int stringLength = s.length();

	for(int index = 0; index < stringLength; index++)
	{
		s[index] = decodeChar(s[index]);
	}

	return s;
}
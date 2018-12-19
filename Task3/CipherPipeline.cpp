#include "CipherPipeline.h"
#include <string>
#include <vector>

using namespace std;

string CipherPipeline::encode( string plain )
{
	string cipher = plain;

	for ( Cipher* pipe1 : Pipeline )
	{
		cipher = pipe1->encode(cipher);
	}

	return cipher;
}

CipherPipeline& CipherPipeline::operator=( vector<Cipher*> pipeArg)
{
	Pipeline.swap(pipeArg);

	return *this;
}


CipherPipeline& CipherPipeline::operator+=( Cipher* cipherArg)
{
	Pipeline.push_back( cipherArg );

	return *this;
}

vector <Cipher*> operator+(Cipher& cipher1, Cipher& cipher2)
{		
	Cipher* cipher1Temp = &cipher1;

	Cipher* cipher2Temp = &cipher2;
	
	vector<Cipher*> temp;

	temp.push_back(cipher1Temp);

	temp.push_back(cipher2Temp);

	return temp;
}

CipherPipeline& CipherPipeline::operator+=( vector<Cipher*> pipeArg)
{
	Pipeline.insert( Pipeline.end(), pipeArg.begin(), pipeArg.end() );

	return *this;
}

string CipherPipeline::decode( string cipher )
{
	string plain = cipher;

	int size = Pipeline.size() - 1;

	for (int x = size; x >= 0 ; x--)
	{
		plain = Pipeline[x]->decode(plain);
	}

	return plain;
}


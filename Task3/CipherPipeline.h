#ifndef CIPHERPIPELINE_H
#define CIPHERPIPELINE_H

#include "Cipher.h"

#include <vector>


using namespace std;

class CipherPipeline
{
	private:
		vector<Cipher*> Pipeline;

	public:
		string encode( string );
		string decode( string );
		CipherPipeline& operator+=( Cipher* );
		CipherPipeline& operator=( vector<Cipher*> );
		CipherPipeline& operator+=( vector<Cipher*> );	
	
};

vector <Cipher*> operator+(Cipher&, Cipher&);

#endif
#ifndef ROWSCOLUMNS_H
#define ROWSCOLUMNS_H

#include "TranspositionCipher.h"
#include <string>

using namespace std;

class RowsColumns : public TranspositionCipher
{
	public:
		~RowsColumns()
		{	}
		string encode(string);
		string decode(string);

};


#endif
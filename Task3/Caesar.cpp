#include "SubstitutionCipher.h"
#include "Cipher.h"
#include "Caesar.h"
#include <string>

using namespace std;

Caesar::Caesar()
{
	this->shift = 0;
}

void Caesar::setShift(int x)
{
	bool again = true;
	while(again)
	{
		try
		{
			string positive = "Please provide a positive shift value";
			string greater = "Maximum shift is 94 for ASCII, please try again";
			if(x <= 0)
			{
				throw positive;
			}

			else if(x > 94)
			{
				throw greater;
			}

			else
			{
				again = false;	
			}
		}catch(string message)
			{
				cout << message << endl;
				cin >> x;
			}
			
			shift = x;
			return;
				
	}

}

char Caesar::encodeChar(char a)
{
	setShift(shift);

	
	if((a + shift) <= 126 && a>= 32)
	{
		a = a + shift;
		return a;
	}

	else
	{
		a = 32 + (a - (126-shift) -1);
		return a;
	}

}

char Caesar::decodeChar(char a)
{
	if( (a - shift) >= 32 && a <= 126 )
	{
		a = a - shift;
		return a;
	}

	else 
	{
		return (126+1) - (shift - (a-32));

	}
}
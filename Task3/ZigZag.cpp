#include "ZigZag.h"
#include "TranspositionCipher.h"
#include <cmath>
#include <string>

using namespace std;

string ZigZag::encode(string plain)
{	
	int length = plain.length();
	int size = calculateSide(length);

	char** matrix = createMatrix(size);

	fillMatrix(matrix, size, plain);

	string cipher = "";

	for(int col = 0; col < size; col++)
	{	
		//if even
		if((col % 2) == 0 || col == 0)
		{
			for(int row = 0; row < size; row++)
			{
				cipher += matrix[row][col];
			}
		}

		//if odd
		else
		{
			for(int row = size; row > 0; row--)
			{
				cipher += matrix[row-1][col];
			}	
		}
	}

	deleteMatrix(matrix, size);

	return cipher;
}

string ZigZag::decode(string cipher)
{
	string error = "Incompatible text length";

	int length = cipher.length();

	int size = calculateSide(length);

	try
	{
		if(size != sqrt(length))
		{
			throw error;
		}
	}catch(string err)
	 {
		cout << err;
		return "";
	 }

	string plain = "";

	char ** matrix = createMatrix(size);

	fillMatrix(matrix, size, cipher);
	
	int col2 = (size - 1);

	for (int col = 0; col < size; col++)
	{
		for (int row = 0; row < size; row++)
		{
			if ( (row % 2 ) != 0 )
			{
				plain += matrix[row][col2];				
			}

			else
			{
				plain += matrix[row][col];
			}
		}

		col2--;		
	}	
	
	deleteMatrix(matrix, size);

	return plain;
}
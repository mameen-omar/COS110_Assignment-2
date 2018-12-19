#include "TranspositionCipher.h"
#include <cmath>
#include <string>

using namespace std;

char** TranspositionCipher::createMatrix(int size)
{
	char** matrixPtr = new char*[size];

	for(int x = 0; x<size; x++)
	{
		matrixPtr[x] = new char[size];
	}

	return matrixPtr;
}	

void TranspositionCipher::deleteMatrix(char ** matrixPtr, int size)
{
	for(int x = 0; x< size; x++)
	{
		delete [] matrixPtr[x];
	}

	delete [] matrixPtr;

}

void TranspositionCipher::fillMatrix(char** matrix, int size, string text)
{
	int count = 0;

	for(int row = 0; row < size; row++)
	{
		for(int col = 0; col < size; col++)
		{
			if( count < text.length() )
			{
				matrix[row][col] = text[count];
				count++;
			}

			else
			{
				matrix[row][col] = 32;
				count++;
			}
			
		}
	}

}

int TranspositionCipher::calculateSide(int length)
{
	int size = ceil(sqrt(length));

	return size;
}
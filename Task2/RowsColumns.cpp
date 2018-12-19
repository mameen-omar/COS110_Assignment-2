#include "RowsColumns.h"
#include "TranspositionCipher.h"
#include <cmath>
#include <string>

using namespace std;

string RowsColumns::encode(string plain) 
{
  string cipher = "";

  int length = plain.length();

  // size of matrix
  int size = calculateSide(length);

  char **matrix = createMatrix(size);

  fillMatrix(matrix, size, plain);

  // matrix now contains our plaintext

  for (int col = 0; col < size; col++)
	{
    for (int row = 0; row < size; row++)
	{
      cipher += matrix[row][col];
    }
  }

  deleteMatrix(matrix, size);

  return cipher;
}

string RowsColumns::decode(string cipher) 
{
  string error = "Incompatible text length";

  int length = cipher.length();

  int size = calculateSide(length);

  try
  {
    if (size != sqrt(length))
	{
      throw error;
    }
  }catch (string err)
	{
   	 	cout << err;
    	return "";
 	}

  string plain = "";

  char **matrix = createMatrix(size);

  fillMatrix(matrix, size, cipher);

  for (int col = 0; col < size; col++)
  {
    for (int row = 0; row < size; row++)
	{
      plain += matrix[row][col];
    }
  }

  deleteMatrix(matrix, size);

  return plain;
}

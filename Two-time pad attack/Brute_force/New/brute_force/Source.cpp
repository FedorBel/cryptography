#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>

#include "ttp_decoder.h"

using namespace std;

/*
1) The target message has 83 characters. Truncate all 11 ciphertexts to 83 chars
(each char is represented by hex 00-ff) and arrange them in a matrix.
Each column is now encrypted by a single byte, 00-ff.
2) Xor all possible key-bytes 00-ff with the column and add the number of times the result is contained in the following (notice the included space):
3) " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
4) The byte-key with the highest score wins for that column. Repeat for each column.

Текст для расшифровки:
32510ba9babebbbefd001547a810e67149caee11d945cd7fc81a05e9f85aac650e9052ba6a8cd8257bf14\
d13e6f0a803b54fde9e77472dbff89d71b57bddef121336cb85ccb8f3315f4b52e301d16e9f52f904
(Последний индекс вектора cts)
*/

int main()
{
	cout << "Two-time pad attack." << "\n\n";
	string path = "ciphertext.txt";
	cout << "Input file format example:" << "\n\n";
	cout << "=======================\n";
	cout << "Text 1\n"
		<< "\"Hex encoded string\"\n"
		<< "Text 2\n"
		<< "\"Hex encoded string\"\n"
		<< "Text N\n"
		<< "\"Hex encoded string\"\n"
		<< "Target\n"
		<< "\"Hex encoded string\"\n";
	cout << "=======================\n\n";

	cout << "Enter input file name:";
	//cin >> path;

	ttp_decoder::BruteForce decoder;
	decoder.SetCiphertexts(ttp_decoder::ReadFromFile(path));
	string plaintext = decoder.Decode();
	//ttp_decoder::ClearFile();


	return 0;
}
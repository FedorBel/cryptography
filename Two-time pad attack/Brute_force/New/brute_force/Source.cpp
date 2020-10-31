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
	string read_path = "ciphertext.txt";
	cout << "Input file format example:" << "\n\n";
	cout << "=======================\n";
	cout << "Text 1\n"
		<< "Hex encoded string\n"
		<< "Text 2\n"
		<< "Hex encoded string\n"
		<< "Text N\n"
		<< "Hex encoded string\n"
		<< "Target\n"
		<< "Hex encoded string\n";
	cout << "=======================\n\n";

	cout << "Default input file name: " << read_path << "\n";
	cout << "Change it? y/n\n";
	char change_res;
	cin >> change_res;

	while (change_res != 'y' && change_res != 'n')
	{
		cout << "Wrong input!\n";
		cout << "Default input file name: " << read_path << "\n";
		cout << "Change it? y/n\n";
		cin >> change_res;
	}

	if (change_res == 'y')
	{
		cout << "Enter input file name: ";
		cin >> read_path;
	}


	cout << "Decoding started..." << std::endl;
	
	vector<string> ciphertexts = ttp_decoder::ReadFromFile(read_path);
	string target_text_hex = ciphertexts.back();
	vector<int> target_text = ttp_decoder::HexStringToDec(target_text_hex);

	ttp_decoder::BruteForce decoder;
	decoder.SetCiphertexts(ciphertexts);
	vector<int> key = decoder.CrackKey(); // normal string
	string plaintext = ttp_decoder::Decode(target_text, key);
	//ttp_decoder::ClearFile();
	string write_path = "plaintext.txt";

	cout << "Default output file name: " << write_path << "\n";
	cout << "Change it? y/n\n";
	cin >> change_res;

	while (change_res != 'y' && change_res != 'n')
	{
		cout << "Wrong input!\n";
		cout << "Default output file name: " << write_path << "\n";
		cout << "Change it? y/n\n";
		cin >> change_res;
	}

	if (change_res == 'y')
	{
		cout << "Enter input file name: ";
		cin >> write_path;
	}

	ttp_decoder::WriteToFile(write_path, plaintext);

	return 0;
}
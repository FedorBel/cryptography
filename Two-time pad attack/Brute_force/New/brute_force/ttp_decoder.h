#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <cmath>
#include <vector>
#include <fstream>
#include <numeric>

namespace ttp_decoder
{
	// *********************************************
	// Decode ciphertext using secret key
	// *********************************************
	std::string Decode(std::vector<int> ciphertext, std::vector<int> key);

	// *********************************************
	// Last string in vector must be target text
	// *********************************************
	std::vector<std::string> ReadFromFile(const std::string& path);

	// *********************************************
	// Write plaitext to file
	// *********************************************
	void WriteToFile(const std::string& path, const std::string& plaintext);

	// *********************************************
	// Clear file before writing to it
	// *********************************************
	void ClearFile();

	// *********************************************
	// Transform hex encoded string into dec
	// *********************************************
	std::vector<int> HexStringToDec(const std::string& hex_ciphertext);

	// *********************************************
	// Make all strings equal size for decription
	// *********************************************
	void MakeEqualSize(std::vector<std::string>& target);

	// *********************************************
	// Main class for performing brute force ttp attack
	// *********************************************
	class BruteForce
	{
	public:
		BruteForce();
		void SetCiphertexts(std::vector<std::string> ciphertexts);
		std::vector<int> CrackKey();

	private:		
		std::vector<int> symbols_to_compare_;
		std::vector<int> guess_; // vector with letters for guessing (int representation)
		

		std::vector<std::vector<int>> dec_ciphertexts_;

		// Makes all texts equal length with target text (last element)
		void ChangeTextLength(std::vector<std::string>& ciphertexts);
		void FillFreqTable(std::vector<std::vector<int>>& freq_table);
	};
}

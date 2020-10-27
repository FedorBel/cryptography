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
	// Last string in vector must be target text
	std::vector<std::string> ReadFromFile(const std::string& path);
	void WriteToFile(const std::vector<int>& plaintext);
	void ClearFile();
	std::vector<int> HexStringToInt(std::string hex_ciphertext);
	void MakeEqualSize(std::vector<std::string>& target);

	class BruteForce
	{
	public:
		BruteForce();
		void SetCiphertexts(std::vector<std::string> ciphertexts);
		std::string Decode();

	private:
		const std::string symbols_to_compare_ = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		std::vector<int> int_symbols_;
		std::vector<int> guess_; // vector with letters for guessing (int representation)

		std::vector<std::string> ciphertexts_;

		// Makes all texts equal length with target text (last element)
		void ChangeTextLength();
	};
}

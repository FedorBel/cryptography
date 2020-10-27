#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <cmath>
#include <vector>
#include <fstream>

namespace ttp_decoder
{
	class BruteForce
	{
	public:
		BruteForce()
		{
			size_t size = symbols_to_compare.size();
			int_symbols.resize(size);
			for (size_t i = 0; i < size; i++)
			{
				int_symbols[i] = (int)symbols_to_compare[i];
			}
		}
	private:
		const std::string symbols_to_compare = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		std::vector<int> int_symbols;
	};

	std::vector<std::string> ReadFromFile(const std::string& path);
	void WriteToFile(const std::vector<int>& plaintext);
	void ClearFile();
	std::vector<int> HexStringToInt(std::string hex_ciphertext);
	void MakeEqualSize(std::vector<std::string>& target);
}

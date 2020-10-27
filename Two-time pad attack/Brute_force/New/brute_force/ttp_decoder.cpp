#include "ttp_decoder.h"

using namespace std;

namespace ttp_decoder
{
	std::vector<std::string> ReadFromFile(const std::string& path)
	{
		vector<string> ciphertexts;
		ifstream fin;
		fin.open(path);
		if (fin.is_open())
		{
			for (string line; getline(fin, line);)
			{
				if (line != "Target" && line.substr(0, 4) != "Text")
				{
					ciphertexts.push_back(move(line));
				}
			}
		}
		else
		{
			cout << "Error openning file " << path << endl;
		}
		fin.close();
		return ciphertexts;
	}

	void WriteToFile(const std::vector<int>& plaintext)
	{

	}

	void ClearFile()
	{
		string path = "text.txt";
		ofstream fout;
		fout.open(path);
		if (!fout.is_open())
		{
			cout << "Error!" << endl;
		}
		fout.close();
	}

	std::vector<int> HexStringToInt(std::string hex_ciphertext)
	{
		return {};
	}

	void MakeEqualSize(std::vector<std::string>& target)
	{

	}

	BruteForce::BruteForce() : guess_(256)
	{
		size_t size = symbols_to_compare_.size();
		int_symbols_.resize(size);
		for (size_t i = 0; i < size; i++)
		{
			int_symbols_[i] = (int)symbols_to_compare_[i];
		}
		iota(guess_.begin(), guess_.end(), 0);
	}
	void BruteForce::SetCiphertexts(std::vector<std::string> ciphertexts)
	{
		ciphertexts_ = move(ciphertexts);
	}

	std::string BruteForce::Decode()
	{
		// Ciphertexts must be equal length with target text
		ChangeTextLength();
		HexStringToInt("hello");
		return {};
	}

	void BruteForce::ChangeTextLength()
	{
		size_t new_size = ciphertexts_.back().size();
		for (int i = 0; i < ciphertexts_.size() - 1; i++)
		{
			ciphertexts_[i].resize(new_size);
		}
	}
}
#include "ttp_decoder.h"

using namespace std;

namespace ttp_decoder
{
	std::string Decode(std::vector<int> ciphertext, std::vector<int> key)
	{
		string plaintext;
		plaintext.resize(ciphertext.size());

		for (int i = 0; i < ciphertext.size(); i++)
		{
			int xor_res = (ciphertext[i] ^ key[i]);
			plaintext[i] = (char)xor_res;
		}
		cout << "Decoding finished.\n";
		return plaintext;
	}

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

	void WriteToFile(const std::string& path, const std::string& plaintext)
	{
		fstream fs;
		fs.open(path, fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Error openning file: " << path << " !!!" << endl;
		}
		else
		{
			fs << "Target plaintext: \n";
			for (int i = 0; i < plaintext.size(); i++)
			{
				fs << plaintext[i];
			}

		}
		fs.close();

		cout << "Writing complete!" << "\n";
		cout << "Message saved at: " << path << endl;
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

	std::vector<int> HexStringToDec(const std::string& hex_ciphertext)
	{
		std::vector<int> dec_ciphertext;
		
		string str = "0x12";
		int size = hex_ciphertext.size();
		for (int i = 0; i < size - 1; i += 2)
		{
			str[2] = hex_ciphertext[i];
			str[3] = hex_ciphertext[i + 1];
			int tmp = stoi(str, 0, 16);
			dec_ciphertext.push_back(tmp);
		}
		return dec_ciphertext;
	}

	void MakeEqualSize(std::vector<std::string>& target)
	{

	}

	BruteForce::BruteForce() : guess_(256)
	{
		const std::string tmp_symbols_to_compare_ = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		size_t size = tmp_symbols_to_compare_.size();
		symbols_to_compare_.resize(size);
		for (size_t i = 0; i < size; i++)
		{
			symbols_to_compare_[i] = (int)tmp_symbols_to_compare_[i];
		}
		iota(guess_.begin(), guess_.end(), 0);		
	}

	void BruteForce::SetCiphertexts(std::vector<std::string> ciphertexts)
	{
		size_t size = ciphertexts.size();
		dec_ciphertexts_.resize(size);

		// Ciphertexts must be equal length with target text
		ChangeTextLength(ciphertexts);
		for (size_t i = 0; i < size; i++)
		{
			dec_ciphertexts_[i] = HexStringToDec(ciphertexts[i]);
		}
	}

	vector<int> BruteForce::CrackKey()
	{
		const int letters_size = 256; // each char is represented by hex 00-ff
		const int ciphertext_size = dec_ciphertexts_.back().size();

		vector<int> key(ciphertext_size);

		vector<vector<int>> freq_table(letters_size, vector<int>(ciphertext_size));
		FillFreqTable(freq_table);

		// The byte-key with the highest score wins for that column. Repeat for each column.
		int index = 0;
		for (int j = 0; j < freq_table[0].size(); j++)
		{
			int max = 0;
			for (int i = 0; i < freq_table.size(); i++)
			{
				if (max < freq_table[i][j])
				{
					max = freq_table[i][j];
					index = i;
				}
			}
			key[j] = index;
		}

		return key;
	}

	void BruteForce::ChangeTextLength(std::vector<std::string>& ciphertexts)
	{
		size_t new_size = ciphertexts.back().size();
		for (int i = 0; i < ciphertexts.size() - 1; i++)
		{
			ciphertexts[i].resize(new_size);
		}
	}

	void BruteForce::FillFreqTable(vector<vector<int>>& freq_table)
	{
		int ct_size = dec_ciphertexts_.size();
		int ct_length = dec_ciphertexts_[0].size();
		vector<int> xOr_res(ct_size);

		for (int i = 0; i < ct_length; i++)
		{
			for (int j = 0; j < guess_.size(); j++)
			{
				for (int k = 0; k < ct_size; k++)
				{
					xOr_res[k] = (dec_ciphertexts_[k][i] ^ guess_[j]);

					for (int d = 0; d < symbols_to_compare_.size(); d++)
					{
						if (xOr_res[k] == symbols_to_compare_[d])
						{
							{
								freq_table[j][i]++;
							}
						}
					}
				}
			}
		}
	}
}
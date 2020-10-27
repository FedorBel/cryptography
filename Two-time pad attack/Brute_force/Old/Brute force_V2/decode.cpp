#include "decode.h"

void getInt(vector<string>& cts, vector<vector<int> >& cti)
{
	int tmp;
	string str = "0x12";
	int size = cts.size();
	int length = cts[10].length();
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < length - 1; i += 2)
		{
			str[2] = cts[k][i];
			str[3] = cts[k][i + 1];
			tmp = stoi(str, 0, 16);
			cti[k].push_back(tmp);
		}
	}
}

void getInt(string& find, vector<int>& find_int)
{
	int tmp;
	int length = find.length();

	for (int i = 0; i < length; i++)
	{
		tmp = (int)find[i];
		find_int.push_back(tmp);
	}
}

void equal(vector<string>& cts)
{
	for (int i = 0; i < cts.size() - 1; i++)
	{
		cts[i].resize(cts[10].size());
	}
}

void xOr(vector<vector<int>>& cti, vector<int>& key, vector<int>& target_text)
{

	int size = cti.size();
	int length = cti[10].size();
	int tmp;

	for (int i = 0; i < length; i++)
	{
		tmp = (cti[10][i] ^ key[i]);
		target_text.push_back(tmp);
	}
}

void xOr(vector<vector<int>>& cti, vector<int>& key_guess, vector<int>& find_int, vector<vector<int> >& num_f)
{
	int ct_size = cti.size();
	int ct_length = cti[10].size();
	int key_size = key_guess.size();
	int find_size = find_int.size();
	vector<int> xOr(ct_size);

	for (int i = 0; i < ct_length; i++)
	{
		for (int j = 0; j < key_size; j++)
		{
			for (int k = 0; k < ct_size; k++)
			{
				xOr[k] = (cti[k][i] ^ key_guess[j]);

				for (int d = 0; d < find_size; d++)
				{
					if (xOr[k] == find_int[d])
					{
						{
							num_f[j][i]++;
						}
					}
				}
			}
		}
	}
}

void file_write(vector<int>& target_text)
{
	string path = "text.txt";

	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);

	if (!fs.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{
		fs << "Text: " << endl;
		for (int i = 0; i < target_text.size(); i++)
		{
			fs << (char)target_text[i];
		}

	}
	fs.close();

	cout << "Writing complete!" << endl;
	cout << "Message saved at text.txt" << endl;
}

void clear_file()
{
	string path = "text.txt";
	ofstream fout;

	fout.open(path);

	if (!fout.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{

	}

	fout.close();
}

void max_f(vector<vector<int>>& num_f, vector<int>& key)
{
	int index = 0;
	for (int j = 0; j < num_f[j].size(); j++)
	{
		int max = 0;
		for (int i = 0; i < num_f.size(); i++)
		{
			if (max < num_f[i][j])
			{
				max = num_f[i][j];
				index = i;
			}
		}
		key[j] = index;
	}
}
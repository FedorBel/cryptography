#include "ttp_decoder.h"

using namespace std;

namespace ttp_decoder
{
	std::vector<std::string> ReadFromFile(const std::string& path)
	{
		vector<string> ciphertext;
		ifstream fin;
		fin.open(path);
		if (fin.is_open())
		{
			for (string line; getline(fin, line);)
			{
				cout << line;
			}
		}
		else
		{
			cout << "Error openning file " << path << endl;
		}
		fin.close();
		return {};
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
		else
		{

		}

		fout.close();
	}
}
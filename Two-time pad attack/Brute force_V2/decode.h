#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

void getInt(vector<string>& cts, vector<vector<int> >& cti);
void getInt(string& find, vector<int>& find_int);
void equal(vector<string>& cts);
void xOr(vector<vector<int>>& cti, vector<int>& key, vector<int>& target_text);
void xOr(vector<vector<int> >& cti, vector<int>& key_guess, vector<int>& find_int, vector<vector<int> >& num_f);
void file_write(vector<int>& target_text);
void clear_file();
void max_f(vector<vector<int> >& num_f, vector<int>& key);

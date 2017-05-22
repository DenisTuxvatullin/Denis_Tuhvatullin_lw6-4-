#pragma once
#include <map>
#include <vector>
#include <string>
using namespace std;

class MyDictionary
{
public:
	void FillDictionary(const vector<string> &words, ofstream &f);
	void WriteD();
	bool StringPocessing(string &str, ofstream &f);
	void Add(ofstream &f, string &val, const string &s);
	void Start();
private:
	map<string, int> myDictionary;
	int size;
	string filename;
	
};


#include "stdafx.h"
#include <map>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <thread>
#include "MDictionary.h"
using namespace std;
static const string D_FILENAME = "dictionary.txt";

bool MyDictionary::StringPocessing(string &str, ofstream &f)
{
	int j;
	while ((j = str.find('\t')) != std::string::npos)
		str.erase(j, 1);
	j = 0;
	string newStr;
	while (j < str.length())
	{
		if (ispunct(str[j]))
		{
			if (str.length() == 1)
			{
				f << str[j] << " ";
				return false;
			}
			newStr = str.substr(0, j);
			Add(f, newStr, "");
			f << str[j];
			str.erase(0, j + 1);
			j = -1;
		}
		j++;
	}
	return true;
}

void MyDictionary::WriteD()
{
	ofstream f(D_FILENAME);
	for (auto& val : myDictionary)
	{
		f << val.first << " : " << val.second << endl;
	}
}

/*
void MyDictionary::Start()
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Input error";
		throw;
	}
	ofstream f(OUTPUT_FILENAME);
	vector<string> words, words2;
	string str, str2;
	while (getline(fin, str))
	{
		boost::split(words, str, boost::is_any_of(" "));
		FillDictionary(words, f);
	}
	WriteD();
}
*/

void MyDictionary::FillDictionary(const vector<string> &words, ofstream &f)
{
	string v;
	for (auto& val : words)
	{
		v = val;
		if (StringPocessing(v, f))
		{
			if (v == "")
			{
				continue;
			}
			Add(f, v, " ");
		}			
	}
	f << endl;
}

void MyDictionary::Add(ofstream &f, string &v, const string &s)
{
	size = myDictionary.size();
	if (v != "")
	{
		if (!myDictionary.count(v) > 0)
		{
			size++;
			myDictionary.insert(pair<string, int>(v, size));
		}
		else
		{
			size = myDictionary.find(v)->second;
		}
		f << size << s;
	}
}
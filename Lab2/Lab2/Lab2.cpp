// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MDictionary.h"
#include <string>
static const string OUTPUT_FILENAME = "output.txt";

void ThreadFunction(MyDictionary &D, vector<string> &w, ofstream &f)
{
	D.FillDictionary(w, f);
}

void Start(const string &filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Input error";
		throw;
	}
	MyDictionary D;
	ofstream f(OUTPUT_FILENAME);
	vector<string> words;
	string str;
	while (getline(fin, str))
	{
		boost::split(words, str, boost::is_any_of(" "));
		//thread t1(ThreadFunction, ref(D), ref(words), ref(f));
		//t1.join();
		D.FillDictionary(words, f);
	}
	D.WriteD();
}

int main(int argc, char* argv[])
{
	string filename;
	clock_t time;
	time = clock();
	try
	{
		if (argc != 2)
		{
			filename = "file.txt";
			cout << "Default text:" << filename << endl;
		}
		else 
		{
			filename = argv[1];
		}
		Start(filename);
	}
	catch (...)
	{
		cout << "Error!";
	}
	time = clock() - time;
	printf("%f", (double)time / CLOCKS_PER_SEC);
	cout << endl;
	cin >> filename;
	return 0;
}


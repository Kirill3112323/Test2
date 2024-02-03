#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include <cassert>
using namespace std;

class Stroki
{
private:
	string file;
	string str;
	vector<string>line;
public:
	Stroki(string _file)
	{
		this->file = _file;
	}

	void Load()
	{
		fstream f(this->file, ios::in);
		if (!f)
		{
			cout << "Файл не открылся для чтения !!!" << endl;
			exit(1);
		}
	
		while (getline(f, str))
		{
			line.push_back(str);
		}
		f.close();		
	}
	void Print()
	{
		for (int i = 0; i < line.size(); i++)
		{
			cout << "Строка №" << i << " : " << line[i] << endl;
		}
	}

	void ReversePrint()
	{
		for (int i = line.size()-1; i >= 0; i--)
		{
			cout << line[i] << endl;
		}
	}

	void Search()
	{
		for (int i = 0; i < line.size(); i++)
		{
			int n = line[i].find("this");
			if (line[i].find("#include<stdlib.h>")>0)
			{
				cout << "Номер строки: " << i << endl;
			}
			assert(line[i].find("this"));
		}   
	}

	void Replaces()
	{

	}
};

int main1()
{
	setlocale(LC_ALL, "RUS");

	Stroki s("test.txt");
	s.Load();
	s.ReversePrint();
	s.Search();
	return 0;
}
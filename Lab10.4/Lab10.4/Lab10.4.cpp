#include <iomanip>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
void printfile(string filename);
string getbiggestword(string str);
string getstrtowrite(string filename);
void task(string filename);
void input(string filename);
void main()
{
	srand(time(NULL));
	string filename;
	cout << "Enter filename: "; cin >> filename;
	cout << "Press 1 to enter some text int the file,any else key to continue:";
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		input(filename);
		break;
	}
	default:
	{
		printfile(filename);
		task(filename);
		break;
	}
	}

	system("pause");
}
void printfile(string filename)
{
	ifstream fin;
	fin.open(filename);
	cout << "===============" << filename << "===============" << endl << endl;
	string str;
	while (getline(fin, str))
	{
		cout << str << endl;
	}
	cout << endl << "======================================" << endl << endl;
	fin.close();
}
void task(string filename)
{
	string strtowrite = getstrtowrite(filename);
	ifstream fin;
	fin.open(filename);
	filename.insert(filename.end() - 4, '2');
	ofstream fout;
	fout.open(filename);
	string str;
	while (getline(fin, str))
	{
		fout << str + strtowrite << endl;
	}
	fin.close();
	fout.close();
	cout << "Done.\nResult:" << endl;
	printfile(filename);
}
void input(string filename)
{
	char ch;
	string s;
	ofstream fout;
	fout.open(filename);
	cin.sync();
	do
	{
		cin.ignore();
		cin.sync();
		cout << "enter line: ";
		cin.sync();
		getline(cin, s);
		fout << s << endl;
		cout << "continue? (y/n): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
	fout.close();

}
string getstrtowrite(string filename)
{
	ifstream fin;
	fin.open(filename);
	string str;
	int i = 0;
	string strtowrite = "";
	while (getline(fin, str))
	{
		if (i % 2 != 0)
			strtowrite += (getbiggestword(str) + " ");
		i++;
	}
	fin.close();
	return strtowrite;
}

string getbiggestword(string str)
{
	int prevsize, size;
	string word;
	string longestword = "";
	int maxhol = 0;
	string holosni = "eyuioaіаоуеи";
	int j = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		j = str.find(" ", i);
		if (j != -1)
		{
			word = str.substr(i, j - i);
			int wordhol = 0;
			for (size_t k = 0; k < word.size(); k++)
			{
				if (word[k] == 'i' ||
					word[k] == 'u' ||
					word[k] == 'o' ||
					word[k] == 'e' ||
					word[k] == 'a')
					wordhol++;
			}
			if (wordhol > maxhol)
			{
				longestword = word;
				maxhol = wordhol;
			}
			cout << word << endl;
			i = j;
		}
		else
		{
			word = str.substr(i, str.size() - i);
			int wordhol = 0;
			for (size_t k = 0; k < word.size(); k++)
			{
				if (word[k] == 'i' ||
					word[k] == 'u' ||
					word[k] == 'o' ||
					word[k] == 'e' ||
					word[k] == 'a')
					wordhol++;
			}
			if (wordhol > maxhol)
			{
				longestword = word;
				maxhol = wordhol;
			}
			cout << word << endl;
			break;
		}

	}
	//cout << longestword << endl;
	return longestword;
}
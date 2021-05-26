#include <iomanip>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
void createtext(string filename)
{
	// при написанні назви файлу використовуйте в кінці .тхт
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
void printttext(string filename)
{
	ifstream fin;
	fin.open(filename);
	string str;
	while (getline(fin, str))
	{
		cout << str << endl;
	}
	cout << endl << "Readind ended." << endl;
}

void find(string filename)
{

	ifstream fin(filename);
	string str;
	int counter = 0;
	while (getline(fin, str))
	{
		cout << str << endl;
		for (size_t i = 0; i < str.size() - 1; i++)
		{
			if (str[i] == ',' && str[i + 1] == '-')
				counter++;
		}
	}
	cout << "Count of ',-':" << counter << endl;
}
void main()
{
	srand(time(NULL));
	string filename;
	cout << "Enter filename: ";
	cin.sync();
	getline(cin, filename);
	cout << "Menu\n1.Enter some text\n2.print text\n3.task" << endl;
	int ch; cin >> ch;
	switch (ch)
	{
	case 1:
	{
		createtext(filename);
		break;
	}
	case 2:
	{
		printttext(filename);
		break;
	}
	case 3:
	{
		find(filename);
		break;
	}
	default:
		break;
	}
	system("pause");
}

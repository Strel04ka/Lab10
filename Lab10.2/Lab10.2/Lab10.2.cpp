#include <iomanip>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void createtext(string filename)
{
	//if ((filename.size() <=4) && filename.substr(filename.size() - 4,filename.size()-1) != ".txt")
	//{
	//  cout << "Error! You must enter the valid filename with \".txt\" in the end of the name!" << endl;
	//  return;
	//}
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
	fin.close();
}
void task(string filename, string str)
{
	ifstream fin;
	fin.open(filename);

	filename.insert((filename.size() - 4), "2");
	ofstream fout;
	fout.open(filename);


	str.erase(0, str.find_first_not_of(" "));
	cout << "|" << str << "|" << endl;

	int tmp = str.find_last_not_of(" ");
	str.erase(tmp + 1, str.size() - tmp);
	cout << "|" << str << "|" << endl;
	int iter = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if ((iter = str.find(' ', iter)) != -1 && (iter = str.find(' ', iter)) < str.size() - 1)
		{
			str.erase(str.begin() + iter, str.begin() + str.find_first_not_of(' ', iter));
			str.insert(str.begin() + iter, ' ');
			i = ++iter;
		}
		else break;
	}
	cout << str << endl;
	fin.close();
	fout.close();
	cout << "Done.Changed text has beem written in " << filename << endl;
	cout << endl << endl;
	ifstream fin2;
	fin2.open(filename);
	cout << "Resulting file: " << endl;
	string str2;
	while (getline(fin2, str2))
	{
		cout << str2 << endl;
	}
	cout << "Done" << endl;
}

void main()
{
	string str = "     test   test1    test2         test3     ";
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
		//printttext(filename);
		task(filename, str);
		break;
	}
	default:
		break;
	}
	system("pause");
}

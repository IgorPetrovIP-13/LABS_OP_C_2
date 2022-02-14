#include "Header.h"

void write_file(string path)
{
	ofstream fout;
	fout.open(path);
	if (fout.is_open())
	{
		string line;
		cout << "Enter your strings. To finish entering go to a new line and press <Ctrl + S>.\n";
		getline(cin, line);
		while (line[0] != 19)
		{
			fout << line << '\n';
			getline(cin, line);
		}
		fout.close();
	}
	else
	{
		cout << "Fatal error!";
	}
}

void read_file(string path) {
	
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		cout << "\nReading file " << path << " :\n";
		while (!fin.eof()) {
			string line;
			getline(fin, line);
			cout << line << '\n';
		}
		fin.close();
	}
	else
	{
		cout << "Fatal error!";
	}
}

vector<string> split(string line, char sep = ' ') {
	vector<string> res;
	string slice = "";
	line += sep;
	for (int i = 0; i < int(line.length()); i++) {
		if (line[i] == sep) {
			if (slice.length() > 0) res.push_back(slice);
			slice = "";
		}
		else slice += line[i];
	}
	return res;
}

void format_file(string first_path, string second_path, int number) {
	ofstream fout;
	ifstream fin;
	vector<string> words;
	vector<string>perfect;
	fin.open(first_path);
	fout.open(second_path);
	if (fin.is_open()) {
		while (!fin.eof()) {
			string line;
			getline(fin, line);
			vector<string>tmp = split(line);
			words.insert(words.end(), tmp.begin(), tmp.end());
		}
		for (int i = 0; i < words.size(); i++)
		{
			if (count(words.begin(), words.end(), words[i]) < number) {
				perfect.push_back(words[i]);
			}
		}
		sort(perfect.begin(), perfect.end(),
			[](const string& a, const string& b)
			{ return a.length() > b.length(); });
		for (int i = 0; i < perfect.size(); i++)
		{
			fout << perfect[i] << ' ';
		}
		fin.close();
		fout.close();
	}
	else
	{
		cout << "Fatal error!";
	}
}
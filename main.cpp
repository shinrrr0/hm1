#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

bool isEmpty(string filename) {
	bool res;
	ifstream file;
	file.open(filename);
	res = file.peek() == ifstream::traits_type::eof();
	file.close();
	return res;
}

void readFromFiles() {
	system("cls");
	if (isEmpty("Cost.txt") || isEmpty("Names.txt") || isEmpty("Quantity.txt")) {
		cout << "�� ��� ����� ���������\n";
		return;
	}

	vector<string> names;
	vector<string> costs;
	vector<string> quantities{};
	ifstream file;
	string line;

	int length = 0;
	int min_length = 100;
	file.open("Names.txt");
	while (getline(file, line)) {
		names.push_back(line);
		++length;
	}
	file.close();
	if (length < min_length) {
		min_length = length;
	}
	length = 0;

	file.open("Cost.txt");
	while (getline(file, line)) {
		costs.push_back(line);
		++length;
	}
	file.close();
	if (length < min_length) {
		min_length = length;
	}
	length = 0;

	file.open("Quantity.txt");
	while (getline(file, line)) {
		quantities.push_back(line);
		++length;
	}
	file.close();
	if (length < min_length) {
		min_length = length;
	}

	cout << "\t\t��������\t����\t\t����������\n";
	for (int i = 0; i < min_length; ++i) {
		cout << i + 1 << ")\t\t" << names[i] << "\t\t" << costs[i] << "\t\t" << quantities[i] << '\n';
	}
}


void writeToFile(string filename) {
	fstream file;

	if (!isEmpty("Cost.txt") && !isEmpty("Names.txt") && !isEmpty("Quantity.txt")) {
		string choice;
		while (true) {
			cout << "� ������ �� ������ ��� ���� ����������." << "\n";
			cout << "�� ������ ���������� ������ � ���� ��� ������ ������� ���������� ���� ������? �/� (����������/�������)\n";
			getline(cin, choice);
			if (choice == "�") {
				system("cls");
				file.open(filename, ios::app);
				break;
			}
			else if (choice == "�") {
				system("cls");
				readFromFiles();
				return;
			}
			else {
				system("cls");
				cout << "��� ������ �������� ������, ������� ��� ���" << "\n";
				continue;
			}
		}
	}
	else {
		system("cls");
		file.open(filename, ios::app);
	}
	cout << "������ ������, ��� ������� ����� ����� �������� � ���� " << filename << ". ����� ���������� ������, ������� ������ �������" << endl;

	string line = "0";
	while (true) {
		getline(cin, line);
		if (line.compare("") == 0) {
			break;
		}
		file << line << endl;
	}
	file.close();
	system("cls");
	return;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string line;
	string choice;
	while (true) {
		cout << "��� �� ������ �������? �/� (��������/�������)\n";
		getline(cin, choice);
		if (choice == "�") {
			system("cls");
			while (true) {
				cout << "� ����� ���� �� ������ ������� ������? �/�/� (��������/����������/����)\n";
				getline(cin, choice);
				if (choice == "�") {
					system("cls");
					writeToFile("Names.txt");
					break;
				}
				else if (choice == "�") {
					system("cls");
					writeToFile("Quantity.txt");
					break;
				}
				else if (choice == "�") {
					system("cls");
					writeToFile("Cost.txt");
					break;
				}
				else {
					system("cls");
					cout << "��� ������ �������� ������, ������� ��� ���" << "\n";
					continue;
				}
			}
		}
		else if (choice == "�") {
			readFromFiles();
		}
		else {
			system("cls");
			cout << "��� ������ �������� ������, ������� ��� ���" << "\n";
			continue;
		}
	}
	return 0;
}
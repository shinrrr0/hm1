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
		cout << "Не все файлы заполнены\n";
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

	cout << "\t\tНазвание\tЦена\t\tКоличество\n";
	for (int i = 0; i < min_length; ++i) {
		cout << i + 1 << ")\t\t" << names[i] << "\t\t" << costs[i] << "\t\t" << quantities[i] << '\n';
	}
}


void writeToFile(string filename) {
	fstream file;

	if (!isEmpty("Cost.txt") && !isEmpty("Names.txt") && !isEmpty("Quantity.txt")) {
		string choice;
		while (true) {
			cout << "В каждом из файлов уже есть содержимое." << "\n";
			cout << "Вы хотите продолжить запись в файл или готовы вывести содержимое всех файлов? д/в (дозаписать/вывести)\n";
			getline(cin, choice);
			if (choice == "д") {
				system("cls");
				file.open(filename, ios::app);
				break;
			}
			else if (choice == "в") {
				system("cls");
				readFromFiles();
				return;
			}
			else {
				system("cls");
				cout << "Нет такого варианта ответа, введите ещё раз" << "\n";
				continue;
			}
		}
	}
	else {
		system("cls");
		file.open(filename, ios::app);
	}
	cout << "Каждая строка, что введете далее будет записана в файл " << filename << ". Чтобы прекратить запись, введите пустую строчку" << endl;

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
		cout << "Что вы хотите сделать? з/в (записать/вывести)\n";
		getline(cin, choice);
		if (choice == "з") {
			system("cls");
			while (true) {
				cout << "В какой файл вы хотите сделать запись? н/к/ц (название/количество/цена)\n";
				getline(cin, choice);
				if (choice == "н") {
					system("cls");
					writeToFile("Names.txt");
					break;
				}
				else if (choice == "к") {
					system("cls");
					writeToFile("Quantity.txt");
					break;
				}
				else if (choice == "ц") {
					system("cls");
					writeToFile("Cost.txt");
					break;
				}
				else {
					system("cls");
					cout << "Нет такого варианта ответа, введите ещё раз" << "\n";
					continue;
				}
			}
		}
		else if (choice == "в") {
			readFromFiles();
		}
		else {
			system("cls");
			cout << "Нет такого варианта ответа, введите ещё раз" << "\n";
			continue;
		}
	}
	return 0;
}
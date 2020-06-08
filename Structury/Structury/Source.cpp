#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

struct Bus  {
	int busnum;
	string shofer_secondname;
	string shofer_othername;
	int pathnum;
	float timedur;
};

int CountBus();
void FillBus(Bus* BS, int n);
void FindOclod(Bus* BS, int n);
void Find_Timedur(Bus* BS, int n);

void Find_Timedur(Bus* BS, int n)  {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (strcmp(BS[i].shofer_secondname.c_str(), BS[j].shofer_secondname.c_str()) < 0)
				swap(BS[i], BS[j]);
	cout << endl << endl << "Список маршрутов продолжительностью менее 2 часов: ";
	for (int i = 0; i < n; i++)
		if (BS[i].timedur < 120)
			cout << endl << BS[i].busnum << " " << BS[i].shofer_secondname + " " + BS[i].shofer_othername << " " << BS[i].pathnum << " " << BS[i].timedur;
}

void FindOclod(Bus* BS, int n)  {
	cout << endl << endl << "Маршруты не Сидоровых: ";
	for (int i = 0; i < n; i++)
		if (BS[i].shofer_secondname != "Sidorov")
			cout << endl << BS[i].busnum << " " << BS[i].shofer_secondname + " " + BS[i].shofer_othername << " "
			<< BS[i].pathnum << " " << BS[i].timedur;
}

int CountBus()  {
	string str;
	int n = 0;
	ifstream file;
	file.open("input.txt");

	while (!file.eof())	{
		getline(file, str);
		getline(file, str);
		getline(file, str);
		getline(file, str);
		getline(file, str);
		n++;
	}

	file.close();
	return n;
}

void FillBus(Bus* BS, int n)  {
	int k = 0;
	Bus temp;
	ifstream file;
	file.open("input.txt");

	while (!file.eof())	{
		file >> temp.busnum;
		file >> temp.shofer_secondname;
		file >> temp.shofer_othername;
		file >> temp.pathnum;
		file >> temp.timedur;
		BS[k] = temp;
		k++;
	}

	file.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	n = CountBus();
	Bus* BS = new Bus[n];
	FillBus(BS, n);
	cout << "Все автобусы: ";
	for (int i = 0; i < n; i++)
		cout << endl << BS[i].busnum << " " << BS[i].shofer_secondname + " " + BS[i].shofer_othername << " " << BS[i].pathnum << " " << BS[i].timedur;
	FindOclod(BS, n);
	Find_Timedur(BS, n);
	return 0;
}
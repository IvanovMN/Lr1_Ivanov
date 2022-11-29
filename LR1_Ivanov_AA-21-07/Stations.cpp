#include "Stations.h"
#include "utils.h"
using namespace std;

int Stations::max_cs_id = 0;
Stations::Stations()
{
	max_cs_id++;
	cs_id = max_cs_id;
}
ostream& operator << (ostream& out,  Stations& y)
{
	system("cls");
	out
		<< "id: " << y.cs_id << endl
		<< "название: " << y.name_CS << endl
		<< "число цехов: " << y.workshop << endl
		<< "число рабочих цехов: " << y.active_workshop << endl;
		//<< "эффективность: " << y.effiency << endl
	cout << "Показатель эффективности рабочих цехов: " << " " << y.effiency << "%" << endl;
	 cout << "Процент незадействованных цехов: " << " " << y.k << "%" << endl << endl;
	system("pause");
	return out;

};
istream& operator >> (istream& in, Stations& y)
{
	system("cls");
	cout << "название компрессорной станции ";
	cin >> ws;
	getline(cin, y.name_CS);
	cout << "число цехов:  ";
	y.workshop = GetCorrectNumber(1.0, 20000.0);
	while (true) {
		cout << "число рабочих цехов компрессорной станции :" << endl;
		cin >> y.active_workshop;
		if (cin.good() == true) {
			if (y.active_workshop < 0) {
				cout << "Ошибка ввода!" << endl;
				cin.clear(); cin.ignore(1000, '\n');
			}
			else if (y.active_workshop > y.workshop) {
				cout << "Ошибка ввода!" << endl;
				cin.clear(); cin.ignore(1000, '\n');
			}
			else if (int(y.active_workshop) != y.active_workshop) {
				cout << "Ошибка ввода!" << endl;
				cin.clear(); cin.ignore(1000, '\n');
			}
			else {
				//cout << "Количество рабочих цехов:" << " " << y.active_workshop << endl;
				break;
			}
		}
		else {
			cout << "Ошибка ввода!" << endl;
			cin.clear(); cin.ignore(1000, '\n');
		}
	}
	//cout << "эффективность  ";
	//y.effiency = GetCorrectNumber(0.0, 100.0);
	 y.effiency = (y.active_workshop*100 / y.workshop) ;
	cout << "Показатель эффективности: " << " " << y.effiency << "%" << endl;
	//процент незайдествованных цехов
	y.k = 100 - y.effiency;
	cout << "Процент незадействованных цехов: " << " " << y.k << "%" << endl;
	system("pause");
	return in;

}


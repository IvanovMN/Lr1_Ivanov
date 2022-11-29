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
		<< "��������: " << y.name_CS << endl
		<< "����� �����: " << y.workshop << endl
		<< "����� ������� �����: " << y.active_workshop << endl;
		//<< "�������������: " << y.effiency << endl
	cout << "���������� ������������� ������� �����: " << " " << y.effiency << "%" << endl;
	 cout << "������� ����������������� �����: " << " " << y.k << "%" << endl << endl;
	system("pause");
	return out;

};
istream& operator >> (istream& in, Stations& y)
{
	system("cls");
	cout << "�������� ������������� ������� ";
	cin >> ws;
	getline(cin, y.name_CS);
	cout << "����� �����:  ";
	y.workshop = GetCorrectNumber(1.0, 20000.0);
	while (true) {
		cout << "����� ������� ����� ������������� ������� :" << endl;
		cin >> y.active_workshop;
		if (cin.good() == true) {
			if (y.active_workshop < 0) {
				cout << "������ �����!" << endl;
				cin.clear(); cin.ignore(1000, '\n');
			}
			else if (y.active_workshop > y.workshop) {
				cout << "������ �����!" << endl;
				cin.clear(); cin.ignore(1000, '\n');
			}
			else if (int(y.active_workshop) != y.active_workshop) {
				cout << "������ �����!" << endl;
				cin.clear(); cin.ignore(1000, '\n');
			}
			else {
				//cout << "���������� ������� �����:" << " " << y.active_workshop << endl;
				break;
			}
		}
		else {
			cout << "������ �����!" << endl;
			cin.clear(); cin.ignore(1000, '\n');
		}
	}
	//cout << "�������������  ";
	//y.effiency = GetCorrectNumber(0.0, 100.0);
	 y.effiency = (y.active_workshop*100 / y.workshop) ;
	cout << "���������� �������������: " << " " << y.effiency << "%" << endl;
	//������� ����������������� �����
	y.k = 100 - y.effiency;
	cout << "������� ����������������� �����: " << " " << y.k << "%" << endl;
	system("pause");
	return in;

}


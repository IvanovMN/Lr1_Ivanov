#include "Stations.h"
#include "utils.h"
using namespace std;

ostream& operator << (ostream& out, const Stations& y)
{
	system("cls");
	out
		<< "id: " << y.id2 << endl
		<< "��������: " << y.name_CS << endl
		<< "����� �����: " << y.workshop << endl
		<< "����� ������� �����: " << y.active_workshop << endl
		<< "�������������: " << y.effiency << endl;
	system("pause");
	return out;

};
istream& operator >> (istream& in, Stations& y)
{
	system("cls");
	cout << "�������� ������������� ������� ";
	cin >> ws;
	getline(cin, y.name_CS);

	cout << "����� �����  ";
	y.workshop = GetCorrectNumber(1.0, 20000.0);;
	cout << "����� ������� �����  ";
	y.active_workshop = GetCorrectNumber(1, y.workshop);
	cout << "�������������  ";
	y.effiency = GetCorrectNumber(0.0, 100.0);
	return in;

}


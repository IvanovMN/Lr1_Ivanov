#include "Pipe.h"
#include "utils.h"
using namespace std;


ostream& operator << (ostream& out, const Pipe& t)
{
	system("cls");
	out
		<< "id: " << t.id1 << endl
		<< "��������: " << t.name << endl
		<< "�������: " << t.diametr << endl
		<< "�����: " << t.length << endl
		<< "��������� �����: " << t.repair << endl;
	system("pause");
	return out;
};
istream& operator >> (istream& in, Pipe& t)
{
	system("cls");
	cout << "�������� ����� ";
	cin >> ws;
	getline(cin, t.name);
	cout << "������� ";
	t.diametr = GetCorrectNumber(0.1, 20000.0);
	cout << "����� ";
	t.length = GetCorrectNumber(0.1, 20000.0);;
	cout << "������� ��������� ";
	t.repair = GetCorrectNumber(0, 1);;
	return in;

}

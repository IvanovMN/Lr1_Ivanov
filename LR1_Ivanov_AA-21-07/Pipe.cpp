#include "Pipe.h"
#include "utils.h"
using namespace std;


ostream& operator << (ostream& out, const Pipe& t)
{
	system("cls");
	out
		<< "id: " << t.id1 << endl
		<< "название: " << t.name << endl
		<< "Диаметр: " << t.diametr << endl
		<< "Длина: " << t.length << endl
		<< "Состояние трубы: " << t.repair << endl;
	system("pause");
	return out;
};
istream& operator >> (istream& in, Pipe& t)
{
	system("cls");
	cout << "название трубы ";
	cin >> ws;
	getline(cin, t.name);
	cout << "диаметр ";
	t.diametr = GetCorrectNumber(0.1, 20000.0);
	cout << "длина ";
	t.length = GetCorrectNumber(0.1, 20000.0);;
	cout << "текущее состояние ";
	t.repair = GetCorrectNumber(0, 1);;
	return in;

}

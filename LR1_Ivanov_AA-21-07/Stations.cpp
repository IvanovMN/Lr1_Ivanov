#include "Stations.h"
#include "utils.h"
using namespace std;

ostream& operator << (ostream& out, const Stations& y)
{
	system("cls");
	out
		<< "id: " << y.id2 << endl
		<< "название: " << y.name_CS << endl
		<< "число цехов: " << y.workshop << endl
		<< "число рабочих цехов: " << y.active_workshop << endl
		<< "эффективность: " << y.effiency << endl;
	system("pause");
	return out;

};
istream& operator >> (istream& in, Stations& y)
{
	system("cls");
	cout << "название компрессорной станции ";
	cin >> ws;
	getline(cin, y.name_CS);

	cout << "число цехов  ";
	y.workshop = GetCorrectNumber(1.0, 20000.0);;
	cout << "число рабочих цехов  ";
	y.active_workshop = GetCorrectNumber(1, y.workshop);
	cout << "эффективность  ";
	y.effiency = GetCorrectNumber(0.0, 100.0);
	return in;

}


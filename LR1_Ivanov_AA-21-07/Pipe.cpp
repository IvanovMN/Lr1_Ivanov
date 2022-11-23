#include "Pipe.h"
#include "utils.h"
#include <iostream>
using namespace std;

int Pipe::max_pipe_id = 1;
Pipe::Pipe()
{
	pipe_id = max_pipe_id++;
}
ostream& operator << (ostream& out, Pipe& t)
{
	system("cls");
	out
		<< "id: " << t.pipe_id << endl
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

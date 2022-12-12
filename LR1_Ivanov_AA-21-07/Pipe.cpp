#include "Pipe.h"
#include "utils.h"
#include <iostream>
using namespace std;


void Edit_pipe(Pipe&t)
{
	if (t.repair == 0)
		{
			t.repair = true;
		}
	else
		{
			t.repair = false;
		}
}

int Pipe::max_pipe_id=0;
Pipe::Pipe()
{
	max_pipe_id++;
	 pipe_id = max_pipe_id;
	
}

int Pipe::getId() const
{
	return pipe_id;
}

ostream& operator << (ostream& out, Pipe& t)
{
	system("cls");
	out
		<< "id: " << t.pipe_id << endl
		<< "��������: " << t.name << endl
		<< "�����: " << t.length << endl
		<< "�������: " << t.diametr << endl
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
	cout << "����� ";
	t.length = GetCorrectNumber(0.1, 20000.0);
	cout << "������� ";
	t.diametr= GetCorrectNumber(0.1, 20000.0);;
	cout << "������� ��������� ";
	t.repair = GetCorrectNumber(0, 1);
	return in;

}

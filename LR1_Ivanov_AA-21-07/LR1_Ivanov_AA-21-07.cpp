#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <fstream>
#include <locale.h> 
#include <locale> 
#include <map>
#include <set>


#include <vector>

#include <algorithm>
#include <iterator>
#include "Pipe.h"
#include "Stations.h"
#include "utils.h"
#include <stdio.h>
#include <cstdlib>
using namespace std;



template <typename T>
void Tryanswer(T& input) {
	while ((cin >> input).fail() || (input != 0 && input != 1)) {
		cout << "Ошибка ввода" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
}


void MainMenu()
{
	system("cls");
	cout
		<< "(1) Добавить новую трубу:" << endl
		<< "(2) Добавить новую КС:" << endl
		<< "(3) Просмотр всех объектов:" << endl
		<< "(4) Редактировать трубу:" << endl
		<< "(5) Редактировать КС: " << endl
		<< "(6) Сохранить:" << endl
		<< "(7) Загрузить:" << endl
		<< "(0) Выход:" << endl
		<< "(8) Find pipe by repair: " << endl
		<< "(9) Delete pipe by id (no work): " << endl
		<< "(10) Find CS by name: " << endl
		<< "(11) Find CS by inactive workshop" << endl
		<< "(12) Find pipe by name";
		
}

void  DeleteObjPipe(map <int, Pipe>&pipes)
{
	system("cls");
	if (pipes.size() != 0)
	{
		cout << "PLS enter ID pipe to delete: " << endl;
		int  input_info, id_checker = 0;
		cin >> input_info;
		for (auto& [id,Pipe] : pipes)
		{
			if (input_info == id)
			{
				id_checker++;
				pipes.erase(id);
				cout << "Element has been delete" << endl;
				break;
			}
		}

		if (id_checker == 0)
		{
			cout << "Element with this ID not found!!!" << endl;
		}
	}
	else
	{
		cout << "There no pipes to delete: " << endl;
	}

}
void  DeleteObjStation(map <int, Stations>& stations)
{

	system("cls");
	if (stations.size() != 0)
	{
		cout << "PLS enter ID pipe to delete: " << endl;
		int  input_info, id_checker = 0;
		cin >> input_info;
		for (auto& [id, Stations] : stations)
		{
			if (input_info == id)
			{
				id_checker++;
				stations.erase(id);
				cout << "Element has been delete" << endl;
				break;
			}
		}

		if (id_checker == 0)
		{
			cout << "Element with this ID not found!!!" << endl;
		}
	}
	else
	{
		cout << "There no stations to delete: " << endl;
	}
} 
 


vector<int> FindPipebyName(const vector <Pipe>& pGroup)
{
	system("cls");
	string CheckNamePipe;
	vector <int> res;
	unsigned long long int i = 0;
	cout << "pls write station name: ";
	cin >> ws;
	getline(cin, CheckNamePipe);

	for (auto& t : pGroup)
	{
		if (CheckNamePipe == t.name)
			res.push_back(i);
		i++;
	}
	return res;
}
vector<int> FindCSbyName(const vector <Stations>& csGroup)
{
	system("cls");
	string CheckNameCS;
	vector <int> res;
	unsigned long long int i = 0;
	cout << "pls write station name: ";
	cin >> ws;
	getline(cin, CheckNameCS);
	
	for (auto& y : csGroup)
	{
		if (CheckNameCS == y.name_CS)
			res.push_back(i);
		i++;
	}
	return res;
}

vector<int> FindCSbyWorkshop(const vector <Stations>& csGroup)
{
	system("cls");
	vector <int> res;
	unsigned long long int i = 0;
	int ukpd;
	cout << "pls enter kpd: ";
	cin >> ukpd;
	for (auto& y : csGroup)
	{
		
		if (ukpd >= (100-(y.active_workshop/y.workshop)*100));
			res.push_back(i);
		i++;
	}
	return res;
}


void ShowNewPipe(map <int, Pipe> pipes )
{
	unsigned long long int i;
	system("cls");
	for (i = 0; i < pipes.size(); i++)
	{
		if (pipes[i].diametr > 0)
			{
				cout << "труба уже создана" << endl << endl;
				cout << "название трубы: " << pipes[i].name << endl;
				cout << "диаметр трубы: " << pipes[i].diametr << endl;
				cout << "длина трубы: " << pipes[i].length << endl;
				cout << "Состояние трубы (0 - поломана , 1 - исправна ):" << pipes[i].repair << endl;

				if (pipes[i].repair == false)
				{
					cout << "truba v remonte" << endl;

				}
				else
				{
					cout << "truba v rabote" << endl;
				}

			}

		else
		{
				cout << "труба не создана" << endl;
		}
	}
	
}
void ShowNewCS(map <int, Stations> stations)
{
	unsigned long long int i;
	system("cls");
	for (i = 0; i < stations.size(); i++)
	{
		if (stations[i].workshop > 0)
		{
			cout << "компрессорная станция  создана" << endl << endl;
			cout << "Название компрессорной станции:" << stations[i].name_CS << endl;
			cout << "Эффективность:" << stations[i].effiency << endl;
			cout << "число цехов:" << stations[i].workshop << endl;
			cout << "Кол-во рабочих цехов:" << stations[i].active_workshop << endl;
		}
		else
		{
			cout << "Станция не создана" << endl;
		}
		
	}system("pause");
	
}
void Edit_pipe(Pipe&t)
{
	system("cls");
	cout << "Отредактируйте параметры трубы" << endl;
				if (t.repair == 0)
				{
					t.repair = true;
				}
				else
				{
					t.repair = false;
				}
	system("pause");

}

void Edit_cs(Stations& y)
{
	system("cls");

	if (y.workshop > 0)
	{
		cout << "Отредактируйте параметры" << endl;
		for (;;) {
			cout << "Число рабочих цехов: ";
			if (cin >> y.active_workshop) {
				if (y.active_workshop < 0) {
					cout << "ERROR!!! ВАША кс не может иметь отрицательное кол-во рабочих цехов " << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}

				else if (y.active_workshop > y.workshop) {
					cout << "ERROR!!!  число рабочих цехов не может превосходить общее число цехов" << endl;
					cin.clear();
					cin.ignore(10000, '\n');

				}
				/*else if (int(y.active_workshop) != y.active_workshop) {
					cout << "ERROR!!! Вводимое число не может быть дробным " << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}*/

				else {
					cout << y.active_workshop << endl;
					break;
				}

			}
			else {
				cout << "ERROR!!! ВВЕДЕНО НЕ ЧИСЛО" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		cout << " Пересчитанная Эффективность:";
		y.effiency = int(y.active_workshop * 100 / y.workshop);
		cout << y.effiency << "%" << endl;

	}
	/*else
	{
		cout << "Кс не создана" << endl;
	}
	system("pause");*/
	system("pause");

}

bool wanna_rewrite()
{
	double a = 0;
	cin >> a;
	if (a == 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		return 1;
	}
	else
	{
		cin.clear();
		cin.ignore(10000, '\n');
		return 0;
	}

}

void Save(map <int, Pipe>& pipes, map <int, Stations>& stations)
{
	system("cls");
	ofstream fout_lr1;
	cout << "Pls enter file name: ";
	string file_name;
	cin >> file_name;
	fout_lr1.open(file_name, ios::out);
	if (!fout_lr1.is_open())
	{
		cout << "Error!!! file is not open: "<<endl;
	}
	else
	{
		cout << "Your data successfully recordered" << endl;
		fout_lr1 << pipes.size() << endl;
		for (auto& [id, Pipe] : pipes)
		{
			fout_lr1 << id << endl << Pipe.name << endl << Pipe.length << endl << Pipe.diametr << endl << Pipe.repair << endl;
		}
		fout_lr1 << stations.size() << endl;
		for (auto& [id1, Stations] : stations)
		{
			fout_lr1 << id1 << endl << Stations.name_CS << endl << Stations.workshop << endl << Stations.active_workshop << endl << Stations.effiency << endl << Stations.k << endl;
		}

	}
	fout_lr1.close();
}

void load(map <int, Pipe>& pipes, map <int, Stations>& stations)
{
	system("cls");
	ifstream F;
	cout << "Pls enter file name: " << endl;
	string file_name;
	cin >> file_name;

	F.open(file_name, ios::in);
	if (!F.is_open()) {
		cout << "Error!!! file not open" << endl;
	}
	else if (F.peek() == EOF) {
		cout << "File is empty :(" << endl;
	}
	else
	{
		cout << "Data in file successfully loaded" << endl;
		int value1;
		F >> value1;
		if (pipes.size() == 0)
		{
			for (auto& [pipe_id, Pipe] : stations)
			{
				pipes.erase(pipe_id);
			}
		}
		for (int j = 1; j <= value1; j++)
		{
			Pipe t;
			int output_pipe_id = 0;
			F >> output_pipe_id;
			//F >> t.pipe_id;
			cout << " Parametrs pipe №: " << output_pipe_id << endl;
			F >> ws;
			getline(F, t.name);
			cout << "Название трубы: " << t.name << endl;
			F >> t.length;
			cout << "Длина трубы: " << t.length << endl;
			F >> t.diametr;
			cout << "Диаметр трубы: " << t.diametr << endl;
			F >> t.repair;
			cout << "Текущее состояние трубы: " << t.repair << endl;
			pipes.emplace(t.pipe_id, t);
		}


		int value2;
		F >> value2;
		if (stations.size() == 0)
		{
			for (auto& [cs_id, Stations] : stations)
			{
				stations.erase(cs_id);
			}
		}
		for (int i = 1; i <= value2; i++)
		{
			Stations y;
			int output_cs_id = 0;
			F >> output_cs_id;
			cout << " Parametrs CS №: " << output_cs_id << endl;
			F >> ws;
			getline(F, y.name_CS);
			cout << "название : " << y.name_CS << endl;
			F >> y.workshop;
			cout << "число  цехов : " << y.workshop << endl;
			F >> y.active_workshop;
			cout << "число рабочих цехов: " << y.active_workshop << endl;
			F >> y.effiency;
			cout << "Показатель эффективности рабочих цехов: " << y.effiency << endl;
			F >> y.k;
			cout << "Процент незадействованных цехов: " << y.k << endl;
			stations.emplace(output_cs_id, y);
		}
	
	}
	F.close();
	
		
	
	system("pause");
}


void gotoxy(int x, int y)    // эта функция написана благодаря статье https://stackoverflow.com/questions/13706439/gotoxy-function-is-not-working-in-visual-studio
{
	COORD plane = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), plane);

}


/*bool IsNumberCorrect(double t1, double t2, double t3)
{
	return (t1, t2, t3 > 0) && (t1, t2, t3 < 10000);
}*/





Pipe& SelectPipe(vector <Pipe>& pGroup)
{
	system("cls");
	cout << "pls enter id: "; 
	unsigned long long int id = GetCorrectNumber(1ull, pGroup.size());
	return pGroup[id-1];
}


Stations& SelectCS(vector <Stations>& csGroup)
{
	system("cls");
	cout << "pls enter id: ";
	unsigned long long int id = GetCorrectNumber(1ull, csGroup.size());
	return csGroup[id - 1];
}

vector<int> FindPipeByRepair(const vector <Pipe>& pGroup)
{
	vector <int> res;
	unsigned long long int i = 0; 
	for (auto& t : pGroup)
	{
		if (t.repair == true)
			res.push_back(i);
		i++;
	}
	return res;
}



int main()
{
	system("cls");
	vector <Pipe> pGroup; //= vector<pipe>{};
	vector <Stations> csGroup; // = vector <Stations>{};
	const int Num_of_menu = 13;
	// выбранный пункт меню 
	int activeMainMenu = 0;
	// хранение нажатой клавишы  
	int ch = 0;
	// ввожу переменную для отслеживания выхода из цикла 
	bool exit = false;
	Pipe tb{};
	Stations st{};
	int id_pipe = 0; 
	int id_cs = 0;
	map <int,Pipe>pipes  = {};
	map <int, Stations>stations = {};
	while (!exit)
	{
		setlocale(LC_ALL, "Russian");
		MainMenu();
		//движение курсора по меню 
		gotoxy(0, activeMainMenu);
		// получение кода нажатой клавиши
		ch = _getch();
		//обработка кодов  при нажатой клавише
		switch (ch)
		{
		case 27: exit = true; break;                 //эта часть кода была взята с видео https://www.youtube.com/watch?v=PQyVWMaAJLg&ab_channel=%D0%9C%D0%B0%D0%BA%D1%81%D0%B8%D0%BC%D0%92%D0%BE%D0%BB%D0%BA%D0%BE%D0%B2

		case 72: activeMainMenu--; break;

		case 80: activeMainMenu++; break; //down

		case 13: //enter 
			// далее выполняется переход в соответсвии с нажатым пунктом меню 
			if (activeMainMenu == 0)
			{
				//id++;
				Pipe tb;
				//tb.pipe_id = id;
				cin >> tb;
				pipes.emplace(tb.pipe_id, tb);
				//id_pipe++;
				//pGroup.push_back(tb);

				break;
			}
			else if (activeMainMenu == 1)
			{
				
				Stations st;
				//st.cs_id = id;
				cin >> st;
				//csGroup.push_back(st);
				stations.emplace(st.cs_id, st);
				

				break;
			}
			else if (activeMainMenu == 2)
			{

				/*ShowNewPipe(pipes);
				ShowNewCS(stations);*/
				system("cls");
				cout << "Параметры труб:" << endl;
				for (auto& [id, Pipe] : pipes) {
					cout << Pipe;
				}

				cout << "Параметры КС:" << endl;
				for (auto& [id, Stations] : stations) {
					cout << Stations;
				}

				
				break;
			}
			else if (activeMainMenu == 3)
			{
				//Edit_pipe();
				Edit_pipe(SelectPipe(pGroup));
				//ShowNewPipe(pipes);

				break;

			}
			else if (activeMainMenu == 4)
			{
				//Edit_cs();
				Edit_cs(SelectCS(csGroup));
				//ShowNewCS(stations);

				break;
			}
			else if (activeMainMenu == 5)
			{
				//Save(tb, st);
				system("cls");
				Save(pipes, stations);
				system("pause");
				break;

			}
			else if (activeMainMenu == 6)
			{
				//load(tb, st);
				system("cls");
				load(pipes, stations);
				system("pause");
				break;
				break;
			}
			else if (activeMainMenu == 7)
			{
				//Save(tb, st);
				exit = true;
				break;
			}
			
			else if (activeMainMenu == 8)
			{
				for (int i : FindPipeByRepair(pGroup))
					cout << pGroup[i];
				break;
			}
			
			else if (activeMainMenu == 9)
			{
				DeleteObjPipe(pipes);
				//ShowNewPipe(pipes);
				
				break;
			}
			else if (activeMainMenu == 10)
			{
			for (int i : FindCSbyName(csGroup))
				cout << csGroup[i];
			break;
			}
			else if (activeMainMenu == 11)
			{
				for (int i : FindCSbyWorkshop(csGroup))
					cout << csGroup[i];
				break;
			}
			else if (activeMainMenu == 12)
			{
				for (int i : FindPipebyName(pGroup))
				cout << pGroup[i];
			}
			break;
		}
		// ограничение курсора
		if (activeMainMenu < 0) activeMainMenu = 0;                                         //эта часть кода была взята с видео https://www.youtube.com/watch?v=PQyVWMaAJLg&ab_channel=%D0%9C%D0%B0%D0%BA%D1%81%D0%B8%D0%BC%D0%92%D0%BE%D0%BB%D0%BA%D0%BE%D0%B2
		if (activeMainMenu > Num_of_menu - 1) activeMainMenu = Num_of_menu - 1;
	}
	return 0;
}
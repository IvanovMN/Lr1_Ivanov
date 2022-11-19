#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Pipe.h"
#include "Stations.h"
#include "utils.h"

using namespace std;


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

Pipe& DeleteObjPipe(vector <Pipe>& pGroup)
{
	system("cls");
	cout << "pls enter id: ";
	unsigned long long int id = GetCorrectNumber(1ull, pGroup.size());
	//return pGroup[id-1];
	pGroup.erase(pGroup.begin() + (id - 1));
	return pGroup[id - 1];

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


void ShowNewPipe(const vector <Pipe>&pGroup)
{
	unsigned long long int i;
	system("cls");
	for (i = 0; i < pGroup.size(); i++)
	{
		if (pGroup[i].diametr > 0)
			{
				cout << "труба уже создана" << endl << endl;
				cout << "название трубы: " << pGroup[i].name << endl;
				cout << "диаметр трубы: " << pGroup[i].diametr << endl;
				cout << "длина трубы: " << pGroup[i].length << endl;
				cout << "Состояние трубы (0 - поломана , 1 - исправна ):" << pGroup[i].repair << endl;

				if (pGroup[i].repair == false)
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
	
	system("pause");
}
void ShowNewCS(const vector <Stations>&csGroup)
{
	unsigned long long int i;
	system("cls");
	for (i = 0; i < csGroup.size(); i++)
	{
		if (csGroup[i].workshop > 0)
		{
			cout << "компрессорная станция  создана" << endl << endl;
			cout << "Название компрессорной станции:" << csGroup[i].name_CS << endl;
			cout << "Эффективность:" << csGroup[i].effiency << endl;
			cout << "число цехов:" << csGroup[i].workshop << endl;
			cout << "Кол-во рабочих цехов:" << csGroup[i].active_workshop << endl;
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

void Save(ofstream&fout_lr1, const vector <Pipe>&pGroup, const vector <Stations> & csGroup)
{
	system("cls");
	cout << "Если файл еще не создан, то он автоматически создаcтся при нажатии на 1, с записанными параметрами" << endl << endl << "Иначе, создания не произойдет" << endl;
	cout << endl << "Если файл уже имеется и вы хотите перезаписать его, нажмите 1, иначе просто любую клавишу: " << endl;
	if (wanna_rewrite())
	{
	for (int i = 0; i < pGroup.size(); i++)
	{
		if (pGroup[i].diametr == 0)
		{
			cout << "net trubi" << endl;
			system("pause");
		}
		else
		{
			if (fout_lr1.is_open() == true)
			{

				fout_lr1 << "PIPE" << endl;

				fout_lr1 <<pGroup[i].name << endl << pGroup[i].diametr << endl << pGroup[i].length << endl << pGroup[i].repair << endl;

			}
			//fout_lr1.close();

		}
	}
	for (int i = 0; i < csGroup.size(); i++)
	{ 
		if (csGroup[i].workshop == 0) {
			cout << "cs net" << endl;
			system("pause");
		}
		else
		{
			if (fout_lr1.is_open() == true)
			{
				fout_lr1 << "STATION" << endl;
				fout_lr1 << csGroup[i].name_CS << endl << csGroup[i].effiency << endl << csGroup[i].workshop << endl << csGroup[i].active_workshop << endl;
			}
			

		}
		

	}
	}

}

void load(ifstream & F, vector <Pipe>& pGroup, vector <Stations>& csGroup)
{
	system("cls");
	//ifstream F;
	
	string our_word;
	//F.open("My_LR1.txt", ios::in);
	cout << "При нажатии 1, все ваши данные перезапишутся" << endl << "на те, которые были в файле, если вы не хотите перезаписывать введенные вами данные, нажмите на любую другую кнопку: " << endl;
	if (wanna_rewrite())
	{
		if (F.is_open() == true)
		{
			cout << "Файл открыт, все имеющиеся в нем данные будут считаны : " << endl;
		}
		else
		{
			cout << "Error!!! не удалось открыть файл: " << endl;
		}

		/*if (F.peek() == EOF)
		{

			cout << "ERROR!!! no data in file " << endl;
		}*/


		//while (F >> our_word)
		//{
		int index2,index1;
		F >> index1;
		F >> index2;
		pGroup.resize(index1);
		csGroup.resize(index2);
		string mark;
			for (int i = 0; i < index1; i++)
			{
				F >> mark;
				F >> pGroup[i].name;
								F >> pGroup[i].diametr;
								F >> pGroup[i].length;
								F >> pGroup[i].repair;

			}

			for (int i = 0; i < index2; i++)
			{
				F >> mark;
					F.ignore();
					getline(F, csGroup[i].name_CS);
					F >> csGroup[i].workshop;
					F >> csGroup[i].effiency;
					F >> csGroup[i].active_workshop;
			}
		//}



		return;
		//F.close();
		system("pause");
	}
	
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
	vector <Stations> csGroup = vector <Stations>{};
	const int Num_of_menu = 13;
	// выбранный пункт меню 
	int activeMainMenu = 0;
	// хранение нажатой клавишы  
	int ch = 0;
	// ввожу переменную для отслеживания выхода из цикла 
	bool exit = false;
	Pipe tb{};
	Stations st{};
	int id = 0; 
	unordered_map <int,Pipe>pipes;
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
				id++;
				Pipe tb;
				tb.id1 = id;
				cin >> tb;
				pGroup.push_back(tb);

				break;
			}
			else if (activeMainMenu == 1)
			{
				id++;
				Stations st;
				st.id2 = id;
				cin >> st;
				csGroup.push_back(st);


				break;
			}
			else if (activeMainMenu == 2)
			{

				ShowNewPipe(pGroup);
				ShowNewCS(csGroup);

				break;
			}
			else if (activeMainMenu == 3)
			{
				//Edit_pipe();
				Edit_pipe(SelectPipe(pGroup));
				ShowNewPipe(pGroup);

				break;

			}
			else if (activeMainMenu == 4)
			{
				//Edit_cs();
				Edit_cs(SelectCS(csGroup));
				ShowNewCS(csGroup);

				break;
			}
			else if (activeMainMenu == 5)
			{
				//Save(tb, st);
				ofstream fout_lr1;
				fout_lr1.open("My_LR1.txt", ios::out);
				if (fout_lr1.is_open())

				{

					/*fout_lr1 << pipes.size() << endl;
					for (auto&elm: pipes)
						Save(fout_lr1,tb,st);
					fout_lr1.close();
				}*/
					fout_lr1 << pGroup.size() << endl;



					fout_lr1 << csGroup.size() << endl;

					Save(fout_lr1, pGroup, csGroup);

				}fout_lr1.close();
				break;

			}
			else if (activeMainMenu == 6)
			{
				//load(tb, st);
				ifstream F;
				F.open("My_LR1.txt", ios::in);
				if (F.is_open())
				{
					load(F, pGroup, csGroup);
					F.close();
				}
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
				DeleteObjPipe(pGroup);
				ShowNewPipe(pGroup);
				
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
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;
template <typename T>
T GetCorrectNumber(T min, T max)
{
	T x;
	while ((cin>>x).fail() || x<min || x > max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "ОШИБКА ВВОДА ДАННЫХ \n";
	}
	return x;
}

class pipe
{
public:
	int id1;
	float length;
	float diametr;
	bool repair;
};

struct CS
{
	string name_CS;
	int active_workshop;
	int effiency;
	int workshop;
};

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
		<< "(0) Выход:" << endl;
}


/*template <typename T>
void check_input_info(T&input)
{
	while ((cin >> input).fail() || (input < 0) )
	{

		cout << "невозможное значение переменной" << endl;
		cin.clear();
		
		cin.ignore(10000, '\n');
	}
}*/
istream& operator >> (istream& in, pipe& t)
{
	system("cls");
	cout << "диаметр ";
	t.diametr = GetCorrectNumber(0.1,20000.0);
	cout << "длина ";
	t.length = GetCorrectNumber(0.1, 20000.0);;
	cout << "текущее состояние ";
	t.repair = GetCorrectNumber(0,1);;
	return in;

}

ostream& operator << (ostream& out, pipe& t)
{
	system("cls");
 out 
	    << "id: " <<  t.id1 << endl
		<< "Диаметр: " << t.diametr << endl
		<< "Длина: " << t.length << endl
		<< "Состояние трубы: " << t.repair << endl;
	system("pause");
	return out;
	         
}

/*pipe Add_New_Pipe()
{
	system("cls");
	pipe t;
	cout << "Создайте трубу:" << endl;
	
	cout << "диаметр трубы: ";
	check_input_info(t.diametr);
	cout << "длина трубы: ";
	check_input_info(t.length);
	cout << "текущее состояние трубы: ";
	check_input_info(t.repair);
	return t;
	system("pause");
}*/
void ShowNewPipe(pipe& t)
{
	system("cls");
	if (t.diametr > 0)
	{
		cout << "труба уже создана" << endl << endl;
		cout << "диаметр трубы: " << t.diametr << endl;
		cout << "длина трубы: " << t.length << endl;
		cout << "Состояние трубы (0 - поломана , 1 - исправна ):" << t.repair << endl;

		if (t.repair == false)
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
	system("pause");
}

CS Add_New_CS()
{
	system("cls");
	CS y;
	cout << "Создайте компрессорную станцию" << endl;
	cout << "Название компрессорной станции:";
	cin.clear();
	cin >> ws;
	getline(cin, y.name_CS);

	for (;;) {
		cout << "Число цехов: ";
		if (cin >> y.workshop) {

			if (y.workshop == 0) {
				cout << "Ваша КС не содержит цехов" << " " << y.workshop << endl;
				cin.clear();
				cin.ignore(10000, '\n');

			}
			else if (y.workshop < 0) {
				cout << "ERROR!!! Ваша КС не содержит цехов, кроме того учитывайте, что их количество не может быть отрицательно  " << endl;
				cin.clear();
				cin.ignore(10000, '\n');

			}

			else {
				cout << y.workshop << endl;
				break;
			}

		}
		else {
			cout << "ERROR!!! ВВЕДЕНО НЕ ЧИСЛО" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}


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
	cout << "Эффективность:";
	y.effiency = int(y.active_workshop * 100 / y.workshop);
	cout << y.effiency << "%" << endl;
	system("pause");
	return y;
	system("pause");

}

void ShowNewCS(CS& y)
{
	system("cls");
	if (y.workshop > 0)
	{
		cout << "компрессорная станция  создана" << endl << endl;
		cout << "Название компрессорной станции:" << y.name_CS << endl;
		cout << "Эффективность:" << y.effiency << endl;
		cout << "число цехов:" << y.workshop << endl;
		cout << "Кол-во рабочих цехов:" << y.active_workshop << endl;
	}
	else
	{
		cout << "Станция не создана" << endl;
	}
	system("pause");
}


pipe Edit_pipe(pipe& t)
{
	system("cls");
	cout << "Отредактируйте параметры трубы" << endl;
	if (t.diametr > 0)
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
	return t;
	system("pause");

}

CS Edit_cs(CS& y)
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
	return y;

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

void Save(ofstream&fout_lr1,  pipe&t, const CS & y)
{
	system("cls");
	cout << "Если файл еще не создан, то он автоматически создаcтся при нажатии на 1, с записанными параметрами" << endl << endl << "Иначе, создания не произойдет" << endl;
	cout << endl << "Если файл уже имеется и вы хотите перезаписать его, нажмите 1, иначе просто любую клавишу: " << endl;
	if (wanna_rewrite())
	{

		/*ofstream fout_lr1;
		fout_lr1.open("My_LR1.txt", ios::out);*/


		if (t.diametr == 0)
		{
			cout << "net trubi" << endl;
			system("pause");
		}
		else
		{
			if (fout_lr1.is_open() == true)
			{

				fout_lr1 << "PIPE" << endl;
				
				fout_lr1 << t.diametr << endl << t.length << endl << t.repair << endl;

			}
			//fout_lr1.close();

		}
		if (y.workshop == 0) {
			cout << "cs net" << endl;
			system("pause");
		}
		else
		{
			if (fout_lr1.is_open() == true)
			{
				fout_lr1 << "STATION" << endl;
				fout_lr1 << y.name_CS << endl << y.effiency << endl << y.workshop << endl << y.active_workshop << endl;
			}
			//fout_lr1.close();

		}
		/*if ((t.diametr > 0) && (y.workshop > 0))
		{
			if (fout_lr1.is_open() == true)
			{
				fout_lr1 << "truba" << endl;
				fout_lr1 << t.diametr << endl << t.length << endl << t.repair << endl;
				fout_lr1 << "cs" << endl;
				fout_lr1 << y.name_CS << endl << y.effiency << endl << y.workshop << endl << y.active_workshop << endl;
			}

		}*/

		//fout_lr1.close();



	}

}

void load(ifstream & F,  pipe & t,  CS &y)
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

		if (F.peek() == EOF)
		{

			cout << "ERROR!!! no data in file " << endl;
		}


		while (F >> our_word)
		{


			if (our_word == "PIPE")
			{
				F >> t.diametr;
				F >> t.length;
				F >> t.repair;
			}

			if (our_word == "STATION")
			{
				F.ignore();
				getline(F, y.name_CS);
				F >> y.workshop;
				F >> y.effiency;
				F >> y.active_workshop;
			}

		}



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





/*pipe& SelectPipe(vector <pipe>& g)
{
	unsigned int id = GetCorrectNumber(1u, g.size() - 1);
	return g[id-1];
}*/


int main()
{
	system("cls");
	const int Num_of_menu = 8;
	// выбранный пункт меню 
	int activeMainMenu = 0;
	// хранение нажатой клавишы  
	int ch = 0;
	// ввожу переменную для отслеживания выхода из цикла 
	bool exit = false;
	pipe tb{};
	CS st{};
	unordered_map <int,pipe>pipes;
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
				//ShowNewPipe(tb);
				//tb = Add_New_Pipe();
				//pipe tb;
				//group.push_back(tb);
				cin >> tb;
				tb.id1 = pipes.size() + 1;
				pipes.emplace(pipes.size()+1, tb);
				for (auto& elm : pipes)
				{
					cout << elm.first << endl << elm.second; 
				}
				break;
			}
			else if (activeMainMenu == 1)
			{

				st = Add_New_CS();

				break;
			}
			else if (activeMainMenu == 2)
			{
				//View_All_objects();
				//ShowNewPipe(tb);
				//cout << SelectPipe(group)
				
				for (auto& elm : pipes)
				{
					cout << elm.first << endl<< elm.second;
				}
				
				ShowNewCS(st);
				break;
			}
			else if (activeMainMenu == 3)
			{
				//Edit_pipe();
				tb = Edit_pipe(tb);
				ShowNewPipe(tb);

				break;

			}
			else if (activeMainMenu == 4)
			{
				//Edit_cs();
				st = Edit_cs(st);
				ShowNewCS(st);

				break;
			}
			else if (activeMainMenu == 5)
			{
				//Save(tb, st);
				ofstream fout_lr1;
				fout_lr1.open("My_LR1.txt", ios::out);
				if (fout_lr1.is_open())

				{
					
					fout_lr1 << pipes.size() << endl;
					for (auto&elm : pipes)
						Save(fout_lr1,tb,st);
					fout_lr1.close();
				}
				break;
				
			}
			else if (activeMainMenu == 6)
			{
				//load(tb, st);
				ifstream F;
				F.open("My_LR1.txt", ios::in);
				if (F.is_open())
				{
					for (auto& elm : pipes)
						load(F, tb, st);
					F.close();
				}
				break;
			
			}
			else if (activeMainMenu == 7)
			{
				//Save(tb, st);
				exit = true;
			}
			break;
		}
		// ограничение курсора
		if (activeMainMenu < 0) activeMainMenu = 0;                                         //эта часть кода была взята с видео https://www.youtube.com/watch?v=PQyVWMaAJLg&ab_channel=%D0%9C%D0%B0%D0%BA%D1%81%D0%B8%D0%BC%D0%92%D0%BE%D0%BB%D0%BA%D0%BE%D0%B2
		if (activeMainMenu > Num_of_menu - 1) activeMainMenu = Num_of_menu - 1;
	}
	return 0;
}
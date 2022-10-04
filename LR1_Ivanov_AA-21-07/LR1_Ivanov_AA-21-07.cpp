#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

struct pipe
{
	float length;
	float diametr;
	int repair;
};

struct CS
 {
	 string name_CS;
	 float active_workshop;
	 float effiency;
	 float workshop; 
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



 pipe Add_New_Pipe()
{
	system("cls");
	pipe t;
	
	cout << "Создайте трубу:" << endl;
	
		
	for (;;) {
		cout << "Диаметр трубы:";
		if(cin >> t.diametr){
		
			if (t.diametr == 0) {
				cout << "ERROR!!! ВАША ТРУБА НЕ МОЖЕТ ИМЕТЬ ТАКОЙ ДИАМЕТР" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (t.diametr < 0 ) {
				cout << "ERROR!!! ВАША ТРУБА НЕ МОЖЕТ ИМЕТЬ ОТРИЦАТЕЛЬНЫЕ ЗНАЧЕНИЯ " << endl;
				cin.clear();
				cin.ignore(10000, '\n');

			}
			else if (t.diametr > 1470) {
				cout << "ERROR!!! ВАША ТРУБА ВЫХОДИТ ЗА РАМКИ ДОПУСТИМЫХ ЗНАЧЕНИЙ (ВЕРХНИЙ ПРЕДЕЛ ЗНАЧЕНИЙ 1470) " << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else {
				cout << t.diametr << endl;
				break;
			}

		}
		else  {
			cout << "ERROR!!! ВВЕДЕНО НЕ ЧИСЛО" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		
	}

	
	
	for (;;) {
		cout << "Длина трубы:";
		if (cin >> t.length) {
			
			if (t.length == 0) {
				cout << "ERROR!!! ВАША ТРУБА НЕ МОЖЕТ ИМЕТЬ ТАКУЮ ДЛИНУ" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (t.length < 0) {
				cout << "ERROR!!! ВАША ТРУБА НЕ МОЖЕТ ИМЕТЬ ОТРИЦАТЕЛЬНЫЕ ЗНАЧЕНИЯ ДЛИНЫ" << endl;
				cin.clear();
				cin.ignore(10000, '\n');

			}
			
			else {
				cout << t.length << endl;
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
		cout << "Состояние трубы (0 - поломана, 1 - исправна ):";
		if (cin >> t.repair) {
			//if (cin.good() == true) 
			if (t.repair == 0) {
				cout << "Ваша труба поломана" << " " << t.repair << endl;
				break;
				
			}
			else if (t.repair < 0) {
				cout << "ERROR!!! ВАША ТРУБА НЕ МОЖЕТ ИМЕТЬ ОТРИЦАТЕЛЬНЫЕ ЗНАЧЕНИЯ ДЛЯ ОТОБРАЖЕНИЯ ЕЕ ТЕКУЩЕГО СОСТОЯНИЯ " << endl;
				cin.clear();
				cin.ignore(10000, '\n');

			}
			
			else if (t.repair > 1) {
				cout << "ERROR!!! СОСТОЯНИЕ ВАШЕЙ ТРУБЫ ДОЛЖНО ОЦЕНИВАТЬСЯ В РАМКАХ ДОПУСТИМЫХ ЗНАЧЕНИЙ ( 0 ИЛИ 1) " << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			
			else {
				cout << t.repair << endl;
				break;
			}

		}
		else {
			cout << "ERROR!!! ВВЕДЕНО НЕ ЧИСЛО" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		
	}
	
	

	

	return t;
	
	
	system("pause");
   

}
 void ShowNewPipe(pipe&t)
 {
	 system("cls");
	 
	 
	 
	 
	 if ((t.diametr == 0) || (t.length == 0))
	 {
		 
		 cout << "труба не создана" << endl;
		 
		 
		
	 }

	 else
	 {
		 cout << "труба уже создана" << endl << endl;

		 cout << "Диаметр трубы:" << t.diametr << endl;
		 
		 cout << "Длина трубы:" << t.length << endl;
		 cout << "Состояние трубы (0 - поломана , 1 - исправна ):" << t.repair << endl;

		 

		 
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
	cin.ignore();
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
			else if (int(y.workshop) != y.workshop) {
				cout << "ERROR!!! Вводимое число не может быть дробным " << endl;
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
			else if (int(y.active_workshop) != y.active_workshop) {
				 cout << "ERROR!!! Вводимое число не может быть дробным " << endl;
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
		y.effiency = (y.active_workshop / y.workshop) * 100;
		cout << y.effiency << "%" << endl;
		system("pause");

	return y;


	system("pause");
	
}

void ShowNewCS(CS&y)
{ 
	system("cls");
	if (y.workshop == 0)
	{
		cout << "компрессорная станция не создана" << endl;
	}
	else
	{ 
		cout << "компрессорная станция создана" << endl << endl;
		cout << "Название компрессорной станции:" << y.name_CS << endl;
		cout << "Эффективность:" << y.effiency << endl;
		cout << "число цехов:" << y.workshop << endl;
		cout << "Кол-во рабочих цехов:" << y.active_workshop << endl;
	}


	system("pause");
}

void View_All_objects()
{
	system("cls");
	cout << "Просмотреть состояние всех объектов" << endl;
	system("pause");
}

pipe Edit_pipe(pipe & t)
{
	system("cls");
	cout << "Отредактируйте параметры трубы" << endl;
	for (;;) {
		cout << "Состояние трубы (0 - поломана, 1 - исправна ):";
		if (cin >> t.repair) {
			
			if (t.repair == 0) {
				cout << "Ваша труба поломана" << " " << t.repair << endl;
				system("pause");
				break;

			}
			else if (t.repair < 0) {
				cout << "ERROR!!! ВАША ТРУБА НЕ МОЖЕТ ИМЕТЬ ОТРИЦАТЕЛЬНЫЕ ЗНАЧЕНИЯ ДЛЯ ОТОБРАЖЕНИЯ ЕЕ ТЕКУЩЕГО СОСТОЯНИЯ " << endl;
				cin.clear();
				cin.ignore(10000, '\n');

			}
			
			else if (t.repair > 1) {
				cout << "ERROR!!! СОСТОЯНИЕ ВАШЕЙ ТРУБЫ ДОЛЖНО ОЦЕНИВАТЬСЯ В РАМКАХ ДОПУСТИМЫХ ЗНАЧЕНИЙ ( 0 ИЛИ 1) " << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			else {
				cout << t.repair << endl;
				break;
			}

		}
		else {
			cout << "ERROR!!! ВВЕДЕНО НЕ ЧИСЛО" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			
		}
	}


	return t;


	system("pause");

}

CS Edit_cs(CS&y)
{
	system("cls");
	cout << "Отредактируйте параметры КС" << endl;
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
				break;
			}
			else if (int(y.active_workshop) != y.active_workshop) {
				cout << "ERROR!!! Вводимое число не может быть дробным " << endl;
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

	cout << " Пересчитанная Эффективность:";
	y.effiency = (y.active_workshop / y.workshop) * 100;
	cout << y.effiency << "%" << endl;
	system("pause");
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

void Save(const pipe & t, const CS & y)
{
	system("cls");
	cout << "Сохранить изменения???" << endl << "Если файл уже имеется и вы хотите перезаписать его, нажмите 1, иначе просто любую клавишу: " << endl;
	cout << "Если вы только что создали новый файл, то при нажатии 1, данные в него просто сохранятся" << endl;
	
	if (wanna_rewrite())
	{
		
		ofstream fout_lr1;
		
		fout_lr1.open("My_LR1.txt", ios::out);



		fout_lr1 << t.diametr << endl << t.length << endl << t.repair << endl << y.name_CS << endl << y.effiency << endl << y.workshop << endl << y.active_workshop;



		fout_lr1.close();
		system("pause");

	}

}

void load(pipe & t, CS & y)
{
	system("cls");
	
	ifstream F;
	F.open("My_LR1.txt", ios::in);
	cout << "При нажатии 1, все ваши данные перезапишутся" << endl << "на те, которые были в файле, если вы не хотите перезаписывать введенные вами данные, нажмите на любую другую кнопку: "  << endl; 
	if (wanna_rewrite())
	{ 

		if (F.is_open() == true)
		{
			cout << "Файл открыт, все имеющиеся в нем данные будут считаны : " << endl;
			if (F.peek() == EOF )
			{
				cout << "ERROR!!! no data in file " << endl;
				

			
			
			
			}
			else 
			{
				
				F >> t.diametr;
				F >> t.length;
				F >> t.repair;
				
				F.ignore();
				getline(F, y.name_CS);

				F >> y.workshop;

				F >> y.effiency;

				F >> y.active_workshop;

				
			}
		}
		else
		{
			cout << "Error!!! не удалось открыть файл: " << endl;
		}

	
	
	F.close();
	system("pause");
	}
}


void gotoxy(int x, int y)    // эта функция написана благодаря статье https://stackoverflow.com/questions/13706439/gotoxy-function-is-not-working-in-visual-studio
{
	COORD plane = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), plane);

}

pipe checkpipe(pipe& t)
{
	if (t.diametr == 0)
	{
		t = Add_New_Pipe();
	}
	else
	{
		cout << "труба уже создана" << endl;
	}
	return t;
}

CS checkCS(CS& y)
{
	if (y.workshop == 0)
	{
		y = Add_New_CS();
	}
	else
	{
		cout << "компрессорная станция уже создана" << endl;
	}
	return y;
}

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
			case 27: exit = true;break;                 //эта часть кода была взята с видео https://www.youtube.com/watch?v=PQyVWMaAJLg&ab_channel=%D0%9C%D0%B0%D0%BA%D1%81%D0%B8%D0%BC%D0%92%D0%BE%D0%BB%D0%BA%D0%BE%D0%B2
				            
			case 72: activeMainMenu--; break; 
				
			case 80: activeMainMenu++;break; //down
				
			case 13: //enter 
				// далее выполняется переход в соответсвии с нажатым пунктом меню 
				if (activeMainMenu == 0)
				{	
					ShowNewPipe(tb);
					tb = checkpipe(tb);
					break;
					
					 
					
					
					
					
				}
				else if (activeMainMenu == 1)
				{
					ShowNewCS(st);
					st = checkCS(st);
					
					break;
				}
				else if (activeMainMenu == 2)
				{
					//View_All_objects();
					ShowNewPipe(tb); 
					ShowNewCS(st);
					break;
				}
				else if (activeMainMenu == 3)
				{
					//Edit_pipe();
					ShowNewPipe(tb);
					tb = Edit_pipe(tb);
					break;
					
				}
				else if (activeMainMenu == 4)
				{
					//Edit_cs();
					ShowNewCS(st);
					st = Edit_cs(st);
					break;
				}
				else if (activeMainMenu == 5)
				{
					Save(tb, st);
					
				}
				else if (activeMainMenu == 6)
				{
					load( tb, st);
				}
				else if (activeMainMenu == 7)
				{
					Save(tb, st);
					exit=true;
				}
			break;
		}

		// ограничение курсора
		if (activeMainMenu < 0) activeMainMenu = 0;                                         //эта часть кода была взята с видео https://www.youtube.com/watch?v=PQyVWMaAJLg&ab_channel=%D0%9C%D0%B0%D0%BA%D1%81%D0%B8%D0%BC%D0%92%D0%BE%D0%BB%D0%BA%D0%BE%D0%B2
		if (activeMainMenu > Num_of_menu - 1) activeMainMenu = Num_of_menu - 1;
	}
	return 0;
	
	
	
}
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
	//float diametr, length;
	//int repair;
	cout << "Укажите параметры трубы:" << endl;;
	cout << "Диаметр трубы:";
	cin >> t.diametr;
	cout << "Длина трубы:";
	cin >> t.length;
	cout << "Состояние трубы:";
	cin >> t.repair;

	return t;
	
	
	system("pause");
   

}
 void ShowNewPipe(pipe t)
 {
	 system("cls");
	 cout << "Диаметр трубы:" << t.diametr << endl;
	 cout << "Длина трубы:" << t.length << endl;
	 cout << "Находится ли труба в ремонте:" << t.repair << endl;

	 system("pause");

 }

 struct CS
 {
	 string name_CS;
	 int number_of_workshop;
	 float effiency;
 };
 
CS Add_New_CS()
{
	system("cls");
	CS y;
	cout << "Укажите параметры КС " << endl;
	cout << "Название компрессорной станции:";
	
	//cin >> y.name_CS;

	cin.clear();
	cin.ignore();
	getline(cin, y.name_CS);
	cout << "Кол-во рабочих цехов:";
	cin >> y.number_of_workshop;
	cout << "Эффективность:";
	cin >> y.effiency;

	return y;


	system("pause");
	
}

void ShowNewCS(CS y)
{
	system("cls");
	cout << "Название компрессорной станции:" << y.name_CS << endl;
	
	cout << "Кол-во рабочих цехов:" << y.number_of_workshop << endl;
	cout << "Эффективность:" << y.effiency << endl;

	system("pause");
}

void View_All_objects()
{
	system("cls");
	cout << "Просмотреть состояние всех объектов" << endl;
	system("pause");
}

void Edit_pipe()
{
	system("cls");
	cout << "Отредактируйте параметры трубы" << endl;
	system("pause");
}

void Edit_cs()
{
	system("cls");
	cout << "Отредактируйте параметры КС" << endl;
	system("pause");
}



void Save(const pipe & t, const CS & y)
{
	system("cls");
	cout << "Сохранить изменения" << endl;
	//system("pause");
	ofstream fout_lr1;
	//ofstream fout_nCS;
	fout_lr1.open("My_LR1.txt", ios::out);
	fout_lr1 <<t.diametr << endl <<  t.length << endl <<  t.repair << endl <<  y.name_CS << endl <<  y.effiency << endl <<  y.number_of_workshop;

	fout_lr1.close();


	


}

void load(pipe & t, CS & y)
{
	system("cls");
	cout << "загрузить все изменения" << endl;
	//system("pause");
	ifstream F;
	F.open("My_LR1.txt", ios::in);
	F >> t.diametr; 
	F >> t.length; 
	F >> t.repair;
	//F >> y.name_CS; 
	F.ignore();
	getline(F,y.name_CS);
	
	F >> y.effiency;
	F >> y.number_of_workshop;  
	
	F.close();
}
void exit()
{
	system("cls");
	cout << "Выйти из программы" << endl;
	
	
}

void gotoxy(int x, int y)    // эта функция написана благодаря статье https://stackoverflow.com/questions/13706439/gotoxy-function-is-not-working-in-visual-studio
{
	COORD plane = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), plane);

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
					
					tb = Add_New_Pipe();
					 ShowNewPipe(tb);
					break;
					
					
					
				}
				else if (activeMainMenu == 1)
				{
					st = Add_New_CS();
					ShowNewCS(st);
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
					tb = Add_New_Pipe();
					break;
					
				}
				else if (activeMainMenu == 4)
				{
					//Edit_cs();
					ShowNewCS(st);
					st = Add_New_CS();
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
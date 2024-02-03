#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;


////////////////////////////////////////////
//ТЕСТИРУЕМЫЙ
class Test
{
private:
	string file;
	vector<string> quest;
	vector<string> rez;
	string act;
	int bal = 0;
public:
	Test(string _file)
	{
		this->file = _file;
	}

	//Добавление в вектор текстовый файл
	void AddQuestion(const string q)
	{
		quest.push_back(q);
	}

	//Работа с файлом для чтения
	void Load()
	{
		string question;
		fstream f(this->file, ios::in);
		if (!f)
		{
			cout << "Файл не открылся для чтения !!!" << endl;
			exit(1);
		}
		while (getline(f, question))
		{
			this->AddQuestion(question);
		}
		f.close();
	}

	//Функция вывода на экран
	void Print() {
		for (int i = 0; i < quest.size(); i++) {
			cout << quest[i].c_str() << endl;
		}
	}

	//Вывод вопросов и вариатов ответа
	void Run()
	{
		int q = 0;
		int a = 0;
		int otv = 0;

		for (int i = 0; i < 5; i++)
		{
			system("cls");
			cout << quest[q].c_str() << endl;
			cout << quest[a + 1].c_str() << endl;
			cout << quest[a + 2].c_str() << endl;
			cout << quest[a + 3].c_str() << endl;
			cout << "Введите ответ:?";
			cin >> act;
			if (act == quest[otv + 4].c_str())
			{
				bal++;
			}
			q += 5;
			a += 5;
			otv += 5;
		}
	}

	//Вывод результата
	void Result()
	{
		system("cls");
		if (this->bal == 1 or this->bal == 2 or this->bal == 0)
			cout << "Ваша оценка: " << 2 << endl;
		else
			cout << "Ваша оценка: " << this->bal << endl;
	}


	//void Load3()
	//{
	//	string question;
	//	fstream f(this->file, ios::app);
	//	if (!f)
	//	{
	//		cout << "Файл не открылся для чтения !!!" << endl;
	//		exit(1);
	//	}
	//	
	//	if (bal >= 2)
	//	{
	//		f << endl << "Оценка за тест: " << endl << bal;
	//	}
	//	else
	//		f << endl << "Оценка за тест: " << endl << 2;

	//	f.close();
	//}

};



/////////////////////////////////////////////////////////////////////
//АДМИНИСТРАТОР
class Administrator
{
private:
	vector<string> quest1;
	string file1;

public:
	Administrator(string _file1)
	{
		this->file1 = _file1;
	}

	//Добавление в вектор текстовый файл
	void AddQuestion1(const string q1)
	{
		quest1.push_back(q1);
	}


	//класс для записи в файл
	void Load1()
	{
		string a, a1, a2, a3;

		int fin = 0;
		string question;
		fstream f;
		f.open(this->file1, ios:: out);
		if (!f)
		{
			cout << "Файл не открылся для записи !!!" << endl;
			exit(1);
		}
			
		cout << "Введите имя пользователя: " << endl;
		cin >> a; 
		f << "Имя пользователя: " << endl << a << endl;
		cout << "Введите возвраст пользователя: " << endl;
		cin >> a1;
		f << "Возвраст: " << endl << a1 << endl;
		cout << "Введите тест, пройденный пользователем: " << endl;
		cin >> a2;
		f << "Тест: " << endl << a2 << endl;
		cout << "Введите оценку за тест: " << endl;
		cin >> a3;
		f << "Оценка за тест: " << endl << a3 << endl;
		
		f.close();
	}

	//Для чтения о пользователе
	void Load2()
	{
		string question;
		fstream f(this->file1, ios::in);
		if (!f)
		{
			cout << "Файл не открылся для чтения !!!" << endl;
			exit(1);
		}
		while (getline(f, question))
		{
			this->AddQuestion1(question);
		}
		f.close();
	}

	void Print() 
	{
		for (int i = 0; i < quest1.size(); i++)
		{
			cout << quest1[i].c_str() << endl;
		}

	}

	
};
///////////////////////////////////////////////////////////


class Data
{
private:
	vector<string> quest1;
	string file1;
public:

	Data(string _file1)
	{
		this->file1 = _file1;
	}
	//Добавление в вектор текстовый файл
	void AddQuestion1(const string q1)
	{
		quest1.push_back(q1);
	}

	//класс для записи в файл
	void Load1()
	{
		string a, a1, a2, a3;

		int fin = 0;
		string question;
		fstream f;
		f.open(this->file1, ios::out);
		if (!f)
		{
			cout << "Файл не открылся для чтения !!!" << endl;
			exit(1);
		}

		cout << "Введите свое имя: " << endl;
		cin >> a;
		f << "Имя пользователя: " << endl << a << endl;
		cout << "Введите свой возвраст: " << endl;
		cin >> a1;
		f << "Возвраст: " << endl << a1 << endl;
		cout << "Введите тест, который будете проходить(Математика, Биология, Русский язык): " << endl;
		cin >> a2;
		f << "Тест: " << endl << a2 << endl;
		
		f.close();
	}
};



int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "RUS");
	Test t("Математика.txt");
	Test b("Биология.txt");
	Test r("Русский язык.txt");

	Administrator g("Пользователь1.txt");
	Data i("Пользователь1.txt");
	//g.Load1();
	//g.Load2();
	//g.Print();
	

	int who;
	cout << "Кто использует программу: " << endl;
	cout << "1. Тестируемый" << endl;
	cout << "2. Администратор" << endl;
	cin >> who;


	//ТЕСТИРУЕМЫЙ
	if (who == 1)
	{
		system("cls");
		i.Load1();
	
		int vibor = 1;
		while (vibor != 0)
		{			
			//Меню
			system("cls");
			cout << "\t\t\tТЕСТ" << endl;
			Sleep(500);
			cout << "Вам предстоит пройти 1 из 3 тестов на выбор" << endl; Sleep(500);
			cout << "По количеству верных и неверных ответов будет поставленна оценка" << endl; Sleep(500);
			cout << "На выбор имеется следующие предметы:" << endl; Sleep(500);
			cout << "1. Математика" << endl; Sleep(500);
			cout << "2. Биология" << endl; Sleep(500);
			cout << "3. Русский язык" << endl; Sleep(500);
			cout << "0. ВВЕДИТЕ 0 ДЛЯ ОСТАНОВКИ ПРОГРАММЫ" << endl;
			cout << "Для выбора теста введите его номер: " << endl;
			cin >> vibor;

			//Математика
			if (vibor == 1)
			{
				system("cls");
				Sleep(1000);
				cout << "\t\t\t\tТЕСТ по теме: Математика" << endl;
				Sleep(1000);
				system("cls");

				t.Load();
				t.Run();
				t.Result();
				//t.Load3();

				cout << endl << endl << "Для продолжения введите любое число" << endl;
				int cont;
				cin >> cont;
			}

			//Биология
			if (vibor == 2)
			{
				system("cls");
				Sleep(1000);
				cout << "\t\t\t\tТЕСТ по теме: Биолгия" << endl;
				Sleep(1000);
				system("cls");

				b.Load();
				b.Run();
				b.Result();
				cout << endl << endl << "Для продолжения введите любое число" << endl;
				int cont;
				cin >> cont;
			}

			//Русский язык
			if (vibor == 3)
			{
				system("cls");
				Sleep(1000);
				cout << "\t\t\t\tТЕСТ по теме: Русский язык" << endl;
				Sleep(1000);
				system("cls");

				r.Load();
				r.Run();
				r.Result();
				cout << endl << endl << "Для продолжения введите любое число" << endl;
				int cont;
				cin >> cont;
			}
		}
	}

	//АДМИНИСТРАТОР
	else if (who == 2)
	{
		system("cls");
		string login, login1;
		int parol, parol1;
		cout << "Введите новый логин: "; cin >> login; cout << endl;
		cout << "Введите новый пароль: "; cin >> parol; cout << endl;

		int vibor_admin = 1;
		while (vibor_admin != 0)
		{
			system("cls");
			Sleep(1000);
			cout << "Введите логин: ";
			cin >> login1;
			cout << endl << "Введите пароль: ";
			cin >> parol1;
			if (login1 == login && parol1 == parol)
			{
				cout << "\t\t\t\tАДМИНИСТРАТОР";
				Sleep(1500);
				system("cls");
				cout << "Вам доступны следующие функции: " << endl;
				Sleep(500);
				cout << "1. Чтение данных о последнем пользователе" << endl;
				Sleep(500);
				cout << "2. Запись данных о пользователе" << endl;
				Sleep(500);
				cout << "0. ВВЕДИТЕ 0 ДЛЯ ЗАВЕРШЕНИЯ ПРОГРАММЫ" << endl;


				cout << "Введите номер команды: "; cin >> vibor_admin;

				if (vibor_admin == 1)
				{
					system("cls");
					g.Load2();
					g.Print();

					cout << endl << endl << "Для продолжения введите любое число" << endl;
					int cont;
					cin >> cont;
				}
				else if (vibor_admin == 2)
				{
					system("cls");
					g.Load1();

					cout << endl << endl << "Для продолжения введите любое число" << endl;
					int cont1;
					cin >> cont1;
				}
			}
			else
			{
				cout << endl << endl << "ВВЕДЕН НЕПРАВИЛЬНЫЙ ЛОГИН ИЛИ ПАРОЛЬ";
				Sleep(2000);
			}
		}
	}

	return 0;
}


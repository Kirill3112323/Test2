#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;


////////////////////////////////////////////
//�����������
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

	//���������� � ������ ��������� ����
	void AddQuestion(const string q)
	{
		quest.push_back(q);
	}

	//������ � ������ ��� ������
	void Load()
	{
		string question;
		fstream f(this->file, ios::in);
		if (!f)
		{
			cout << "���� �� �������� ��� ������ !!!" << endl;
			exit(1);
		}
		while (getline(f, question))
		{
			this->AddQuestion(question);
		}
		f.close();
	}

	//������� ������ �� �����
	void Print() {
		for (int i = 0; i < quest.size(); i++) {
			cout << quest[i].c_str() << endl;
		}
	}

	//����� �������� � �������� ������
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
			cout << "������� �����:?";
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

	//����� ����������
	void Result()
	{
		system("cls");
		if (this->bal == 1 or this->bal == 2 or this->bal == 0)
			cout << "���� ������: " << 2 << endl;
		else
			cout << "���� ������: " << this->bal << endl;
	}


	//void Load3()
	//{
	//	string question;
	//	fstream f(this->file, ios::app);
	//	if (!f)
	//	{
	//		cout << "���� �� �������� ��� ������ !!!" << endl;
	//		exit(1);
	//	}
	//	
	//	if (bal >= 2)
	//	{
	//		f << endl << "������ �� ����: " << endl << bal;
	//	}
	//	else
	//		f << endl << "������ �� ����: " << endl << 2;

	//	f.close();
	//}

};



/////////////////////////////////////////////////////////////////////
//�������������
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

	//���������� � ������ ��������� ����
	void AddQuestion1(const string q1)
	{
		quest1.push_back(q1);
	}


	//����� ��� ������ � ����
	void Load1()
	{
		string a, a1, a2, a3;

		int fin = 0;
		string question;
		fstream f;
		f.open(this->file1, ios:: out);
		if (!f)
		{
			cout << "���� �� �������� ��� ������ !!!" << endl;
			exit(1);
		}
			
		cout << "������� ��� ������������: " << endl;
		cin >> a; 
		f << "��� ������������: " << endl << a << endl;
		cout << "������� �������� ������������: " << endl;
		cin >> a1;
		f << "��������: " << endl << a1 << endl;
		cout << "������� ����, ���������� �������������: " << endl;
		cin >> a2;
		f << "����: " << endl << a2 << endl;
		cout << "������� ������ �� ����: " << endl;
		cin >> a3;
		f << "������ �� ����: " << endl << a3 << endl;
		
		f.close();
	}

	//��� ������ � ������������
	void Load2()
	{
		string question;
		fstream f(this->file1, ios::in);
		if (!f)
		{
			cout << "���� �� �������� ��� ������ !!!" << endl;
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
	//���������� � ������ ��������� ����
	void AddQuestion1(const string q1)
	{
		quest1.push_back(q1);
	}

	//����� ��� ������ � ����
	void Load1()
	{
		string a, a1, a2, a3;

		int fin = 0;
		string question;
		fstream f;
		f.open(this->file1, ios::out);
		if (!f)
		{
			cout << "���� �� �������� ��� ������ !!!" << endl;
			exit(1);
		}

		cout << "������� ���� ���: " << endl;
		cin >> a;
		f << "��� ������������: " << endl << a << endl;
		cout << "������� ���� ��������: " << endl;
		cin >> a1;
		f << "��������: " << endl << a1 << endl;
		cout << "������� ����, ������� ������ ���������(����������, ��������, ������� ����): " << endl;
		cin >> a2;
		f << "����: " << endl << a2 << endl;
		
		f.close();
	}
};



int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "RUS");
	Test t("����������.txt");
	Test b("��������.txt");
	Test r("������� ����.txt");

	Administrator g("������������1.txt");
	Data i("������������1.txt");
	//g.Load1();
	//g.Load2();
	//g.Print();
	

	int who;
	cout << "��� ���������� ���������: " << endl;
	cout << "1. �����������" << endl;
	cout << "2. �������������" << endl;
	cin >> who;


	//�����������
	if (who == 1)
	{
		system("cls");
		i.Load1();
	
		int vibor = 1;
		while (vibor != 0)
		{			
			//����
			system("cls");
			cout << "\t\t\t����" << endl;
			Sleep(500);
			cout << "��� ��������� ������ 1 �� 3 ������ �� �����" << endl; Sleep(500);
			cout << "�� ���������� ������ � �������� ������� ����� ����������� ������" << endl; Sleep(500);
			cout << "�� ����� ������� ��������� ��������:" << endl; Sleep(500);
			cout << "1. ����������" << endl; Sleep(500);
			cout << "2. ��������" << endl; Sleep(500);
			cout << "3. ������� ����" << endl; Sleep(500);
			cout << "0. ������� 0 ��� ��������� ���������" << endl;
			cout << "��� ������ ����� ������� ��� �����: " << endl;
			cin >> vibor;

			//����������
			if (vibor == 1)
			{
				system("cls");
				Sleep(1000);
				cout << "\t\t\t\t���� �� ����: ����������" << endl;
				Sleep(1000);
				system("cls");

				t.Load();
				t.Run();
				t.Result();
				//t.Load3();

				cout << endl << endl << "��� ����������� ������� ����� �����" << endl;
				int cont;
				cin >> cont;
			}

			//��������
			if (vibor == 2)
			{
				system("cls");
				Sleep(1000);
				cout << "\t\t\t\t���� �� ����: �������" << endl;
				Sleep(1000);
				system("cls");

				b.Load();
				b.Run();
				b.Result();
				cout << endl << endl << "��� ����������� ������� ����� �����" << endl;
				int cont;
				cin >> cont;
			}

			//������� ����
			if (vibor == 3)
			{
				system("cls");
				Sleep(1000);
				cout << "\t\t\t\t���� �� ����: ������� ����" << endl;
				Sleep(1000);
				system("cls");

				r.Load();
				r.Run();
				r.Result();
				cout << endl << endl << "��� ����������� ������� ����� �����" << endl;
				int cont;
				cin >> cont;
			}
		}
	}

	//�������������
	else if (who == 2)
	{
		system("cls");
		string login, login1;
		int parol, parol1;
		cout << "������� ����� �����: "; cin >> login; cout << endl;
		cout << "������� ����� ������: "; cin >> parol; cout << endl;

		int vibor_admin = 1;
		while (vibor_admin != 0)
		{
			system("cls");
			Sleep(1000);
			cout << "������� �����: ";
			cin >> login1;
			cout << endl << "������� ������: ";
			cin >> parol1;
			if (login1 == login && parol1 == parol)
			{
				cout << "\t\t\t\t�������������";
				Sleep(1500);
				system("cls");
				cout << "��� �������� ��������� �������: " << endl;
				Sleep(500);
				cout << "1. ������ ������ � ��������� ������������" << endl;
				Sleep(500);
				cout << "2. ������ ������ � ������������" << endl;
				Sleep(500);
				cout << "0. ������� 0 ��� ���������� ���������" << endl;


				cout << "������� ����� �������: "; cin >> vibor_admin;

				if (vibor_admin == 1)
				{
					system("cls");
					g.Load2();
					g.Print();

					cout << endl << endl << "��� ����������� ������� ����� �����" << endl;
					int cont;
					cin >> cont;
				}
				else if (vibor_admin == 2)
				{
					system("cls");
					g.Load1();

					cout << endl << endl << "��� ����������� ������� ����� �����" << endl;
					int cont1;
					cin >> cont1;
				}
			}
			else
			{
				cout << endl << endl << "������ ������������ ����� ��� ������";
				Sleep(2000);
			}
		}
	}

	return 0;
}


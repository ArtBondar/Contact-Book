#include "Header.h"
int main() {
	setlocale(LC_ALL, "rus");
	int size = 0;
	int menu = 0;
	int poisk = 0;
	int del = 0;
	contact **book = NULL;
	do {
		cout << "===================================================\n";
		cout << "\t \t ����: \n";
		cout << "===================================================\n";
		cout << "\t 0 - �����\n";
		cout << "\t 1 - �������� �������\n";
		cout << "\t 2 - ������� �������\n";
		cout << "\t 3 - ����� ������ ��������� �� �����\n";
		cout << "\t 4 - �����\n";
		cout << "\t 5 - ��������� � ����\n";
		cout << "\t 6 - ��������� ���� � ����������\n";
		cout << "===================================================\n";
		cout << "������� ����� �������: "; cin >> menu;
		system("cls");
		switch (menu){
		default:
			cout << "������� ������� �� ������.\n"; break;
		case 0:
			cout << "�� �������.\n"; break;
		case 1:
			createcontact(book, size);
			break;
		case 2:
			cout << "===========================\n";
			cout << "\t ��������\n";
			cout << "===========================\n";
			cout << "\t 1 - �� �����\n";
			cout << "\t 2 - ��� � ��� !\n";
			cout << "===========================\n";
			cout << "������� ����� �������: "; cin >> del;
			switch (del)
			{
			default:
				cout << "������� 1 ��� 2 \n";
				break;
			case 1:
				delcontact(book, size);
				break;
			case 2:
				delALL(book, size);
				break;
			}
		case 3:
			coutcont(book, size);
			break;
		case 4:
			cout << "===========================\n";
			cout << "\t �����\n";
			cout << "===========================\n";
			cout << "\t 1 - �� �����\n";
			cout << "\t 2 - �� ������\n";
			cout << "===========================\n";
			cout << "������� ����� �������: "; cin >> poisk;
			switch (poisk)
			{
			default:
				cout << "������� 1 ��� 2 \n";
				break;
			case 1:
				findName(book, size);
				break;
			case 2:
				findNumber(book, size);
				break;
			}
			break;
		case 5:
			write_file(book, size);
			break;
		case 6:
			read_file(book, size);
			break;
		}
	} while (menu != 0);
	return 0;
}

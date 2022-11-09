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
		cout << "\t \t МЕНЮ: \n";
		cout << "===================================================\n";
		cout << "\t 0 - Выход\n";
		cout << "\t 1 - Добавить контакт\n";
		cout << "\t 2 - Удалить контакт\n";
		cout << "\t 3 - Вывод списка контактов на экран\n";
		cout << "\t 4 - Поиск\n";
		cout << "\t 5 - Сохранить в файл\n";
		cout << "\t 6 - Загрузить файл с контактами\n";
		cout << "===================================================\n";
		cout << "Введите номер команды: "; cin >> menu;
		system("cls");
		switch (menu){
		default:
			cout << "Введите команду из списка.\n"; break;
		case 0:
			cout << "До встречи.\n"; break;
		case 1:
			createcontact(book, size);
			break;
		case 2:
			cout << "===========================\n";
			cout << "\t Удаление\n";
			cout << "===========================\n";
			cout << "\t 1 - По имени\n";
			cout << "\t 2 - Все и вся !\n";
			cout << "===========================\n";
			cout << "Введите номер команды: "; cin >> del;
			switch (del)
			{
			default:
				cout << "Введите 1 или 2 \n";
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
			cout << "\t Поиск\n";
			cout << "===========================\n";
			cout << "\t 1 - По имени\n";
			cout << "\t 2 - По номеру\n";
			cout << "===========================\n";
			cout << "Введите номер команды: "; cin >> poisk;
			switch (poisk)
			{
			default:
				cout << "Введите 1 или 2 \n";
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

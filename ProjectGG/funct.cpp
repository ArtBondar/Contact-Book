#include "Header.h"
int cin_int() {
	bool flag;
	char temp[12];
	char *str;
	do {
		flag = true;
		gets_s(temp);
		str = new char[strlen(temp) + 1];
		strcpy(str, temp);
		for (int i = 0; i < strlen(str); i++) {
			if (isdigit(str[i]) != 0) {
				if (i == 0 && (str[i] == '-' || str[i] == '+')) {
					continue;
				}
			}
			else {
				flag = false;
				cout << "Только цифры!!!\n";
				break;
			}
		}
	} while (flag != true);
	int x = atoi(str);
	return x;
}
void sort(contact **&book, int &size) {
	for (int i = (size - 1); i >= 0; i--) {
		int z = 0;
		for (int j = 0; j < (size - 1); j++)
		{
			if (strcmp(book[j]->name, book[j + 1]->name) > 0) {
				swap(book[j], book[j + 1]);
				z++;
			}
		}
		if (z == 0)
			break;
	}
}
void createcontact(contact **&book, int &size) {
	size++;
	contact **tempbook = new contact*[size];
	for (int i = 0; i < size - 1; i++) {
		tempbook[i] = book[i];
	}
	tempbook[size - 1] = new contact;
	tempbook[size - 1]->name = NULL;
	tempbook[size - 1]->telcount = 0;
	rename(tempbook, size, size - 1);
	cindate(tempbook, size, size - 1);
	addtel(tempbook, size, size - 1);
	if (size > 1)
		delete[] book;
	book = tempbook;
	cout << "\nКонтакт добавлен.";
	Sleep(1000);
	system("cls");
}
void rename(contact **book, int size, int Ncont) {
	char temp[50];
	if (book[Ncont]->name != NULL) {
		delete book[Ncont]->name;
	}
	cout << "===================================";
	cout << "\nВведите имя контакта: "; gets_s(temp);
	gets_s(temp);
	book[Ncont]->name = new char[strlen(temp) + 1];
	strcpy(book[Ncont]->name, temp);
}
void cindate(contact **book, int size, int Ncont) {
	cout << "\n=======Введите дату рождения=======";
	int temp;
	do {
		cout << "\nГод: ";
		temp = cin_int();
		if (temp > 2019)
			cout << "\nОн еще не родился?";
		if (temp < 1865)
			cout << "\nОго!!! он бессмертный?";
	} while (temp > 2019 || temp < 1865);
	book[Ncont]->bd.year = temp;
	do {
		cout << "\nМесяц: ";
		temp = cin_int();
		if (temp > 12 || temp < 1)
			cout << "\nВ году 12 месяцев!!!";
	} while (temp > 12 || temp < 1);
	book[Ncont]->bd.month = temp;
	bool day;
	do {
		day = true;
		cout << "\nДень: ";
		temp = cin_int();
		if ((book[Ncont]->bd.year) % 4 == 0) {
			if (book[Ncont]->bd.month == 11 && temp > 30)
				day = false;
			if (book[Ncont]->bd.month == 2 && temp > 29)
				day = false;
		}
		else {
			if (book[Ncont]->bd.month == 11 && temp > 30)
				day = false;
			if (book[Ncont]->bd.month == 2 && temp > 28)
				day = false;
		}
		if (temp < 1 || temp>31)
			day = false;
		if (day != true)
			cout << "\nВ этом году/месяце такого дня нет!!!";
	} while (day != true);
	book[Ncont]->bd.day = temp;
}
void addtel(contact **book, int size, int Ncont) {
	book[Ncont]->telcount++;
	char**temptel = new char*[book[Ncont]->telcount];
	for (int i = 0; i < (book[Ncont]->telcount) - 1; i++) {
		temptel[i] = book[Ncont]->tel[i];
	}
	char temp[36];
	cout << "\nВведите номер: ";
	gets_s(temp);
	temptel[book[Ncont]->telcount - 1] = new char[strlen(temp) + 1];
	strcpy(temptel[book[Ncont]->telcount - 1], temp);
	if (book[Ncont]->telcount > 1)
		delete[] book[Ncont]->tel;

	book[Ncont]->tel = temptel;
	cout << "\nНомер добавлен.";
	Sleep(1000);
}
//Создание+
void delALL(contact **&book, int &size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < book[i]->telcount; j++)
			delete[] book[i]->tel[j];
		delete[] book[i]->tel;
		delete book[i]->name;
		delete[] book[i];
	}
	book = NULL;
	size = 0;
	cout << "\nУдаленно!!!";
	Sleep(1500);
}
void delcontact(contact **&book, int &size) {
	char temp[50];
	cout << "\nВведите имя: ";
	gets_s(temp); gets_s(temp);
	char *find = new char[strlen(temp) + 1];
	strcpy(find, temp);
	int findcol = 0;
	for (int i = 0; i < size; i++) {
		if (strstr(book[i]->name, find) != 0)
			findcol++;
	}
	int *mas = new int[findcol];
	for (int i = 0, j = 0; i < size; i++) {
		if (strstr(book[i]->name, find) != 0) {
			mas[j] = i;
			j++;
		}
	}
	if (findcol == 0) {
		cout << "\nСовпадений не найденно!";
		Sleep(1500);
	}
	else {
		int *arr = new int[size];
		cout << "\nНайденно " << findcol << " контакотов...";
		Sleep(1500);
		char**n = new char*[findcol];//массив найденных(имена)
		for (int i = 0; i < findcol; i++) {
			n[i] = new char[strlen(book[mas[i]]->name) + 1];
			strcpy(n[i], book[mas[i]]->name);
		}
		for (int j = 0; j < findcol; j++) {
			cout << "\n===================================================";
			cout << "\nИмя: ";			 cout << book[mas[j]]->name;
			cout << "\nДата рождения: "; cout << book[mas[j]]->bd.day << "." << book[mas[j]]->bd.month << "." << book[mas[j]]->bd.year;
			cout << "\nНомера телефонов: ";
			for (int i = 0; i < book[mas[j]]->telcount; i++)
				cout << book[mas[j]]->tel[i] << endl;
		}
	}
	if (size == 1) {
		delALL(book, size);
	}
	else {
		contact **tempbook = new contact*[size - 1];
		for (int i = 0, j = 0; i < size; i++) {
			if (i == mas[j]) {
				continue;
			}
			else {
				tempbook[j] = new contact;
				tempbook[j] = book[i];
				j++;
			}
		}
		for (int i = 0; i < findcol; i++){
			for (int j = 0; j < book[mas[i]]->telcount; j++)
				delete[] book[mas[i]]->tel[j];
			delete[] book[mas[i]]->tel;
			delete[] book[mas[i]]->name;
			delete[] book[mas[i]];
			book = tempbook;
			size--;
		}
		cout << "\nУдаленно!!!";
		Sleep(1500);
	}
}
//Удаление+
void write_file(contact **&book, int &size) {
	FILE *f;
	f = fopen("telbook.txt", "wb");
	fclose(f);
	f = fopen("telbook.txt", "wb");
	fwrite(&size, sizeof(int), 1, f);
	for (int i = 0; i < size; i++) {
		int namecoll = strlen(book[i]->name);
		fwrite(&namecoll, sizeof(int), 1, f);
		fwrite(book[i]->name, sizeof(char), namecoll, f);
		fwrite(&(book[i]->bd.day), sizeof(int), 1, f);
		fwrite(&(book[i]->bd.month), sizeof(int), 1, f);
		fwrite(&(book[i]->bd.year), sizeof(int), 1, f);
		fwrite(&(book[i]->telcount), sizeof(int), 1, f);
		for (int j = 0; j < book[i]->telcount; j++) {
			int telcoll = strlen(book[i]->tel[j]);
			fwrite(&telcoll, sizeof(int), 1, f);
			fwrite(book[i]->tel[j], sizeof(char), telcoll, f);
		}
	}
	fclose(f);
	cout << "===================================================\n";
	cout << "\t Файл успешно записан\n";
	cout << "===================================================\n";
	Sleep(2000);
	system("cls");
}
void read_file(contact **&book, int &size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < book[i]->telcount; j++)
			delete[] book[i]->tel[j];
		delete[] book[i]->tel;
		delete book[i]->name;
		delete[] book[i];
	}
	book = NULL;
	size = 0;
	FILE *f;
	if ((f = fopen("telbook.txt", "rb")) != NULL) {
		int sizebook;
		fread(&sizebook, sizeof(int), 1, f);
		for (int i = 0, nl; i < sizebook; i++) {
			size++;
			contact **tempbook = new contact*[size];
			for (int i = 0; i < size - 1; i++) {
				tempbook[i] = book[i];
			}
			tempbook[size - 1] = new contact;
			tempbook[size - 1]->name = NULL;
			tempbook[size - 1]->telcount = 0;
			fread(&nl, sizeof(int), 1, f);
			tempbook[i]->name = new char[nl + 1];
			fread(tempbook[i]->name, sizeof(char), nl, f);
			tempbook[i]->name[nl] = '\0';
			fread(&tempbook[i]->bd.day, sizeof(int), 1, f);
			fread(&tempbook[i]->bd.month, sizeof(int), 1, f);
			fread(&tempbook[i]->bd.year, sizeof(int), 1, f);
			fread(&tempbook[i]->telcount, sizeof(int), 1, f);
			int tell;
			tempbook[i]->tel = new char*[tempbook[i]->telcount];
			for (int j = 0; j < tempbook[i]->telcount; j++) {
				fread(&tell, sizeof(int), 1, f);
				tempbook[i]->tel[j] = new char[tell + 1];
				fread(tempbook[i]->tel[j], sizeof(char), tell, f);
				tempbook[i]->tel[j][tell] = '\0';
			}
			if (size > 1)
				delete[] book;
			book = tempbook;
		}
		fclose(f);
		cout << "===================================================\n";
		cout << "\t Файл успешно загружен\n";
		cout << "===================================================\n";
		Sleep(2000);
		system("cls");
	}
	else {
		cout << "===================================================\n";
		cout << "\nОшибка, файл не найден!!!";
		cout << "===================================================\n";
		system("cls");
		Sleep(1500);
	}

}
//Файл+
void findName(contact **&book, int &size) {
	char temp[50];
	cout << "\nВведите имя: ";
	gets_s(temp); gets_s(temp);
	char *find = new char[strlen(temp) + 1];
	strcpy(find, temp);
	int findcol = 0;
	for (int i = 0; i < size; i++) {
		if (strstr(book[i]->name, find) != 0)
			findcol++;
	}
	int *mas = new int[findcol];
	for (int i = 0, j = 0; i < size; i++) {
		if (strstr(book[i]->name, find) != 0) {
			mas[j] = i;
			j++;
		}
	}
	if (findcol == 0) {
		cout << "\nСовпадений не найденно!";
		Sleep(1500);
	}
	else {
		int *arr = new int[size];
		cout << "\nНайденно " << findcol << " контакотов...";
		Sleep(1500);
		char**n = new char*[findcol];//массив найденных(имена)
		for (int i = 0; i < findcol; i++) {
			n[i] = new char[strlen(book[mas[i]]->name) + 1];
			strcpy(n[i], book[mas[i]]->name);
		}
		for (int j = 0; j < findcol; j++) {
			cout << "\n===================================================";
			cout << "\nИмя: ";			 cout << book[mas[j]]->name;
			cout << "\nДата рождения: "; cout << book[mas[j]]->bd.day << "." << book[mas[j]]->bd.month << "." << book[mas[j]]->bd.year;
			cout << "\nНомера телефонов: ";
			for (int i = 0; i < book[mas[j]]->telcount; i++)
				cout << book[mas[j]]->tel[i] << endl;
		}
	}
	cout << "\nДля возврата в основное меню нажмите любую клавишу...\n";
	_getch();
	system("cls");
}
void findNumber(contact **&book, int &size) {
	cout << "\nВведите номер для поиска: ";
	char temp[36];
	gets_s(temp); gets_s(temp);
	char *findtel = new char[strlen(temp) + 1];
	strcpy(findtel, temp);
	int findcol = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < book[i]->telcount; j++) {
			if (strstr(book[i]->tel[j], findtel) != 0)
				findcol++;
		}
	}
	int *mas = new int[findcol];
	for (int i = 0, k = 0; i < size; i++) {
		for (int j = 0; j < book[i]->telcount; j++) {
			if (strstr(book[i]->tel[j], findtel) != 0) {
				mas[k] = i;
				k++;
				break;
			}
		}
	}
	if (findcol == 0) {
		cout << "\nСовпадений не найденно!";
		Sleep(1500);
	}
	else {
		cout << "\nНайденно " << findcol << " контакотов...";
		Sleep(1500);
		char**n = new char*[findcol];//массив найденных(имена)
		for (int i = 0; i < findcol; i++) {
			n[i] = new char[strlen(book[mas[i]]->name) + 1];
			strcpy(n[i], book[mas[i]]->name);
		}
		for (int j = 0; j < findcol; j++) {
			cout << "\n===================================================";
			cout << "\nИмя: ";			 cout << book[mas[j]]->name;
			cout << "\nДата рождения: "; cout << book[mas[j]]->bd.day << "." << book[mas[j]]->bd.month << "." << book[mas[j]]->bd.year;
			cout << "\nНомера телефонов: ";
			for (int i = 0; i < book[mas[j]]->telcount; i++)
				cout << book[mas[j]]->tel[i] << endl;
		}
	}
	cout << "\nДля возврата в основное меню нажмите любую клавишу...\n";
	_getch();
	system("cls");
}
//Поиск+
void coutcont(contact **book, int size) {
	sort(book, size);
	system("cls");
	for (int j = 0; j < size; j++) {
		cout << "\n===================================================";
		cout << "\nИмя: ";			 cout << book[j]->name;
		cout << "\nДата рождения: "; cout << book[j]->bd.day << "." << book[j]->bd.month << "." << book[j]->bd.year;
		cout << "\nНомера телефонов: ";
		for (int i = 0; i < book[j]->telcount; i++)
			cout << book[j]->tel[i] << endl;
	}
	cout << "\nДля возврата в основное меню нажмите любую клавишу...\n";
	_getch();
	system("cls");
}
//Вывод+
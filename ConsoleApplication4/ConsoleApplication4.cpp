// ConsoleApplication4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <cstdlib>
#include "ConsoleApplication4.h"
using namespace std;

class Contacts {
private:
	ofstream ofstr;
	ifstream ifstr;
	string newContact, newNumber, result;
	friend void writeResult(int choice, Contacts&);
	friend int getResult();
public:
	Contacts() {
	}
	void addContact() {			
		ofstr.open("contactlist.txt", ios_base::app);
		cout << "������� ��� �������� : ";
		cin >> newContact;
		ofstr << newContact << " ";
		cout << "������� ����� : ";
		cin >> newNumber;
		ofstr << newNumber << "\n";
		ofstr.close();
		cout << "������� �������� " << endl;
	}

	void deleteContact() {
		int a = getSizeFirstFile();
		int get;
		ifstr.open("contactlist.txt");
		clearSecondList();
		ofstr.open("contactlistcopy.txt", ios::app);
		string *list = new string[a];
		int i = 0;
		while (getline(ifstr, result)) {
			list[i] = result;
			cout << i + 1 << ") " << result << endl;
			i++;
		}
		cout << "�������� ����� ��������, ������� �� ������ ������� : " << endl;
		get = getResult();
		for (int j = 0; j < a; j++) {
			if (j + 1 != get) {
				ofstr << list[j] << "\n";
			}
		}
		
		ifstr.close();
		ofstr.close();
		writeInFirstTxt(list, i - 1, get - 1);
	}

	void writeInFirstTxt(string *list, int size, int choice) {
		clearList();
		ofstr.open("contactlist.txt", ios::in | ios_base::app);
		for (int i = 0; i <= size; i++) {
			if (i != choice) {
				ofstr << list[i] << "\n";
			}
		}
		ofstr.close();
	}

	void clearList() {
		ofstr.open("contactlist.txt", ios::out);
		ofstr.close();
	}

	void clearSecondList() {
		ofstr.open("contactlistcopy.txt", ios::out);
		ofstr.close();
	}

	void closeOfstream() {
		ofstr.close();
	}

	int getSizeSecondFile() {
		int i = 0;
		ifstr.open("contactlistcopy.txt");
		while (getline(ifstr, result)) {
			i++;
		}
		ifstr.close();
		return i;
	}

	int getSizeFirstFile() {
		int i = 0;
		ifstr.open("contactlist.txt");
		string res;
		while (getline(ifstr, res)) {
			i++;
		}
		ifstr.close();
		return i;
	}

	void contactList() {
		int i = 1;
		ifstr.open("contactlist.txt");
		while (getline(ifstr, result)) {
			cout << i << ") " << result << endl;
			i++;
		}
		ifstr.close();
	}

};

void setStandartText() {
	//������� ������ �� �����
	cout << "                      ------------------------------------------" << endl;
	cout << "                      -%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%-" << endl;
	cout << "                      -% ������� �������� ����� ��� ��������: %-" << endl;
	cout << "                      -%                                      %-" << endl;
	cout << "                      -% 1 - �������� �������                 %-" << endl;
	cout << "                      -% 2 - ���������� ������ ���������      %-" << endl;
	cout << "                      -% 3 - ������� �������                  %-" << endl;
	cout << "                      -% 4 - �������� ������ ���������        %-" << endl;
	cout << "                      -% 0 - �����                            %-" << endl;
	cout << "                      -%                                      %-" << endl;
	cout << "                      -%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%-" << endl;
	cout << "                      ------------------------------------------" << endl;
}

bool checkLine(char str[]){
	//������� �������� ������ �� �����
	char *p = str;
	bool isNumber = true;
	while (*p)
		if (!isdigit(*p++)) {
			isNumber = false;
			break;
		}
	if (isNumber) {
		return true;
	}
	else return false;
}

int getIntFromArray(char arr[]) {
	//���������� �������� ��������
	int num = 0;
	for (int i = 0; arr[i]; i++) {
		if (arr[i] == '0') {
			num = 0;
		}
		else if (arr[i] == '1') {
			num = 1;
		}
		else if (arr[i] == '2') {
			num = 2;
		}
		else if (arr[i] == '3') {
			num = 3;
		}
		else if (arr[i] == '4') {
			num = 4;
		}
		else if (arr[i] == '5') {
			num = 5;
		}
		else if (arr[i] == '6') {
			num = 6;
		}
		else if (arr[i] == '7') {
			num = 7;
		}
		else if (arr[i] == '8') {
			num = 8;
		}
		else if (arr[i] == '9') {
			num = 9;
		}
		else num = 10;
	} 
	return num;
}

int getResult() {
	//�������� �������� ������ � ������
	char choice[256];
	cin >> choice;
	int value;
	if (checkLine(choice)){
		return value = getIntFromArray(choice);
	}
	else
	{
		cout << "�� �� ����� �����" << endl;
		getResult();
	}
	
}

void writeResult(int choice, Contacts& contacts) {
	//������� ���������
	if (choice == 0) {
		contacts.closeOfstream();
		exit(1); //���������� ������ ��������� 
	}
	else if (choice == 1) {
		contacts.addContact();
	}
	else if(choice == 2){
		contacts.contactList();
	}
	else if (choice == 3){
		contacts.deleteContact(); 
	}
	else if(choice == 4){
		contacts.clearList();
	}
	else if(choice > 4){
		cout << "������ ����� � ������ ���" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Contacts contacts;
	while (true)
	{
		
		setStandartText();
		writeResult(getResult(), contacts);
	}
	system("PAUSE");
    return 0;
}


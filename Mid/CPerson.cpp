#include "pch.h"
#include "CPerson.h"


// Ű����� �ι����� ����
void Person::SetTitlefromKB() {
	string str;
	cout << "\tPerson Name : " << endl << "\t>> ";
	cin >> str;
	m_cName = str;
}


// Ű����� �ι� ������ ����
void Person::SetDescriptionfromKB() {
	string str;
	cout << "\tPerson Description : " << endl << "\t>> ";
	cin.ignore();
	getline(cin, str);
	m_cDes = str;
}


// �ι����� ȭ�鿡 ���
void Person::DisplayTitle() {
	cout << "\t�ι� : " << m_cName << endl;
}


// �ι� ������ ȭ�鿡 ���
void Person::DisplayDescriptionOnScreen() {
	cout << "\t�ι� ���� : " << m_cDes << endl;
}


// �ι� ������ ȭ�鿡 ���
void Person::DisplayRecordOnScreen() {
	DisplayTitle();
	DisplayDescriptionOnScreen();
	DisplayIncludedContents();
	cout << endl;
}
#include "pch.h"
#include "CLocation.h"


// Ű����� ��Ҹ��� ����
void Location::SetTitlefromKB() {
	string str;
	cout << "\tLocation : " << endl << "\t>> ";
	cin >> str;
	m_cName = str;
}


// Ű����� ��� ������ ����
void Location::SetDescriptionfromKB() {
	string str;
	cout << "\tLocation Description : " << endl << "\t>> ";
	cin.ignore();
	getline(cin, str);
	m_cDes = str;
}


// ��Ҹ��� ȭ�鿡 ���
void Location::DisplayTitle() {
	cout << "\t��� : " << m_cName << endl;
}


// ��� ������ ȭ�鿡 ���
void Location::DisplayDescriptionOnScreen() {
	cout << "\t��� ���� : " << m_cDes << endl;
}


// ��� ������ ȭ�鿡 ���
void Location::DisplayRecordOnScreen() {
	DisplayTitle();
	DisplayDescriptionOnScreen();
	DisplayIncludedContents();
	cout << endl;
}
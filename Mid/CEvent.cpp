#include "pch.h"
#include "CEvent.h"


// Ű����� �̺�Ʈ���� ����
void Event::SetTitlefromKB() {
	string str;
	cout << "\tEventName : " << endl << "\t>> ";
	cin >> str;
	m_cName = str;
}


// Ű����� �̺�Ʈ ������ ����
void Event::SetDescriptionfromKB() {
	string str;
	cout << "\tEventDescription : " << endl << "\t>> ";
	cin.ignore();
	getline(cin, str);
	m_cDes = str;
}


// �̺�Ʈ���� ȭ�鿡 ���
void Event::DisplayTitle() {
	cout << "\t�̺�Ʈ�� : " << m_cName << endl;
}


// �̺�Ʈ ������ ȭ�鿡 ���
void Event::DisplayDescriptionOnScreen() {
	cout << "\t�̺�Ʈ ���� : " << m_cDes << endl;
}


// �̺�Ʈ ������ ȭ�鿡 ���
void Event::DisplayRecordOnScreen() {
	DisplayTitle();
	DisplayDescriptionOnScreen();
	DisplayIncludedContents();
	cout << endl;
}
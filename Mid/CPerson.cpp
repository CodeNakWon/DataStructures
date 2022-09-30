#include "pch.h"
#include "CPerson.h"


// 키보드로 인물명을 설정
void Person::SetTitlefromKB() {
	string str;
	cout << "\tPerson Name : " << endl << "\t>> ";
	cin >> str;
	m_cName = str;
}


// 키보드로 인물 설명을 설정
void Person::SetDescriptionfromKB() {
	string str;
	cout << "\tPerson Description : " << endl << "\t>> ";
	cin.ignore();
	getline(cin, str);
	m_cDes = str;
}


// 인물명을 화면에 출력
void Person::DisplayTitle() {
	cout << "\t인물 : " << m_cName << endl;
}


// 인물 설명을 화면에 출력
void Person::DisplayDescriptionOnScreen() {
	cout << "\t인물 설명 : " << m_cDes << endl;
}


// 인물 정보를 화면에 출력
void Person::DisplayRecordOnScreen() {
	DisplayTitle();
	DisplayDescriptionOnScreen();
	DisplayIncludedContents();
	cout << endl;
}
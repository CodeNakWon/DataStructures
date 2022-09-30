#include "pch.h"
#include "CLocation.h"


// 키보드로 장소명을 설정
void Location::SetTitlefromKB() {
	string str;
	cout << "\tLocation : " << endl << "\t>> ";
	cin >> str;
	m_cName = str;
}


// 키보드로 장소 설명을 설정
void Location::SetDescriptionfromKB() {
	string str;
	cout << "\tLocation Description : " << endl << "\t>> ";
	cin.ignore();
	getline(cin, str);
	m_cDes = str;
}


// 장소명을 화면에 출력
void Location::DisplayTitle() {
	cout << "\t장소 : " << m_cName << endl;
}


// 장소 설명을 화면에 출력
void Location::DisplayDescriptionOnScreen() {
	cout << "\t장소 설명 : " << m_cDes << endl;
}


// 장소 정보를 화면에 출력
void Location::DisplayRecordOnScreen() {
	DisplayTitle();
	DisplayDescriptionOnScreen();
	DisplayIncludedContents();
	cout << endl;
}
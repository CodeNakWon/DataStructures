#include "pch.h"
#include "CEvent.h"


// 키보드로 이벤트명을 설정
void Event::SetTitlefromKB() {
	string str;
	cout << "\tEventName : " << endl << "\t>> ";
	cin >> str;
	m_cName = str;
}


// 키보드로 이벤트 설명을 설정
void Event::SetDescriptionfromKB() {
	string str;
	cout << "\tEventDescription : " << endl << "\t>> ";
	cin.ignore();
	getline(cin, str);
	m_cDes = str;
}


// 이벤트명을 화면에 출력
void Event::DisplayTitle() {
	cout << "\t이벤트명 : " << m_cName << endl;
}


// 이벤트 설명을 화면에 출력
void Event::DisplayDescriptionOnScreen() {
	cout << "\t이벤트 설명 : " << m_cDes << endl;
}


// 이벤트 정보를 화면에 출력
void Event::DisplayRecordOnScreen() {
	DisplayTitle();
	DisplayDescriptionOnScreen();
	DisplayIncludedContents();
	cout << endl;
}
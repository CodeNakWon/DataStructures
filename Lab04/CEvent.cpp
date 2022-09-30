#include "pch.h"
#include "CEvent.h"

// 이벤트명을 설정
void Event::setEventName(string name) {
	m_eName = name;
}

// 이벤트 설명을 설정
void Event::setEventDescription(string des) {
	m_eDes = des;
}


// 이벤트 이름을 반환
string Event::getEventName() const{
	return m_eName;
}

// 이벤트 설명을 반환
string Event::setEventDescription() const{
	return m_eDes;
}


//키보드로 이벤트명을 설정
void Event::setEventNamefromKB() {
	string str;
	cout << "\tEventName : " << endl << "\t>> ";
	cin >> str;
	m_eName = str;
}


// 키보드로 이벤트 설명을 설정
void Event::setEventDescriptionfromKB() {
	string str;
	cout << "\tEventDescription : " << endl << "\t>> ";
	cin >> str;
	m_eDes = str;
}


// 이벤트명을 화면에 출력
void Event::DisplayEventName() {
	cout << "\t이벤트명 : " << m_eName << endl;
}

void Event::DisplayDescriptionOnScreen() {
	cout << "\t이벤트설명 : " << m_eDes << endl;
}

// 이벤트에 포함된 콘텐츠명을 출력
void Event::DisplayIncludedContents() {
	int count = 0;
	string item;
	cout << "\t포함된 컨텐츠 : " << endl;
	m_mcList.ResetList();
	while (m_mcList.GetNextItem(item) != -1) {
		cout << "\t\t\t - " << item << endl;
		count++;
	}
	if (!count) {
		cout << "\t\t없음.";
	}
	cout << endl;
}


// 이벤트 정보를 화면에 출력
void Event::DisplayRecordOnScreen() {
	DisplayEventName();
	DisplayDescriptionOnScreen();
	DisplayIncludedContents();
	cout << endl;
}

int Event::Retrieve(MultimediaContent &mc) {
	string str = mc.GetName();
	return m_mcList.Retrieve(str);
}


// MC이름(MC의 Pirmary key)을 이벤트 리스트에 추가
int Event::AddMC(MultimediaContent &mc) {
	string name = mc.GetName();
	if (m_mcList.Add(name) == 1) {
		m_eLen++;
		return 1;
	}
	else if (m_mcList.Add(name) == -1) {
		return -1;
	}
	else {
		return 0;
	}
}


// MC이름(MC의 Pirmary key)을 이벤트 리스트에서 삭제
int Event::Delete(MultimediaContent &mc) {
	string name = mc.GetName();
	if (m_mcList.Delete(name)) {
		m_eLen--;
		return 1;
	}
	return 0;
}


// 이벤트 리스트가 비었는지 확인
bool Event::isEmpty() {
	if (m_eLen == 0) {
		return true;
	}
	return false;
}

void Event::DisplayDetailAll(SortedList<MultimediaContent>& lst) {
	m_mcList.ResetList();
	string str;
	MultimediaContent con;
	while (m_mcList.GetNextItem(str) != -1) {
		con.SetName(str);
		lst.Retrieve(con);
		con.DisplayRecordOnScreen();
	}
}
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


// 이벤트에 포함된 콘텐츠명을 출력
void Event::DisplayIncludedContents() {
	string str;
	int count = 0;
	cout << "\t포함된 컨텐츠 : " << endl;
	cout << "\t";
	m_MCKeys.ResetList();
	while (m_MCKeys.GetNextItem(str) != -1) {
		cout << "\t" << str;
		count++;
	}
	if (!count) {
		cout << "\t없음.";
	}
	cout << endl;
}


// 이벤트 정보를 화면에 출력
void Event::DisplayRecordOnScreen() {
	DisplayEventName();
	cout << "\t이벤트 설명 : " << m_eDes << endl;
	DisplayIncludedContents();
	cout << endl;
}


// MC이름(MC의 Pirmary key)을 이벤트 리스트에 추가
int Event::AddMC(MultimediaContent mc) {
	string name = mc.GetName();
	cout << "AddMC" << endl;
	if (m_MCKeys.Add(name) == 1) {
		m_eLen++;
		m_MCKeys.ResetList();
		while (m_MCKeys.GetNextItem(name)!=-1) {
			cout << name;
		}
		return 1;
	}
	else if (m_MCKeys.Add(name) == -1) {
		return -1;
	}
	else {
		cout << "else" << endl;
		return 0;
	}
}


// MC이름(MC의 Pirmary key)을 이벤트 리스트에서 삭제
int Event::Delete(MultimediaContent& mc) {
	string name = mc.GetName();
	if (m_MCKeys.Delete(name)) {
		m_eLen--;
		return 1;
	}
	return 0;
}


// MC이름(MC의 Pirmary key)으로 이벤트 리스트에서 검색
int Event::Retrieve(MultimediaContent& mc) {
	string name = mc.GetName();
	return m_MCKeys.Retrieve_Binary(name);
}


// 이벤트 리스트가 비었는지 확인
bool Event::isEmpty() {
	if (m_eLen == 0) {
		return true;
	}
	return false;
}